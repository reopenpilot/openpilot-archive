#pragma once

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include "selfdrive/ui/qt/widgets/keyboard.h"

const int DEFAULT_MAX_LENGTH = 512;

class DialogBase : public QDialog {
  Q_OBJECT

protected:
  DialogBase(QWidget *parent);
  bool eventFilter(QObject *o, QEvent *e) override;

public slots:
  int exec() override;
};

class InputDialog : public DialogBase {
  Q_OBJECT

public:
  explicit InputDialog(const QString &title, QWidget *parent, const QString &subtitle = "", bool secret = false);
  static QString getText(const QString &title, QWidget *parent, const QString &subtitle = "",
                         bool secret = false, int minLength = -1, const QString &defaultText = "", int maxLength = DEFAULT_MAX_LENGTH);
  QString text();
  void setMessage(const QString &message, bool clearInputField = true);
  void setMinLength(int length);
  void show();

  // FrogPilot widgets
  void setMaxLength(int length);

private:
  int minLength;
  QLineEdit *line;
  Keyboard *k;
  QLabel *label;
  QLabel *sublabel;
  QVBoxLayout *main_layout;
  QPushButton *eye_btn;

  // FrogPilot widgets
  void updateMaxLengthSublabel(const QString &text);

  // FrogPilot variables
  int maxLength;

private slots:
  void handleEnter();

signals:
  void cancel();
  void emitText(const QString &text);
};

class ConfirmationDialog : public DialogBase {
  Q_OBJECT

public:
  explicit ConfirmationDialog(const QString &prompt_text, const QString &confirm_text,
                              const QString &cancel_text, const bool rich, QWidget* parent, const bool is_long=false);
  static bool alert(const QString &prompt_text, QWidget *parent, bool isLong=false);
  static bool confirm(const QString &prompt_text, const QString &confirm_text, QWidget *parent);
  static bool rich(const QString &prompt_text, QWidget *parent);
};

class MultiOptionDialog : public DialogBase {
  Q_OBJECT

public:
  explicit MultiOptionDialog(const QString &prompt_text, const QStringList &l, const QString &current, QWidget *parent);
  static QString getSelection(const QString &prompt_text, const QStringList &l, const QString &current, QWidget *parent);
  QString selection;
};
