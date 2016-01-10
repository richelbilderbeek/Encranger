#include <string>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "encrangermenudialog.h"
#pragma GCC diagnostic pop

int main(int argc, char *argv[])
{
  const std::vector<std::string> args { ribi::MenuDialog::ConvertArguments(argc,argv) };
  ribi::ToolEncrangerMenuDialog d;
  return d.Execute(args);
}
