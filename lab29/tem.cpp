#include "tem.hpp"


int main()
{

    int x = Add(2, 3);
    float y = Add(2.2, 3.2);
    std::cout<<x<<" "<<y<<std::endl;
    int z[3] = {1,2,3};
    int (&rz)[3] = z;
    int sum = ArraySum(rz);
    std::cout<<"int sum = "<< sum<<std::endl;
    float f[3] = {1.2f, 3.9f, 9.2f};
    float (&rf)[3] = f;
    float fsum = ArraySum(rf);
    std::cout<<"float sum = "<< fsum <<std::endl;
    std::cout<<Max(rz)<<std::endl;
    std::cout<<Max(rf)<<std::endl;
    std::pair<int, int> pair = MinMax(rz);
    std::cout<<pair.first <<" "<< pair.second<< std::endl;
    std::pair<float, float> fpair= MinMax(rf);
    std::cout<<fpair.first <<" "<< fpair.second<< std::endl;
    const char * a = "a";
    const char * b = "b";
    std::cout<<Maximum(a,b)<<std::endl;
    int brr[4] = {9,2,9,3};
    int (& rbrr)[4] = brr;
    std::cout<<min(brr)<<std::endl;
    const char * names [3] = {"mohammed", "Ebrahim", "ahmed"};
    const char * (&rnames)[3] = names;
    std::cout<<ArraySum(rnames)<<std::endl;
    std::string mynames [3] = {"mohammed", "Ebrahim", "hassanin"};
    std::string (&rmynames)[3] = mynames;
    std::cout<<ArraySum(rmynames)<<std::endl;
    return 0;
}