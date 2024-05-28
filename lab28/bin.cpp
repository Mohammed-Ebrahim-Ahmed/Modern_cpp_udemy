#include <iostream>
#include <fstream>
#include <string>
#include <memory>
typedef struct {
    int id;
    char name[10];
}Record;

std::unique_ptr<Record[]> rPtr;
void writeRecord(Record* R, int length)
{
    int i = 0;
    std::ofstream out{"bin", std::ios::out | std::ios::binary};
    if(!out)
    {
        std::cout<<"Failed to open the file"<<std::endl;
        return;
    }
    for(i = 0; i < length; i++)
    {
        out.write((const char*)&R[i], sizeof(R[i]));
    }
    out.close();
}

Record* GetRecord(int length)
{
    int i = 0;
    rPtr.reset(new Record[length]);
    std::ifstream input{"bin", std::ios::in | std::ios::binary};
    if(!input)
    {
        std::cout<<"Failed to open the file"<<std::endl;
        return NULL;
    }
    for(i = 0; i < length; i++)
    {
        input.read((char*)&rPtr[i], sizeof(rPtr[i]));
    }
    input.close();
    return &rPtr[0];
}
int main()
{
    // std::ofstream datafile("data");
    // int myint{123456789};
    // datafile<<myint;
    // std::ofstream binfile("bin", std::ios::out | std::ios::binary);
    // binfile.write((const char *)&myint, sizeof(myint));
    // datafile.close();
    // binfile.close();
    Record myRecords[4] = {
        {.id = 2, .name = "mohammed"},
        {.id = 1, .name = "yasser"},
        {.id = 3, .name = "hassan"},
        {.id = 4, .name = "amr"}
    };

    writeRecord(myRecords, 4);
    std::unique_ptr<Record[]> mylocalRecords;
    GetRecord(4);
    mylocalRecords = std::move( rPtr );

    for(int i = 0; i < 4; i++)
    {
        std::cout<<mylocalRecords[i].id<<" "<<mylocalRecords[i].name<<std::endl;
    }
    return 0;
}