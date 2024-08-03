#include <iostream>
#include <vector>
template<typename T, int columns>
class PrettyPrinter {

    public:
        PrettyPrinter(T *ptr) : m_ptr{ptr}
        {
        }

        void Print()
        {
            std::cout << "The no of columns is "<< columns << std::endl;
            std::cout << "Pretty Printer" << *m_ptr << std::endl;
        }

        T* getValue()
        {
            return m_ptr;
        }
    private:
        T *m_ptr;
};

template<typename T>
class PrettyPrinter< T, 80> {

    public:
        PrettyPrinter(T *ptr) : m_ptr{ptr}
        {
        }

        void Print()
        {
            std::cout << "The no of columns is 80 ** "<< 80 << std::endl;
            std::cout << "Pretty Printer" << *m_ptr << std::endl;
        }

        T* getValue()
        {
            return m_ptr;
        }
    private:
        T *m_ptr;
};
template<int columns>
class PrettyPrinter<char*, columns> {

    public:
        PrettyPrinter(char *ptr) : m_ptr{ptr}
        {
        }

        void Print()
        {
            std::cout << "Pretty Printer" << m_ptr << std::endl;
        }

        char* getValue()
        {
            return m_ptr;
        }
    private:
        char *m_ptr;
};

template<int columns>
class PrettyPrinter<std::vector<int>, columns >{

    public:
        PrettyPrinter(std::vector<int> *ptr) : m_ptr{ptr}
        {
        }

        void Print()
        {
            for(const auto& x : *m_ptr)
            {
                std::cout<< "Pretty Printer "<< x<<std::endl;
            }
        }

        std::vector<int>* getValue()
        {
            return m_ptr;
        }
    private:
        std::vector<int> *m_ptr;
};


// template<int columns>
// void PrettyPrinter<std::vector<int>, columns>::Print()
// {
//     for(const auto& x : *m_ptr)
//     {
//         std::cout<< "Pretty Printer "<< x<<std::endl;
//     }  
// }

// template<int columns>
// void PrettyPrinter<std::vector<std::vector<int>>>::Print()
// {
//     for(const auto& x : *m_ptr)
//     {
//         //std::cout<< "Pretty Printer "<< x<<std::endl;
//         for(const auto& y : x)
//         {
//             std::cout<< "Pretty Printer " << y << std::endl;
//         }
//         std::cout<< "here we go again"<< std::endl;
//     }  
// }
template< typename T>
class SmartPointer {

    public:
        SmartPointer(T* ptr) : m_ptr{ptr}
        {

        }

        T& operator *()
        {
            return *m_ptr;
        }
        T* operator ->()
        {
            return m_ptr;
        }
        ~SmartPointer()
        {
            delete m_ptr;
        }
    private:
        T* m_ptr;
};

template< typename T>
class SmartPointer<T[]> {

    public:
        SmartPointer(T* ptr) : m_ptr{ptr}
        {

        }

        T& operator [](int index)
        {
            return m_ptr[index];
        }
        ~SmartPointer()
        {
            delete m_ptr;
        }
    private:
        T* m_ptr;
};
int main()
{
    int x = 20;
    float y = 1.9f;

    PrettyPrinter<int, 80> p{&x};
    p.Print();
    std::cout<<p.getValue()<<std::endl;

    PrettyPrinter<float, 20> p2{&y};
    p2.Print();
    std::cout<<p2.getValue()<<std::endl;

    char* mychar{"My name is mohammed"};
    PrettyPrinter<char*, 30> p3{mychar};
    p3.Print();
    std::cout << p3.getValue()<<std::endl;

    std::vector<int> values = {1, 2, 3, 4, 5};
    PrettyPrinter<std::vector<int>, 40> p4{&values};
    p4.Print();
    std::cout << p4.getValue() << std::endl;

    // std::vector<std::vector<int>> doubleValues = { {1, 2, 3}, {4, 5,6}};
    // PrettyPrinter<std::vector<std::vector<int>>, 50> p5{&doubleValues};
    // p5.Print();

    SmartPointer<int> sp{new int{10}};
    std::cout << *sp <<std::endl;

    SmartPointer<int[]> sp2{new int[10]};
    std::cout << sp2[4] <<std::endl;
    return 0;
}