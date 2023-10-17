#include <cstring>
#include <iostream>
#include <memory>
#include <array>

class String {

public:
    String () : isShort(true), size(0) {
        shortString.at(0) = '\0';
    }
    
    String(const char *str) : isShort(true), size(strlen(str)) {
        if (size > shortString.size()) {
            isShort = false;
            bigString.array = std::make_unique<char>(size + 1);
            std::strcpy(bigString.array.get(), str);
            bigString.size = size;
            bigString.capacity = size;
        }
        else {
            std::strcpy(shortString.data(), str);
        }
    }

    ~String() {
        if (!isShort) {
            bigString.array.reset();
        }
    }

    const char* c_str() const {
        return isShort ? shortString.data() : bigString.array.get();
    }

private:
    size_t size;
    bool isShort;
    union {
        struct {
            std::unique_ptr<char> array;
            size_t size;
            size_t capacity;
        } bigString;

        std::array<char, 15> shortString;
    };
    
};

