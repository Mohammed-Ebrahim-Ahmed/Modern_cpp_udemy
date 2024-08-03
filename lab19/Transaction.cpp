#include "Transaction.hpp"
#include "iostream"
#include "Checking.hpp"
#include <typeinfo>
void Transaction(Account *pAccount)
{
    std::cout<<"Transaction started "<< std::endl;
    std::cout<<"Initial balance : "<<pAccount->GetBalance()<<std::endl;
    pAccount->Deposit(100);
    pAccount->AccumlateInterest();
    pAccount->Withdraw(120);

    Checking* chacc = dynamic_cast<Checking*>(pAccount) ;
    if(chacc)
    {
        std::cout<<"The minimum value to be in an account is "<<chacc->Get_miniBalanceVal()<< std::endl;
    }


    std::cout<<"InterestRate is: "<< pAccount->GetInterestRate()<<std::endl;
    std::cout<<"Final balance : "<<pAccount->GetBalance()<<std::endl;
}

void Transaction(Account &pAccount)
{
    std::cout<<"Transaction started "<< std::endl;
    std::cout<<"Initial balance : "<<pAccount.GetBalance()<<std::endl;
    pAccount.Deposit(100);
    pAccount.AccumlateInterest();
    pAccount.Withdraw(120);

    Checking chacc = dynamic_cast<Checking&>(pAccount) ;


    std::cout<<"InterestRate is: "<< pAccount.GetInterestRate()<<std::endl;
    std::cout<<"Final balance : "<<pAccount.GetBalance()<<std::endl;
}