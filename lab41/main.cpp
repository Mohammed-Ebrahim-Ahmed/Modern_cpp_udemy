#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <chrono>
#include "Integer.hpp"
#define no_of_operation 50

std::vector<int>& doDummytask(std::vector<int> & v1, const Integer& Int, const std::string& name)
{
    int i = 0;
    for(i = 0; i < no_of_operation; i++)
    {
        v1.emplace_back(i);
        std::cout << i << std::endl;
    }
    std::cout << name;
    return v1;
}

int Compute(std::vector<int> & vec)
{
    int sum{};
    for(auto v : vec)
    {
        sum += v;
        std::cout << v << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    return sum;
}
int main()
{
    std::vector<int> myvec;
    Integer I{2};
    std::string filename{"main.cpp"};
    // std::thread mythread(doDummytask,std::ref(myvec), std::cref(I), std::cref(filename) );

    std::packaged_task<std::vector<int>&(std::vector<int>&, const Integer&, std::string&)> task{doDummytask};

    std::future<std::vector<int>&> fut = task.get_future();
    std::thread th(std::move(task), std::ref(myvec), std::ref(I), std::ref(filename));

    myvec = fut.get();

    for(auto const & x: myvec)
    {
        std::cout << x << std::endl;
    }
    // std::packaged_task<int(std::vector<int>&)> task{}

    if(th.joinable())
    {
        th.join();
    }
    return 0;
}

