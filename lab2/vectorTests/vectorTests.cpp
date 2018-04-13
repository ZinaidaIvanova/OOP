// vectorTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../lab2/VectorsLab.h"

using namespace std;



TEST_CASE("GetMinElem test")
{
	vector<double> testArray = { 1, 2, 3, 4, 1 };
	double result = GetMinElem(testArray);
	REQUIRE(result == 1);

	testArray = { -1 , 0, 3 };
	result = GetMinElem(testArray);
	REQUIRE(result == -1);
}

TEST_CASE("ChangeVector test")
{
	vector<double> inputVector = {};
	vector<double> resultVector = {};
	vector<double> changeVector = ChangeVector(inputVector);

	REQUIRE(changeVector == resultVector);

	inputVector = { -1, 0, 2, 3.4 };
	resultVector = { 1, -0, -2, (-1)*(3.4) };
	changeVector = ChangeVector(inputVector);
	CHECK(changeVector == resultVector);

}


