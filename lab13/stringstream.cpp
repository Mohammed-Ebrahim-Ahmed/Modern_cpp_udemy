#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <optional>

enum class Case{SENSITIVE, INSENSITIVE};
 
// size_t Find(const std::string &source,         //Source string to be searched
// const std::string &search_string,  //The string to search for
//  Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
//  size_t offset = 0 ) {                //Start the search from this offset
//      //Implementation
 
//      /*
//      return position of the first character 
//      of the substring, else std::string::npos
//      */
//     auto loc_pos = -1;
//     auto pos_return = -1;
//     std::string source_lwr = source;
//     std::string search_string_lwr = search_string;
//     switch (searchCase)
//     {
//         case Case::SENSITIVE:
//             loc_pos = source.find(search_string,offset);
//             break;

//         case Case::INSENSITIVE:
//             if(searchCase == Case::INSENSITIVE)
//             {
//                 strlwr((char *)source_lwr.c_str());
//                 strlwr((char *)search_string_lwr.c_str());
//             }
//             loc_pos = source_lwr.find(search_string_lwr,offset);
//             break;
//         default:
//             break;
//     }
//     if(loc_pos != (int)std::string::npos)
//     {
//         pos_return = loc_pos;
//     }
//     else
//     {
//         pos_return = (int)std::string::npos;
//     }
//     return pos_return;
// }

// std::optional<int> FindString(std::string & source , std::string & string, int offest, Case searchCase = Case::INSENSITIVE)
// {

//     std::optional<int> pos;
//     int local_pos ;
//     switch(searchCase)
//     {
//         case Case::SENSITIVE:

//             local_pos = string.find(source, offest);

//             break;
//         case Case::INSENSITIVE:

//             std::transform(source.begin(), source.end(), source.begin(), [](char c){
//                 return std::tolower(c);
//             });
//             std::transform(string.begin(), string.end(), string.begin(), [](char c){
//                 return std::tolower(c);
//             });
//             local_pos = string.find(source, offest);
//             break;

//         default:
//             break;
//     }
//     if(local_pos != std::string::npos)
//     {
//         pos = local_pos;
//     }
//     return pos;
// }

// std::optional<std::vector<int>> FindAllString(std::string & source , std::string & string, int offest, Case searchCase = Case::INSENSITIVE)
// {
//     std::vector<int> temp_pos;
//     std::optional<std::vector<int>> pos;
//     int local_pos = 0 ;
//     switch(searchCase)
//     {
//         case Case::SENSITIVE:

//             while(local_pos != static_cast<int>(std::string::npos))
//             {
//                 local_pos = string.find(source, offest+local_pos);
//                 if(local_pos != static_cast<int>(std::string::npos))
//                     temp_pos.emplace_back(local_pos);                
//             }

//             break;
//         case Case::INSENSITIVE:

//             std::transform(source.begin(), source.end(), source.begin(), [](char c){
//                 return std::tolower(c);
//             });
//             std::transform(string.begin(), string.end(), string.begin(), [](char c){
//                 return std::tolower(c);
//             });
//             while(local_pos != static_cast<int>(std::string::npos))
//             {
//                 local_pos = string.find(source, offest+local_pos);
//                 if(local_pos != static_cast<int>(std::string::npos))
//                     temp_pos.emplace_back(local_pos);                
//             }
//             break;

//         default:
//             break;
//     }
//     if(!temp_pos.empty())
//     {
//         pos = temp_pos;
//     }
//     return pos;
// }
// std::vector<int>
// FindAll(
//  const std::string &target,              //Target string to be searched
//  const std::string &search_string,       //The string to search for
//  Case searchCase = Case::INSENSITIVE,    //Choose case sensitive/insensitive search
//  size_t offset = 0) {                    //Start the search from this offset
//      //Implementation
 
//     /*
//     Return indices of found strings,
//     else an empty vector
//     */
//     auto loc_pos = -2;
//     std::string target_lwr = target;
//     std::string search_string_lwr = search_string;
//     std::vector<int> pos_return ;
//     while(loc_pos != (int)std::string::npos)
//     {
//         switch (searchCase)
//         {
//             case Case::SENSITIVE:
//                 loc_pos = target.find(search_string,offset);
//                 if(loc_pos != (int)std::string::npos)
//                 {
//                     pos_return.push_back(loc_pos);
//                     offset = loc_pos+1;
//                 }
//                 break;

//             case Case::INSENSITIVE:
//                 strlwr((char *)target_lwr.c_str());
//                 strlwr((char *)search_string_lwr.c_str());
//                 loc_pos = target_lwr.find(search_string_lwr,offset);
//                 if(loc_pos != (int)std::string::npos)
//                 {
//                     pos_return.push_back(loc_pos);
//                     offset = loc_pos+1;
//                 }
//                 break;
//             default:
//                 break;
//         }
//     }


//     return pos_return;
// }

int main()
{
    // int a{1}, b{2};
    // int sum = a+b;

    //std::string s = "sum of " + a + " & " + b " is: "+ sum::std::endl;
    // std::stringstream ss;
    // ss << "sum of " << a << " & "<< b <<" is "<< sum;
    // std::string s = ss.str();
    // std::cout<< s<<std::endl;

    // ss.str("");
    // ss<<sum;
    // s = ss.str();
    // std::cout << s << std::endl;
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

    // std::string source = "worldhelloworldhelloworld";
    // std::string searchString = "world";

    // std::vector<int> pos = FindAll(source, searchString, Case::SENSITIVE, 5);
    // for(auto posele : pos)
    // {
    //     if(posele != (int)std::string::npos)
    //     {
    //         std::cout<< source<< " is found at index: "<<posele<<std::endl;
    //     }     
    // }
    std::string name = "ebrahim";
    std::string find = "mohammedebrahimahmedebrahim";
    auto pos = FindAllString(name ,find , 2, Case::SENSITIVE);

    if(pos.has_value())
    {
        for(const auto & ele : pos.value())
        {
            std::cout << ele << std::endl;
        }
    }

}