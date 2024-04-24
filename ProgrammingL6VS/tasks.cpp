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
		cout << "����������� ��� �������";
		return;
	}

	string function (args[1]);

	cout << "������� " << function << endl;

	if (function == "approximatelyEqual") {
		if (!argsAreCorrect(countArgs, args, 5)) {
			cout << "������������ ���������";
		}
		else {
			
			cout << "��������� ��������� ����� "<< args[2] << " � " << args[3] << " � ��������� "<< args[4]<< ": ";
			cout << (approximatelyEqual(stod(args[2]), stod(args[3]), stod(args[4])) ? "�����" : "�� �����") << endl;
		}
	}
	else if (function == "approximatelyEqualAbsRel") {
		if (!argsAreCorrect(countArgs, args, 6)) {
			cout << "������������ ���������";
		}
		else {
			cout << "��������� ��������� ����� " << args[2] << " � " << args[3] << " � absEpsilon " << args[4] << " � relEpsilon " << args[5] << ": ";
			cout << (approximatelyEqualAbsRel(stod(args[2]), stod(args[3]), stod(args[4]), stod(args[5])) ? "�����" : "�� �����") << endl;
		}
		
	}
	else if (function == "17") {
		//doTask17();
	}
	else if (function == "32") {

	}
	else {
		cout << "������� ��� �������������� �������" << endl;
		return;
	}
}