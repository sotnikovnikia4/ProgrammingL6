#include <string>
#include <iostream>

#include "constants.h"

using namespace std;
using namespace constants;

unsigned long long minusOne(unsigned long long number);

void doTask17(int countArgs, char* args[]) {
	//TODO проверка на корректность аргументов

	unsigned long long number = stoull(args[2]);
	unsigned long long pos = stoull(args[3]);
	unsigned long long byte = stoull(args[4]);

	byte &= firstByte;
	pos = minusOne(pos);

	cout << byte << endl;//remove
	cout << pos << endl;//remove

	unsigned long long mask = ~(~(ULLONG_MAX << 8) << pos);
	byte <<= pos;

	number &= mask;
	number |= byte;
	
	cout << "Преобразованное число: " << number << endl;
}

unsigned long long minusOne(unsigned long long number) {
	if (number == 0) return number;

	unsigned long long pos = 0b1ull;
	unsigned long long temp = 0b1ull;
	
	while ((pos < ULLONG_MAX) && temp != 0) {
		number ^= temp;
		temp = (pos & number) << 1;
		pos <<= 1;
	}

	return number;
}