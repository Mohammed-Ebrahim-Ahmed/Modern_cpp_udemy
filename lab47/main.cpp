#include <iostream>
#include <array>
#include <optional>
#include <variant>

template <typename T>
void check(const T &part)
{
    if constexpr (std::is_pointer_v<T>)
    {
        std::cout << *part << std::endl;
    }
    else if constexpr (std::is_array_v<T>)
    {
        for (auto x : part)
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << part << std::endl;
    }
}

template <typename T>

std::string to_String(const T &ele)
{
    if constexpr (std::is_arithmetic_v<T>)
    {
        return std::to_string(ele);
    }
    else
    {
        return std::string{ele};
    }
}

void checkCppVersion()
{
    if constexpr (__cplusplus == 201103L)
    {
        std::cout << "C++ 2011 is used" << std::endl;
    }
    else if constexpr (__cplusplus == 201402L)
    {
        std::cout << "C++ 2014 is used" << std::endl;
    }
    else if constexpr (__cplusplus == 201703L)
    {
        std::cout << "C++ 2017 is used" << std::endl;
    }
    else if constexpr (__cplusplus == 202002L)
    {
        std::cout << "C++ 2020 is used" << std::endl;
    }
    else
    {
        std::cout << "other standard is used" << std::endl;
    }
}

std::optional<std::string> printdummy(int x)
{
    if (x == 1)
    {
        return "value is one";
    }
    else
    {
        return std::nullopt;
    }
}

class Fullname
{
public:
    Fullname(std::string first, std::optional<std::string> second, std::string third) : firstname{first}, middlename{second}, lastname{third}
    {
    }
    std::string getFullname()
    {
        if (middlename.has_value())
        {
            return (firstname + middlename.value() + lastname);
        }
        else
        {
            return firstname + lastname;
        }
    }

private:
    std::string firstname;
    std::optional<std::string> middlename;
    std::string lastname;
};

class Number
{

public:
    Number() = default;
    Number(const int &num) : num{num}
    {
        std::cout << "parameterized constructor" << std::endl;
    }
    Number(const Number &myNumber)
    {
        std::cout << "copy constructor " << std::endl;
    }
    Number(Number &&myNumber) noexcept
    {
        std::cout << "move constructor " << std::endl;
    }
    Number &operator=(const Number &myNumber)
    {
        if (this != &myNumber)
        {
            std::cout << "copy assignment is called" << std::endl;
        }
        return *this;
    }
    Number &operator=(Number &&myNumber) noexcept
    {
        if (this != &myNumber)
        {
            std::cout << "move assignment is called" << std::endl;
        }
        return *this;
    }

    void setNumber(const int &x)
    {
        num = x;
    }

    int getNumber() const
    {
        return num;
    }

private:
    int num;
};
class Vistor
{
public:
    void operator()(const int &num) const
    {
        std::cout << num << std::endl;
    }
    void operator()(const std::string &string) const
    {
        std::cout << string << std::endl;
    }
    void operator()(const Number &num) const
    {
        std::cout << num.getNumber() << std::endl;
    }
};

class Modifier
{
public:
    void operator()(int &num) const
    {
        num += 2;
    }
    void operator()(std::string &string) const
    {
        string += "mystring";
    }
    void operator()(Number &num) const
    {
        num.setNumber(9);
    }
};
int main()
{
    int a{3};
    check(a);
    check(&a);
    int arr[5]{1, 2, 3, 4, 5};
    check(arr);
    std::string name = to_String(2);
    std::cout << name << std::endl;
    checkCppVersion();

    std::optional op{3};
    if (op)
    {
        std::cout << op.value() << std::endl;
    }
    else
    {
        std::cout << "the value has not been set yet" << std::endl;
    }

    std::optional val = printdummy(2);

    if (val.has_value())
    {
        std::cout << "it has a variable one" << std::endl;
    }
    else
    {
        std::cout << "no you haven't pass one" << std::endl;
    }

    Fullname myname{"mohammed", std::nullopt, "hassanein"};

    std::optional<std::string> opp{std::nullopt};

    std::cout << opp.value_or("The opp does not have a specific value") << std::endl;

    std::cout << myname.getFullname() << std::endl;

    try
    {

        std::variant<std::string, int> v{2};

        auto index = v.index();

        std::cout << index << std::endl;
        std::get<1>(v) = 9;

        auto funnn = std::get<1>(v);

        auto p = std::get_if<std::string>(&v);
        if (p)
        {
            std::cout << *p << std::endl;
        }
        else
        {
            std::cout << "pointing to null " << std::endl;
        }
        std::cout << funnn << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "********************************" << std::endl;
    std::variant<std::string, int, Number> v2v{Number{29}};

    // v2v = 9;

    std::get<Number>(v2v) = 39;

    v2v.emplace<Number>(99);
    std::visit(Modifier{}, v2v);

    std::visit(Vistor{}, v2v);

    v2v = "fine";
    std::visit(Modifier{}, v2v);
    std::visit(Vistor{}, v2v);

    v2v = 9;
    std::visit(Modifier{}, v2v);
    std::visit(Vistor{}, v2v);
    return 0;
}