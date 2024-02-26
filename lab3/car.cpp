#include "car.hpp"
#include<iostream>

int Car::CarCount = 0;

Car::Car():Car(0)
{
    CarCount++;
    std::cout<<"Hello from the default constructor"<<std::endl;
}
Car::Car(float fuel):Car(fuel,0)
{
    CarCount++;
    std::cout<<"Hello from constructor with one parmeter"<<std::endl;
}
Car::Car(float fuel, int passengers): fuel{fuel},speed{0}, passengers{passengers} 
{
    CarCount++;
    std::cout<<"Hello from constructor with two parmeter"<<std::endl;    
}
void Car::FillFuel(float amount)
{

    fuel = amount;
}

void Car::Accelerate()
{
    speed++;
    fuel -= 0.5f;
}
void Car::Brake()
{
    speed = 0;
}
void Car::AddPassengers(int count)
{
    passengers= count;
    FOO(*this);
}

void Car::Dashboard () const
{
    std::cout<<"Fuel: "<<fuel<<std::endl;
    std::cout<<"Speed: "<<speed<<std::endl;
    std::cout<<"Passengers: "<<passengers<<std::endl;
    std::cout<<"Count: "<<CarCount<<std::endl;
}

void Car::FOO(Car & car)
{

}

Car::~Car()
{
    CarCount--;
    std::cout<<"Hello from destructor "<<std::endl;
}

int Car::GetCarCount()
{
    std::cout<<"The car count is "<<CarCount<<std::endl;
    return CarCount;
}
