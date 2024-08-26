#include<iostream>
#include<string>

class Class1{
    public:
      Class1(){
        std::cout<<"Class1()"<<std::endl;
      }  
      Class1(const Class1& class1)
      {
        std::cout<<"Class1(const Class1& )"<<std::endl;
      }
      Class1(Class1&& class1)
      {
        std::cout<<"Class1(Class1&& )"<<std::endl;
      }
      Class1& operator= (const Class1 & class1){
        if(this == &class1)
        {
            return *this;
        }
        return *this;
      }
      Class1 operator= (Class1&& class1){
        if(this == &class1)
        {
            return *this;
        }
        return *this;
      }
      ~Class1()
      {
        std::cout<<"~Class1()"<<std::endl;
      }
};
class Class2{
    public:
      Class2(){
        std::cout<<"Class2()"<<std::endl;
      }  
      Class2(const Class2& class2)
      {
        std::cout<<"Class2(const Class2& )"<<std::endl;
      }
      Class2(Class2&& class2)
      {
        std::cout<<"Class2(Class2&& )"<<std::endl;
      }
      Class2& operator= (const Class2 & class2){
        if(this == &class2)
        {
            return *this;
        }
        return *this;
      }
      Class2 operator= (Class2&& class2){
        if(this == &class2)
        {
            return *this;
        }
        return *this;
      }
    ~Class2()
      {
        std::cout<<"~Class2()"<<std::endl;
      }
};
union Test
{
    // int x;
    // char c;

    // Test(): c{'f'}{}
    // ~Test(){}

    Class1 class1;
    Class2 class2;
    std::string name;
    Test(){}
    ~Test(){}

};

union Mytest{
  Class1 class1;
  Class2 class2;
  int x;
  std::string myString;
  Mytest(){}
  ~Mytest(){}
};

int main()
{
    // Test t;
    // std::cout<<t.c<<std::endl;
    // std::cout<<t.x<<std::endl;

    // t.x = 3;
    // std::cout<<t.x<<std::endl;
    // std::cout<<t.c<<std::endl;
    Test t;
    new(&t.class1) Class1{};

    t.class1.~Class1();
    //t.name.~basic_string();
    new(&t.name) std::string{"mohammed"};
    std::cout<<t.name<<std::endl;


    Mytest t2;

    new(&t2.class1) Class1{};

    t2.class1.~Class1();

    new(&t2.myString) std::string{"mohammed"};

    std::cout << t2.myString << std::endl; 

    t2.myString.~basic_string();
    return 0;
}