#include "resize.hpp"
#include <exception>

char* asafov::resize(const char* string, size_t length)
{
  char* newString = new char[length];
  for (size_t i = 0; i < length || string[i] != 0; i++)
  {
    newString[i] = string[i];
  }
  return newString;
}
