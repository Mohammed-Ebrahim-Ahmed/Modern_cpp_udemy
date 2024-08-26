#include <iostream>
#include <source_location>

#ifdef __has_include
#if __has_include(<unistd.h>)
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

#endif

#include <fstream>
// [[deprecated("this function no longer used")]]
// int returnint (int x)
// {
//     return x;
// }

// class [[deprecated("This class is replaced by the newer one")]] funny{

// };

// namespace [[deprecated("this is namespace is replaced by newer one")]] ff {

// }
// using namespace ff;

[[nodiscard("Return is used by this function to prevent memory leak")]]
int *allocateSpace(size_t size)
{
    return new int[size];
}
class [[nodiscard("this is class should be received when it returned from any function")]] dummy
{
};

dummy myfun(int x)
{
    return dummy{};
}
using namespace fs;

void writeOnFile(const std::string &data)
{

    if (std::ofstream file{"Text.txt"}; file && !data.empty())
    {
        file << data;
    }
    else
    {
        file << "###############";
    }
}

class FileInfo
{
public:
    FileInfo(const fs::path &ps) : ps{ps}
    {
    }
    enum Type
    {
        source,
        executable
    };
    Type GetFileType() const
    {
        std::string st{ps.string()};
        std::cout << st << std::endl;
        if (std::string file = st.substr(st.find_last_of('.')); file == ".cpp")
        {
            return source;
        }
        else if (file == ".exe")
        {
            return executable;
        }
    }
    int GetFileSize(fs::path &p) const
    {
        return fs::file_size(p);
    }

private:
    fs::path ps;
};

// FileInfo GetFileInfo()
// {
//     return FileInfo{};
// }

void operate(const fs::path &ps)
{

    switch (auto Info = FileInfo{ps}; Info.GetFileType())
    {
    case FileInfo::Type::source:
        std::cout << "no";
        break;
    case FileInfo::Type::executable:
        std::cout << "yes";
        break;
    default:
        break;
    }
}
int main()
{
    // auto p = allocateSpace(9);
    // returnint(2);
    // funny fun;
    // dummy f = myfun(2);
    fs::path p{"c:"};
    writeOnFile("");
    std::source_location location = std::source_location::current();
    fs::path ps{location.file_name()};
    std::cout << ps.string() << std::endl;
    operate(ps);
    return 0;
}