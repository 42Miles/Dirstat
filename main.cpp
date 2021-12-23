#include "main.h"

void Application::getDir(std::string &directory)
{
    std::cout << "Enter directory name: " << std::endl;
    std::cin >> directory;
}

int Application::countLinesInFile(const std::string &directory)
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

std::vector<std::string> Application::getDirFiles(const fs::path & dir)
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

unsigned int Application::getAllLines(const std::vector<std::string> & files)
{
    unsigned int all_lines = 0;
    for(const std::string &s: files)
    {
        all_lines += countLinesInFile(s);
    }
    return all_lines;
}

unsigned int Application::getAllEmptyLines(const std::vector<std::string> & files)
{
    unsigned int all_empty_lines = 0;
    for(const std::string &s: files)
    {
        all_empty_lines += countEmptyLinesInFile(s);
    }
    return all_empty_lines;
}

inline bool Application::isExistsing (const std::string& name)
{
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

void Application::checkDirectory(std::string & directory)
{
    while(!isExistsing(directory))
    {
        std::cout << "Oh, looks like you entered the wrong directory name, please try again" << std::endl;
        this->getDir(directory);
    }
}

Application::~Application()
{

}

int main()
{
    Application app;
    std::string directory;
    app.getDir(directory);
    app.checkDirectory(directory);
    std::vector<std::string> files = app.getDirFiles(directory);

    app.getAllLines(files);
    std::cout << "Number of lines: " << app.getAllLines(files) << std::endl;
    std::cout << "Empty lines: " << app.getAllEmptyLines(files) << std::endl;
    std::cout << "Number of files: " << files.size() << std::endl;

    return 0;
}
