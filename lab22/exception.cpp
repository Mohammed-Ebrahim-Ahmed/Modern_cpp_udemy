#include <iostream>


void fun(int x)noexcept(false)
{
    std::cout<<x<<std::endl;
    //throw x;
}
int sum(int x, int y)noexcept(noexcept(fun(x)))
{
    fun(x);
    return x+y;
}

class Test
{
private:
    /* data */
public:
    Test(/* args */);
    ~Test();
};

Test::Test(/* args */)
{

}

Test::~Test() 
{

}

int main()
{
    
    std::cout << noexcept(fun(2))<<std::endl;
    Test t;
    
    try{
        sum(3,2);
        std::cout<< std::boolalpha << noexcept(t.~Test())<< std::endl;
    }
    catch(int x)
    {
        std::cout<< x <<std::endl;
    }

}