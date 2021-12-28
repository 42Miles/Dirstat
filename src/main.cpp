#include "dirstat.hpp"

int main()
{
    Application app;
    app.getDir();
    app.checkDirectory();
    app.countDirFiles();
    app.countAllLines();
    app.countAllEmptyLines();
    app.printResult();
    return 0;
}