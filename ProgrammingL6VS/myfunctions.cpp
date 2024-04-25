#include "constants.h"
#include <string>

using ullong = unsigned long long;
using namespace constants;
using namespace std;

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