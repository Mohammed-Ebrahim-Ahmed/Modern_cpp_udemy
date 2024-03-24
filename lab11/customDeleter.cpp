#include <cstdlib>
#include <iostream>
#include <memory>

class Udel{
    public:
        void operator()(int* p){
            free(p);
            std::cout<<"Freed the ptr"<<std::endl;
        }
};

class Point{
    int x;
    int y;

    public:
        Point(int x,int y):x{x},y{y}
        {

        }
};
void Unique_delete(void)
{
    std::unique_ptr<int, Udel> p {(int*)malloc(4), Udel{}};
    *p = 100;
}

void Shared_delete(void)
{
    std::shared_ptr<int> p {(int*)malloc(4), Udel{}};
    *p = 100;
}

void Dynamic_array(void)
{
    std::unique_ptr<int[]> p {new int[5]{1,2,3,4,5}};
    p[2] = 3;
    std::shared_ptr<int[]> x {new int[5]{1,2,3,4,5}};
    x[2] = 3;
}
int main()
{
    Unique_delete();
    Shared_delete();

    // auto a = std::make_unique<int>(2);
    // auto b = std::make_unique<Point>(2,3);
    // auto f = std::make_shared<int[]>(2);
    // auto c = std::make_shared<int>(2);
    // auto d = std::make_shared<int[]>(3);
    
    return 0;
}