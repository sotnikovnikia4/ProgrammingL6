#include <iostream>
#include <cmath>
#include <iostream>
#include <string>

#include "constants.h"

using namespace std;
using namespace constants;

// Возвращаем true, если разница между a и b в пределах процента эпсилона
bool approximatelyEqual(double a, double b, double epsilon)
{
	if (a * -1 == b) return false;
	return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

// Возвращаем true, если разница между a и b меньше absEpsilon
// или в пределах relEpsilon
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon) {
	if (a * -1 == b) return false;

	double diff = fabs(a - b);
	if (diff <= absEpsilon)
		return true;
	// В противном случае, возвращаемся к алгоритму Кнута
	return diff <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}

void doTaskDependOnArgsOrPrintError(int countArgs, char* args[]) {//32 17
	if (countArgs < 2) {
		cout << "Отсутствует имя функции";
	}

	string function (args[1]);

	if (function == "approximatelyEqual") {
		//TODO проверка на корректность аргументов
		cout << "Результат работы функции: " << boolalpha << approximatelyEqual(stod(args[2]), stod(args[3]), stod(args[4])) << endl;
	}
	else if (function == "approximatelyEqualAbsRel") {
		//TODO проверка на корректность аргументов
		cout << "Результат работы функции: " << boolalpha << approximatelyEqualAbsRel(stod(args[2]), stod(args[3]), stod(args[4]), stod(args[5])) << endl;
	}
	else if (function == "32") {

	}
	else if (function == "17") {

	}
	else {
		cout << "Введено имя несуществующей функции" << endl;
	}
}