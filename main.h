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

    std::vector<std::string> getDirFiles(const fs::path & dir);

    unsigned int getAllLines();

    unsigned int getAllEmptyLines(const std::vector<std::string> & files);

    inline bool isExistsing (const std::string& name);

    void checkDirectory();

    void printResult();



    std::string directory;

    ~Application();

    const std::vector<std::string> &getFiles() const;
    void setFiles(const std::vector<std::string> &newFiles);
    unsigned int getAll_lines() const;
    void setAll_lines(unsigned int newAll_lines);
    unsigned int getEmpty_lines() const;
    void setEmpty_lines(unsigned int newEmpty_lines);
    unsigned int getNon_empty_lines() const;
    void setNon_empty_lines(unsigned int newNon_empty_lines);

private:

    std::vector<std::string> files;

    unsigned int all_lines;
    unsigned int empty_lines;
    unsigned int non_empty_lines;

};

#endif // MAIN_H
