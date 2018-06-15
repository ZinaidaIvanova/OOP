#include "stdafx.h"
#include "CardanoMethod.h"
#include "Second-degreeEquation.h"
#include "FerrariMethod.h"


int main()
{
	std::vector<double> coef;
	std::string temp;
	while(std::getline(std::cin, temp))
	{
		std::istringstream strm(temp);
		double num;
		while (strm >> num)
		{
			coef.push_back(num);
		}
		try
		{
			PrintSolution(Solve4(coef));
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}

