// vectorTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../lab2/VectorsLab.h"

using namespace std;



TEST_CASE("GetMinElem test")
{
	vector <double> testArray = { 1, 2, 3, 4, 1 };
	double result = GetMinElem(testArray);
	REQUIRE(result == 1);

	testArray = { -1 , 0, 3 };
	result = GetMinElem(testArray);
	REQUIRE(result == -1);
}