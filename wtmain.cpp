#include <Wt/WApplication>
#include <Wt/WEnvironment>

#include "wtautoconfig.h"
#include "wtencrangermenudialog.h"

struct WtApplication : public Wt::WApplication
{
  WtApplication(const Wt::WEnvironment& env)
    : Wt::WApplication(env),
    m_dialog(new ribi::WtEncrangerMenuDialog)
  {
    this->setTitle("Encranger");
    this->useStyleSheet("wt.css");
    root()->addWidget(m_dialog);
  }
  WtApplication(const WtApplication&) = delete;
  WtApplication& operator=(const WtApplication&) = delete;
  private:
  ribi::WtEncrangerMenuDialog * const m_dialog;
};

Wt::WApplication *createApplication(
  const Wt::WEnvironment& env)
{
  return new WtApplication(env);
}

int main(int argc, char **argv)
{
  ribi::WtAutoConfig::SaveDefaultStylesheet();
  ribi::WtAutoConfig a(argc,argv,createApplication);
  return a.Run();
}

