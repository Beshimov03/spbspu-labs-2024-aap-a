#include <cstdlib>
#include <cstring>

namespace beshimow {
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
}
