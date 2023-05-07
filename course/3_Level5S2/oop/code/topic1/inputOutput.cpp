#include <iostream>

int main() {
    // std is a namespace. a namespace contains classes, methods...
    // intellisense cout and endl appear after std only if you put #include <iostream> at the top
    // arrow direction: streaming from right to left, so Hi streams to console out
    std::cout << "Type in a number" << std::endl;

    int x;
    // arrow direction: x streams to console in
    std:: cin >> x;
    std::cout << "You typed " << x << std::endl;

    return 0;
}