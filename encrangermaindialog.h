//---------------------------------------------------------------------------
/*
Encranger, encryption tool
Copyright (C) 2009-2016 Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/ToolEncranger.htm
//---------------------------------------------------------------------------
#ifndef TOOLENCRANGERMAINDIALOG_H
#define TOOLENCRANGERMAINDIALOG_H

#include <string>
#include <vector>
#include <boost/scoped_ptr.hpp>
#include "about.h"
#include "encranger.h"

namespace ribi {

struct ToolEncrangerMainDialog
{
  ToolEncrangerMainDialog(const int key = 0) noexcept;
  void Deencrypt() noexcept;
  void Encrypt() noexcept;

  const std::string& GetEncryptedText() const noexcept { return m_encrypted_text; }

  int GetKey() const noexcept { return m_key; }

  const std::string& GetPlainText() const noexcept { return m_plain_text; }

  void SetEncryptedText(const std::string& s) noexcept;
  void SetKey(const int i) noexcept;
  void SetPlainText(const std::string& s) noexcept;

  private:
  boost::scoped_ptr<Encranger> m_encranger;
  std::string m_encrypted_text;
  int m_key;
  std::string m_plain_text;
};

} //~namespace ribi

#endif // TOOLENCRANGERMAINDIALOG_H
