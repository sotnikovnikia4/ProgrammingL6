#include <string>
#include <iostream>
#include <bitset>

#include "constants.h"
#include "myfunctions.h"

using ullong = unsigned long long;

using namespace std;
using namespace constants;

bool bitsAreEqual(ullong number1, ullong pos1, ullong number2, ullong pos2) {
	pos1 = minusOne(pos1);
	pos2 = minusOne(pos2);

	number1 >>= pos1;
	number2 >>= pos2;

	number1 &= firstBit;
	number2 &= firstBit;

	return number1 == number2;
}

void printInputArgs(ullong number1, ullong pos1, ullong number2, ullong pos2) {
	cout << "������ �����: " << bitset<sizeLongLong>(number1) << endl;
	cout << "������� � ������ �����: " << pos1 << endl;
	cout << "������ �����: " << bitset<sizeLongLong>(number2) << endl;
	cout << "������� �� ������ �����: " << pos2 << endl << endl;
}

bool argsAreCorrect32(int countArgs, char* args[]) {
	if (countArgs < 6) {
		cout << "������� ���� ����������";
		return false;
	}
	else if (!isullong(args[2]) || !isullong(args[3]) || !isullong(args[4]) || !isullong(args[5])) {
		cout << "��������� ������ ���� ���� ullong" << endl;
		return false;
	}
	else if (stoull(args[3]) > sizeLongLong || stoull(args[5]) > sizeLongLong || stoull(args[3]) < 1 || stoull(args[5]) < 1) {
		cout << "������� ������ ���� ����� 1 � " << sizeLongLong << endl;
		return false;
	}
	else return true;
}

void doTask32(int countArgs, char* args[]) {
	//�������� � ����� ����������

	if (!argsAreCorrect32(countArgs, args)) return;

	ullong number1 = stoull(args[2]);
	ullong pos1 = stoull(args[3]);
	ullong number2 = stoull(args[4]);
	ullong pos2 = stoull(args[5]);

	printInputArgs(number1, pos1, number2, pos2);

	cout << "��������� �������� ���� ��������� ����� � ������ ������: " << (bitsAreEqual(number1, pos1, number2, pos2) ? "���������" : "�� ���������");
}