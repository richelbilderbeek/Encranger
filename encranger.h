#ifndef ENCRANGER_H
#define ENCRANGER_H

#include <string>
#include <vector>

namespace ribi {

//Encranger stands for 'ENCryption by RAndom Number GEneratoR'
struct Encranger
{
  Encranger(const int key) noexcept;
  std::string Encrypt(std::string s) const noexcept;
  std::string Deencrypt(std::string s) const noexcept;

  static std::string GetVersion() noexcept;
  static std::vector<std::string> GetVersionHistory() noexcept;

  private:

  const std::vector<char> m_characters;
  const std::vector<int> m_table;

  ///The unsigned int is the size of 'm_characters'
  std::vector<int> CreateTable(const int key, const unsigned int sz) const noexcept;

  static std::vector<int> CreateTestKeys() noexcept;

  static std::vector<char> CreateCharacters() noexcept;

  char Encrypt(const char c, const int d) const noexcept;
  char Deencrypt(const char c, const int d) const noexcept;
  int GetIndex(const char c) const noexcept;
};

} //~namespace ribi

#endif // ENCRANGER_H
