#pragma once

#include <memory>
#include <string>

#include <QObject>
#include <QTimer>
#include <QColor>
#include <QFuture>
#include <QPolygonF>
#include <QTransform>

#include "cereal/messaging/messaging.h"
#include "common/mat.h"
#include "common/params.h"
#include "common/timing.h"
#include "selfdrive/ui/qt/network/wifi_manager.h"
#include "selfdrive/ui/qt/util.h"
#include "system/hardware/hw.h"

#include "selfdrive/frogpilot/ui/qt/widgets/frogpilot_controls.h"

const int UI_BORDER_SIZE = 30;
const int UI_HEADER_HEIGHT = 420;

const int UI_FREQ = 20; // Hz
const int BACKLIGHT_OFFROAD = 50;

const float MIN_DRAW_DISTANCE = 10.0;
const float MAX_DRAW_DISTANCE = 100.0;
constexpr mat3 DEFAULT_CALIBRATION = {{ 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0 }};
constexpr mat3 FCAM_INTRINSIC_MATRIX = (mat3){{2648.0, 0.0, 1928.0 / 2,
                                           0.0, 2648.0, 1208.0 / 2,
                                           0.0, 0.0, 1.0}};
// tici ecam focal probably wrong? magnification is not consistent across frame
// Need to retrain model before this can be changed
constexpr mat3 ECAM_INTRINSIC_MATRIX = (mat3){{567.0, 0.0, 1928.0 / 2,
                                           0.0, 567.0, 1208.0 / 2,
                                           0.0, 0.0, 1.0}};


constexpr vec3 default_face_kpts_3d[] = {
  {-5.98, -51.20, 8.00}, {-17.64, -49.14, 8.00}, {-23.81, -46.40, 8.00}, {-29.98, -40.91, 8.00}, {-32.04, -37.49, 8.00},
  {-34.10, -32.00, 8.00}, {-36.16, -21.03, 8.00}, {-36.16, 6.40, 8.00}, {-35.47, 10.51, 8.00}, {-32.73, 19.43, 8.00},
  {-29.30, 26.29, 8.00}, {-24.50, 33.83, 8.00}, {-19.01, 41.37, 8.00}, {-14.21, 46.17, 8.00}, {-12.16, 47.54, 8.00},
  {-4.61, 49.60, 8.00}, {4.99, 49.60, 8.00}, {12.53, 47.54, 8.00}, {14.59, 46.17, 8.00}, {19.39, 41.37, 8.00},
  {24.87, 33.83, 8.00}, {29.67, 26.29, 8.00}, {33.10, 19.43, 8.00}, {35.84, 10.51, 8.00}, {36.53, 6.40, 8.00},
  {36.53, -21.03, 8.00}, {34.47, -32.00, 8.00}, {32.42, -37.49, 8.00}, {30.36, -40.91, 8.00}, {24.19, -46.40, 8.00},
  {18.02, -49.14, 8.00}, {6.36, -51.20, 8.00}, {-5.98, -51.20, 8.00},
};


typedef enum UIStatus {
  STATUS_DISENGAGED,
  STATUS_OVERRIDE,
  STATUS_ENGAGED,

  // FrogPilot statuses
  STATUS_ALWAYS_ON_LATERAL_ACTIVE,
  STATUS_CONDITIONAL_OVERRIDDEN,
  STATUS_EXPERIMENTAL_MODE_ACTIVE,
  STATUS_NAVIGATION_ACTIVE,
  STATUS_TRAFFIC_MODE_ACTIVE,
} UIStatus;

enum PrimeType {
  UNKNOWN = -2,
  UNPAIRED = -1,
  NONE = 0,
  MAGENTA = 1,
  LITE = 2,
  BLUE = 3,
  MAGENTA_NEW = 4,
  PURPLE = 5,
};

