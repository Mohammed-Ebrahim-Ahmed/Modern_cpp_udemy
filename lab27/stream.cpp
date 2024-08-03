#include <iostream>
#include <fstream>
#include <string>

void write(){

    std::ofstream out("test.txt");
    if(!out)
    {
        std::cout<<"Could not open the file for reading"<<std::endl;
        return;
    }
    std::string message{"C++ was invented by Bjarne"};
    out.seekp(2);
    for(char &ch: message)
    {
        out.put(ch);
    }

}

void read(){
    std::ifstream inp("test.txt");
    if(!inp)
    {
        std::cout<<"Could not read the file please try again"<<std::endl;
        return;
    }
    inp.seekg(9);
    std::string message;
    std::getline(inp, message);
    std::cout<<message<<std::endl;
    inp.seekg(3, std::ios::beg);
    std::cout<<"current position is "<<inp.tellg()<<std::endl;
    char ch{};
    while(inp.get(ch))
    {
        std::cout<<ch;
    }
}

void usingfstream()
{
    std::fstream stream{"test.txt"};
    if(!stream)
    {
        std::ofstream out{"test.txt"};
        out.close();
        stream.open("test.txt");
    }
    std::string message("Hello from the other side");
    stream<<message;
    stream.seekg(0);
    std::getline(stream, message);
    std::cout<<message<<std::endl;
    stream.close();
}
int main()
{
    // write();
    // read();
    usingfstream();
    return 0;
}