#include <iostream>
#include <initializer_list>
#include <string>
#include <cassert>
class Bag {
    public:
        Bag(std::initializer_list<int> data)
        {
            assert(data.size() < 10);
            auto it = data.begin();
            while(it != data.end())
            {
                add(*it++);
            }
        }
        void add(int val)
        {
            assert(m_size < 10);
            arr[m_size] = val;
            m_size++;
        }
        void Remove()
        {
            assert(m_size >= 0);
            m_size--;
        }
        int operator [] (int index)
        {
            return arr[index];
        }
        int getSize() const  {
            return m_size;
        }
    private:
        int arr[10];
        int m_size{0};
};

void Print(std::initializer_list<int> values)
{
    // auto it = values.begin();

    // while(it != values.end())
    // {
    //     std::cout<<*it<<std::endl;
    // }

    for(auto value: values)
    {
        std::cout<<value<<std::endl;
    }
}
int main()
{
    int x{2};
    float z {2.2};
    int arr[3] {1,3,4};
    std::string name {"mohammed"};
    std::initializer_list<int> data {1,2,3};
    auto values = {1,2,3,4};
    Bag bag{1,2,3};
    // bag.add(2);
    // bag.add(3);
    // bag.add(5);
    Print({1,3,9});
    return 0;

}