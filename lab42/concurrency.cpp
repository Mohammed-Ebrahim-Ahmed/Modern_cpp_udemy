#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <future>
#include <processthreadsapi.h>

#define max_size 1000
std::list<int> l1;
std::mutex mutex;

int Download(int& id)
{
    int i; 
    for(i = 0; i < max_size;i++)
    {
        std::lock_guard<std::mutex> mtx(mutex);
        l1.emplace_front(i);
        if(i == 500)
        {
            break;
        }
    }
    return id+1;
}

int Download2(int&& id)
{
    int i; 
    for(i = 0; i < max_size;i++)
    {
        std::lock_guard<std::mutex> mtx(mutex);
        l1.emplace_front(i);

    }
    return id+2;
}

int printnums(std::promise<int> & p1, std::promise<int> & p2)
{
    int i = 0;
    using namespace std::chrono_literals;
    
    std::cout << "getting the future of the value inside the task" << std::endl;
    auto f1 = p1.get_future();
    try{
        throw std::runtime_error{"no no no"} ;
        int val = f1.get();
        std::cout << "The value has been acquired inside the task" << std::endl;
        for(i = 0; i < 10; i++)
        {
            std::this_thread::sleep_for(1ms);
            std::lock_guard<std::mutex> mtx{mutex};
            std::cout << i << std::endl;
            val += i;
        }
        p2.set_value(30);
        return val;
    }
    catch(const std::exception & ex)
    {
        std::cout << "exception from the printnums " << ex.what() << std::endl;
        p2.set_exception(std::make_exception_ptr(ex));
        return -1;
    }

}
int main()
{
    // int id = 4;
    // std::packaged_task<int(int& id)> task1{Download};
    // std::packaged_task<int(int&& id)> task2{Download2};
    // std::future<int> f1 = task1.get_future();
    // std::future<int> f2 = task2.get_future();
    // std::thread t1{std::move(task1), std::ref(id)};
    // std::thread t2{std::move(task2), 2};

    // auto num1 = f1.get();
    // auto num2 = f2.get();

    // std::cout << num1 << " " << num2 << std::endl;
    // std::cout << l1.size() << std::endl;
    // if(t1.joinable())
    // {
    //     t1.join();
    // }

    // if(t2.joinable())
    // {
    //     t2.join();
    // }

    // std::thread t1{printnums};
    // std::cout << t1.get_id() << std::endl;
    // auto h1 = t1.native_handle();
    // // SetThreadPriorityBoost(h1, 10);
    // t1.join();
    // auto counts = std::thread::hardware_concurrency();
    // std::cout << "no of cours " << counts;
    using namespace std::chrono_literals;
    // int val = 30;
    std::promise<int> p1;
    std::promise<int> p2;
    std::future<int > ele = std::async(std::launch::async, printnums, std::ref(p1), std::ref(p2) );
    std::this_thread::sleep_for(40ms);
    std::cout << "We are in the main task ...";
    try{
        // throw std::runtime_error{"what the hell"};
        p1.set_value(20);
    }
    catch(const std::exception & ex)
    {
        std::cout << "exception from main thread to be shared " << ex.what() << std::endl;
        p1.set_exception(std::make_exception_ptr(ex));
    }

    if(ele.valid())
    {
        // printnums();
        auto time = std::chrono::steady_clock::now();
        time += 36ms;
        auto status =ele.wait_until(time);
        switch(status)
        {
            case std::future_status::deferred:
                std::cout << "the task is already sychronous stop being idiot"<< std::endl;
                break;
            case std::future_status::ready:
                std::cout << "We are ready for this moment" << std::endl;
                break;
            case std::future_status::timeout:
                std::cout << "Timeout unfortunately" << std::endl;
                break;
            default:
                break;
        }
        std::cout << "my name is mohammed" << std::endl;
        auto val = ele.get();
        std::cout << "we finished the thread" << std::endl;
        std::cout << val << std::endl;
    }
    std::cout << "we are here again" << std::endl;

    try{
        auto f2 = p2.get_future();
        auto val = f2.get();
        std::cout << val << std::endl;
    }catch(std::exception & ex)
    {
        std::cout << "The exception is thrown from the thread " << ex.what() << std::endl;
    }
    return 0;
}