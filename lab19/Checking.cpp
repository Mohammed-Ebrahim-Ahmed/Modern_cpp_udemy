#include "Checking.hpp"

Checking::Checking(const std::string &name, float balance, float mini_val):Account(name,balance), mini_val{mini_val}
{
}
Checking::~Checking()
{
    std::cout<<"~Checking()"<<std::endl;
}
void Checking::Withdraw(float amount)
{
    if(amount < 0.5 * m_Balance)
    {
        Account::Withdraw(amount);
    }
    else
    {
        std::cout<<"amount drawn more than half balance"<<std::endl;
    }

}

float Checking::Get_miniBalanceVal() const
{
    return mini_val;
}
