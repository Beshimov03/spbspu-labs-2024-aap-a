#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <stdexcept>

double evaluateExpression(const std::string& expression) {
    try {
        return std::stod(expression);
    } catch (const std::invalid_argument&) {
        throw std::runtime_error("Некорректное арифметическое выражение");
    } catch (const std::out_of_range&) {
        throw std::runtime_error("Выражение выходит за пределы допустимого диапазона");
    }
}

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

    try {
        double result = evaluateExpression(expression);
        std::cout << "Результат: " << result << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 2;
    }
}
