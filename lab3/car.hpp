#pragma once

class Car{
    private:
        float fuel{0};
        float speed{0};
        int passengers{0};
        static int CarCount ;
        // int arr[4] { 1,2,3,5};
        // int* ptr {};
        // int* ptra = new int{2};
    public:
        Car();
        Car(float fuel);
        Car(float fuel, int passengers);
        void FillFuel(float amount);
        void Accelerate();
        void Brake();
        void AddPassengers(int count);
        void Dashboard() const;
        void FOO(Car& car);
        static int GetCarCount();
        ~Car();
};