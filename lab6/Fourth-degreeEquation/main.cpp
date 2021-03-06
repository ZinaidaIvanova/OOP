#include "stdafx.h"
#include "root2.h"
#include "Root3.h"
#include "root4.h"
#include "CardanoMethod.h"
#include "FerrariMethod.h"
#include "Second-degreeEquation.h"

std::vector<double> GetCoef(std::string& inputString)
{
	std::istringstream input(inputString);
	std::vector<double> coef;
	double num;
	while (input >> num)
	{
		coef.push_back(num);
	}
	if (coef.size() != 5)
	{
		throw std::invalid_argument("Equation must have 5 coefficient\n");
	}
	return coef;
}

int main()
{
	std::vector<double> coef;
	std::string inputString;
	while (std::getline(std::cin, inputString))
	{
		try
		{
			coef = GetCoef(inputString);
			CRoot4 solution = Solve4(coef);
			PrintRoot(solution);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
