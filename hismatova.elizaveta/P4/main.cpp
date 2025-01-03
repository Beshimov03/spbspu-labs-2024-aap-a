#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <get_string.h>
#include "check_string.h"

int main()
{
  size_t length = 0;
  char *str1 = hismatova::get_line(std::cin, length);
  const char *str2 = "abc";
  if (str1 == nullptr)
  {
    std::cerr << "error in reading first line\n";
    return 1;
  }
  if (str1[0] == '\0')
  {
    std::cerr << "empty string\n";
    free(str1);
    return 1;
  }
  char result[128] = {0};
  hismatova::uniqueChar(str1, str2, result);
  std::cout << result << "\n";
  free(str1);
  return 0;
}
