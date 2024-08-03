#include <iostream>
#include <string>
#include <string.h>

template<typename T>
T Add(T x,T y) 
{
    return x+y;
} 
template<typename T, int arrSize>
T ArraySum(const T (&pArr)[arrSize]){\
    int i = 0;
    T sum = 0;
    for(i = 0; i <arrSize; i++)
    {
        sum = pArr[i];
    }
    return sum;
}
template<int arrSize> const char* ArraySum(const char* (&pArr)[arrSize])
{
    int i = 0;
    char* arr = new char[100];
    for(i = 0; i <arrSize; i++)
    {
        strcat(arr, pArr[i]);
    }
    return arr;    
}
template<int arrSize> std::string ArraySum(std::string (&pArr)[arrSize])
{
    int i = 0;
    std::string arr;
    for(i = 0; i <arrSize; i++)
    {
        arr += pArr[i];
    }
    return arr;        
}
template<typename T, size_t arrSize>
T Max(const T (&pArr)[arrSize] )
{
    int i = 0;
    T max = pArr[i];

    for(i = 0; i < arrSize; i++)
    {
        if(pArr[i] > max)
        {
            max = pArr[i];
        }
    }
    return max;
}

template<typename T, size_t arrSize>
std::pair<T,T> MinMax(const T (&pArr)[arrSize])
{
    std::pair<T,T> pair{};
    int i = 0;
    T max  = pArr[i];
    T min = pArr[i];

    for(i = 0 ; i < arrSize; i++)
    {
        if(pArr[i] > max)
        {
            max = pArr[i];
        }
        if(pArr[i] < min)
        {
            min = pArr[i];
        }
    }
    pair = {min, max};
    return pair;
}

template<typename T>
T Maximum(T x, T y)
{
    return x>y? x:y;
}



template<typename T, int size>
T min(T (& a)[size])
{
    T min = a[0];
    for(int i = 0; i < size; i++)
    {
        if(min > a[i])
        {
            min = a[i];
        }
    }
    return min;
}