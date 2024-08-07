#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <fstream>
#include <filesystem>

void Set()
{
    std::multiset<int> ss {10, 20, 30 , 40, 50, 70};

    ss.insert(80);
    ss.insert({90,100,1000});

    std::set<int>::iterator it = ss.begin();

    while(it != ss.end())
    {
        std::cout << *it << std::endl;
        it++;
    }

    it = ss.begin();
    it = ss.emplace_hint(it, 299);
    it = ss.emplace_hint(it, 888);

    auto p = ss.extract(30);
    ss.erase(20);

    for(const auto & x : ss)
    {
        std::cout << x << std::endl;
    }  

    auto ff = ss.find(40);

    if(ff != ss.end())
    {
        std::cout << *ff << " is found " << std::endl;
    }

    auto com = ss.key_comp();
    it = ss.begin();
    const int && num = 71;

    for(;com(*it, num); it++)
    {
        std::cout << *it << " is found" << std::endl;
    }

    auto first = ss.lower_bound(10);
    auto second = ss.upper_bound(50);

    ss.erase(first, second);

    for(auto const & a : ss)
    {
        std::cout << a << std::endl;
    }
    ss.insert(100);
    ss.insert(100);
    ss.insert(100);

    auto occur = ss.equal_range(100);
    auto count = 0;
    while(occur.first != occur.second)
    {
        count++;
        occur.first++;
    }
    std::cout <<"count is " << count << std::endl;
}

