#include<iostream>
#include<cstring>
#include<string>


const char* Combine(const char* a, const char* b)
{
    char* result = new char[strlen(a) + strlen(b) +1];
    strcpy(result, a);
    strcat(result, b);
    return result;
}

std::string Combine(const std::string& a, const std::string& b)
{
    std::string result = a+" "+b;
    return result;
}
int main()
{
    // char first [10] = "name";
    // char second [10] = "fun";
    // std::cin.getline(first, 10);
    // std::cin.getline(second, 10);
    // const char* pname = Combine((const char*)first, (const char*)second);
    // std::cout<< pname<<std::endl;
    // delete[] pname;


    std::string first;
    std::string second;

    std::getline(std::cin, first);
    std::getline(std::cin, second);

    // std::string fullname = first + " " + second;
    std::string fullname = Combine(first, second);
    std::cout<<fullname << std::endl;
    printf("%s", fullname.c_str());

    // std::uint16_t nice = 1999u;
    using namespace std::string_literals;
    std::string mocking = "Uname mohsen"s;
    // std::string s = "hello";
    // std::string str = "world";
    // s[0] = 'w';
    // char ch = s[0];

    // std::cout<<s<<std::endl;
    // std::cin>>s;
    // std::cout<<s<<std::endl;
    // std::getline(std::cin, s);

    // s.length();
    // std::string result_string {" "};

    // result_string = s+str;

    // std::cout<<result_string<<std::endl;

    // result_string += result_string;

    // std::cout<<result_string<<std::endl;;
    // s = "fawzy";
    // s.insert(2,"mohsen");
    // if(s != str)
    // {

    // }
    // s = "lnln";
    // str = "nader";
    // //str.erase('a');
    // str.clear();
    // s.erase(0,2);
    // auto pos = str.find("er",0);

    // if(pos != std::string::npos)
    // {

    // }
    return 0;
}