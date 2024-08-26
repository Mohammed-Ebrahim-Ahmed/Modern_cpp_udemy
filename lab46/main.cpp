#include <iostream>


template<typename T>

T Divide(T && x,T && y)
{
    if(std::is_floating_point<T>::value == false)
    {
        std::cout << "The passed argument is not float" << std::endl;
        return 0;
    }

    return (x / y) ;
};

template<typename T>
void check(T && val)
{
    std::cout << std::boolalpha;
    std::cout << std::is_reference<T>::value << std::endl;

    std::cout << std::is_reference< typename std::remove_reference<T>::type >::value << std::endl;
    val = 10;
}

template< typename T >
class Number {
    public:
        Number() = default;
        Number(const T & x) : num{x}
        {

        }

    private:
        T num;
};


int main()
{
    Divide(9,3);
    int a = 9;
    check(a);
    std::cout << a <<  std::endl;
    static_assert(std::is_default_constructible<Number<int>>::value, "does not have default constructor");
    return 0;
}



