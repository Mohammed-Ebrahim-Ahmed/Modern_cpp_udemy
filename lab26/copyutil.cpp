#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <sstream>

using namespace std::filesystem;
bool ConfirmOveride(path& p)
{
    if(exists(p) && is_regular_file(p))
    {
        std::cout<<"The file exists do you want to override it (Y/N)"<<std::endl;
        char repsonse;
        std::cin >> repsonse;
        return (repsonse == 'y' || repsonse == 'Y');
    }
    return true;
}
std::stringstream readData(path& p)
{   
    std::stringstream mystream{};
    std::ifstream sourcefile{p};
    if (!sourcefile.is_open()) {
        std::cout << "Failed to open the source file" << std::endl;
        return mystream;
    }
    mystream << sourcefile.rdbuf();
    sourcefile.close();
    return mystream;
}
void writeData(path& p, std::stringstream& ss )
{
    std::ofstream distfile{p};
    if (!distfile.is_open()) {
        std::cout << "Failed to open the dist file" << std::endl;
        return ;
    }
    distfile << ss.rdbuf();
    distfile.close();
}
void writeBin(path& p, std::stringstream& ss )
{
    if(!ConfirmOveride(p))
    {
        std::cout<<"you can't proceed with this operation";
        return;
    }
    std::ofstream distfile{p, std::ios::out | std::ios::binary};
    if (!distfile.is_open()) {
        std::cout << "Failed to open the dist file" << std::endl;
        return ;
    }
    std::string myString = ss.str();
    std::size_t length = myString.size();
    distfile.write(myString.data(), length);
    distfile.close();
}

std::string readBin(path& p, size_t length)
{
    std::string mystream(length,'\0');
    std::ifstream sourcefile{p};
    if (!sourcefile.is_open()) {
        std::cout << "Failed to open the source file" << std::endl;
        return mystream;
    }
    sourcefile.read((char*)&mystream[0], length);
    sourcefile.close();
    return mystream;    
}
int main() {
    std::string mysource;
    std::string mydist;
    std::cout<<"Enter the source directory: ";
    std::cin>>mysource;
    std::cout<<"Enter the distination directory: ";
    std::cin>>mydist;
    path source{current_path()};
    source /= mysource;

    path dist{current_path()};
    dist /= mydist;

    std::string buffer = readBin(source, 9);
    std::stringstream outbuffer(buffer);
    writeBin(dist, outbuffer);
    return 0;
}
