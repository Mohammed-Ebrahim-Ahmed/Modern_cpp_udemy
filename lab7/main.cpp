


#include <iostream>
#include <memory>
#include "../lab4/Integer.hpp"

Integer* GetPointer (int value)
{
    Integer* p = new Integer{value};
    return p;
}

void Display(Integer* p)
{
    if(p)
    {
        std::cout<<p->GetValue()<<std::endl;
    }
}

void Store(std::unique_ptr<Integer> &p)
{
    std::cout<<p->GetValue()<<std::endl;
}

void operate (int value)
{
    std::unique_ptr <Integer> p {GetPointer(value)};
    if(!p)
    {
         p.reset(new Integer{value}) ;
    }

    p->SetValue(value);
    Display(p.get());
    //delete p ;
    p = nullptr;
    p.reset(new Integer{39}) ;
    *p = __LINE__;
    Display(p.get());
    //delete(p);
    Store(p);
    *p = 300;
}
int main()
{
    operate(3);
    return 0;
}