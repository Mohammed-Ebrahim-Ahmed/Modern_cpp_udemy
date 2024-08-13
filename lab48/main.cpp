#include <iostream>
#include <any>
#include <string_view>

class Number
{

public:
    Number(int x) : x{x}
    {
        std::cout << "Parameterized constructor is called" << std::endl;
    }
#ifdef deleted_copy_move_cons
    Number(const Number &) = delete;
    Number(Number &&) = delete;
#endif
#ifndef deleted_copy_move_cons
    Number(const Number &num) : x{num.x}
    {
        std::cout << "Copy constructor" << std::endl;
    }

    Number(Number &&num) : x{num.x}
    {
        std::cout << "move constructor is called" << std::endl;
        num.x = 0;
    }
    Number &operator=(const Number &other)
    {
        if (this != &other)
        {
            x = other.x;
        }
        return *this;
    }

    Number &operator=(Number &&other)
    {
        if (this != &other)
        {
            x = other.x;
            other.x = 0;
        }
        return *this;
    }
    int getValue() const
    {
        return x;
    }
#endif
private:
    int x;
};
#pragma region Example1
void stringDisplay(std::string_view myCustomString, char c)
{

    for(auto ch : myCustomString)
    {
        std::cout << c ;
    }

    std::cout << std::endl;
    std::cout << myCustomString;
}
#pragma endregion

#pragma region Example2

#pragma region Example3

class Person{

    public:
        Person(std::string  name) : name{std::move(name)}
        {

        }
        void print() const
        {
            std::cout << name << std::endl;
        }

    private:
        std::string name;
};

Person createPerson(std::string_view name)
{
    std::string n{name};
    Person p{n};
    return p;
}

void withClass()
{
    using namespace std::string_literals;
    // Person p{"Ebrahim"s};

    Person p {"fact"};
    p.print();
}

#pragma endregion
enum class Title{MR, MRS, MS};
std::string& CombineName(std::string& name, std::string_view last, Title s)
{
    switch (s)
    {
    case Title::MR :
        name.insert(0, "MR.");
        break;
    
    case Title::MRS:
        name.insert(0, "MRS.");
        break;

    case Title::MS:
        name.insert(0, "MS.");
        break;
    }

    name += last;

    return name;
}

#pragma endregion
int main()
{
    using namespace std::string_literals;
    // std::any num = 9;
    // num.reset();
    // num = "this fine"s;

    // if(num.has_value())
    // {
    //     if (num.type() == typeid(int))
    //     {
    //         std::cout << std::any_cast<int>(num) << std::endl;
    //     }
    //     else if (num.type() == typeid(std::string))
    //     {
    //         std::cout << std::any_cast<std::string>(num) << std::endl;
    //     }
    // }

    Number num{9};
    auto num2 = std::make_any<Number &>(num);

    num = 10;

    std::any n1 = Number{9};
    auto &n2 = std::any_cast<Number &>(n1);
    n1 = Number{10};

    std::cout << std::any_cast<Number>(n1).getValue() << std::endl;

    std::any p = std::any_cast<Number>(&n1);

    std::cout << p.type().name() << std::endl;
    std::cout << (std::any_cast<Number*>(p))->getValue() << std::endl;
    // try{
    //     std::cout << std::any_cast<Number>(num2).getValue()<< std::endl;
    // }catch(std::exception & ex)
    // {
    //     std::cout << ex.what() << std::endl;
    // }
    // try
    // {
    //     std::cout << std::any_cast<std::string>(num) << std::endl;
    // }catch(std::exception & ex)
    // {
    //     std::cout << ex.what() << std::endl;
    // }
    using namespace std::string_view_literals;
    std::string_view sv{"like"};

    std::string fact{"fried"};

    std::string_view sv2{fact};

    std::cout << sv2 << std::endl;

    std::cout << sv << std::endl;

    auto sv3 = "i like burger"sv;

    std::cout << sv3 << std::endl;
    std::cout << sv3.size() << std::endl;
    std::cout << sv3.length() << std::endl;

    std::cout << sv3[9] << std::endl;
    std::cout << sv3.at(3) << std::endl;

    if(auto loc = sv3.find("burger"); loc != std::string::npos)
    {
        sv3.remove_suffix(loc);
        std::cout << sv3 << std::endl;
    }

    std::string_view sub = std::string{sv3.substr(0,10)};

    std::cout << sv3.data() << std::endl;

    stringDisplay("hello from the other size", '?');
    std::string name = "first";
    std::cout << CombineName(name, "second", Title::MR);
    createPerson("mohammed").print() ;

    withClass();
}
