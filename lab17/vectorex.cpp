#include <iostream>
#include <vector>

#include <algorithm>

int main()
{
    int * a = new int[3] {1,2,3};
    for(int i = 0; i < 3; i++)
    {
        a[i] = i * 10;
    }
    std::vector<int> data = {1,8,3};
    for(auto i = 0; i < 3; i++)
    {
        data.push_back(i*2);
    }
    //access
    // data[0] = 10;
    // for(auto i = 0; i < data.size(); i++)
    // {
    //     std::cout<<data[i]<<" ";
    // }
    // for(auto ele : data)
    // {
    //     std::cout<<ele<<" ";
    // }
    auto it = data.begin();
    *it = 9;
    //auto x = *it;
    it++;
    it--;
    it = it + 5;
    //delete
    it = data.begin();
    data.erase(it);
    std::cout<<std::endl;
    // for(auto item : data)
    // {
    //     std::cout<<item<<" ";
    // }
    //insert

    it = data.begin()+1;
    auto itt = std::find(data.begin(), data.end(), 8);
    std::cout << (it - data.begin()) << std::endl;
    data.insert(it, 500);
    data.insert(it, {29,22});
    for(auto item : data)
    {
        std::cout<<item<<" ";
    }

}