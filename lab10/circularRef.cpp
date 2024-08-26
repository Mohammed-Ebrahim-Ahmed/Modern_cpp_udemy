#include <iostream>
#include <memory>

class Employee;

class Project{
    public:
        std::shared_ptr<Employee> emp;

    Project(){
        std::cout<<"Project"<<std::endl;
    }
    ~Project()
    {
        std::cout<<"~Project"<<std::endl;
    }
};

class Employee {
    public:
        std::weak_ptr<Project> pro;

    Employee(){
        std::cout<<"Employee"<<std::endl;
    }
    ~Employee(){
        std::cout<<"~Employee"<<std::endl;
    }
};


int main()
{
    std::shared_ptr<Project> pro {new Project{}};
    std::shared_ptr<Employee> emp{new Employee{}};
    std::cout << pro.use_count() << " " << emp.use_count() << std::endl;
    pro->emp = emp;
    emp->pro = pro;

    return 0;
}