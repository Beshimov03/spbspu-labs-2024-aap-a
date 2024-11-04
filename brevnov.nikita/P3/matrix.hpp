#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <fstream>

namespace brevnov
{
  int input_matrix(std::ifstream & in, int * t, size_t m, size_t n);
  int * alloc(size_t m, size_t n);
}
#endif
