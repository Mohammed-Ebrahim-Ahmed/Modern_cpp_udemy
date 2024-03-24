#include<iostream>

int main()
{
    int a = 5, b =2;

    float f = static_cast<float> (a)/b;

    char* p = reinterpret_cast<char*>(&a);

    const int c = 3;

    int* pp = const_cast<int*>(&c);
    
    std::cout<<f<<std::endl;

}