void Map()
{
    std::multimap<std::string, int> mp;
    mp.insert(std::make_pair("man", 20));
    mp.insert({"woman", 30});
    mp.insert(std::make_pair("child" , 10));
    // mp["child"] = 10;
    mp.erase("child");

    auto it = mp.begin();
    mp.emplace("man", 40);


    it = mp.begin();

    mp.emplace_hint(it, std::make_pair("man", 20));
    mp.emplace_hint(it, std::pair<std::string, int>("child", 10));
    it = mp.begin();
    while(it != mp.end())
    {
        std::cout << it->first << " " << it->second <<std::endl;
        it++;
    }
    auto lobound = mp.lower_bound("child");
    auto hobound = mp.upper_bound("man");

    for(auto it = lobound; it != hobound; it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
    auto foundnum = mp.find("child");
    if ( foundnum != mp.end())
    {
        std::cout << "Found 'child' with value: " << foundnum->second << std::endl;
    }
    else
    {
        std::cout << "'child' not found in the map" << std::endl;
    }

    mp.emplace("man", 20) ;

    auto p = mp.extract("child");

    mp.insert({{"one",20}, {"two", 20}, {"three", 30}});
    
    mp.emplace("man", 30);

    for(const auto & x : mp)
    {
        std::cout << x.first << " " << x.second << std::endl;
    }

    std::cout << "*************" << std::endl;
    auto com = mp.value_comp();
    it = mp.begin();
    auto ll = mp.find("two");
    while(com(*it, *ll ))
    {
        
        std::cout << it->first << " " << it -> second << std::endl;
        it++;
    }

    auto ff = mp.equal_range("man");
    int count = 0;
    while(ff.first != ff.second)
    {
        std::cout << ff.first->first << " " << ff.first->second << " " << ++count << std::endl;
        ff.first++;
    }
}

void Unset()
{
    std::unordered_multiset<std::string> s1;

    s1.insert("pizze");
    s1.insert("burger");
    s1.insert("mozaralla");
    s1.insert("french fries");
    s1.insert("koshrie");
    s1.insert("cola");
    s1.insert("shrimp");

    std::unordered_set<std::string>::iterator it = s1.begin();

    while(it != s1.end())
    {
        std::cout << "bucket #" << s1.bucket(*it) << " " << *it << std::endl;
        it++;
    }
    s1.rehash(20);
    std::cout << "**************************" << std::endl;
    it = s1.begin();
    s1.erase("cola");
    s1.insert("shrimp");
    s1.insert("shrimp");
    while(it != s1.end())
    {
        std::cout << "bucket #" << s1.bucket(*it) << " " << *it << std::endl;
        it++;
    }
    std::cout << "no of elements "<< s1.size() << std::endl;
    std::cout << "bucket count "<< s1.bucket_count() << std::endl;
    std::cout << "load factor " << s1.load_factor() << std::endl;
}

void Unmap()
{
    std::unordered_map<std::string, int> mp;
    mp.insert(std::make_pair("mohammed", 0));
    mp.emplace("Eman", 1);
    mp.try_emplace("amal", 2);
    mp["Ebrahim"] = 3;

    for(auto const & a : mp)
    {
        std::cout << "bucket #" << mp.bucket(a.first) << " " <<a.first << " " << a.second << std::endl;
    }

}

class Employee{
    public:
        // Employee()
        // {
        //     id =0;
        //     name = "";
        //     lan = "";
        // }
        Employee(std::string && name, int && id, std::string && lan) : name{name}, id{id}, lan{lan}
        {

        }
        const std::string& getName() const
        {
            return name;
        }
        int getId() const
        {
            return id;
        }
        const std::string& getLanguage() const
        {
            return lan;
        }
        bool operator< ( const Employee& e2)
        {
            return this->getId() > e2.getId(); 
        }
    private:
        std::string name;
        int id;
        std::string lan;
};

class EmployeeHasher{
    public:
        size_t operator() (const Employee& e1) const
        {
            size_t seed = 0;

            auto h1 = std::hash<std::string>{}(e1.getName());
            auto h2 = std::hash<int>{}(e1.getId());
            return h1^h2;
        }
};

class EmployeeEquality{
    public:
        bool operator()(const Employee& e1, const Employee& e2) const
        {
            return (e1.getId() == e2.getId()) && (e1.getName() == e2.getName());
        }
};

struct EmployeeCompare{
    bool operator()(const Employee & e1) const
    {
        return e1.getLanguage() == "c++";
    }
};
int main()
{
    // std::unordered_map<Employee, std::string, EmployeeHasher, EmployeeEquality> mp;
    
   std::vector<Employee> vec {
        Employee{"mohammed", 22, "c++"},
        Employee{"hala", 30, "c++"},
        Employee {"fares", 33, "Java"}
   };


    std::sort(vec.begin(), vec.end(), [](const Employee & e1, const Employee & e2){
        return e2.getId() < e1.getId();
    });

   for(auto const & x : vec)
   {
        std::cout<<x.getName() << " " << x.getId() << " "<< x.getLanguage() << std::endl;
   }
   auto count = std::count_if(vec.begin(), vec.end(), EmployeeCompare());
    std::cout << count << std::endl;

    auto it = std::find_if(vec.begin(), vec.end(), [](const Employee & e1){
        return e1.getLanguage() == "Java";
    });

    if(it != vec.end())
    {
        std::cout << "Java programmer found" << it->getId() << " "<<it->getName() << std::endl;
    }
    std::vector<int> vec2{20,39,11,99,33};
    std::erase(vec2,20);

    std::map <std::string,int> mp{
        {"ma", 20},
        {"ha", 60},
        {"eb", 99}
    };
    auto node = mp.extract("ma");
    // node.key()[0] = 'M';
    node.key()[0] = 'M';
    mp.insert(std::move(node));
    for(auto ele : mp)
    {
        std:: cout << ele.first << " " << ele.second << std::endl;
    }
    // auto find = mp.find("ma");
    // std::string name = find->first;
    // name[0] = 'M';
    // mp.erase(find);
    // mp[name]= 90;
    // std::set<int> s1{1,2,3,4,5};
    // bool what = mp.contains("ma");
    // if(what)
    // {
    //     std::cout << "element found" << std::endl;
    // }
    // mp[Employee{"mohammed", 22, "c++"}] = "first";
    // mp[Employee{"hala", 30, "c++"}] = "second"; 
    // mp[Employee {"fares", 33, "Java"}] = "third";

    // std::sort(mp.begin(), mp.end(), [](const Employee & e1, const Employee & e2){
    //     return e1.getId() > e2.getId();
    // });
    // for(auto const & f: mp)
    // {
    //     std::cout << "bucket #" << mp.bucket(f.first) << f.first.getId() << " " << f.first.getName() << " " << f.first.getLanguage() << " " << f.second << std::endl;
    // }
    // Set();
    // Map();
    // Unset();
    // Unmap();
    // std::ifstream input{"associative.cpp"};

    // if(!input)
    // {
    //     std::cout << "file does not exist" << std::endl;
    //     return -1;
    // }
    // auto size = std::filesystem::file_size("associative.cpp");
    // std::vector<char> words;
    // words.resize(size);
    // char word[2000];
    // input.read(words.data(), size);

    // std::cout << words.data() << std::endl;
    return 0;
}