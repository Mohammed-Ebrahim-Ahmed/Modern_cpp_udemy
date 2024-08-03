#include <iostream>

template<typename T>
T Add(T x,T y) 
{
    return x+y;
} 
template<typename T>
T ArraySum(const T *pArr, size_t arrSize){\
    int i = 0;
    T sum = 0;
    for(i = 0; i <arrSize; i++)
    {
        sum = pArr[i];
    }
    return sum;
}
template<typename T>
T Max(const T *pArr, size_t arrSize)
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
template<typename T>
std::pair<T,T> MinMax(const T *pArr, size_t arrSize)
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

int main()
{

    int x = Add(2, 3);
    float y = Add(2.2, 3.2);
    std::cout<<x<<" "<<y<<std::endl;
    int z[3] = {1,2,3};
    int sum = ArraySum(z, 3);
    std::cout<<"int sum = "<< sum<<std::endl;
    float f[3] = {1.2f, 3.9f, 9.2f};
    float fsum = ArraySum(f, 3);
    std::cout<<"float sum = "<< fsum <<std::endl;
    std::cout<<Max(z, 3)<<std::endl;
    std::cout<<Max(f, 3)<<std::endl;
    std::pair<int, int> pair = MinMax(z, 3);
    std::cout<<pair.first <<" "<< pair.second<< std::endl;
    std::pair<float, float> fpair= MinMax(f, 3);
    std::cout<<fpair.first <<" "<< fpair.second<< std::endl;

    return 0;
}