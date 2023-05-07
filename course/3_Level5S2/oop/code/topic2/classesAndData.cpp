#include <iostream>
#include <vector> 


class Vec3D 
{
    public:
        int x;
        int y;
        int z;   
};

Vec3D vec1;


int main() 
{
    
    vec1.x = 10;
    vec1.y = 12;
    vec1.z = 25;
    std::cout << vec1.x << std::endl;
    
    std::vector<Vec3D> coords;
    coords.push_back(vec1);
    std::cout << coords[0].x << std::endl;
    

    
    return 0;
}