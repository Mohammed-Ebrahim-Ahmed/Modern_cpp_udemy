#include<iostream>
#include "car.hpp"
struct Point{
    int x;
    int y;
};

void drawLine(struct Point start, struct Point end)
{
    std::cout<<start.x<<std::endl;
}

int main()
{   
    Car::GetCarCount();
    Car car;
    Car car2(8);
    Car::GetCarCount();
    car.Dashboard();
    // car.FillFuel(6);
    // car.Accelerate();
    // car.Accelerate();
    // car.Accelerate();
    // car.Accelerate();
    // car.Accelerate();
    car.Dashboard();
    // car.Brake();
    return 0;
}