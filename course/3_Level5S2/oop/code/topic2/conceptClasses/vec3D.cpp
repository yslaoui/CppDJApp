#include <cmath>
#include "vec3D.h"

int vec3D::length()
{
    int result;
    result = sqrt(x*x + y*y + z*z);
    return result;
}