
#include <iostream>
#include <string>
#include "function.hpp"

int Add(int x, int y)
{
    return x+y;
}

extern "C"{
int Add(int *a, int *b)
{
    return (*a)+(*b);
}
}
void print(char c)
{
    for(int i = 0; i < 10 ; i++)
    {
        std::cout<<c<<std::endl;
    }
    std::cout<<std::endl;
}



void AddVal(int *a, int *b, int *result)
{
    *result = *a + *b ;
}

void Swap(int *a, int *b)
{
    *a = (*a)^(*b);
    *b = (*a)^(*b);
    *a = (*a)^(*b);
}

void Factorial(int *a, int *result)
{
    *result = 1;
    for(int i = 1 ; i <= *a; i++)
    {
        *result *=i;
    }
}

void Add2(int a,int b, int &result)    //Add two numbers and return the result through a reference parameter
{
    result = a + b;
}

void Factorial2(int a, int &result)     //Find factorial of a number and return that through a reference parameter
{
    result = 1;
    for(int i = 1 ; i <= a; i++)
    {
        result *=i;
    }
}

void Swap2(int &a, int &b)             //Swap two numbers through reference arguments
{
    a = a+b;
    b = a-b;
    a = a-b;
}

void printScreen(const char* name, int x , int y, int width, int height)
{
    std::cout<<"The name is"<<name<<std::endl;
    std::cout<<"x is "<<x<<std::endl;
    std::cout<<"y is "<<y<<std::endl;
    std::cout<<"witdth is "<<width<<std::endl;
    std::cout<<"height is "<<height<<std::endl;
}

void print(int count, const char* ch)
{
    int i = 0;
    
    for(i = 0; i < count; i++)
    {
        std::cout<<ch;
    }
    std::cout<<std::endl;
}