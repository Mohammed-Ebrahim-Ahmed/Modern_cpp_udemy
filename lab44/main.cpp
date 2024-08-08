#include <iostream>
#include <utility>
#include <map>

class dumdum
{
public:
    int money;
    int age;
    dumdum() = default;
    dumdum(const int &money, const int &age) : money{money}, age{age}
    {
    }
};

class foo
{
public:
    int arr[29];
    int prr[39];
};

int main()
{
    std::pair<int, int> p{2, 3};
    auto [first, second] = p;

    std::cout << first << " " << second << std::endl;

    std::map<std::string, int> mp{
        {"what", 1},
        {"why", 2},
        {"how", 3}};

    for (auto [key, val] : mp)
    {
        std::cout << key << " " << val << std::endl;
    }

    int arr[3]{1, 2, 3};
    auto prr = arr;
    auto [f, s, t] = arr;
    std::cout << f << " " << s << " " << t << std::endl;
    dumdum d{29, 99};
    auto &[money, age] = d;
    money = 89;
    age = 29;
    std::cout << d.age << " " << d.money << std::endl;

    auto [crr, rrr] = foo();
    return 0;
}