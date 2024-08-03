#include "Integer.hpp"
#include <iostream>

// template<typename T>
// void print(std::initializer_list<T> && p)
// {
//     for(const auto &x : p)
//     {
//         std::cout<<x<<" ";
//     }
// }
void print()
{
    std::cout<<std::endl;
}
template<typename T1,typename... Parmas>
void print(T1&& a, Parmas&&... args)
{

    std::cout<<a;
    if(sizeof...(args) != 0)
    {
        std::cout<<",";
    }
    print(std::forward<Params>(args)...);
}
int main()
{
    Integer v1{2};
    print(0, v1, Integer{2});
    return 0;
}