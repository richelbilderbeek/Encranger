#include "encranger.h"

void ribi::Encranger::Test() noexcept
{
  const std::vector<std::string> v {
    "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz",
    "a cde ghijklm opqrstuvwxyzabc efghijklmnopqrstuvwxyzabcdefghi klmnopqrstuvwxyz",
    "a",
    " a",
    "a ",
    " a ",
    "  a  "
  };
  for (const std::string& s: v)
  {
    for (const int key: CreateTestKeys())
    {
      const Encranger e(key);
      assert(e.Deencrypt(e.Encrypt(s)) == s);
      //Test encryption with real, decryption with faker
      const Encranger faker(key + 1);
      assert(faker.Deencrypt(e.Encrypt(s)) != s);
    }
  }
}
