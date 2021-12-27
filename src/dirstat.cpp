#include "dirstat.hpp"

Application::Application()
{
    directory = "";
    all_lines = 0;
    empty_lines = 0;
}

Application::Application(std::string user_input)
{
    directory = user_input;
    all_lines = 0;
    empty_lines = 0;
}

void Application::getDir()
{
    std::cout << "Enter directory name: " << std::endl;
    if(directory.empty()) std::cin >> directory;
}

unsigned int Application::countLinesInFile(const std::string &directory)
{
    std::ifstream file(directory);
    return std::count(std::istreambuf_iterator<char>(file),
                      std::istreambuf_iterator<char>(), '\n');
}

unsigned int Application::countEmptyLinesInFile(const std::string & file_path)
{
    unsigned int countEmpty = 0;
    std::string text;
    std::ifstream file(file_path);
    while(std::getline(file, text))
        if(!text.size())
            countEmpty++;
    return countEmpty;
}

void Application::getDirFiles()
{
    for(auto & file: fs::recursive_directory_iterator(directory))
    {
        if(fs::is_regular_file(file))
        {
            files.push_back(file.path().string());
        }
    }
}

void Application::getAllLines()
{
    for(const std::string &s: files)
    {
        all_lines += countLinesInFile(s);
    }
}

void Application::getAllEmptyLines()
{
    for(const std::string &s: files)
    {
        empty_lines += countEmptyLinesInFile(s);
    }
}

inline bool Application::isExistsing ()
{
  struct stat buffer;
  return (stat (directory.c_str(), &buffer) == 0);
}

void Application::checkDirectory()
{
    while(!isExistsing())
    {
        std::cout << "Oh, looks like you entered the wrong directory name, please try again" << std::endl;
        directory.clear();
        getDir();
    }
}

void Application::printResult()
{
    std::cout << "Number of lines: " << all_lines << std::endl;
    std::cout << "Empty lines: " << empty_lines << std::endl;
    std::cout << "Non-empty lines: " << all_lines - empty_lines << std::endl;
    std::cout << "Number of files: " << files.size() << std::endl;
}

Application::~Application()
{

}

