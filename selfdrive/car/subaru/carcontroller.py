from cereal import car
from openpilot.common.numpy_fast import clip, interp
from opendbc.can.packer import CANPacker
from openpilot.selfdrive.car import apply_driver_steer_torque_limits, common_fault_avoidance, make_tester_present_msg
from openpilot.selfdrive.car.interfaces import CarControllerBase
from openpilot.selfdrive.car.subaru import subarucan
from openpilot.selfdrive.car.subaru.values import DBC, GLOBAL_ES_ADDR, CanBus, CarControllerParams, SubaruFlags, SubaruFlagsSP

# FIXME: These limits aren't exact. The real limit is more than likely over a larger time period and
# involves the total steering angle change rather than rate, but these limits work well for now
MAX_STEER_RATE = 25  # deg/s
MAX_STEER_RATE_FRAMES = 7  # tx control frames needed before torque can be cut

_SNG_ACC_MIN_DIST = 3
_SNG_ACC_MAX_DIST = 4.5


class CarController(CarControllerBase):
  def __init__(self, dbc_name, CP, VM):
    super().__init__(dbc_name, CP, VM)
    self.apply_steer_last = 0

    self.cruise_button_prev = 0
    self.steer_rate_counter = 0

    self.subaru_sng = False
    if CP.spFlags & SubaruFlagsSP.SP_SUBARU_SNG:
      self.subaru_sng = True
      self.prev_close_distance = 0
      self.prev_standstill = False
      self.standstill_start = 0
      self.sng_acc_resume = False
      self.sng_acc_resume_cnt = -1
      self.manual_hold = False
      self.prev_cruise_state = 0

    self.p = CarControllerParams(CP)
    self.packer = CANPacker(DBC[CP.carFingerprint]['pt'])

  def update(self, CC, CS, now_nanos):
    actuators = CC.actuators
    hud_control = CC.hudControl
    pcm_cancel_cmd = CC.cruiseControl.cancel

    can_sends = []

    # *** steering ***
    if (self.frame % self.p.STEER_STEP) == 0:
      apply_steer = int(round(actuators.steer * self.p.STEER_MAX))

      # limits due to driver torque

      new_steer = int(round(apply_steer))
      apply_steer = apply_driver_steer_torque_limits(new_steer, self.apply_steer_last, CS.out.steeringTorque, self.p)

      if not CC.latActive:
        apply_steer = 0

      if self.CP.flags & SubaruFlags.PREGLOBAL:
        can_sends.append(subarucan.create_preglobal_steering_control(self.packer, self.frame // self.p.STEER_STEP, apply_steer, CC.latActive))
      else:
        apply_steer_req = CC.latActive

        if self.CP.flags & SubaruFlags.STEER_RATE_LIMITED:
          # Steering rate fault prevention
          self.steer_rate_counter, apply_steer_req = \
            common_fault_avoidance(abs(CS.out.steeringRateDeg) > MAX_STEER_RATE, apply_steer_req,
                                  self.steer_rate_counter, MAX_STEER_RATE_FRAMES)

        can_sends.append(subarucan.create_steering_control(self.packer, apply_steer, apply_steer_req))

      self.apply_steer_last = apply_steer

    # *** stop and go ***
    throttle_cmd, speed_cmd = self.stop_and_go(CC, CS)

    # *** longitudinal ***

    if CC.longActive:
      apply_throttle = int(round(interp(actuators.accel, CarControllerParams.THROTTLE_LOOKUP_BP, CarControllerParams.THROTTLE_LOOKUP_V)))
      apply_rpm = int(round(interp(actuators.accel, CarControllerParams.RPM_LOOKUP_BP, CarControllerParams.RPM_LOOKUP_V)))
      apply_brake = int(round(interp(actuators.accel, CarControllerParams.BRAKE_LOOKUP_BP, CarControllerParams.BRAKE_LOOKUP_V)))

      # limit min and max values
      cruise_throttle = clip(apply_throttle, CarControllerParams.THROTTLE_MIN, CarControllerParams.THROTTLE_MAX)
      cruise_rpm = clip(apply_rpm, CarControllerParams.RPM_MIN, CarControllerParams.RPM_MAX)
      cruise_brake = clip(apply_brake, CarControllerParams.BRAKE_MIN, CarControllerParams.BRAKE_MAX)
    else:
      cruise_throttle = CarControllerParams.THROTTLE_INACTIVE
      cruise_rpm = CarControllerParams.RPM_MIN
      cruise_brake = CarControllerParams.BRAKE_MIN

    # *** alerts and pcm cancel ***
    if self.CP.flags & SubaruFlags.PREGLOBAL:
      if self.frame % 5 == 0:
        # 1 = main, 2 = set shallow, 3 = set deep, 4 = resume shallow, 5 = resume deep
        # disengage ACC when OP is disengaged
        if pcm_cancel_cmd:
          cruise_button = 1
        # turn main on if off and past start-up state
        elif not CS.out.cruiseState.available and CS.ready:
          cruise_button = 1
        else:
          cruise_button = CS.cruise_button

        # unstick previous mocked button press
        if cruise_button == 1 and self.cruise_button_prev == 1:
          cruise_button = 0
        self.cruise_button_prev = cruise_button

        can_sends.append(subarucan.create_preglobal_es_distance(self.packer, cruise_button, CS.es_distance_msg))

      if self.subaru_sng:
        can_sends.append(subarucan.create_preglobal_throttle(self.packer, CS.throttle_msg["COUNTER"] + 1, CS.throttle_msg, throttle_cmd))

    else:
      if self.frame % 10 == 0:
        can_sends.append(subarucan.create_es_dashstatus(self.packer, self.frame // 10, CS.es_dashstatus_msg, CC.enabled,
                                                        self.CP.openpilotLongitudinalControl, CC.longActive, hud_control.leadVisible))

        can_sends.append(subarucan.create_es_lkas_state(self.packer, self.frame // 10, CS.es_lkas_state_msg, CC.latActive, CS.madsEnabled, hud_control.visualAlert,
                                                        hud_control.leftLaneVisible, hud_control.rightLaneVisible,
                                                        hud_control.leftLaneDepart, hud_control.rightLaneDepart))

        if self.CP.flags & SubaruFlags.SEND_INFOTAINMENT:
          can_sends.append(subarucan.create_es_infotainment(self.packer, self.frame // 10, CS.es_infotainment_msg, hud_control.visualAlert))

      if self.subaru_sng:
        can_sends.append(subarucan.create_throttle(self.packer, CS.throttle_msg["COUNTER"] + 1, CS.throttle_msg, throttle_cmd))

        if self.frame % 2 == 0:
          can_sends.append(subarucan.create_brake_pedal(self.packer, self.frame // 2, CS.brake_pedal_msg, speed_cmd, pcm_cancel_cmd))

      if self.CP.openpilotLongitudinalControl:
        if self.frame % 5 == 0:
          can_sends.append(subarucan.create_es_status(self.packer, self.frame // 5, CS.es_status_msg,
                                                      self.CP.openpilotLongitudinalControl, CC.longActive, cruise_rpm))

          can_sends.append(subarucan.create_es_brake(self.packer, self.frame // 5, CS.es_brake_msg,
                                                     self.CP.openpilotLongitudinalControl, CC.longActive, cruise_brake))

          can_sends.append(subarucan.create_es_distance(self.packer, self.frame // 5, CS.es_distance_msg, 0, pcm_cancel_cmd,
                                                        self.CP.openpilotLongitudinalControl, cruise_brake > 0, cruise_throttle))
      else:
        if pcm_cancel_cmd:
          if not (self.CP.flags & SubaruFlags.HYBRID):
            bus = CanBus.alt if self.CP.flags & SubaruFlags.GLOBAL_GEN2 else CanBus.main
            can_sends.append(subarucan.create_es_distance(self.packer, CS.es_distance_msg["COUNTER"] + 1, CS.es_distance_msg, bus, pcm_cancel_cmd))

      if self.CP.flags & SubaruFlags.DISABLE_EYESIGHT:
        # Tester present (keeps eyesight disabled)
        if self.frame % 100 == 0:
          can_sends.append(make_tester_present_msg(GLOBAL_ES_ADDR, CanBus.camera, suppress_response=True))

        # Create all of the other eyesight messages to keep the rest of the car happy when eyesight is disabled
        if self.frame % 5 == 0:
          can_sends.append(subarucan.create_es_highbeamassist(self.packer))

        if self.frame % 10 == 0:
          can_sends.append(subarucan.create_es_static_1(self.packer))

        if self.frame % 2 == 0:
          can_sends.append(subarucan.create_es_static_2(self.packer))

    new_actuators = actuators.as_builder()
    new_actuators.steer = self.apply_steer_last / self.p.STEER_MAX
    new_actuators.steerOutputCan = self.apply_steer_last

    self.frame += 1
    return new_actuators, can_sends

  # Stop and Go auto-resume thanks to martinl from subaru-community
  def stop_and_go(self, CC: car.CarControl, CS: car.CarState, throttle_cmd: bool = False, speed_cmd: bool = False) -> tuple[bool, bool]:
    if not self.subaru_sng:
      return throttle_cmd, speed_cmd
    if self.CP.flags & SubaruFlags.PREGLOBAL:
      # Initiate the ACC resume sequence if conditions are met
      if (CC.enabled                                          # ACC active
        and CS.car_follow == 1                                # lead car
        and CS.out.standstill                                 # must be standing still
        and CS.close_distance > _SNG_ACC_MIN_DIST             # acc resume trigger low threshold
        and CS.close_distance < _SNG_ACC_MAX_DIST             # acc resume trigger high threshold
        and CS.close_distance > self.prev_close_distance):    # distance with lead car is increasing
        self.sng_acc_resume = True
    elif not (self.CP.flags & (SubaruFlags.GLOBAL_GEN2 | SubaruFlags.HYBRID)):
      if CS.params_list.subaru_manual_parking_brake and self.subaru_sng:
        # Send brake message with non-zero speed in standstill to avoid non-EPB ACC disengage
        if (CC.enabled                                        # ACC active
          and CS.car_follow == 1                              # lead car
          and CS.out.standstill
          and self.frame > self.standstill_start + 50):       # standstill for >0.5 second
          speed_cmd = True
      else:
        # Record manual hold set while in standstill and no car in front
        if CS.out.standstill and self.prev_cruise_state == 1 and CS.cruise_state == 3 and CS.car_follow == 0:
          self.manual_hold = True
        # Cancel manual hold when car starts moving
        if not CS.out.standstill:
          self.manual_hold = False
        # Initiate the ACC resume sequence if conditions are met
        if (CC.enabled                                        # ACC active
          and not self.manual_hold
          and CS.car_follow == 1                              # lead car
          and CS.cruise_state == 3                            # ACC HOLD (only with EPB)
          and CS.close_distance > _SNG_ACC_MIN_DIST           # acc resume trigger low threshold
          and CS.close_distance < _SNG_ACC_MAX_DIST           # acc resume trigger high threshold
          and CS.close_distance > self.prev_close_distance):  # distance with lead car is increasing
          self.sng_acc_resume = True

      if CS.out.standstill and not self.prev_standstill:
        self.standstill_start = self.frame
      self.prev_standstill = CS.out.standstill
      self.prev_cruise_state = CS.cruise_state

    if self.sng_acc_resume:
      if self.sng_acc_resume_cnt < 5:
        throttle_cmd = True
        self.sng_acc_resume_cnt += 1
      else:
        self.sng_acc_resume = False
        self.sng_acc_resume_cnt = -1

    self.prev_close_distance = CS.close_distance

    return throttle_cmd, speed_cmd