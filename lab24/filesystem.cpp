#include <iostream>

#include <filesystem>


int main()
{
    using namespace std::filesystem;
    path p{R"(E:/ES_ITI/C++/udemy)"};
    if(p.has_filename())
    {
        std::cout<<p.filename()<<std::endl;
    }
    for(auto &x :p)
    {
        std::cout<<x<<std::endl;
    }

    // directory_iterator beg{p};
    // directory_iterator end{};
    // while(beg !=end)
    // {
    //     std::cout<<beg<<std::endl;
    //     beg++;
    // }

}