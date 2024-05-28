#include <iostream>
#include <memory>
#include <vector>
class A {
    public:
        A(){std::cout<<"A() is called"<<std::endl;}
        ~A(){std::cout<<"~A() is called"<<std::endl;}
};

class B {
    public:
        B(){std::cout<<"B() is called"<< std::endl;}
        ~B(){std::cout<<"~B() is called"<<std::endl;}
};

class Test {

    std::unique_ptr<A> pA{};
    B b{};
    std::unique_ptr<int> pInt{};
    std::string pStr{};
    std::vector<int> pArr{};
    int* ptr;
    public:
        Test()
        {
            std::cout<<"Test() Acquire resources"<<std::endl;
            pA.reset(new A);
            throw std::runtime_error("Failed to continue");
            //pInt.reset(new int);
            //pStr = "my name is ahmed";
            //pArr.emplace_back(2);
            ptr = new int;
        }
        ~Test()
        {
            std::cout<<"~Test() Release resources"<<std::endl;

        }
};


int main()
{
    try{
        Test t;
    }
    catch(std::runtime_error &ex)
    {
        std::cout<<ex.what()<<std::endl;
    }
}