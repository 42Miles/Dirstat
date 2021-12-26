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

    void getDirFiles();

    void getAllLines();

    void getAllEmptyLines();

    inline bool isExistsing ();

    void checkDirectory();

    void printResult();

    Application();

    ~Application();

private:

    std::vector<std::string> files;

    std::string directory;

    unsigned int all_lines;

    unsigned int empty_lines;

};

#endif // MAIN_H
