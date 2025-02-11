#include <iostream>
#include <string>
#include <cstdlib>

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

    return 0;
}