const QColor bg_colors [] = {
  [STATUS_DISENGAGED] = QColor(0x17, 0x33, 0x49, 0xc8),
  [STATUS_OVERRIDE] = QColor(0x91, 0x9b, 0x95, 0xf1),
  [STATUS_ENGAGED] = QColor(0x17, 0x86, 0x44, 0xf1),

  // FrogPilot colors
  [STATUS_ALWAYS_ON_LATERAL_ACTIVE] = QColor(0x0a, 0xba, 0xb5, 0xf1),
  [STATUS_CONDITIONAL_OVERRIDDEN] = QColor(0xff, 0xff, 0x00, 0xf1),
  [STATUS_EXPERIMENTAL_MODE_ACTIVE] = QColor(0xda, 0x6f, 0x25, 0xf1),
  [STATUS_NAVIGATION_ACTIVE] = QColor(0x31, 0xa1, 0xee, 0xf1),
  [STATUS_TRAFFIC_MODE_ACTIVE] = QColor(0xc9, 0x22, 0x31, 0xf1),
};


typedef struct UIScene {
  bool calibration_valid = false;
  bool calibration_wide_valid  = false;
  bool wide_cam = true;
  mat3 view_from_calib = DEFAULT_CALIBRATION;
  mat3 view_from_wide_calib = DEFAULT_CALIBRATION;
  cereal::PandaState::PandaType pandaType;

  // modelV2
  float lane_line_probs[4];
  float road_edge_stds[2];
  QPolygonF track_vertices;
  QPolygonF lane_line_vertices[4];
  QPolygonF road_edge_vertices[2];

  // lead
  QPointF lead_vertices[2];

  // DMoji state
  float driver_pose_vals[3];
  float driver_pose_diff[3];
  float driver_pose_sins[3];
  float driver_pose_coss[3];
  vec3 face_kpts_draw[std::size(default_face_kpts_3d)];

  bool navigate_on_openpilot = false;
  cereal::LongitudinalPersonality personality;

  float light_sensor = -1;
  bool started, ignition, is_metric, map_on_left, longitudinal_control;
  bool world_objects_visible = false;
  uint64_t started_frame;

  // FrogPilot variables
  bool acceleration_path;
  bool adjacent_path;
  bool adjacent_path_metrics;
  bool always_on_lateral_active;
  bool big_map;
  bool blind_spot_left;
  bool blind_spot_path;
  bool blind_spot_right;
  bool brake_lights_on;
  bool compass;
  bool conditional_experimental;
  bool disable_smoothing_mtsc;
  bool disable_smoothing_vtsc;
  bool driver_camera;
  bool dynamic_path_width;
  bool dynamic_pedals_on_ui;
  bool enabled;
  bool experimental_mode;
  bool experimental_mode_via_screen;
  bool fahrenheit;
  bool force_onroad;
  bool full_map;
  bool has_auto_tune;
  bool has_lead;
  bool hide_alerts;
  bool hide_lead_marker;
  bool hide_map_icon;
  bool hide_max_speed;
  bool hide_speed;
  bool hide_speed_ui;
  bool is_CPU;
  bool is_GPU;
  bool is_IP;
  bool is_memory;
  bool is_storage_left;
  bool is_storage_used;
  bool lead_info;
  bool live_valid;
  bool map_open;
  bool model_randomizer;
  bool model_ui;
  bool numerical_temp;
  bool online;
  bool onroad_distance_button;
  bool parked;
  bool pedals_on_ui;
  bool random_events;
  bool red_light;
  bool reverse;
  bool reverse_cruise;
  bool reverse_cruise_ui;
  bool right_hand_drive;
  bool road_name_ui;
  bool rotating_wheel;
  bool screen_recorder;
  bool show_aol_status_bar;
  bool show_blind_spot;
  bool show_cem_status_bar;
  bool show_fps;
  bool show_jerk;
  bool show_signal;
  bool show_slc_offset;
  bool show_slc_offset_ui;
  bool show_steering;
  bool show_stopping_point;
  bool show_stopping_point_metrics;
  bool show_tuning;
  bool sidebar_metrics;
  bool speed_limit_changed;
  bool speed_limit_controller;
  bool speed_limit_overridden;
  bool standby_mode;
  bool standstill;
  bool static_pedals_on_ui;
  bool stopped_timer;
  bool tethering_enabled;
  bool traffic_mode;
  bool traffic_mode_active;
  bool turn_signal_left;
  bool turn_signal_right;
  bool unlimited_road_ui_length;
  bool use_si;
  bool use_stock_colors;
  bool use_stock_wheel;
  bool use_vienna_slc_sign;
  bool vtsc_controlling_curve;
  bool wake_up_screen;
  bool wheel_speed;

  double fps;

  float acceleration;
  float acceleration_jerk;
  float acceleration_jerk_difference;
  float adjusted_cruise;
  float friction;
  float lane_detection_width;
  float lane_line_width;
  float lane_width_left;
  float lane_width_right;
  float lat_accel;
  float lead_detection_threshold;
  float path_edge_width;
  float path_width;
  float road_edge_width;
  float speed_jerk;
  float speed_jerk_difference;
  float speed_limit;
  float speed_limit_offset;
  float speed_limit_overridden_speed;
  float steer;
  float unconfirmed_speed_limit;

  int bearing_deg;
  int camera_view;
  int conditional_speed;
  int conditional_speed_lead;
  int conditional_status;
  int desired_follow;
  int driver_camera_timer;
  int map_style;
  int model_length;
  int obstacle_distance;
  int obstacle_distance_stock;
  int screen_brightness;
  int screen_brightness_onroad;
  int screen_timeout;
  int screen_timeout_onroad;
  int started_timer;
  int steering_angle_deg;
  int stopped_equivalence;
  int tethering_config;

  QColor lane_lines_color;
  QColor lead_marker_color;
  QColor path_color;
  QColor path_edges_color;
  QColor road_edges_color;
  QColor sidebar_color1;
  QColor sidebar_color2;
  QColor sidebar_color3;

  QPolygonF track_adjacent_vertices[6];
  QPolygonF track_edge_vertices;

} UIScene;

