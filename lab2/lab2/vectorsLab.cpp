#include "stdafx.h"
#include "VectorsLab.h"


std::vector<double> GetVector()
{
	std::vector<double> inputNum(std::istream_iterator<double>(std::cin), (std::istream_iterator<double>()));
	return inputNum;
}


 void ChangeVector(std::vector<double> &inputVector)
{
	if (!inputVector.empty())
	{
		auto minEl = *(std::min_element(inputVector.begin(), inputVector.end()));
		for (double &vecElem: inputVector)
		{
			vecElem *= minEl;
		}
	}

}
