#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <limits>
#include <iomanip>

#include "tasks.h"

using namespace std;
int main(int argc, char* argv[]) {
    system("chcp 1251");
    setlocale(LC_ALL, "");

    try {
        doTaskDependOnArgsOrPrintError(argc, argv);
    }
    catch (out_of_range& у) {
        cout << "Число выходит за пределы" << endl;
        exit(0);
    }
    catch (invalid_argument& e) {
        cout << "Число выходит за пределы" << endl;
        exit(0);
    }
    

    return 0;

}