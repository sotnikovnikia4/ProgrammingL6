// ���������� true, ���� ������� ����� a � b � �������� �������� ��������
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

bool isDouble(const string& str) {
	//cout << "checking number: " << str << endl;
	bool e = false;
	bool dot = false;
	for (int i = 0; i < str.length(); i++) {
		if (isdigit(str[i])) {
			continue;
		}
		else {
			if (i == 0 && (str[i] == '-' || str[i] == '+')) {
				continue;
			}
			else if (str[i] == ',' && !dot && !e && !(i==1 && (str[i - 1] == '-' || str[i - 1] == '+'))) {
				dot = true;
				continue;
			}
			else if (str[i] == 'e' && !e) {
				e = true;
				continue;
			}
			else if (i > 0 && str[i - 1] == 'e' && (str[i] == '-' || str[i] == '+')) {
				continue;
				
			}
			else {
				return false;
			}
		}
	}

	//cout << stod(str) << endl;

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

	for (int i = 2; i < countMeaningfulArgs; i++) {
		if (!isDouble(args[i]))
			return false;
	}

	return true;
}

void doApproximatelyEqual(int countArgs, char* args[]) {
	if (!argsAreCorrect(countArgs, args, 5)) {
		cout << "������������ ���������";
	}
	else {
		std::cout << std::fixed << std::setprecision(15);
		cout << "��������� ��������� ����� " << stod(args[2]) << " � " << stod(args[3]) << " � ��������� " << stod(args[4]) << ": ";
		cout << (approximatelyEqual(stod(args[2]), stod(args[3]), stod(args[4])) ? "�����" : "�� �����") << endl;
	}
}

void doApproximatelyEqualAbsRel(int countArgs, char* args[]) {
	if (!argsAreCorrect(countArgs, args, 6)) {
		cout << "������������ ���������";
	}
	else {
		std::cout << std::fixed << std::setprecision(15);
		cout << "��������� ��������� ����� " << stod(args[2]) << " � " << stod(args[3]) << " � absEpsilon " << stod(args[4]) << " � relEpsilon " << stod(args[5]) << ": ";
		cout << (approximatelyEqualAbsRel(stod(args[2]), stod(args[3]), stod(args[4]), stod(args[5])) ? "�����" : "�� �����") << endl;
	}
}
