#pragma once
using ullong = unsigned long long;

namespace constants {
	const ullong firstByte = 0xFF;
	const ullong sizeLongLong = sizeof(unsigned long long) << 3;
	const ullong firstBit = 0x1ULL;
	const ullong maxValue = ~0ULL;
}