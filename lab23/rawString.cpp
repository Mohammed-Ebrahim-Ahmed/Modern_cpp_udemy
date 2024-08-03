#include "iostream"
#include "string"
int main()
{
    std::string filename(R"(C:\temp\file.c)");
    std::cout<<filename<<std::endl;
    std::string rawname(R"(my name is "mohammed")");
    std::cout<<rawname<<std::endl;
    return 0;
}