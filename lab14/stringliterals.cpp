#include <iostream>


class Distance {
    
    public:
        Distance(long double m_kilometer): m_kilometer{m_kilometer}{}
        long double getDistance()const {
            return m_kilometer;
            }

        void setDistance(long double dis)
        {
            m_kilometer = dis;
        }

    private:
        long double m_kilometer;

};


Distance operator "" _mi (long double value)
{
    return Distance{value * 1.6};
}

Distance operator "" _m (long double value)
{
    return Distance{value / 1000};
}

int main()
{
    Distance dis_1{ 20.0_mi};
    Distance dis_2{ 2222.2_m};

    std::cout<<dis_1.getDistance() << " "<< dis_2.getDistance()<<std::endl;
}
