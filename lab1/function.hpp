#ifndef FUNCTION_HPP_
#define FUNCTION_HPP_

inline int add(int x, int y);
void print(char c);
void print(int count, const char* ch);
extern "C" int Add(int *a, int *b) ;    //Add two numbers and return the sum
int Add(int a, int b);
void AddVal(int *a, int *b, int *result); //Add two numbers and return the sum through the third pointer argument
void Swap(int *a, int *b) ;  //Swap the value of two integers
void Factorial(int *a, int *result);       //Generate the factorial of a number and return that through the second pointer argument

void Add2(int a,int b, int &result) ;    //Add two numbers and return the result through a reference parameter
void Factorial2(int a, int &result) ;    //Find factorial of a number and return that through a reference parameter
void Swap2(int &a, int &b) ;            //Swap two numbers through reference arguments

void printScreen(const char* name, int x = -1, int y= -1, int width= -1, int height = -1); //print the resolution of the screen with some default values


#endif