#include "stdafx.h"
#include "VectorsLab.h"


std::vector<double> GetVector()
{
	std::vector<double> inputNum(std::istream_iterator<double>(std::cin), (std::istream_iterator<double>()));
	return inputNum;
}

double GetMinElem(const std::vector<double>& numArr)
{
	auto result = std::min_element(numArr.begin(), numArr.end());
	return *result;
}


std::vector<double> ChangeVector(std::vector<double> &inputVector)
{
	if (inputVector.begin() != inputVector.end())
	{
		double minEl = GetMinElem(inputVector);
		for (auto vecElem:inputVector)
		{
			vecElem *= minEl;
			std::cout << vecElem << "  ";
		}
	}
	return inputVector;
}
