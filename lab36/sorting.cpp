#include <iostream>
#include <algorithm>
#include <fstream>
#include <utility>
#include <limits>
#include <vector>
#include <set>
#include <deque>
#include <list>

// template<typename T>
// using Swap = void (*)(T &, T &);

// template<typename T>
// void swapTwoElements(T &a, T &b)
// {
//     a = a + b;
//     b = a - b;
//     a = a - b;
// }

template<int size, typename T, typename Comp>
void sortArray(T (&arr)[size], Comp ss)
{
    size_t i , j;
    for(i = 0; i < size-1; i++)
    {
        for(j = 0 ; j < size - i -1; j++)
        {
            if(arr[j+1] < arr[j])
            {
                ss(arr[j+1], arr[j]);
            }
        }
    }
} 

template<typename T, int size, typename MyFun>
void arrayTrans(T (&arr) [size],  MyFun fun)
{
    int i = 0;

    for(auto & x : arr)
    {
        fun(x);
    }
}

template<typename T>
struct sorting
{
    public:
        void operator()(T& a, T& b)
        {
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
        }
};

class Product {
    
    public:
        Product(int base_price, std::string name) : base_price{base_price}, name{name}
        {

        }

        int getNetIncome()
        {
            int tax[] = {5, 10, 20};
            int max = tax[0];
            arrayTrans(tax, [max, this](int x)mutable{
                max = std::max(x, max);
                base_price -=x;
            });
            return base_price;
        }
    private:
        int base_price;
        std::string name;
};
struct Unamed {

    int operator()(int x, int y)
    {
        return x+y;
    }
};
template<typename T>
std::pair<T,T> MinMax(auto ItrBegin,auto ItrEnd)
{
    T min = std::numeric_limits<T>::max();
    T max = std::numeric_limits<T>::min();
    std::pair<T,T> pr;
    for(auto it = ItrBegin; it != ItrEnd; it++)
    {
        max = std::max(*it, max);
        min = std::min(*it, min);
    }
    pr.first = min;
    pr.second = max;
    return pr;
}
int main()
{
    int arr [] = {9, 3, 9, 78, 20};
    sorting<int> ss;
    constexpr int x = 5;
    for(const auto & x : arr)
    {
        std::cout << x << std::endl;
    }
    sortArray(arr, [](int& x, int& y)
    {
        int temp = x;
        x = std::move(y);
        y = std::move(temp);
    });
    
    for(const auto & x : arr)
    {
        std::cout << x << std::endl;
    }    
    auto sum = [](auto x, auto y) -> double
    {
        if(x > y)
            return true;
        return x + y;
    };

    std::cout<<sum(2, 3.9);
    Unamed un;
    std::cout<<un(2,3)<<std::endl;

    auto greater = [](int a, int b) -> bool
    {
        return a > b;
    };

    std::cout << greater(9, 10);
    int max = 0 ;
    auto greatest = [max](int(&arr)[], int size ) mutable -> int
    {
        int i = 0;
        for(i = 0; i < size; i++)
        {
            max = std::max(arr[i], max);
        }
        return max;
    };

    std::cout << greatest(arr, (sizeof(arr) / sizeof(arr[0])));

    Product pro(20, "Washing machine");
    std::cout<<pro.getNetIncome();

    std::ofstream out{"file.txt"};
    //int x{2};

    auto write = [out = std::move(out)](int x)mutable{
        out << x;
    };

    write(200);

    std::cout<<std::endl;

    std::list<int> v1 {1, 99, 2, 93, 100, 33};
    auto par = MinMax<int>(v1.begin(), v1.end());
    std::cout<< par.first << " " << par.second <<std::endl;
    return 0;
}