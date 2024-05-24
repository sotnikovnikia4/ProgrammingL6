#include <string>
#include <iostream>
#include <bitset>

#include "constants.h"
#include "myfunctions.h"

using namespace std;
using namespace constants;

using ullong = unsigned long long;

bool argsAreCorrect17(int countArgs, char* args[]) {
	
	if (countArgs < 5) {
		cout << "������� ���� ����������";
		return false;
	}
	else if (!isullong(args[2]) || !isullong(args[3]) || !isullong(args[4])) {
		cout << "��������� ������ ���� ���� ullong" << endl;
		return false;
	}
	else if (stoull(args[3]) > sizeLongLong || stoull(args[3]) < 1) {
		cout << "������� ������ ���� ����� 1 � " << sizeLongLong << endl;
		return false;
	}
	else if (stoull(args[4]) >= (1 << 8)) {
		cout << "������������ ���� ������������� ������ ���� ������ (<256)" << endl;
		return false;
	}
	else
		return true;
}

void printInputArgs(ullong number, ullong pos, ullong byte) {
	cout << "�������� �����: " << bitset<sizeLongLong>(number) << endl;
	cout << "�������: " << pos << endl;
	cout << "����, ������� ����� ��������: " << bitset<8>(byte) << endl << endl;
}

ullong getModifiedNumber(ullong number, ullong pos, ullong byte) {
	ullong byteToPlus = byte;
	pos = minusOne(pos);

	//cout << byteToPlus << endl;//remove
	//cout << pos << endl;//remove

	ullong mask = ~(firstByte << pos);
	byteToPlus <<= pos;

	ullong mask2 = 63ull ^ pos;
	
	if (mask2 < 7ULL) {
		ullong mask3 = maxValue << (7ULL ^ mask2);
		mask &= mask3;

		byteToPlus |= (byte >> mask2 >> 1);
	}

	number &= mask;
	number |= byteToPlus;
	//cout << mask << endl;//remove
	return number;
}

void doTask17(int countArgs, char* args[]) {

	if (!argsAreCorrect17(countArgs, args)) return;

	ullong number = stoull(args[2]);
	ullong pos = stoull(args[3]);
	ullong byte = stoull(args[4]);

	printInputArgs(number, pos, byte);

	number = getModifiedNumber(number, pos, byte);
	
	cout << "��������������� �����: " << bitset<sizeLongLong>(number) << endl << endl;
}