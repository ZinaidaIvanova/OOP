#include "stdafx.h"
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
	std::string temp;
	while (std::getline(std::cin, temp))
	{
		try
		{
			coef = GetCoef(temp);
			try
			{
				PrintSolution(Solve4(coef));
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
