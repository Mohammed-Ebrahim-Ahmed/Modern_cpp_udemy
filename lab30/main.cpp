#include <iostream>
#include "Integer.hpp"


class Employee{

    public:
    // Employee(const Integer &id,const  std::string &name):id(id),name(name){
    //     std::cout<<"Employee(Integer &id, std::string &name):id(id),name(name)"<<std::endl;
    // }
    template<typename T1, typename T2>
    Employee(T1&& id, T2 &&name):id(id),name(name){
        std::cout<<"Employee(Integer&& id,const  std::string &&name):id(id),name(name)"<<std::endl;
    }    
    ~Employee()
    {
        std::cout<<"~Employee()"<<std::endl;
    }
    private:
        Integer id;
        std::string name;
};
template<typename T1, typename T2>
Employee* createEmployee(T1&& id, T2&& name)
{
    return new Employee(std::forward<T1>(id), std::forward<T2>(name));
}

int main()
{   
    // Integer v1{22};
    // Employee e1{v1,"mohammed"};
    // std::string name{"mohammed"};
    // Employee e2{22, name };
    // std::string name = "mohamemd";
    // Employee e1{v1, name};
    auto a1 = createEmployee(22, "mohammed");
    return 0;
}