#ifndef DIRSTAT_HPP
#define DIRSTAT_HPP

#include <iostream>
#include <fstream>
#include <filesystem>
#include <thread>
#include <vector>
#include <algorithm>
#include <sys/stat.h>
#include <boost/asio/thread_pool.hpp>
#include <boost/asio/post.hpp>
#include <iterator>
#include <sstream>

namespace fs = std::filesystem;

class Application{
public:

    void start();

    void getDir();

    void countDirFiles();

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

    unsigned int getWords() const;

    unsigned int getLetters() const;

private:

    std::vector<std::string> files;

    std::string directory;

    unsigned int all_lines;

    unsigned int empty_lines;

    unsigned int words;

    unsigned int letters;

    unsigned int countLinesInFile(const std::string & file_path);

    unsigned int countEmptyLinesInFile(const std::string & file_path);

    unsigned int countWordsAndLettersInFile(const std::string & file_path);

};

#endif // DIRSTAT_HPP