class UIState : public QObject {
  Q_OBJECT

public:
  UIState(QObject* parent = 0);
  void updateStatus();
  inline bool engaged() const {
    return scene.started && (*sm)["controlsState"].getControlsState().getEnabled();
  }

  void setPrimeType(PrimeType type);
  inline PrimeType primeType() const { return prime_type; }
  inline bool hasPrime() const { return prime_type > PrimeType::NONE; }

  int fb_w = 0, fb_h = 0;

  std::unique_ptr<SubMaster> sm;

  UIStatus status;
  UIScene scene = {};

  QString language;

  QTransform car_space_transform;

  // FrogPilot variables
  WifiManager *wifi = nullptr;

signals:
  void uiUpdate(const UIState &s);
  void offroadTransition(bool offroad);
  void primeChanged(bool prime);
  void primeTypeChanged(PrimeType prime_type);

  // FrogPilot signals
  void driveRated();
  void reviewModel();

private slots:
  void update();

private:
  QTimer *timer;
  bool started_prev = false;
  PrimeType prime_type = PrimeType::UNKNOWN;

  // FrogPilot variables
  Params paramsMemory{"/dev/shm/params"};
};

UIState *uiState();

// device management class
class Device : public QObject {
  Q_OBJECT

public:
  Device(QObject *parent = 0);
  bool isAwake() { return awake; }
  void setOffroadBrightness(int brightness) {
    offroad_brightness = std::clamp(brightness, 0, 100);
  }

private:
  bool awake = false;
  int interactive_timeout = 0;
  bool ignition_on = false;

  int offroad_brightness = BACKLIGHT_OFFROAD;
  int last_brightness = 0;
  FirstOrderFilter brightness_filter;
  QFuture<void> brightness_future;

  void updateBrightness(const UIState &s);
  void updateWakefulness(const UIState &s);
  void setAwake(bool on);

signals:
  void displayPowerChanged(bool on);
  void interactiveTimeout();

public slots:
  void resetInteractiveTimeout(int timeout = -1, int timeout_onroad = -1);
  void update(const UIState &s);
};

Device *device();

void ui_update_params(UIState *s);
int get_path_length_idx(const cereal::XYZTData::Reader &line, const float path_height);
void update_model(UIState *s,
                  const cereal::ModelDataV2::Reader &model,
                  const cereal::UiPlan::Reader &plan);
void update_dmonitoring(UIState *s, const cereal::DriverStateV2::Reader &driverstate, float dm_fade_state, bool is_rhd);
void update_leads(UIState *s, const cereal::ModelDataV2::Reader &model_data);
void update_line_data(const UIState *s, const cereal::XYZTData::Reader &line,
                      float y_off, float z_off, QPolygonF *pvd, int max_idx, bool allow_invert);

// FrogPilot functions
void ui_update_frogpilot_params(UIState *s, Params &params);