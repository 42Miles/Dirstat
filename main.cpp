#include <iostream>
#include <fstream>
#include <filesystem>
#include <thread>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

namespace fs = std::filesystem;

void getDir(std::string & directory)
{
    std::cout << "Enter directory name: ";
    std::cin >> directory;
    std::cout << "Fine!" << std::endl;
}

int countLinesInFile(const std::string & file_path)
{
    std::ifstream inFile(file_path);
    return std::count(std::istreambuf_iterator<char>(inFile),
                      std::istreambuf_iterator<char>(), '\n');
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

int getAllLines(const std::vector<std::string> & files)
{
    unsigned int all_lines = 0;
    for(const std::string &s: files)
    {
        all_lines += countLinesInFile(s);
    }
    return all_lines;
}

inline bool isExistsing (const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

void checkDirectory(std::string & directory)
{

    while(!isExistsing(directory))
    {
        std::cout << "Oh, looks like you entered the wrong directory name, please try again" << std::endl;
        getDir(directory);
    }
}

int main()
{
    std::string directory;
    getDir(directory);
    checkDirectory(directory);
    std::vector<std::string> files;
    files = getDirFiles(directory);
    std::cout << "Number of lines: " << getAllLines(files) << std::endl;
    std::cout << "Number of files: " << files.size() << std::endl;

    return 0;
}
