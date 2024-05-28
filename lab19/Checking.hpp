#pragma once 
#include "account.hpp"
class Checking final : public Account  {
    public:
        //using Account::Account ;
        Checking(const std::string& name, float balance, float mini_val);
        ~Checking();
        void Withdraw(float amount) final override; 
        float Get_miniBalanceVal()const;
    private:
        float mini_val;
};