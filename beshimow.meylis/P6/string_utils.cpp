#include "string_utils.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>

char* beshimow::removeChars(const char* input, const char* toRemove) noexcept {
    if (!input || !toRemove) return nullptr;

    size_t len = std::strlen(input);
    char* result = (char*)std::malloc(len + 1);
    if (!result) {
        std::cerr << "beshimow: Ошибка: не удалось выделить память.\n";
        std::exit(1);
    }

    size_t k = 0;
    for (size_t i = 0; i < len; ++i) {
        if (!std::strchr(toRemove, input[i])) {
            result[k++] = input[i];
        }
    }
    result[k] = '\0';
    return result;
}
