#include <iostream>
#include <format>
#include <vector>

class CustomClass{

    public:
        CustomClass(int val): myval{new int{val}}
        {
            std::cout << "parameterized constructor is called " << std::endl;
        }
        ~CustomClass()
        {
            delete myval;
            std::cout << "destructor is called" << std::endl;
        }

        CustomClass(const CustomClass& other)
        {
            myval = new int{other.getVal()};
            std::cout << "copy constructor is called" << std::endl;
        }
        CustomClass(CustomClass&& other)
        {
            myval = other.getPointer();
            other.setPointer(nullptr);

            std::cout << "move constructor is called" << std::endl;
        }
        CustomClass& operator=(const CustomClass& other)
        {
            if(this != &other)
            {
                delete myval;
                myval = new int{other.getVal()};\
                std::cout << "copy assignment operator is called" << std::endl;
            }
            return *this;
        }

        CustomClass& operator==(CustomClass&& other)
        {
            if(this != &other)
            {
                std::cout << "move assignment operator is called" << std::endl;
                myval = other.getPointer();
                other.setPointer(nullptr);
            }

            return *this;
        }
        int getVal()const{
            return *myval;
        }

        void setVal(const int val)
        {
            myval = new int{val};
        }
        int* getPointer()const{
            return myval;
        }
        void setPointer(int* val)
        {
            myval = val;
        }
    private:
        int *myval;
};

// CustomClass myfun()
// {
    
//     return CustomClass{29};
// }

const CustomClass& myfun(const CustomClass& myclass)
{
    std::cout << myclass.getVal() << std::endl;
    return myclass;
}
int main()
{
    CustomClass cl{29};
    auto cl2 = myfun(cl);

    constexpr const char * myformat = "this is {0} and address is {1:p}\n";

    int a = 55;

    std::cout << &a << std::endl;
    std::cout << std::format(myformat, a, static_cast<void*>(&a));


    constexpr const char * customformat = "{0} is my {1:6f}";

    float f = 888889.37655555555;

    std::cout << std::format(customformat, a, f) << std::endl;


    std::cout << std::format("{0:0>8b}", a) << std::endl;

    std::cout << std::format("{0:0>8x}", a) << std::endl;

    int b = 99;
    std::cout << std::format("{1} is {0}", a, b) << std::endl;
    return 0;
}