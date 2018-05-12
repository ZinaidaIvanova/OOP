// lab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "VectorsLab.h"

int main()
{
	std::vector<double> inputNum = GetVector();
	ChangeVector(inputNum);
	std::sort(inputNum.begin(),inputNum.end());
	std::copy(inputNum.begin(), inputNum.end(), std::ostream_iterator<double>(std::cout, " "));
	std::cout << "\n";
	return 0;
}

