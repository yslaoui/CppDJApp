//  This file prints the sizes of different types in C++
// sizeOf gives the size in bytes

#include <iostream>


int main() {
    char c = 0;
    std::cout << "char " << sizeof(char) << std::endl;
    // output 1 ie 1 byte ie 8 bits
    signed int i = 0;
    std::cout << "signed int " << sizeof(i) << std::endl;
    // output 4 bytes ie 32 bits
    float f = 0.0f; // if you do not put f it will cast it as a double
    std::cout << "float " << sizeof(f) << std::endl;
    // output 4 byte ie 32 bits
    long double d = 0.0; // if you do not put f it will cast it as a double
    std::cout << "long double " << sizeof(d) << std::endl;
    // 16 bytes ie 128 bits ie 2^128 memory cells waw. Gives you the most precisions
}