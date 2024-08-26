#include <iostream>
#include <functional>

using fun = int(*) (int, int);

int add(int a, int b)
{
    return a+b;
}

bool Max(int a, int b)
{
    return a > b;
}

int isWell(fun add)
{
    return add(2,3);
}

struct dummy{
    
    public:
    int operator()(int a, int b) const
    {
        return a+b;
    }
};

int functionfun (int ran, std::function<int(int, int)> fur)
{
    return fur(ran , 2);
}
int main()
{
    using namespace std::placeholders;
    // std::function<int(int)> fos = std::bind(add, _1, 5);
    auto fos = [](auto && a){
        return add(std::forward<decltype(a)>(a), 5);
    };

    std::cout << fos(2) << std::endl;

    // auto bound_dummy = std::bind(dummy{},2, 1);
    auto bound_dummy = []<typename T>(T&& a, T&& b){
        return Max(std::forward<T>(b), std::forward<T>(a));
    };
    std::cout << bound_dummy(1, 2) << std::endl;

    // auto dumdum = std::bind(functionfun, _1, add);
    auto dumdum = []<typename T>(T&& a){
        return functionfun(std::forward<T>(a), add);
    };
    std::cout << dumdum(9) << std::endl;
    return 0;
}