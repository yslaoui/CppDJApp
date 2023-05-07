#include <iostream>

// function promises
void printHello();
float average(float x, float y);

int main ()
{
    float z = average(15,7.5);
    std::cout << z << std::endl;
    printHello();    
    return 0;
}


// run using g++ functions.cpp implementations.cpp 