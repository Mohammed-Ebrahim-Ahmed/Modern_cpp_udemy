#include <iostream>
#include <filesystem>
#include <algorithm>
#include <vector>

namespace fs = std::filesystem;

void printPath()
{
    fs::path ps{R"(E:\ROS2)"};

    std::cout << ps.string() << std::endl;

    if (ps.has_extension())
    {
        std::cout << ps.extension().string() << std::endl;
    }

    if (ps.has_filename())
    {
        std::cout << ps.filename().string() << std::endl;
    }
    if (ps.has_parent_path())
    {
        std::cout << ps.parent_path().string() << std::endl;
    }

    if (ps.has_relative_path())
    {
        std::cout << ps.relative_path().string() << std::endl;
    }

    if (ps.has_root_directory())
    {
        std::cout << ps.root_directory().string() << std::endl;
    }
    if (ps.has_root_name())
    {
        std::cout << ps.root_name().string() << std::endl;
    }

    if (ps.has_root_path())
    {
        std::cout << ps.root_path().string() << std::endl;
    }

    if (ps.has_stem())
    {
        std::cout << ps.stem().string() << std::endl;
    }

    ps.append(R"(Ros setup.pptx)");
    ps.replace_filename(R"(Introduction.pptx)");
    // ps.assign(R"(E:\ROS2)");
    fs::path ps2{R"(E:\ROS2)"};
    auto val = ps.compare(std::string_view{R"(E:\ROS2\Introduction.pptx)"});
    std::cout << val << std::endl;
    if (!val)
    {
        std::cout << ps.string() << std::endl;
    }
}

void directoryEntry(std::string_view file)
{
    // fs::directory_iterator begin{file};
    // fs::directory_iterator end{};

    // while(begin != end)
    // {
    //     auto dir = *begin++;
    //     std::cout << dir.path().string() << std::endl;
    // }
    std::vector<fs::directory_entry> entries;

    for (const auto &entry : fs::directory_iterator{file})
    {
        entries.push_back(entry);
    }

    std::partition(entries.begin(), entries.end(), [](const fs::directory_entry &en)
                   { return en.is_directory(); });

    for (const auto &entry : entries)
    {
        switch (auto &p = entry.path(); entry.status().type())
        {
        case fs::file_type::regular:
            std::cout << "regular " << p.string() << " file size " << entry.file_size() << std::endl;
            break;
        case fs::file_type::directory:
            std::cout << "[Dir]" << p.string() << std::endl;
            break;
        }

        // if(entry.exists())
        // {
        //     std::cout << "it does exist" << std::endl;
        //     if(entry.is_directory())
        //     {
        //         std::cout << "is director " << entry.is_directory() << std::endl;
        //     }
        //     switch(entry.status().permissions())
        //     {
        //         case fs::perms::all:
        //             std::cout << "has all permissions" << std::endl;
        //             break;

        //         case fs::perms::group_all:
        //             std::cout << "has all groups permissions" << std::endl;
        //             break;

        //         case fs::perms::others_all:
        //             std::cout << "has all others permissions" << std::endl;
        //             break;
        //         case fs::perms::owner_all:
        //             std::cout << "all is owner here pro" << std::endl;
        //             break;
        //     }

        // }
    }
}

void manipulateDir(std::string_view file)
{
    fs::path ps{file};

    if (fs::exists(ps))
    {
        std::cout << "The directory given does exist" << std::endl;
    }
    else
    {
        std::cout << "The directory given does not exist" << std::endl;
    }
    ps /= "zezo";
    if (fs::create_directory(ps))
    {
        std::cout << "directory " << ps.string() << "is created successfully" << std::endl;
    }
    else
    {
        std::cout << "directory couldn't be created " << std::endl;
    }
    // if(fs::remove(ps))
    // {
    //     std::cout << "directory removed successfully " << std::endl;
    // }
    // else
    // {
    //     std::cout << "couldn't remove the directory" << std::endl;
    // }

    std::cout << fs::current_path() << std::endl;
    try
    {
        fs::current_path(ps);
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    // if(ee){
    //     std::cout << "couldn't change the current directory, message: " << ee.message() << std::endl;
    // }
    std::cout << fs::current_path() << std::endl;
}

void demoperms(fs::perms p)
{
    std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
              << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
              << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-") << std::endl;
}
void changePermissions(std::string_view file)
{
    fs::path ps{file};

    if (!fs::exists(ps))
    {
        std::cout << "directory does not exist" << std::endl;
    }

    fs::permissions(ps, fs::perms::others_read, fs::perm_options::add);

    auto perms = fs::status(ps).permissions();

    demoperms(perms);

    fs::permissions(ps, fs::perms::group_all, fs::perm_options::remove);

    perms = fs::status(ps).permissions();

    demoperms(perms);
}
int main()
{
    // printPath();
    directoryEntry(R"(E:\ROS2)");
    // manipulateDir(R"(E:\ROS2)");
    changePermissions(R"(E:\ROS2)");
    return 0;
}