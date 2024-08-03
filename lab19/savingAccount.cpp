
#include "savingAccount.hpp"

Saving::Saving(const std::string &name, float balance, float rate): Account(name,balance), m_Rate{rate}
{
    std::cout<<"Saving()"<<std::endl;
}
Saving::~Saving()
{
    std::cout<<"~Saving()"<<std::endl;
}

float Saving::GetInterestRate() const
{
    return m_Rate;
}

void Saving::AccumlateInterest()
{
    m_Balance += (m_Balance* m_Rate);
}
