#include <iostream>

constexpr int getNumber()
{
    return 43;
}
constexpr int add (int x, int y)
{
    int sum = 0;
    sum = x + y;
    return sum;
}
int main()
{
    const int x = 10;
    int arr[x];
    const int y = getNumber();
    int arr2[y];
    constexpr int z = getNumber();
    int arr3[z];
    int g = getNumber();
    constexpr int f = add(z,3);
    std::cout<< f<< g <<std::endl;
    return 0;
}