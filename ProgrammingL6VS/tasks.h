#pragma once

bool approximatelyEqual(double a, double b, double epsilon);

// ���������� true, ���� ������� ����� a � b ������ absEpsilon
// ��� � �������� relEpsilon
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double
	relEpsilon);

void doTaskDependOnArgsOrPrintError(int countArgs, char* args[]);