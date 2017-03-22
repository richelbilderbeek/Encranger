#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qtencrangermenudialog.h"

#include <QDesktopWidget>
#include <QKeyEvent>

#include "encrangermenudialog.h"
#include "qtaboutdialog.h"
#include "qtencrangermaindialog.h"
#include "qthideandshowdialog.h"
#include "ui_qtencrangermenudialog.h"
#pragma GCC diagnostic pop

ribi::QtToolEncrangerMenuDialog::QtToolEncrangerMenuDialog(QWidget *parent) noexcept :
    QtHideAndShowDialog(parent),
    ui(new Ui::QtToolEncrangerMenuDialog)
{
  ui->setupUi(this);
}

ribi::QtToolEncrangerMenuDialog::~QtToolEncrangerMenuDialog() noexcept
{
  delete ui;
}

void ribi::QtToolEncrangerMenuDialog::keyPressEvent(QKeyEvent * event) noexcept
{
  if (event->key() == Qt::Key_Escape) { close(); return; }
}

void ribi::QtToolEncrangerMenuDialog::on_button_about_clicked() noexcept
{
  ribi::About a = ribi::ToolEncrangerMenuDialog().GetAbout();
  a.AddLibrary("QtHideAndShowDialog version: " + QtHideAndShowDialog::GetVersion());
  ribi::QtAboutDialog d(a);
  d.setWindowIcon(this->windowIcon());
  d.setStyleSheet(this->styleSheet());
  this->ShowChild(&d);
}

void ribi::QtToolEncrangerMenuDialog::on_button_quit_clicked() noexcept
{
  close();
}

void ribi::QtToolEncrangerMenuDialog::on_button_start_clicked() noexcept
{
  QtToolEncrangerMainDialog d;
  ShowChild(&d);
}
