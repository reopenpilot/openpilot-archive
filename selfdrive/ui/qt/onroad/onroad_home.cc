#include "selfdrive/ui/qt/onroad/onroad_home.h"

#include <QPainter>
#include <QStackedLayout>

#include "selfdrive/ui/qt/util.h"

OnroadWindow::OnroadWindow(QWidget *parent) : QWidget(parent) {
  QVBoxLayout *main_layout  = new QVBoxLayout(this);
  main_layout->setMargin(UI_BORDER_SIZE);
  QStackedLayout *stacked_layout = new QStackedLayout;
  stacked_layout->setStackingMode(QStackedLayout::StackAll);
  main_layout->addLayout(stacked_layout);

  nvg = new AnnotatedCameraWidget(VISION_STREAM_ROAD, this);

  QWidget * split_wrapper = new QWidget;
  split = new QHBoxLayout(split_wrapper);
  split->setContentsMargins(0, 0, 0, 0);
  split->setSpacing(0);
  split->addWidget(nvg);

  if (getenv("DUAL_CAMERA_VIEW")) {
    CameraWidget *arCam = new CameraWidget("camerad", VISION_STREAM_ROAD, true, this);
    split->insertWidget(0, arCam);
  }

  stacked_layout->addWidget(split_wrapper);

  alerts = new OnroadAlerts(this);
  alerts->setAttribute(Qt::WA_TransparentForMouseEvents, true);
  stacked_layout->addWidget(alerts);

  // setup stacking order
  alerts->raise();

  setAttribute(Qt::WA_OpaquePaintEvent);
  QObject::connect(uiState(), &UIState::uiUpdate, this, &OnroadWindow::updateState);
  QObject::connect(uiState(), &UIState::offroadTransition, this, &OnroadWindow::offroadTransition);

  #ifdef DP
  border_indicator = new BorderIndicator;
  #endif
}

void OnroadWindow::updateState(const UIState &s) {
  if (!s.scene.started) {
    return;
  }

  alerts->updateState(s);
  nvg->updateState(s);

  // dp - alka colored border
  const SubMaster &sm = *(s.sm);
  bool alka_active = sm["carControl"].getCarControl().getLatActive() && sm["controlsStateExt"].getControlsStateExt().getAlkaActive();
  QColor bgColor = bg_colors[alka_active && s.status == STATUS_DISENGAGED? STATUS_ALKA : s.status];
  #ifdef DP
  border_indicator->update_states(s);
  if (bg != bgColor || border_indicator->should_repaint()) {
  #else
  if (bg != bgColor) {
  #endif
    // repaint border
    bg = bgColor;
    update();
  }
}

void OnroadWindow::offroadTransition(bool offroad) {
  alerts->clear();
}

void OnroadWindow::paintEvent(QPaintEvent *event) {
  QPainter p(this);
  #ifdef DP
  p.fillRect(rect(), QColor(bg.red(), bg.green(), bg.blue(), 180));

  border_indicator->paint_bottom(p, QRect(0, height() - UI_BORDER_SIZE, width(), 30));
  border_indicator->paint_left(p, QRect(0, 0, width()*0.2, height()));
  border_indicator->paint_right(p, QRect(width()*0.8, 0, width()*0.2, height()));
  #else
  p.fillRect(rect(), QColor(bg.red(), bg.green(), bg.blue(), 255));
  #endif
}
