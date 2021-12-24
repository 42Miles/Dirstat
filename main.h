#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <thread>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

namespace fs = std::filesystem;

class Application{
public:

    void getDir();

    unsigned int countLinesInFile(const std::string & file_path);

    unsigned int countEmptyLinesInFile(const std::string & file_path);

    /*std::vector<std::string>*/ void getDirFiles(const fs::path & dir);

    unsigned int getAllLines();

    unsigned int getAllEmptyLines();

    inline bool isExistsing ();

    void checkDirectory();

    void printResult();

    std::string directory;

    ~Application();

private:

    std::vector<std::string> files;

    unsigned int all_lines;
    unsigned int empty_lines;
    unsigned int non_empty_lines;

};

#endif // MAIN_H
