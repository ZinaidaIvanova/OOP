// lab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "VectorsLab.h"

int main()
{
	std::vector<double> inputNum = GetVector();

	for (auto num : ChangeVector(inputNum))
	{
		std::cout << num << ", ";
	}
	std::cout << "\n";

	return 0;
}

