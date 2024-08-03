#include <iostream>
#include "Integer.hpp"
class Employee{

    public:
    // Employee(const Integer &id,const  std::string &name):id(id),name(name){
    //     std::cout<<"Employee(Integer &id, std::string &name):id(id),name(name)"<<std::endl;
    // }
    template<typename T1, typename T2, typename T3>
    Employee(T1&& name, T2 &&id, T3 &&salary):name(name),id(id),salary(salary){
        std::cout<<"Employee(Integer&& id,const  std::string &&name):id(id),name(name)"<<std::endl;
    }    
    ~Employee()
    {
        std::cout<<"~Employee()"<<std::endl;
    }
    private:
        Integer id;
        std::string name;
        Integer salary;
};
class Contact{
    public:
        template<typename T1, typename T2, typename T3, typename T4>
        Contact(T1&& name, T2&& number, T3 address, T4 email):name{std::forward<T1>(name)}, number{std::forward<T2>(number)}, address{std::forward<T3>(address)}, email{std::forward<T4>(email)}
        {
            std::cout<<"Contact(T1&& name, T2&& number, T3 address, T4 email):name{name}, number{number}, address{address}, email{email}";
        }
    private:
    std::string name;
    int number;
    std::string address;
    std::string email;
};
template<typename T1>
T1* CreateObject()
{
    return new T1();
}

template<typename T1, typename... Params>
T1* CreateObject(Params&&... args)
{
    return new T1(std::forward<Params>(args)...);
}
int main()
{
int *p1 = CreateObject<int>(5) ;
 
std::string *s = CreateObject<std::string>() ;//Default construction
 
Employee * emp = CreateObject<Employee>(
"Bob",    //Name
101,      //Id
1000) ;   //Salary
 
Contact *p = CreateObject<Contact>(
"Joey",                //Name
987654321,             //Phone number
"Boulevard Road, Sgr", //Address
"joey@poash.com") ;    //Email
}