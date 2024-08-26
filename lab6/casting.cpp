#include<iostream>


// class Base{
//     public:
//     virtual void print()const noexcept 
//     {
//         std::cout << "Base" << std::endl;
//     }
// };

// class Derived: public Base{
//     public:
//     Derived(const int x):x{x}{}
//     void print() const noexcept override 
//     {
//         std::cout << "Derived" << std::endl;
//     }
//     virtual void printInfoDerived()
//     {
//         std::cout << x << std::endl;
//     }
//     protected:
//         int x;
// };


// class DDerived: public Derived{
//     public:
//     DDerived(const int x, const int y): Derived{x}, y{y}{}
//     void print() const noexcept override final
//     {
//         std::cout << "DerivedDerived" << std::endl;
//     }

//     void printInfoDerived()
//     {
//         std::cout << x << " " << y << std::endl;
//     }
//     protected:
//         int y;
// };


int main()
{
    int a = 5, b =2;

    float f = static_cast<float> (a)/b;

    char* p = reinterpret_cast<char*>(&a);

    const int c = 3;

    int* pp = const_cast<int*>(&c);
    
    std::cout<<f<<std::endl;


    // int a = 97, b= 19;

    // std::cout << static_cast<float>(a) / b << std::endl;


    // char c = *reinterpret_cast<char*>(&a);

    // std::cout << c << std::endl;


    // const char d= 'c';

    // char f = *const_cast<char*>(&d);

    // f = 'h';

    // std::cout << d << f << std::endl;

    // Base* p1 = new DDerived{10,9};

    // p1->print();
    

    // DDerived* p2 = dynamic_cast<DDerived*>(p1);
    // if(!p2)
    // {
    //     std::cout << "casting has failed" << std::endl;
    // }
    // else
    // {
    //     p2->printInfoDerived();
    // }

    // Derived* d = new DDerived{10,9};

    // d->printInfoDerived();


    return 0;
}