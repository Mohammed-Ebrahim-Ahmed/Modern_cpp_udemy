#include <iostream>
#include <limits>
#include <memory>
#include <vector>
#include <random>
class test{
    public:
    test(){std::cout<<"Test()"<<std::endl;}
    ~test(){std::cout<<"~Test()"<<std::endl;}
};
int processWords(int count)
{
    std::unique_ptr<test> t1 = std::make_unique<test>();
    if(count < 10)
    {
        throw std::out_of_range("Count is less than ten");
    }
    // int* myptr = (int* ) malloc(sizeof(int)*count);
    // int* ptr = new int[count];
    std::vector<int> myptr;
    myptr.reserve(count);
    std::vector<int> ptr;
    ptr.reserve(count);
    // if(myptr == nullptr)
    // {
    //     // printf("Failed to allocate memory");
    //     // return -1;
    //     throw std::runtime_error("Failed to allocate memory");
    // }
    for(int i = 0; i < count; i++)
    {
        ptr.push_back(i);
    }
    std::default_random_engine eng;
    std::bernoulli_distribution dist;
    int error{};
    for(int i = 0; i < count; i++)
    {   
        try{
        std::cout<<"Process record # " << i <<" "<<std::endl;
        if(!dist(eng))
        {
            error++;
            throw std::runtime_error("Could not process the record");
        }
        }
        catch(std::runtime_error &ex)
        {
            std::cout<<ex.what()<<std::endl;
            if(error > 5)
            {
                std::runtime_error err("Too many corrupted files!");
                ex = err;
                throw;
            }
        }
    }
    return 0;
}

int main()
{
    try{
        // processWords(std::numeric_limits<int>::max());
        // processWords(5);
        processWords(22);
    }
    // catch(std::runtime_error &ex)
    // {
    //     std::cout<<ex.what()<<std::endl;
    // }
    // catch(std::out_of_range &ex)
    // {
    //     std::cout<<ex.what()<<std::endl;
    // }
    // catch(std::bad_alloc &ex)
    // {
    //     std::cout<<ex.what()<<std::endl;
    // }
    // catch(std::exception &ex)
    // {
    //     std::cout<<ex.what()<<std::endl;
    // }
    catch(...)
    {
        std::cout<<"Exception has happend"<<std::endl;
    }
    return 0;
}