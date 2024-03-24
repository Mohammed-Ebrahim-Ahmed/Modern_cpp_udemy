#include <iostream>
#include "Integer.hpp"
#include "memory"
Integer operator+(const Integer& a, const Integer& b)
{
    Integer temp;
    temp.SetValue(a.GetValue()+ b.GetValue());
    return temp;
}

Integer operator+(const int x, const Integer& b)
{
    Integer temp;
    temp.SetValue(x+b.GetValue());
    return temp;
}
std::ostream& operator<<(std::ostream& output, const Integer& obj)
{
    output<<obj.m_pInt;
    return output;
} 

std::istream& operator>>(std::istream& input, Integer obj)
{
    int x;
    input>>x;
    obj.SetValue(x);
    return input;
}

class Number{
        Integer m_Value{};
    public:
        Number() = default;
        Number(int value):m_Value{value}{

        }
        Number(const Number &n) = default;
        // ~Number()
        // {
            
        // }
        Number(Number &&n) = default;
        Number& operator=(Number&& num) = default;
        Number& operator=(Number& num) = default;
};
Number CreateNumberFunc( int num)
{
    Number n{num};
    return n;
}
void Print(Integer Val)
{

}
class Intptr{
    Integer* ptr;
    public:
    Intptr(Integer* ptrVal):ptr{ptrVal}
    {

    }
    ~Intptr()
    {
        delete ptr;
    }
    Integer* operator->()
    {
        return ptr;
    }
    Integer& operator*()
    {
        return *ptr;
    }

};
void print(std::shared_ptr<Integer> ptr)
{
    (*ptr)();
}
void pprint(Integer x)
{

}

class Product{
    private:
        Integer Id;
    public:
        Product(const Integer& a)
        {
            std::cout<<"Product(const Integer &)"<<std::endl;
            Id = a;
        }
        ~Product()
        {
            std::cout<<"~"<<std::endl;
        }
        const Integer& GetInteger() const
        {
            return Id;
        }
        explicit operator Integer()
        {
            return Id;
        }

};
int main()
{
//     int x;
//     Integer i;
//     Integer i_2(8);
//     Integer i_3(i);
//     i.SetValue(8);
//     x= i.GetValue();
//     std::cout<<x<<std::endl;

    // Integer c;
    // const Integer a,b(2);
    // c.SetValue(Add(a,b).GetValue());
    // Number{};
    // Number n1{1};
    // auto n2{n1};
    // n2 = n1;
    // auto n3{CreateNumberFunc(2)};
    // auto n4 = CreateNumberFunc(2);
    // Integer n1{3};
    // Integer n2{std::move(n1) };
    // Print(std::move(n2));
    // n2.SetValue(3);
    // std::cout<<n2.GetValue()<<std::endl;
    // Integer n1{2};Integer n2{4};Integer n3{3};
    // Integer n = n1+n2+n3;
    // std::cout<<n.GetValue()<<std::endl;
    // ++n;
    // std::cout<<n.GetValue()<<std::endl;
    // n++;
    // std::cout<<n.GetValue()<<std::endl;
    // std::cout<<(n1==n3)<<std::endl;
    // n1 = n1;
    // n1 = 8 + n2;
    // std::cin>>n3;
    // std::cout<<n3<<std::endl;
    // n3();
    // std::shared_ptr<Integer> ptr(new Integer);
    //Intptr ptr = new Integer();
    // ptr->SetValue(3);
    // (*ptr).SetValue(8);
    // print((ptr));
    // (*ptr)();
    // ptr->GetValue();

    // Integer a1 = 4;
    // Integer a2 {2};
    // a2 = 9;
    // pprint(3);

    // int x = static_cast<int>(a2);
    // Product p{2};
    // Integer a3 = static_cast<Integer>(p);

    // if(a3 == static_cast<Integer>(p))
    // {
    //     std::cout<<"Casting is ok"<<std::endl;
    // }
    Product p1{2};

    return 0;
}