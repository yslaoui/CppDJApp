#include <iostream>
#include "vec3D.h"

int main()
{
    vec3D coords;
    coords.x = 5;
    coords.y = 5;
    coords.z = 0;
    std::cout << coords.length() << std::endl;

}

