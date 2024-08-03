#include<iostream>

template<typename T, int size>
class stack{
    public:
        stack()= default;
        stack(const stack& obj);
        void push(T num);
        void pop();
        const T Top();
        bool IsEmpty();
        static stack create();
    private:
        T buffer[size];
        int m_top= -1;

};

template<typename T, int size>
void stack<T, size>::push(T num)
{
    buffer[++m_top] = num;
}

template<typename T, int size>
void stack<T, size>::pop()
{
    m_top--;
}

template<typename T, int size>
const T stack<T, size>::Top()
{
    return buffer[m_top];
}

template<typename T, int size>
bool stack<T,size>::IsEmpty()
{
    return m_top== -1;
}
template<typename T, int size>
stack<T,size> stack<T, size>::create()
{
    return stack<T, size>();
}

template<typename T, int size>
stack<T,size>::stack(const stack<T,size>& obj)
{
    m_top = obj.m_top;
    for(int i = 0; i <= m_top ;i++)
    {
        buffer[i] = obj.buffer[i];
    }
}
int main()
{
    stack<int, 10> s1;
    s1.push(2);
    s1.push(3);
    s1.push(9);
    s1.pop();
    std::cout<<s1.Top()<<std::endl;
    return 0;
}