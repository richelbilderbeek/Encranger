#include "encrangermaindialog.h"

ribi::ToolEncrangerMainDialog::ToolEncrangerMainDialog(const int key) noexcept
  : m_encranger(new Encranger(key)),
    m_encrypted_text{},
    m_key(key),
    m_plain_text{}
{

}

void ribi::ToolEncrangerMainDialog::Deencrypt() noexcept
{
  m_plain_text = m_encranger->Deencrypt(m_encrypted_text);
}

void ribi::ToolEncrangerMainDialog::Encrypt() noexcept
{
  m_encrypted_text = m_encranger->Encrypt(m_plain_text);
}

void ribi::ToolEncrangerMainDialog::SetEncryptedText(const std::string& s) noexcept
{
  m_encrypted_text = s;
}

void ribi::ToolEncrangerMainDialog::SetKey(const int i) noexcept
{
  m_encranger.reset(new Encranger(i));
}

void ribi::ToolEncrangerMainDialog::SetPlainText(const std::string& s) noexcept
{
  m_plain_text = s;
}
