#include <iostream>
#include <string>

enum class Colours{blue, green, red};

int main() 
{
    unsigned short i = 1;
    std::cout << "size of unsigned short is " << sizeof(unsigned short) << std::endl; 
    // 2 bytes ie 16 bits and 2^16 = 65536 posible different numvbers

    unsigned short b = 65535; // 65537 will cause error because 0 is included it cannot store numbers up to 65535. 
    std::cout << "b contains " << b << std::endl; 
    // compile error. It tells you need an int zhich is halfway short and long
    // if you ignore the warning it will print a 0
    

    // Now other languages will give you massiv einteger representations by default to avoid these problems
    // we could use a signe long, whose size is 8 bytes so 2^64 characters
    std::cout << "size of signed long is " << sizeof(signed long) << std::endl;
    return 0;
    // probem is that each variable will take a lot of memory
    
    std::string s = "hello";

    float f = 1.5f; // float
    float g = 1.5; // Will do implicit conversion to double
    // float is 32 bits, double is 64 bits
}