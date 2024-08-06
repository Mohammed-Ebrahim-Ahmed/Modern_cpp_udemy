#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>


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
int main()
{

    // Set();
    // Map();
    // Unset();
    Unmap();
    return 0;
}