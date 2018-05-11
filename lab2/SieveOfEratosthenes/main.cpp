
#include "stdafx.h"
#include "SieveOfEratosthenes.h"


int main(int argc, char * argv[])
{
	int upperBound = 0;
	if (!AreInvalidArgument(argc, argv, upperBound))
	{
		PrintPrimeNumbersSet(GeneratePrimeNumbersSet(upperBound));
	}
	return 0;
}

