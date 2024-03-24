#include <iostream>
#include <memory>

class Project {
    std::string Project_name;

    public:
        void setProjectName(std::string Project_name)
        {
            this->Project_name = Project_name;
        }
        const void GetProjectName(void) const {
            std::cout<<"project []"<<std::endl;
        }
};

class Employee{
    std::shared_ptr<Project> m_Project;

    public:
        void SetProject(std::shared_ptr<Project>& Proj)
        {
            m_Project = Proj;
        }
        const std::shared_ptr<Project>& GetProject(void) const
        {
            return m_Project;
        }


};

const void ShowInfo(std::shared_ptr<Employee>& emp)
{
    emp->GetProject()->GetProjectName();
}
int main()
{
    std::shared_ptr<Project> pro {new Project{}} ;
    pro->setProjectName("4MEM");
    std::shared_ptr<Employee> e1 {new Employee{}} ;
    e1->SetProject(pro);
    std::shared_ptr<Employee> e2 {new Employee{}};
    e2->SetProject(pro);
    std::shared_ptr<Employee> e3 {new Employee{}};
    e3->SetProject(pro);

    std::cout<<pro.use_count()<<std::endl;
    ShowInfo(e1);
    ShowInfo(e2);

    std::cout<<e1.use_count()<<std::endl;
    e1.reset(new Employee{});
    pro->GetProjectName();
    return 0;
}