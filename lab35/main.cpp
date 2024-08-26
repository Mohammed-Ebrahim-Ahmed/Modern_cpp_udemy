#include <iostream>
#include <algorithm>
template<typename T, typename Operation>
T DoSomething(T(& arr)[3], Operation op)
{
    T result = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    result = op(arr, size);
    return result;
}
template<typename T>
struct Myclass {

    int operator()(T(&arr)[3], int size)
    {
        T maxi = 0;
        int i = 0;
        for(i = 0; i < size; i++)
        {
            maxi = std::max(arr[i], maxi);
        }
        std::cout<< maxi<<std::endl;
        return maxi;
    }
};


int main()
{
    Myclass<int> OP;
    int arr[3] = {1,2,3};
    int max = DoSomething(arr, OP);
    
    return 0;
}