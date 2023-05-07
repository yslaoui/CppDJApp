#include <iostream>

int main () {
    // types
    float pi = 3.1415926f;
    double inches = 25.4;
    long double root2 = 1.414213623730950488L;

    // calculations
    double pi2 = 3.141592653589793;
    double a = 0.2;
    double z = 9;
    double volume; 
    volume = pi2*z*z*a;
    std::cout << volume << std::endl;

    // invalid results
    double k = 1.5;
    double l = 0;
    double m = 0;
    double result1 = k/l;
    double result2 = l/m; 
    double result3 = result1 + k;
    std::cout << k << "/" << l << " = " << result1 << std::endl;
    std::cout << l << "/" << m << " = " << result2 << std::endl;
    std::cout << result1 << "+" << k << " = " << result3 << std::endl;
    


}