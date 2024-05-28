#pragma once
#include <iostream>
#include <string>

class Account {
    public:
        Account(const std::string &name, float balance);
        virtual ~Account();
        const std::string GetName()const;
        float GetBalance()const;
        int GetAccountNo()const;

        virtual void AccumlateInterest();
        virtual void Withdraw(float amount);
        void Deposit(float amount);
        virtual float GetInterestRate()const;



    private:
        std::string m_Name;
        int m_AccNo;
        static int s_Generator;

    protected:
        float m_Balance;
};