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
	std::vector<double> resultVector;
	if (inputVector.begin() != inputVector.end())
	{
		double minEl = GetMinElem(inputVector);
		for (double vecElem:inputVector)
		{
			vecElem *= minEl;
			resultVector.push_back(vecElem);
		}
	}
	return resultVector;
}
