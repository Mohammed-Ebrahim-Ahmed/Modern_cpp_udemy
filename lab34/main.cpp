#include <iostream>
template<typename T>
class funop {
    public:
        T operator()(T a, T b)
        {
            if(a > b)
            {
                return a;
            }
            else
            {
                return b;
            }
        }
};

template<typename T, typename Comm>
T arrayMax(T& arr, Comm com)
{
    int i = 0;
    for(i = 1; i < arr.size(); i++)
    {
        com(arr[i-1], arr[i]);
    }
}
int main()
{
    auto max = [](int a, int b)-> int{
        if(a > b)
        {
            return a;
        }
        else
        {
            return b;
        }
    };

    int array[3] = {1, 2, 3};
    arrayMax<int, max>(array, [](int a, int b) {
        int max = 0;
        if(a > b)
        {
            max = std::max(a, max);
            return a;
        }
        else
        {
            max = std::max(b, max);
            return b;
        }       
    })

    std::cout<< max(3,2) << std::endl;
    return 0;
}