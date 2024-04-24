#pragma once

bool approximatelyEqual(double a, double b, double epsilon);

// Возвращаем true, если разница между a и b меньше absEpsilon
// или в пределах relEpsilon
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double
	relEpsilon);

void doTaskDependOnArgsOrPrintError(int countArgs, char* args[]);