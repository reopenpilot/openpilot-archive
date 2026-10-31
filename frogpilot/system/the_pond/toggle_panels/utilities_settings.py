import asyncio

from openpilot.system.hardware import HARDWARE

from openpilot.frogpilot.common import frogpilot_utilities, frogpilot_variables
from openpilot.frogpilot.system.the_pond import backups

BUSY_MESSAGE = "Something else is already running. Wait for it to finish and try again."

FLASH_CHECK_INTERVAL = 1

REBOOT_DELAY = 5

RESET_MESSAGES = {"busy": BUSY_MESSAGE, "car_on": "Settings can't be reset while the car is on. Turn the car off and try again."}
RESET_STATUS = {"failure": "Tailscale sign-out failed...", "success": "Reset!"}

action_lock = asyncio.Lock()


def action_guard(context):
  if context.started:
    return "car_on"
  if action_lock.locked():
    return "busy"
  return None


def drive_state(context):
  if frogpilot_variables.params_memory.get_bool("ForceOffroad"):
    return 0
  if frogpilot_variables.params_memory.get_bool("ForceOnroad"):
    return 1
  return 2


async def flash_panda():
  flashed = False
  try:
    frogpilot_variables.params_memory.put_bool("FlashPanda", True)
    while frogpilot_variables.params_memory.get_bool("FlashPanda"):
      await asyncio.sleep(FLASH_CHECK_INTERVAL)

    flashed = frogpilot_variables.params_memory.get("FlashPanda") is None
    frogpilot_variables.params_memory.remove("FlashPanda")
  finally:
    if not flashed:
      action_lock.release()

  if flashed:
    asyncio.get_running_loop().call_later(REBOOT_DELAY, HARDWARE.reboot)
  return flashed


async def force_off(context, body):
  frogpilot_variables.params_memory.put_bool("ForceOffroad", False)
  frogpilot_variables.params_memory.put_bool("ForceOnroad", False)
  return True


async def force_offroad(context, body):
  frogpilot_variables.params_memory.put_bool("ForceOffroad", True)
  frogpilot_variables.params_memory.put_bool("ForceOnroad", False)
  return True


async def force_onroad(context, body):
  context.params.put("CarParams", context.params.get("CarParamsPersistent") or b"")
  context.params.put("FrogPilotCarParams", context.params.get("FrogPilotCarParamsPersistent") or b"")

  frogpilot_variables.params_memory.put_bool("ForceOffroad", False)
  frogpilot_variables.params_memory.put_bool("ForceOnroad", True)
  return True


def force_onroad_guard(context):
  if frogpilot_utilities.is_ignition_on(context.the_pond.sm):
    return "car_on"
  if context.params.get("CarParamsPersistent") is None:
    return "car_unknown"
  return None


async def reflash_panda(context, body):
  return await run_exclusively(flash_panda())


def report_visible(context):
  return context.branch_reason(frogpilot_variables.get_frogpilot_toggles(context.the_pond.sm).issue_report_available)


async def reset_settings(the_pond, stock):
  try:
    signed_out = await backups.sign_out_of_tailscale(the_pond)
    if signed_out:
      await asyncio.to_thread(backups.reset_settings, stock)
  finally:
    action_lock.release()

  if signed_out:
    the_pond.params.put_bool("DoReboot", True)
  return signed_out


async def reset_to_default(context, body):
  return await run_exclusively(reset_settings(context.the_pond, False))


async def reset_to_stock(context, body):
  return await run_exclusively(reset_settings(context.the_pond, True))


async def run_exclusively(coroutine):
  await action_lock.acquire()
  return await asyncio.shield(asyncio.create_task(coroutine))


