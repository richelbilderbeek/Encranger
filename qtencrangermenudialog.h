#ifndef QTTOOLENCRANGERMENUDIALOG_H
#define QTTOOLENCRANGERMENUDIALOG_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qthideandshowdialog.h"
#pragma GCC diagnostic pop

namespace Ui {
  class QtToolEncrangerMenuDialog;
}

namespace ribi {

class QtToolEncrangerMenuDialog : public QtHideAndShowDialog
{
  Q_OBJECT

public:
  explicit QtToolEncrangerMenuDialog(QWidget *parent = 0) noexcept;
  QtToolEncrangerMenuDialog(const QtToolEncrangerMenuDialog&) = delete;
  QtToolEncrangerMenuDialog& operator=(const QtToolEncrangerMenuDialog&) = delete;
  ~QtToolEncrangerMenuDialog() noexcept;

protected:
  void keyPressEvent(QKeyEvent * event) noexcept;

private:
  Ui::QtToolEncrangerMenuDialog *ui;

private slots:
  void on_button_about_clicked() noexcept;
  void on_button_quit_clicked() noexcept;
  void on_button_start_clicked() noexcept;
};

} //~namespace ribi

#endif // QTTOOLENCRANGERMENUDIALOG_H
