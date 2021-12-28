#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <thread>
#include <vector>
#include <algorithm>
#include <sys/stat.h>

namespace fs = std::filesystem;

class Application{
public:

    void getDir();

    void countDirFiles();

    void countAllLines();

    void countAllEmptyLines();

    inline bool isExistsing ();

    void checkDirectory();

    void printResult();

    Application();

    Application(std::string user_input);

    ~Application();

    const std::vector<std::string> &getFiles() const;

    const std::string &getDirectory() const;

    unsigned int getAll_lines() const;

    unsigned int getEmpty_lines() const;
private:

    std::vector<std::string> files;

    std::string directory;

    unsigned int all_lines;

    unsigned int empty_lines;

    unsigned int countLinesInFile(const std::string & file_path);

    unsigned int countEmptyLinesInFile(const std::string & file_path);
};

#endif // MAIN_H
