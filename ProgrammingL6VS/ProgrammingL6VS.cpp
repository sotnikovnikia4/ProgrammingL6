﻿#include <iostream>
#include <sstream> // для std::stringstream
#include <cstdlib>
#include <string>
#include <limits>
#include <iomanip>

#include "tasks.h"

//#include "task1.h"
//#include "task2.h"

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