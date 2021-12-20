#include <iostream>
#include <fstream>
#include <filesystem>
#include <thread>
#include <vector>
#include <algorithm>

namespace fs = std::filesystem;

std::vector<std::string> getDirFiles(const fs::path & dir)
{
    std::vector<std::string> files;
    for(auto & file: fs::recursive_directory_iterator(dir))
    {
        if(fs::is_regular_file(file))
        {
            files.push_back(file.path().string());
        }
    }
    return files;
}

int main()
{
    std::vector<std::string> f = getDirFiles(fs::current_path());
    for(const std::string &s: f)
    {
    std::cout << s << std::endl;
    }

    return 0;
}
