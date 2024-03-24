#pragma once
#include<iostream>
class Integer{
    private:
        int* m_pInt;
    public:
        Integer();
        Integer(int value);
        Integer(const Integer& obj);
        Integer(Integer&& obj);
        Integer& operator=(const Integer& obj);
        Integer& operator=(Integer&& obj);
        int GetValue()const;
        void SetValue(int val);
        ~Integer();
        // Integer operator+(const Integer obj) const ;
        Integer& operator++();
        Integer operator++(int dummy) const;
        bool operator==(const Integer& obj) const;
        void operator()();
        friend std::ostream& operator<<(std::ostream& output, const Integer& obj);
        friend class print;
        explicit operator int();
};

class print
{
    public:
    int GetValue(Integer x)const
    {
        *x.m_pInt = 3; 
    }
};
