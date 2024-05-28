
#include "account.hpp"

int Account::s_Generator = 1000;
Account::Account(const std::string &name, float balance):m_Name{name},m_Balance{balance}
{
    m_AccNo = ++s_Generator;
    std::cout<<"Account()"<<std::endl;
}

Account::~Account()
{
    std::cout<<"~Account()"<<std::endl;
}

const std::string Account::GetName() const
{
    return m_Name;
}

float Account::GetBalance() const
{
    return m_Balance;
}

int Account::GetAccountNo() const
{
    return m_AccNo;
}

void Account::AccumlateInterest()
{
}

void Account::Withdraw(float amount)
{
    if(amount < m_Balance)
    {
        m_Balance -= amount;
    }
    else
    {
        std::cout<<"Insufficient balance"<<std::endl;
    }
}

void Account::Deposit(float amount)
{
    m_Balance += amount;
}

float Account::GetInterestRate() const
{
    return 0.0f;
}
