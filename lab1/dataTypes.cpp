// #include <iostream>
// #include "function.hpp"
// #include <sec_api/string_s.h>
// using namespace std;

// namespace avg{
// float calculator(int x, int y)
// {
//     return x+y;
// }
// }
// namespace basic{
// float calculator(int x, int y)
// {
//     return x+y;
// }
// }
// int main()
// {
//     // int a {2};
//     // bool c {true};
//     // cout<< a;
//     // char o {'s'};
//     // int arr[5] {2,3,6,8,9};
//     // float f {2.223};
//     // double d {2.999};
//     // cout<< a  << c << o << arr << f << d << std::endl;
//     // //cout<<"Enter the number"<<" "<<std::endl;
//     // //cin>>a;
//     // char buff[100];
//     // std::cout<<"Enter your name: "<<std::endl;
//     // std::cin.getline(buff, 54, '\n');
//     // cout<<"The name is "<<buff<<std::endl;
//     // int sum {0};
//     // int x = 0, y = 0;
//     // std::cin >> x >> y ;
//     // sum = add(x,y);
//     // cout<<"The sum is: "<<sum<<endl;
//     // print('c');

//     //value init -> T obj{}
//     //direct init -> T obj{val}
//     //copy init T obj = v

//     // it forces init
//     // you can use direct init for array types
//     //prevents narrowing conversions
//     // unifrom syntex

//     // char d1 {};
//     // char d2[8] = {'\0'};
//     // char d3[8] = {'a', 'b'};
//     // char d4[8] = {"abcd"};
//     // int  b5 = 0;
//     // char e1[3]{};
//     // char e2[8]{"hello"};
//     // int *p = new int[8]{};
//     // char *p2 = new char[8]{"hello"};

//     int a1; // is not init
//     int a2 = 2; //copy init
//     int a3{}; //value init 
//     int a4{2}; // direct init
//     int x {2}, y{5};
//     int sum;
//     sum = Add(&x, &y);
//     sum = Add(x,y);
//     std::cout<<"This first sum is " << sum<<std::endl;
//     AddVal(&x, &y, &sum);
//     std::cout<<"The second sum is "<<sum<<std::endl;
//     Swap(&x,&y);
//     std::cout<<"The value of x is "<<x<<" The value of y "<<y<<std::endl;
//     Factorial(&x, &sum);
//     std::cout<<"The factorial of "<< x <<" is "<<sum<<std::endl;
//     Add2(x, y, sum);
//     std::cout<<"The second sum2 is "<<sum<<std::endl;
//     Swap2(x,y);
//     std::cout<<"The value2 of x is "<<x<<" The value of y "<<y<<std::endl;
//     Factorial2(3, sum);
//     std::cout<<"The factorial2 of "<< x <<" is "<<sum<<std::endl;
//     printScreen("mohammed");

//     void(*funptr)(int, const char*) = &print;
//     (*funptr)(3,"#");
//     funptr(7,"*");
//     using avg::calculator;
//     calculator(2,3);
//     basic::calculator(2,3);

//     // int* f = new int (3);
//     // *f = 4;
//     // delete f;
//     // f = nullptr;
//     // delete f;

//     // int* f = new int[5]{1,2,3,4,5};
//     // f[1] =3;
//     // for(int i = 0 ; i < 5; i++)
//     // {
//     //     std::cout<<f[i]<< " ";
//     // }
//     // delete[] f;
//     // f = nullptr;
//     // char *s = new char [4];
//     // strcpy_s(s,4,"c++");
//     // std::cout<<s<<std::endl;

//     int* row1 = new int[3]{1,2,3};
//     int* row2 = new int[3]{4,5,6};
//     int** matrix = new int*[2];

//     matrix[0] = row1;
//     matrix[1] = row2;

//     matrix[0][1] = 8;

//     delete [] row1 ;// matrix[0]
//     delete [] row2 ;// matrix[1]
//     delete [] matrix;

//     // //Try to modify x1 & x2 and see the compilation output
//     // int x = 5 ;
//     // const int MAX = 12 ;
//     // int &ref_x1 = x ;
//     // const int &ref_x2 = x ;
    
//     // //Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
//     // const int *ptr1 = &x ;
//     // int *const ptr2 = &x ;
//     // const int * const ptr3 = &x ;
    
//     // //Find which declarations are valid. If invalid, correct the declaration
//     // const int *ptr3 = &MAX ;
//     // int *ptr4 = &MAX ;
    
//     // const int &r1 = ref_x1 ;
//     // int &r2 = ref_x2 ;
    
//     // int *&p_ref1 = ptr1 ;
//     // const int*&p_ref2 = ptr2 ;

//     // const int a = 5;
//     // auto c = 'c';
//     // auto f = {1, 2, 3};
//     // auto &b = a;
//     // auto h = &a;

//     // int arr[5]{1,2,3,4,5};

//     // for(auto x : arr)
//     // {
//     //     std::cout<<x << " ";
//     // }
//     // std::cout<<std::endl;
//     // auto &&range = arr;
//     // auto begin = std::begin(range);
//     // auto end   = std::end(range);

//     // for(; *begin != *end; begin++)
//     // {
//     //     auto v = *begin;
//     //     std::cout<< v << " "<<std::endl;
//     // }
//     return 0;
// }
