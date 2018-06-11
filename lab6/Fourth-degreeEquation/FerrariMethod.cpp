#include "stdafx.h"
#include "FerrariMethod.h"
#include "CardanoMethod.h"
#include "Second-degreeEquation.h"
#include "AddedTool.h"


	std::vector<double> GetCoef(std::iostream& input)
{
	std::vector<double> coef;
	std::string temp;
	double num;
	while (input >> temp)
	{
		try
		{
			
		}
		catch (...)
		{

		}
	}
	return coef;
}


EquationRoot4 Solve4(std::vector<double> coef)
{
	if (AreEqualRealNumbers(*coef.begin(), 0))
	{
		throw std::invalid_argument("First coefficient can't be 0\n");//Проверить перевод
	}
	for (auto a : coef)
	{
		a /= (*coef.begin());
	}



	return EquationRoot4();
}