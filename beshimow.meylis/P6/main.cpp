#include <iostream>
#include <cstdlib>
#include <cstring>

char* removeChars(const char* str, const char* charsToRemove) {
    size_t len = std::strlen(str);
    char* result = static_cast<char*>(std::malloc(len + 1));

    if (result == nullptr) {
        return nullptr;
    }

    size_t j = 0;
    for (size_t i = 0; i < len; ++i) {
        if (std::strchr(charsToRemove, str[i]) == nullptr) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';

    return result;
}

bool is_double(const char* str) {
    char* end;
    std::strtod(str, &end);
    return *end == '\0';
}

char* get_string(std::istream& input, size_t& capacity, size_t& size, int ratio, char delimiter) {
    char* buffer = static_cast<char*>(std::malloc(capacity));
    if (!buffer) return nullptr;

    size = 0;
    char ch;
    while (input.get(ch) && ch != delimiter) {
        if (size + 1 >= capacity) {
            capacity *= ratio;
            char* new_buffer = static_cast<char*>(std::realloc(buffer, capacity));
            if (!new_buffer) {
                free(buffer);
                return nullptr;
            }
            buffer = new_buffer;
        }
        buffer[size++] = ch;
    }
    buffer[size] = '\0';
    return buffer;
}

int main() {
    constexpr int ratio = 2;
    size_t capacity = 10, size = 0;

    char* str = get_string(std::cin, capacity, size, ratio, '\n');
    if (str == nullptr) {
        std::cerr << "Error: memory not allocated for string\n";
        return 1;
    }

    if (size == 0) {
        free(str);
        std::cerr << "Empty string\n";
        return 1;
    }

    const char* charsToRemove = " ";
    char* cleanedStr = removeChars(str, charsToRemove);
    if (cleanedStr == nullptr) {
        std::cerr << "Error: memory not allocated for cleaned string\n";
        free(str);
        return 1;
    }

    std::cout << std::boolalpha << is_double(cleanedStr) << "\n";

    free(str);
    free(cleanedStr);

    return 0;
}
