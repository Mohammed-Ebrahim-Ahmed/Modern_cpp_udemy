#include <iostream>
#include "account.hpp"
#include "savingAccount.hpp"
#include "Checking.hpp"
#include "Transaction.hpp"

int main()
{   
    Checking s1{"mohammed",2900,0.05};
    Account &a1 = s1;
    // Account a2{"yasser", 500};
    // //Checking* ch  = static_cast<Checking*>(&a2);
    // Checking ch1{"Yasmin",2900.0,50};
    // Account* a3 = &ch1;
    // a1.Deposit(100);
    // a1.AccumlateInterest();
    // a1.Withdraw(300);
    // std::cout<<"Balance is: "<< a1.GetBalance()<<std::endl;
    try{
         Transaction(a1);
    }catch(std::exception &ex)
    {
        std::cout<<"Exception "<<ex.what()<<std::endl;
    }
   
    
    // int x = 0;
    // float c = 90;
    // std::string s = "yamna";
    // const std::type_info& ti = typeid(*a1);
    // const std::type_info& ti2 = typeid(c);
    // std::cout<<"the type of x is "<<ti.name()<<std::endl;
    // std::cout<<"the type of s is "<<ti2.name()<<std::endl;
    return 0;
}
