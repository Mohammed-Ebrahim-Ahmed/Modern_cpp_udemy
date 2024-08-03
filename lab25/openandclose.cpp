#include<iostream>
#include<fstream>
#include<string>
void write()
{
    std::ofstream out;
    out.open("text.txt");
    if(!out.is_open())
    {
        std::cout<<"Could not open the file"<<std::endl;
        return;
    }
    out<<"my name is mohammed"<<std::endl;
    out<<23<<std::endl;
    out.close();
}

void read()
{
    std::ifstream input;
    input.open("text.txt");
    // if(!input.is_open())
    // {
    //     std::cout<<"Could not open the file"<<std::endl;
    //     return;
    // }
    if(input.fail())
    {
        std::cout<<"Could not open the file"<<std::endl;
        return;        
    }
    std::string stringin;
    std::getline(input, stringin);
    int value{};
    input>>value;
    input>>value;
    if(input.eof())
    {
        std::cout<<"Reached the end of the file"<<std::endl;
    }
    if(input.good())
    {
        std::cout<<"I/O operation has successed"<<std::endl;
    }
    else
    {
        std::cout<<"I/O operation has failed"<<std::endl;
    }
    input.clear();
    input.setstate(std::ios::failbit);
    if(input.fail())
    {
        std::cout<<"failbit has been set"<<std::endl;
    }
    input.close();
    std::cout<<stringin<<":"<<value<<std::endl;
}

int main()
{
    write();
    read();
    return 0;
}