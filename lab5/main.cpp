#include<iostream>

int Add(int x, int y)
{
    return x+y;
}

int& Transform(int& x)
{
    x*=x;
    return x;
}

void Print(int& x)
{
    std::cout<<"int& "<<std::endl;
}

void Print(const int& x)
{
    std::cout<<"const int "<<std::endl;
}
void Print(int&& x)
{
    std::cout<<"int&& "<<std::endl;
}

int main()
{
    int&& r1 = 10;
    int&& r2 = Add(2,3);
    int&& r3 = 2+3;
    int y = 2;
    int& x = y;

    int & z = Transform(y);
    const int & f = 2;
    Print(y);
    Print(f);
    Print(2);

    return 0;
}