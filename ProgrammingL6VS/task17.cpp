#include <string>
#include <iostream>

#include "constants.h"

using namespace std;
using namespace constants;

using ullong = unsigned long long;

ullong minusOne(ullong number) {
	if (number == 0) return number;

	ullong pos = 0b1ull;
	ullong temp = 0b1ull;

	while ((pos < maxValue) && temp != 0) {
		number ^= temp;
		temp = (pos & number) << 1;
		pos <<= 1;
	}

	return number;
}

bool isullong(const string& str) {

	for (char c : str) {
		if (!isdigit(c)) return false;
	}

	return true;
}

bool argsAreCorrect(int countArgs, char* args[]) {
	if (countArgs < 5) {
		cout << "Введено мало аргументов";
		return false;
	}
	else if (!isullong(args[2]) || !isullong(args[3]) || !isullong(args[4])) {
		cout << "Аргументы должны быть типа ullong" << endl;
		return false;
	}
	else if (stoull(args[3]) > sizeLongLong) {
		cout << "Позиция должна быть между 1 и " << sizeLongLong << endl;
		return false;
	}
	else if (stoull(args[4]) >= (1 << 8)) {
		cout << "Записываемый байт действительно должен быть байтом (<256)" << endl;
		return false;
	}
	else
		return true;
}

void printInputArgs(ullong number, ullong pos, ullong byte) {
	cout << "Исходное число: " << number << endl;
	cout << "Позиция: " << pos << endl;
	cout << "Байт, который нужно записать: " << byte << endl << endl;
}

ullong getModifiedNumber(ullong number, ullong pos, ullong byte) {
	ullong byteToPlus = byte;
	pos = minusOne(pos);

	//cout << byteToPlus << endl;//remove
	//cout << pos << endl;//remove

	ullong mask = ~(firstByte << pos);
	byteToPlus <<= pos;

	ullong mask2 = 63ull ^ pos;

	if (mask2 < 7) {
		byteToPlus |= (byte >> mask2 >> 1);
		mask2 = maxValue << mask2 << 1;
		mask &= mask2;
	}

	number &= mask;
	number |= byteToPlus;
	//cout << mask << endl;//remove
	return number;
}

void doTask17(int countArgs, char* args[]) {

	if (!argsAreCorrect(countArgs, args)) return;

	ullong number = stoull(args[2]);
	ullong pos = stoull(args[3]);
	ullong byte = stoull(args[4]);

	printInputArgs(number, pos, byte);

	number = getModifiedNumber(number, pos, byte);
	
	cout << "Преобразованное число: " << number << endl << endl;
}