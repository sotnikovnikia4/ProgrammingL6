#include <iostream>
#include <cmath>
#include <iostream>
#include <string>

#include "constants.h"
#include "approxEqual.h"
#include "task17.h"
#include "task32.h"

using namespace std;
using namespace constants;



void doTaskDependOnArgsOrPrintError(int countArgs, char* args[]) {//32 17
	if (countArgs < 2) {
		cout << "Отсутствует имя функции";
		return;
	}

	string function (args[1]);

	cout << "функция " << function << endl << endl;

	if (function == "approximatelyEqual") {
		doApproximatelyEqual(countArgs, args);
	}
	else if (function == "approximatelyEqualAbsRel") {
		doApproximatelyEqualAbsRel(countArgs, args);
	}
	else if (function == "17") {
		doTask17(countArgs, args);
	}
	else if (function == "32") {
		doTask32(countArgs, args);
	}
	else {
		cout << "Введено имя несуществующей функции" << endl;
		return;
	}
}