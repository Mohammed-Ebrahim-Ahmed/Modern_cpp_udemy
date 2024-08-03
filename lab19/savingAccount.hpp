#pragma once
#include "account.hpp"

class Saving final : public Account {
    public:
        Saving(const std::string &name, float balance, float rate );
        ~Saving();
        float GetInterestRate()const final override;
        void AccumlateInterest() final override;
    
    private:
        float m_Rate;
};