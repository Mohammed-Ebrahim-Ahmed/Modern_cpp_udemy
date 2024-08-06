#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

void Array()
{
    std::array<int, 8> arr;

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = i;
    }

    for (const auto &x : arr)
    {
        std::cout << x << std::endl;
    }
}

void Vector()
{
    std::vector<int> vec;

    for (int i = 0; i < 10; i++)
    {
        vec.emplace_back(i);
    }

    auto it = vec.begin();
    vec.insert(vec.begin(), 9);
    vec.erase(vec.end() - 3);
    vec.assign(2, vec[2]);
    // vec.pop_back();
    while (it != vec.end())
    {
        std::cout << *it++ << std::endl;
    }
}

void Deque()
{
    std::deque<int> deq;

    for (int i = 0; i < 10; i++)
    {
        deq.emplace_back(i);
    }
    for (int i = 0; i < 10; i++)
    {
        deq.emplace_front(i * 10);
    }
    auto it = deq.begin();
    deq.insert(deq.begin(), 9);
    deq.erase(deq.end() - 3);
    deq.assign(3, deq[2]);
    deq.pop_back();
    deq.pop_front();
    while (it != deq.end())
    {
        std::cout << *it++ << std::endl;
    }
}

void List()
{
    std::list <int> lis{9,39,-88,77,29,19,93};

    auto it = lis.begin();
    lis.insert(lis.begin(), 20);
    lis.sort();
    lis.remove_if([](int a){
        return a > 0;
    });
    it = lis.begin();
    while(it != lis.end())
    {
        std::cout << *it++ << std::endl;
    }
}

void Forward_List()
{
    std::forward_list <int> forlis{9,39,-88,-77,29,19,93};

    auto it = forlis.begin();
    forlis.insert_after(forlis.before_begin(), 20);
    forlis.sort(std::greater<int>());
    forlis.reverse();
    forlis.remove_if([](int a){
        return a > 0;
    });
    it = forlis.begin();
    forlis.erase_after(it);
    while(it != forlis.end())
    {
        std::cout << *it++ << std::endl;
    }
}
int main()
{
    Forward_List();
    return 0;
}