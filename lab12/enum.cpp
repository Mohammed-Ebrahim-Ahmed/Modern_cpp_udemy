#include<iostream>

enum class colors {green, blue, red};
void FillColor(colors color)
{
    if(color  == colors::green)
    {
        std::cout<<"The color is green"<<std::endl;
    }
    else if(color == colors::blue)
    {
        std::cout<<"The color is blue"<<std::endl;
    }
    else if(color == colors::red)
    {
        std::cout<<"The color is red"<<std::endl;
    }
}

enum class traffic_lights{green, blue, red};
int main()
{
    FillColor(colors::green);
    FillColor(static_cast<colors>(3));
    return 0;
}