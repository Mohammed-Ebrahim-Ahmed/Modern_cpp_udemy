#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
enum class Case{SENSITIVE, INSENSITIVE};
 
size_t Find(const std::string &source,         //Source string to be searched
const std::string &search_string,  //The string to search for
 Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
 size_t offset = 0 ) {                //Start the search from this offset
     //Implementation
 
     /*
     return position of the first character 
     of the substring, else std::string::npos
     */
    auto loc_pos = -1;
    auto pos_return = -1;
    std::string source_lwr = source;
    std::string search_string_lwr = search_string;
    switch (searchCase)
    {
        case Case::SENSITIVE:
            loc_pos = source.find(search_string,offset);
            break;

        case Case::INSENSITIVE:
            if(searchCase == Case::INSENSITIVE)
            {
                strlwr((char *)source_lwr.c_str());
                strlwr((char *)search_string_lwr.c_str());
            }
            loc_pos = source_lwr.find(search_string_lwr,offset);
            break;
        default:
            break;
    }
    if(loc_pos != (int)std::string::npos)
    {
        pos_return = loc_pos;
    }
    else
    {
        pos_return = (int)std::string::npos;
    }
    return pos_return;
}
 
std::vector<int>
FindAll(
 const std::string &target,              //Target string to be searched
 const std::string &search_string,       //The string to search for
 Case searchCase = Case::INSENSITIVE,    //Choose case sensitive/insensitive search
 size_t offset = 0) {                    //Start the search from this offset
     //Implementation
 
    /*
    Return indices of found strings,
    else an empty vector
    */
    auto loc_pos = -2;
    std::string target_lwr = target;
    std::string search_string_lwr = search_string;
    std::vector<int> pos_return ;
    while(loc_pos != (int)std::string::npos)
    {
        switch (searchCase)
        {
            case Case::SENSITIVE:
                loc_pos = target.find(search_string,offset);
                if(loc_pos != (int)std::string::npos)
                {
                    pos_return.push_back(loc_pos);
                    offset = loc_pos+1;
                }
                break;

            case Case::INSENSITIVE:
                strlwr((char *)target_lwr.c_str());
                strlwr((char *)search_string_lwr.c_str());
                loc_pos = target_lwr.find(search_string_lwr,offset);
                if(loc_pos != (int)std::string::npos)
                {
                    pos_return.push_back(loc_pos);
                    offset = loc_pos+1;
                }
                break;
            default:
                break;
        }
    }


    return pos_return;
}

int main()
{
    // int a{1}, b{2};
    // int sum = a+b;

    // //std::string s = "sum of " + a + " & " + b " is: "+ sum::std::endl;
    // std::stringstream ss;
    // ss << "sum of " << a << " & "<< b <<" is "<< sum <<std::endl;
    // std::string s = ss.str();
    // std::cout<< s<<std::endl;

    // // ss.str("");
    // // ss<<sum;
    // // s = ss.str();
    // auto ssum = std::to_string(sum);
    // std::cout<< ssum<<std::endl;

    // std::string data = "12,,89,,21";
    // int a;
    // std::stringstream ss;
    // ss.str(data);

    // while(std::getline(ss,data,','))
    // {
    //     std::stringstream converter(data);
    //     if(!data.empty())
    //     {
    //         converter>>a;
    //         std::cout<<a<<std::endl;
    //     }

    //     //ss.ignore(); 
    // }

    std::string source = "worldhelloworldhelloworld";
    std::string searchString = "world";

    std::vector<int> pos = FindAll(source, searchString, Case::SENSITIVE, 5);
    for(auto posele : pos)
    {
        if(posele != (int)std::string::npos)
        {
            std::cout<< source<< " is found at index: "<<posele<<std::endl;
        }     
    }

}