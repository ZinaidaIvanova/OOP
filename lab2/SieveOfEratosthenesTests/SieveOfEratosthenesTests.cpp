// SieveOfEratosthenesTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../SieveOfEratosthenes/SieveOfEratosthenes.h"


TEST_CASE("Sieve Of Eratosthenes Testing")
{
	std::set<int> primeNumberSet;
	CHECK(primeNumberSet == GeneratePrimeNumbersSet(1));
	CHECK(primeNumberSet == GeneratePrimeNumbersSet(100000001));
	primeNumberSet.insert(2); 
	CHECK(primeNumberSet == GeneratePrimeNumbersSet(2));
	primeNumberSet.insert(3);
	CHECK(GeneratePrimeNumbersSet(3) == primeNumberSet);
	CHECK(GeneratePrimeNumbersSet(4) == primeNumberSet);
	primeNumberSet.insert(5);
	CHECK(GeneratePrimeNumbersSet(5) == primeNumberSet);
	CHECK(GeneratePrimeNumbersSet(6) == primeNumberSet);
	primeNumberSet.insert(7);
	CHECK(GeneratePrimeNumbersSet(7) == primeNumberSet);
	CHECK(GeneratePrimeNumbersSet(8) == primeNumberSet);
	CHECK(GeneratePrimeNumbersSet(9) == primeNumberSet);
	CHECK(GeneratePrimeNumbersSet(10) == primeNumberSet);
	std::set<int> result;
	result = GeneratePrimeNumbersSet(100);
	CHECK(result.size() == 25);
	#ifndef _DEBUG
		result = GeneratePrimeNumbersSet(100000000);
		CHECK(result.size() == 5761455);
	#endif
}

