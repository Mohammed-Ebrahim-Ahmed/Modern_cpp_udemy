#include <iostream>
#include <chrono>
#include <random>
#include <execution>

class Timer{
    public:
        Timer():m_time{std::chrono::system_clock::now()}
        {

        }
        void getTime()
        {
            auto end = std::chrono::system_clock::now();
            auto duration = end - m_time;
            std::cout << std::chrono::duration_cast< std::chrono::nanoseconds>(duration).count() << std::endl ;
        }

    private:
        std::chrono::system_clock::time_point m_time;
};

constexpr unsigned vecSize{100};
std::vector<int> intializeVector()
{
    std::vector<int> vec;
    vec.resize(vecSize);
    std::default_random_engine eng{std::random_device{}()};
    std::normal_distribution<> dist{0, vecSize};

    for(int i = 0; i < vecSize; i++)
    {
        vec.push_back(dist(eng));
    }

    return vec;
}

int main()
{
    auto num = intializeVector();

    Timer t;
    // std::sort(std::execution::seq ,num.begin(), num.end());
    // auto sum = std::accumulate(num.begin(), num.end(), 0L);
    auto sum = std::reduce(std::execution::par, num.begin(), num.end(), 0L);
    t.getTime();
    std::cout << sum << std::endl;
}
