#include "encrangermenudialog.h"

void ribi::ToolEncrangerMenuDialog::Test() noexcept
{
  {
    ToolEncrangerMenuDialog d;
    d.Execute( {"Encranger", "-k", "123", "--text", "Hello World", "-s" } );
    d.Execute( {"Encranger", "-k", "123", "--cipher", "bc30h3g8h287g", "--silent" } );
  }
}
