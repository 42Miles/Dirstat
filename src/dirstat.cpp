#include "dirstat.hpp"

Application::Application()
{
    directory = "";
    all_lines = 0;
    empty_lines = 0;
    words = 0;
}

Application::Application(std::string user_input)
{
    directory = user_input;
    all_lines = 0;
    empty_lines = 0;
    words = 0;
}

void Application::getDir()
{
    std::cout << "Enter directory name: " << std::endl;
    if(directory.empty()) std::cin >> directory;
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

inline bool Application::isExistsing ()
{
  struct stat buffer;
  return (stat (directory.c_str(), &buffer) == 0);
}

void Application::countDirFiles()
{
    for(auto & file: fs::recursive_directory_iterator(directory))
    {
        if(fs::is_regular_file(file))
        {
            files.push_back(file.path().string());
        }
    }
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

unsigned int Application::countWordsInFile(const std::string & file_path)
{
    std::ifstream file(file_path);

    std::string line;
    std::string word;
    unsigned int word_count = 0;

// read file line by line
    while (getline(file, line)) {

    std::stringstream ss(line);

    // extract all words from line
    while (ss >> word) {
        ++word_count;
    }
}
    return word_count;
}

void Application::printResult()
{
    std::cout << "Number of lines: " << all_lines << std::endl;
    std::cout << "Empty lines: " << empty_lines << std::endl;
    std::cout << "Non-empty lines: " << all_lines - empty_lines << std::endl;
    std::cout << "Number of words: " << words << std::endl;
    std::cout << "Number of files: " << files.size() << std::endl;
}

Application::~Application()
{
        
}

void Application::start()
{
    unsigned int supported_threads = std::thread::hardware_concurrency();
    boost::asio::thread_pool pool(supported_threads);

    getDir();
    checkDirectory();
    countDirFiles();
    for(const std::string &s: files)
    {
    boost::asio::post(pool, [=] { all_lines += countLinesInFile(s); });
    boost::asio::post(pool, [=] { empty_lines += countEmptyLinesInFile(s); });
    boost::asio::post(pool, [=] { words += countWordsInFile(s); });
    }
    printResult();

    pool.join();
}

const std::vector<std::string> &Application::getFiles() const
{
    return files;
}

const std::string &Application::getDirectory() const
{
    return directory;
}

unsigned int Application::getAll_lines() const
{
    return all_lines;
}

unsigned int Application::getEmpty_lines() const
{
    return empty_lines;
}

unsigned int Application::getWords() const
{
    return words;
}