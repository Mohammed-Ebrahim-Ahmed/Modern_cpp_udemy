#include "Integer.hpp"

Integer::Integer()
{
    std::cout<<"Default constructor"<<std::endl;
    m_pInt = new int(0);
}

Integer::Integer(int value)
{
    std::cout<<"Parameterized constructor"<<std::endl;
    m_pInt = new int(value);
}

Integer::Integer(const Integer &obj)
{
    std::cout<<"Copy constructor"<<std::endl;
    m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer &&obj)
{
    std::cout<<"&&obj"<<std::endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

Integer &Integer::operator=(const Integer &obj)
{
    // TODO: insert return statement here
    std::cout<<"Copy assignment operator"<<std::endl;
    if(m_pInt == nullptr)
    {
        std::cout<<"could not allocate "<<std::endl;
    }
    if(this != &obj)
    {
        delete m_pInt;
        m_pInt = new int(*obj.m_pInt);
    }

    return *this;
}

Integer &Integer::operator=(Integer &&obj)
{
    // TODO: insert return statement here
    std::cout<<"Move assignment operator"<<std::endl;

    if(this != &obj)
    {
       delete m_pInt;
       m_pInt = obj.m_pInt;
       obj.m_pInt = nullptr;
    }
    return *this;
}

int Integer::GetValue() const
{
    if(m_pInt == nullptr)
    {
        
    }
    return *m_pInt;
}

void Integer::SetValue(int val)
{
    if(m_pInt == nullptr)
    {
        m_pInt = new int{};
    }
    *m_pInt = val;
}

Integer::~Integer()
{
    std::cout<<"Destructor"<<std::endl;
    delete m_pInt;
}

// Integer Integer::operator+(const Integer obj) const
// {
//     Integer temp{};
//     *temp.m_pInt = *m_pInt + *obj.m_pInt;
//     return temp;
// }

Integer &Integer::operator++()
{
   ++(*m_pInt);
   return *this;
}

Integer Integer::operator++(int dummy) const
{
    Integer temp{*this};
    ++(*m_pInt);
    return temp;
}

bool Integer::operator==(const Integer &obj) const
{
    return (*m_pInt == *obj.m_pInt);
}

void Integer::operator()()
{
    std::cout<<*m_pInt<<std::endl;
}
