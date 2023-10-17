#include <iostream>
#include "include/string.hpp"

int main() {
    String s("Hello, World!");
    std::cout << s.c_str();
    return 0;
}