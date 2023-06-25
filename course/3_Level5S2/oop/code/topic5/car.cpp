#include <iostream>

// Class header
class Car 
{
    public:

        Car();
        double speed;
        void accelerate();
        bool whichIsFaster(Car carA, Car carB);

};

// Class implementation
Car::Car(): speed(0) {};
void Car::accelerate() 
{
    speed += 0.5;
}
bool whichIsFaster(Car carA, Car carB) 
{
    return (carA.speed > carB.speed);
}


// Creating objects
int main() 
{
    std::cout << "Hi" << std::endl;
    Car car{};
    std::cout << "Initial Speed " << car.speed << std::endl;
    car.accelerate();
    std::cout << "Speed after acceleration " << car.speed << std::endl;
    Car car2{};
    car2.accelerate();
    car2.accelerate();
    std::cout << "Speed of car2 after 2 accelerations " << car2.speed << std::endl;
    std::cout << whichIsFaster(car, car2) << std::endl;
    
}





