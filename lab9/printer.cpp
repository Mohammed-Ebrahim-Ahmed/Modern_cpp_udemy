// #include <iostream>
// #include <memory>

// class Printer{
//     std::weak_ptr<int> m_value;

//     public:
//         void setValue(std::weak_ptr<int> value)
//         {
//             m_value = value;
//         }
//         const void print(void) const
//         {
//             if(!(m_value.expired()))
//             {
//                 auto sp = m_value.lock();
//                 std::cout<<"the value is"<<*sp<<std::endl;
//                 std::cout<<"ref count"<<sp.use_count()<<std::endl;
//             }
//             else
//             {
//                 std::cout<<"The object has expired!!!"<<std::endl;
//             }
            
//         }
// };

// int main()
// {
//     Printer pri{};  
//     int num;
//     std::cout<<"enter the num"<<std::endl;
//     std::cin>>num;
//     std::shared_ptr<int> p {new int{num}} ;
//     pri.setValue(p);
//     if(*p > 10)
//     {
//         p = nullptr;
//     }
//     pri.print();
//     return 0;
// }

#include <iostream>
#include <memory>

class Printer {
    std::shared_ptr<int> m_value;

public:
    void setValue(std::shared_ptr<int> value) {
        m_value = value;
    }

    void print() const {
        if (m_value) {
            std::cout << "The value is: " << *m_value << std::endl;
            std::cout << "Reference count: " << m_value.use_count() << std::endl;
        } else {
            std::cout << "The object has expired!" << std::endl;
        }
    }
};

int main() {
    Printer pri{};
    int num;
    std::cout << "Enter the number: " << std::endl;
    std::cin >> num;

    std::shared_ptr<int> p = std::make_shared<int>(num);
    pri.setValue(p);

    if (*p > 10) {
        p = nullptr;  // This decreases the reference count.
    }

    pri.print();
    return 0;
}
