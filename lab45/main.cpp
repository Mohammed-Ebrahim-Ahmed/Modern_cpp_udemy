#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <mutex>
#include <future>

// #define deleted_copy_move_cons
class Number{   

    public:
        Number(int x): x{x}
        {
            std::cout << "Parameterized constructor is called" << std::endl;
        }
        #ifdef deleted_copy_move_cons
        Number(const Number &) = delete;
        Number(Number&&) = delete;
        #endif
        #ifndef deleted_copy_move_cons
        Number(const Number & num): x{num.x}
        {
            std::cout << "Copy constructor" << std::endl;
        }

        Number(Number && num):x{num.x}
        {
            std::cout << "move constructor is called" << std::endl;
            num.x = 0;
        }
        int getValue()const{
            return x;
        }
        #endif
    private:
        int x;
};
void foo(Number num)
{

}
Number create()
{
    // Number num{3};
    // return num;

    return Number{3};
}
template<typename T, typename... Args>
T create(Args... args)
{
    return T{args...};
}
template<typename T>
class Data{
    public:
        Data(const T & d)
        {

        }
};

auto sum()
{
    return 0;
}
template<typename T, typename... Args>
T sum (T a, Args... args)
{
    return a+sum(args...);
}

template <typename... Args>
int sum2(Args... args)
{
    return (args + ... + 0);
}
Data(const char *) -> Data<std::string> ;
Data(int) -> Data<long> ;

// Number&& createAndReturnNumber(int num) {
//     return Number{num};  // Attempting to return an rvalue reference to a temporary object
// }
void addNumber(std::vector<Number>& numbers, Number&& num) {
    numbers.push_back(std::move(num)); // Explicitly move `num` into the vector
}

int main()
{
    Number num = 3;
    auto nf = create();
    foo(Number{9});
    auto var = create<Number>(0);
    std::vector vec{2,3,4};
    std::pair pr{2,3};
    std::mutex mtx;
    std::lock_guard guard{mtx};
    Data d1{5};
    Data d2{9.3f};
    Data d3{"file"};
    std::cout << sum(1,2,3,4,5);
    std::cout << sum2(1,2,3,4,5);
    // auto nnn = createAndReturnNumber();
    std::vector<Number> vv{Number{2}, Number{9}};
    Number mynum = 9;
    addNumber(vv, std::move(mynum));

    for(auto & x: vv)
    {
        std::cout << x.getValue() << std::endl;
    }
    return 0;
}