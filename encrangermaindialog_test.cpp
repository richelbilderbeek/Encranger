#include "encrangermaindialog.h"

void ribi::ToolEncrangerMainDialog::Test() noexcept
{
  ToolEncrangerMainDialog d;
  const std::string s = "Hello World";
  d.SetKey(123);
  d.SetPlainText(s);
  d.Encrypt();
  const std::string encrypted = d.GetEncryptedText();
  d.SetEncryptedText(encrypted);
  d.Deencrypt();
  const std::string deencrypted = d.GetPlainText();
  assert(s == deencrypted);
}