ROWS = [
  {
    "description": ("<b>Show FrogPilot's developer readouts on the driving screen for your next drive, so a bug report can say what openpilot was " +
                    "actually doing.</b><br><br>It switches itself back off once you finish the drive. While it is on, the temperature reads in " +
                    "Celsius and the developer numbers read in scientific units, whatever you picked elsewhere. It also brings back anything you hid " +
                    "from the driving screen and uses the default \"Model UI\" sizes and \"Camera View\", with \"Rainbow Path\" off, until the drive " +
                    "ends. Your speedometer keeps its own units."),
    "default": lambda context: False,
    "key": "DebugMode",
    "order": 0,
    "path": ("System Settings", "UTILITIES"),
    "title": "Debug Mode",
    "widget": "toggle"
  },
  {
    "actions": {
      "OFF": {"run": force_off},
      "OFFROAD": {
        "guard": lambda context: "openpilot_steering" if frogpilot_utilities.is_openpilot_steering(context.the_pond.sm) else None,
        "messages": {"openpilot_steering": "The parked state can't be forced while openpilot is steering. Disengage and try again."},
        "run": force_offroad
      },
      "ONROAD": {
        "guard": force_onroad_guard,
        "messages": {"car_on": "The running state can't be forced while the car is on. Turn the car off and try again.",
                     "car_unknown": "openpilot hasn't learned your car yet, so it can't be forced onroad. Complete a drive first."},
        "run": force_onroad
      }
    },
    "checkable": True,
    "current": drive_state,
    "description": ("<b>Make openpilot behave as though the car is running, or as though it is parked, without the car actually being " +
                    "either.</b><br><br>This is a testing tool. Forcing the running state ignores your \"Screen Brightness (Onroad)\" setting and " +
                    "stops openpilot warning you that its controls are unresponsive, so leave it on \"OFF\" unless you know why you need it. Forcing " +
                    "the running state ends when you turn the car on, and either state clears itself the next time the device restarts. While it is " +
                    "forced, the device still drops back to offroad if it overheats and still shuts down on its usual timer or a low car battery. " +
                    "With the car off, a forced running state runs on the car's battery until the device powers itself off."),
    "id": "ForceDriveState",
    "key": None,
    "level_key": "ForceOnroad",
    "options": ({"label": "OFFROAD", "value": 0}, {"label": "ONROAD", "value": 1}, {"label": "OFF", "value": 2}),
    "order": 1,
    "path": ("System Settings", "UTILITIES"),
    "title": "Force Drive State",
    "widget": "buttons"
  },
  {
    "actions": {
      "FLASH": {
        "confirm": {"cancel": "Cancel", "confirm": "Flash", "text": "Reflash the Panda? Your device reboots once it finishes."},
        "guard": action_guard,
        "messages": {"busy": BUSY_MESSAGE, "car_on": "The Panda can't be reflashed while the car is on. Turn the car off and try again."},
        "restart": "Rebooting",
        "run": reflash_panda,
        "status": {"failure": "Flash failed...", "success": "Flashed!"}
      }
    },
    "description": ("<b>Reinstall the software on the Panda, the small box that lets your device talk to your car.</b><br><br>Try this if openpilot " +
                    "keeps losing contact with the car or the Panda shows up as faulty. Your device reboots once it finishes, and the car has to be " +
                    "off to start."),
    "id": "ReflashThePanda",
    "key": None,
    "order": 2,
    "path": ("System Settings", "UTILITIES"),
    "title": "Reflash the Panda",
    "widget": "action"
  },
  {
    "description": ("<b>Tell the FrogPilot team what went wrong, straight from the car.</b><br><br>You pick what happened from a list, add a " +
                    "description where it helps, and give your Discord name so they can reach you. Your settings and the most recent error log go " +
                    "along with it so the problem can be traced."),
    "id": "ReportABugOrAnIssue",
    "key": None,
    "link": "report",
    "order": 3,
    "path": ("System Settings", "UTILITIES"),
    "title": "Report a Bug or an Issue",
    "visible": report_visible,
    "widget": "action"
  },
  {
    "actions": {
      "RESET": {
        "confirm": {"cancel": "Cancel", "confirm": "Reset",
                    "text": ("Reset all FrogPilot and some openpilot settings? This also erases your saved keys, favorite places, Discord name, " +
                             "cellular APN, map settings, driving stats, Speed Limit Filler data, saved car details, SSH keys, and paired browsers, " +
                             "turns SSH and tethering off, signs out of Tailscale, and asks again whether to share FrogPilot data. You will have to " +
                             "accept the terms, redo the training, and set your language again, and the device reboots.")},
        "guard": action_guard,
        "messages": RESET_MESSAGES,
        "restart": "Rebooting",
        "run": reset_to_default,
        "status": RESET_STATUS
      }
    },
    "description": ("<b>Put every FrogPilot setting back to the value it shipped with, along with some of openpilot's own settings.</b><br><br>Those " +
                    "openpilot settings are \"Enable openpilot\", \"Disengage on Accelerator Pedal\", \"Driving Personality\", and \"Cellular " +
                    "Metered\". The device reboots to finish the reset, which also clears your accepted terms, your completed training, and your " +
                    "language, so you go through first-time setup again in English. It also erases your saved keys (Mapbox, weather, and the Toyota " +
                    "security key in use; keys saved to your Toyota security key list stay), favorite places, Discord name, cellular APN, map " +
                    "settings, FrogPilot driving stats, Speed Limit Filler data, saved car details, SSH keys, and the browsers paired with \"The " +
                    "Pond\" (making a new pairing code if pairing is on), turns SSH and tethering off, signs out of Tailscale, and asks again whether " +
                    "to share FrogPilot data. Your drives, backups, and downloaded themes are left alone, and settings backups still hold your keys " +
                    "and favorite places until you delete them."),
    "id": "ResetSettingsToDefault",
    "key": None,
    "order": 4,
    "path": ("System Settings", "UTILITIES"),
    "title": "Reset Settings to Default",
    "widget": "action"
  },
  {
    "actions": {
      "RESET": {
        "confirm": {"cancel": "Cancel", "confirm": "Reset",
                    "text": ("Reset every setting to match stock openpilot? This also erases your saved keys, favorite places, Discord name, " +
                             "cellular APN, map settings, driving stats, Speed Limit Filler data, saved car details, SSH keys, and paired browsers, " +
                             "turns SSH and tethering off, signs out of Tailscale, and asks again whether to share FrogPilot data. You will have to " +
                             "accept the terms, redo the training, and set your language again, and the device reboots.")},
        "guard": action_guard,
        "messages": RESET_MESSAGES,
        "restart": "Rebooting",
        "run": reset_to_stock,
        "status": RESET_STATUS
      }
    },
    "description": ("<b>Put every setting back to what plain openpilot uses, turning FrogPilot's own features off rather than back to FrogPilot's " +
                    "defaults.</b><br><br>The device reboots to finish the reset, which also clears your accepted terms, your completed training, and " +
                    "your language, so you go through first-time setup again in English. It also erases your saved keys (Mapbox, weather, and the " +
                    "Toyota security key in use; keys saved to your Toyota security key list stay), favorite places, Discord name, cellular APN, map " +
                    "settings, FrogPilot driving stats, Speed Limit Filler data, saved car details, SSH keys, and the browsers paired with \"The " +
                    "Pond\" (making a new pairing code if pairing is on), turns SSH and tethering off, signs out of Tailscale, and asks again whether " +
                    "to share FrogPilot data. Your drives, backups, and downloaded themes are left alone, and settings backups still hold your keys " +
                    "and favorite places until you delete them."),
    "id": "ResetSettingsToStockOpenpilot",
    "key": None,
    "order": 5,
    "path": ("System Settings", "UTILITIES"),
    "title": "Reset Settings to Stock openpilot",
    "widget": "action"
  }
]
