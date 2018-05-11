#include "stdafx.h"
#include "SieveOfEratosthenes.h"

const int upperBoundMaxValue = 100000000;



bool AreInvalidArgument(int argc, char * argv[], int upperBound)
{
	if (argc != 2)
	{
		std::cout << "Invalid argument count!\n"
			<< "Usage: main.exe <upperBound>\n";
		return true;
	}
	std::string inputNumberString = argv[1];
	
	try
	{
		upperBound = std::stoi(inputNumberString);
	}
	catch (...)
	{
		std::cout << "Invalid argument\n" << "<upperBound> must be number\n";
		return true;
	}

	if ((upperBound < 0) || (upperBound > upperBoundMaxValue))
	{
		std::cout << "Invalid argument\n" << "<upperBound> must be in range 0 to 100000000\n";
		return true;
	}

	return false;
}

std::vector<bool> PrimeNumbersSelection(const int upperBound)
{
	std::vector<bool> primeInd(upperBound, true);
	primeInd[0] = false;
	for (int prime = 2; prime * prime <= upperBound; prime++) {
		if (primeInd[prime - 1])
		{
			for (int i = prime * prime; i <= upperBound; i += prime)
			{
				primeInd[i - 1] = false;
			}
		}
	}
	return primeInd;
}

std::set<int> GeneratePrimeNumbersSet(const int upperBound)
{
	std::set<int> result;
	if ((upperBound >= 2) && (upperBound <= upperBoundMaxValue))
	{
		std::vector<bool> primeInd = PrimeNumbersSelection(upperBound);
		{
			for (int i = 2; i <= upperBound; i++)
			{
				if (primeInd[i - 1])
				{
					result.insert(i);
				}
			}
		}
	}
	return result;
}

void PrintPrimeNumbersSet(const std::set<int> &PrimeNumbersSet)
{
	for (int prime : PrimeNumbersSet)
	{
		std::cout << prime << " ";
	}
	std::cout << "\n";
}