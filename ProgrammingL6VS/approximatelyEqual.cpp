// ���������� true, ���� ������� ����� a � b � �������� �������� ��������
#include <cmath>
#include <string>

using namespace std;

bool isDouble(const string& str) {
	return true;
}

bool approximatelyEqual(double a, double b, double epsilon)
{
	if (a * -1 == b) return false;
	return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

// ���������� true, ���� ������� ����� a � b ������ absEpsilon
// ��� � �������� relEpsilon
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon) {
	if (a * -1 == b) return false;

	double diff = fabs(a - b);
	if (diff <= absEpsilon)
		return true;
	// � ��������� ������, ������������ � ��������� �����
	return diff <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}

bool argsAreCorrect(int countArgs, char* args[], int countMeaningfulArgs) {
	if (countArgs < countMeaningfulArgs) return false;

	for (int i = 0; i < countMeaningfulArgs; i++) {
		if (!isDouble(args[i]))
			return false;
	}

	return true;
}

