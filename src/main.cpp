#include "dirstat.hpp"

int main()
{
    Application app;
    app.getDir();
    app.checkDirectory();
    app.getDirFiles();
    app.getAllLines();
    app.getAllEmptyLines();
    app.printResult();
    return 0;
}