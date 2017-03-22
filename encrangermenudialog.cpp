#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "encrangermenudialog.h"

#include <cassert>
#include <iostream>
#include <boost/lexical_cast.hpp>

#include "encranger.h"
#include "encrangermaindialog.h"
#include "loopreader.h"
#pragma GCC diagnostic pop

int ribi::ToolEncrangerMenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  if (argc == 1)
  {
    std::cout << GetHelp() << '\n';
    return 1;
  }
  bool is_silent = false;
  for (int i=0; i!=argc; ++i)
  {
    if (argv[i] == "-s" || argv[i] == "--silence")
    {
      is_silent = true;
    }
  }

  //Determine key, if supplied as an argument
  int key = 0;
  for (int i=0; i!=argc-1; ++i) //-1 because the next argument will be used
  {
    if (argv[i] == "-k" || argv[i] == "--key")
    {
      const std::string s = argv[i+1];
      try
      {
        key = boost::lexical_cast<int>(s);
        //Can key be negative? Yes, it is used only be std::srand
      }
      catch (boost::bad_lexical_cast&)
      {
        std::cout << "Key must be an integer number\n";
        return 1;
      }
    }
  }
  //Determine if plaintext is supplied, if yes: execute
  for (int i=0; i!=argc-1; ++i) //-1 because the next argument will be used
  {
    if (argv[i] == "-t" || argv[i] == "--text")
    {
      const std::string plaintext = argv[i + 1];
      ToolEncrangerMainDialog d;
      d.SetKey(key);
      d.SetPlainText(plaintext);
      d.Encrypt();
      if (!is_silent) { std::cout << d.GetEncryptedText() << '\n'; }
      return 0;
    }
  }
  //Determine if cipertext is supplied, if yes: execute
  for (int i=0; i!=argc-1; ++i) //-1 because the next argument will be used
  {
    if (argv[i] == "-c" || argv[i] == "--cipher")
    {
      const std::string ciphertext = argv[i + 1];
      ToolEncrangerMainDialog d;
      d.SetKey(key);
      d.SetEncryptedText(ciphertext);
      d.Deencrypt();
      if (!is_silent) { std::cout << d.GetPlainText() << '\n'; }
      return 0;
    }
  }
  std::cout << GetHelp() << '\n';
  return 1;
}

ribi::About ribi::ToolEncrangerMenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "Encranger",
    "tool to test the Encranger class",
    "January 10th of 2016",
    "2009-2016",
    "http://www.richelbilderbeek.nl/ToolEncranger.htm",
    GetVersion(),
    GetVersionHistory());
  a.AddLibrary("Encranger version: " + Encranger::GetVersion());
  a.AddLibrary("LoopReader version: " + LoopReader<int>::GetVersion());
  return a;
}

ribi::Help ribi::ToolEncrangerMenuDialog::GetHelp() const noexcept
{
  return ribi::Help(
    this->GetAbout().GetFileTitle(),
    this->GetAbout().GetFileDescription(),
    {
      Help::Option('c',"cipher","the ciphertext, will be decrypted"),
      Help::Option('k',"key","the encryption key, a number, zero by default"),
      Help::Option('t',"text","the plaintext, will be encrypted"),
      Help::Option('s',"silent","silence output, used for debugging")
    },
    {
      "Encranger -k 123 --text \"Hello World\"",
      "Encranger -k 123 --cipher \"bc30h3g8h287g\""
    }
  );
}

std::string ribi::ToolEncrangerMenuDialog::GetVersion() const noexcept
{
  return "3.0";
}

std::vector<std::string> ribi::ToolEncrangerMenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2009-08-22: Version 1.0: initial version (then called 'Encranger') programmed in C++ Builder",
    "2011-03-06: Version 2.0: port to Qt Creator, renamed application to ToolEncranger",
    "2011-03-22: Version 2.1: seperated GUI from logic, added website version",
    "2011-04-25: Version 2.2: removed website version\'s Close button",
    "2011-06-22: Version 2.3: improved website version",
    "2011-08-31: Version 2.4: added arrows and Welcome image",
    "2013-09-27: Version 2.5: conformized for ProjectRichelBilderbeek",
    "2013-11-01: Version 2.6: improved console version",
    "2014-04-01: Version 2.7: added silent mode",
    "2014-07-21: Version 2.8: added picture to desktop menu",
    "2016-01-10: Version 3.0: moved to own GitHub",
  };
}
