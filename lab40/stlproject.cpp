#include <iostream>
#include <set>
#include <algorithm>
typedef enum
{
    Friends,
    Family,
    Coworker,
    Acquaintance
} Group;
class Contact
{
public:
    Contact(const std::string &f, const std::string l,
            const std::string p, const std::string s, const std::string e,
            const std::string a, const std::string c, Group y) : first_name{f}, last_name{l},
                                                                 primary_no{p}, secondary_no{s}, email{e}, address{a}, compony{c}, yourgroup{y}
    {
    }
    void setFirstName(const std::string &f)
    {
        first_name = f;
    }
    void setLastName(const std::string &last_name)
    {
        this->last_name = last_name;
    }
    void setPrimaryNO(const std::string &p)
    {
        primary_no = p;
    }
    void setSecondaryNO(const std::string &s)
    {
        secondary_no = s;
    }
    void setEmail(const std::string &e)
    {
        email = e;
    }
    void setAddress(const std::string &a)
    {
        address = a;
    }
    void setCompony(const std::string &c)
    {
        compony = c;
    }
    void setGroup(const Group y)
    {
        yourgroup = y;
    }

    const std::string &getFirstName(void) const
    {
        return first_name;
    }
    const std::string &getLastName(void) const
    {
        return last_name;
    }
    const std::string &getPrimaryNO(void) const
    {
        return primary_no;
    }
    const std::string &getSecondaryNo(void) const
    {
        return secondary_no;
    }
    const std::string &getEmail(void) const
    {
        return email;
    }
    const std::string &getAddress(void) const
    {
        return address;
    }
    const std::string &getCompony(void) const
    {
        return compony;
    }
    const Group &getGroup(void) const
    {
        return yourgroup;
    }
    bool operator==(const Contact &c1)
    {
        return ((first_name == c1.getFirstName()) && (last_name == c1.getLastName()) && (primary_no == c1.getPrimaryNO()) &&
                (secondary_no == c1.getSecondaryNo()) && (email == c1.getEmail()) && (address == c1.getAddress()) && (compony == c1.getCompony()) &&
                (yourgroup == c1.getGroup()));
    }

private:
    std::string first_name;
    std::string last_name;
    std::string primary_no;
    std::string secondary_no;
    std::string email;
    std::string address;
    std::string compony;
    Group yourgroup;
};

class ContactSortFirstName
{
    public:
    bool operator()(const Contact &c1, const Contact &c2) const
    {
        return c2.getFirstName() > c1.getFirstName();
    }
};
class ContactFindFirstName{
    public:
    bool operator()(const Contact &c1) const
    {
        return c1.getFirstName() == "hala";
    }
};
class ContactSortLastName
{
public:
    bool operator()(const Contact &c1, const Contact &c2) const
    {
        return c2.getLastName() > c1.getLastName();
    }
};
bool compareCompony(const Contact& c1)
{
    return c1.getCompony() == "WeCan";
}
int main()
{
    std::multiset<Contact, ContactSortLastName> s1{
        {"mohammed", "Ebrahim", "+201110634210", "+201558322121", "mohammed@gmail.com", "mansoura", "WeCan", Family},
        {"amal", "Hassanin", "", "+201558322222", "amal@gmail.com", "cairo", "hamama", Family},
        {"eman", "Ebrahim", "+201112228889", "+202223334445", "eman@gmail.com", "alex", "sleepy", Friends},
        {"hala", "Ebrahim", "+201222333888", "+2", "hala@gmail.com", "domiata", "WeCan", Acquaintance}};

    std::for_each(s1.begin(), s1.end() , [](const Contact & c1)
    {
        if(!c1.getPrimaryNO().empty())
        {
            std::cout << c1.getFirstName() << std::endl;
        }
    });
    const std::string&& componyname = "WeCan";
    for_each(s1.begin(), s1.end(), [&componyname](const Contact & c1){
        if(c1.getCompony() == componyname)
        {
            std::cout << c1.getFirstName() << " " << c1.getLastName() << std::endl;
        }
        return false;
    }
    );
    for (const auto &x : s1)
    {
        std::cout << x.getFirstName() << " " << x.getLastName() << " " << x.getPrimaryNO() << " " << x.getSecondaryNo() << " " << x.getEmail() << " " << x.getAddress() << " " << x.getCompony() << " " << x.getGroup() << std::endl;
    }

    for(const auto &x : s1)
    {
        if(x.getGroup() == Acquaintance)
        {
            std::cout << x.getFirstName() << " " << x.getLastName() << std::endl;
        }
    }

    auto it = std::find_if(s1.begin(), s1.end(), [](const Contact & c1){
        return c1.getLastName() == "Ebrahim";
    });
    it = std::find_if(s1.begin(), s1.end(), ContactFindFirstName());

    std::cout << it->getFirstName() << " " <<it->getPrimaryNO() << std::endl;
    std::string com = "WeCan";
    auto gg = Family;
    std::cout << "****************************" << std::endl;
    for_each(s1.begin(), s1.end(), [&com, &gg](const Contact & c1)
    {
        if( (c1.getCompony() == com) && (c1.getGroup() == gg))
        {
            std::cout << c1.getFirstName() << " " << c1.getLastName() << std::endl;
        }
    });
    return 0;
}