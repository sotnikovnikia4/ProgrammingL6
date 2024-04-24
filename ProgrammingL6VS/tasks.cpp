#include <iostream>
#include <cmath>
#include <iostream>
#include <string>

#include "constants.h"
#include "approxEqual.h"

using namespace std;
using namespace constants;



void doTaskDependOnArgsOrPrintError(int countArgs, char* args[]) {//32 17
	if (countArgs < 2) {
		cout << "Отсутствует имя функции";
		return;
	}

	string function (args[1]);

	cout << "функция " << function << endl;

	if (function == "approximatelyEqual") {
		if (!argsAreCorrect(countArgs, args, 5)) {
			cout << "Некорректные аргументы";
		}
		else {
			
			cout << "Результат сравнения чисел "<< args[2] << " и " << args[3] << " с точностью "<< args[4]<< ": ";
			cout << (approximatelyEqual(stod(args[2]), stod(args[3]), stod(args[4])) ? "равны" : "не равны") << endl;
		}
	}
	else if (function == "approximatelyEqualAbsRel") {
		if (!argsAreCorrect(countArgs, args, 6)) {
			cout << "Некорректные аргументы";
		}
		else {
			cout << "Результат сравнения чисел " << args[2] << " и " << args[3] << " с absEpsilon " << args[4] << " и relEpsilon " << args[5] << ": ";
			cout << (approximatelyEqualAbsRel(stod(args[2]), stod(args[3]), stod(args[4]), stod(args[5])) ? "равны" : "не равны") << endl;
		}
		
	}
	else if (function == "17") {
		//doTask17();
	}
	else if (function == "32") {

	}
	else {
		cout << "Введено имя несуществующей функции" << endl;
		return;
	}
}