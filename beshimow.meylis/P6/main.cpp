#include <iostream>
#include <string>
#include "string_utils.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Ошибка: Необходимо ввести арифметическое выражение." << std::endl;
        return 1;
    }

    std::string expression;
    for (int i = 1; i < argc; ++i) {
        expression += argv[i];
        if (i < argc - 1) {
            expression += " ";
        }
    }

    std::cout << "Входное выражение: " << expression << std::endl;

    const char* charsToRemove = " ";
    char* cleanedExpression = removeChars(expression.c_str(), charsToRemove);

    if (cleanedExpression) {
        std::cout << "Очищенное выражение: " << cleanedExpression << std::endl;
        std::free(cleanedExpression);
    } else {
        std::cerr << "Ошибка: Не удалось выделить память." << std::endl;
        return 2;
    }

    return 0;
}
