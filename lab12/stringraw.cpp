#include <iostream>
#include <cstring>
#include <string>

// char * Combine (const char* pFirst, const char* pLast)
// {
//     char * fullname = new char [strlen(pFirst)+strlen(pLast)+1];
//     strcpy(fullname,pFirst);
//     strcat(fullname, pLast);
//     return fullname;
// }

std::string combine(const std::string& first, const std::string& second)
{
    std::string fullname = first + second;
    return fullname;
}
std::string ToUpper(const std::string& str)
{
    return strupr((char*)(str.c_str()));
}
std::string ToLower(const std::string& str)
{
    return strlwr((char*)(str.c_str()));
}
int main()
{
    // char first[10];
    // char last[10];
    // std::cin.getline(first, 10);
    // std::cin.getline(last, 10);

    // const char * fullname = Combine(first, last);

    // // delete[] fullname;
    // std::cout<<fullname<<std::endl;
    // std::string s = "Hello";
    // s[0] = 'w';
    // //char ch = s[0];
    // std::cout << s << std::endl;
    // std::cin >> s ;
    // std::getline(std::cin, s);
    // std::cout<<s.length()<<std::endl;

    std::string first ,last;

    std::getline(std::cin, first);
    std::getline(std::cin, last);

    std::string fullname = combine(first, last);
    std::cout<<fullname<<std::endl;
    printf("%s\n",first.c_str());
    std::cout<<ToLower(first)<<std::endl;
    std::cout<<ToUpper(last)<<std::endl;
    // std::string first;
    // std::string last;
    // std::getline(std::cin,first);
    // std::getline(std::cin, last);


    // std::string fullname = Combine(first, last);
    // std::cout<<fullname<<std::endl;
    // std::string s1{"hello"}, s2 {"world"};
    // s = s1+s2;
    // s+= s1;
    // s.insert(6, "world");

    // if(s1 != s2)
    // {

    // }

    // // s.erase();
    // // s.erase(0,5);
    // // s.clear();

    // auto pos = s.find("world", 4);
    // if(pos != std::string::npos)
    // {
    //     std::cout<<"String is found";
    // }


}

// void UsingStdString()
// {
//         //initializtion
//     std::string first {"mohammed"};
//     std::string seconde = "nader";
//     std::string third("Mohsen");

//     using namespace std::string_literals;

//     auto fourth = "said"s;

//     //Access
    
//     first[0] = 'L';
//     char c = seconde[2];

//     std::cout<< first <<std::endl;
//     std::cin >> first;
//     //size
//     auto size = first.length();

//     //insert
//     std::string s1 {"yassin"}, s2{"karim"};

//     std::string s = s1 + s2;
//     s += s1;

//     s.insert(6,"fady");

//     //comparsion
//     if(s1 != s2)
//     {
//         std::cout<<"They are not the same"<<std::endl;
//     }

//     s.erase(0,2);
//     s.clear();


//     //search
//     auto pos = s.find("fady",0);

//     if(pos != std::string::npos)
//     {
//         //found
//     }

    
// }