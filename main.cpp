#include <iostream>
#include <fstream>
#include <filesystem>
#include <thread>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

namespace fs = std::filesystem;

int countLinesInFile(const std::string & file_path)
{
    std::ifstream inFile(file_path);
    return std::count(std::istreambuf_iterator<char>(inFile),
                      std::istreambuf_iterator<char>(), '\n');
}

int countWordsInFile(){
    while(getline(lineStream, line, ' '))
    {
        ++numWords;
    }
}

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

//int getAllLines(const std::vector<std::string> & files)
//{

//}



int main()
{
    std::vector<std::string> f;
    std::thread first([&f] () { f = getDirFiles("/home/miles42/git/");});
    first.join();
    unsigned int all_lines = 0;
    for(const std::string &s: f)
    {
        all_lines += countLinesInFile(s);
    }
    std::cout << all_lines << std::endl;
    std::cout << f.size() << std::endl;

    return 0;
}
