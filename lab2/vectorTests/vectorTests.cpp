// vectorTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../lab2/VectorsLab.h"

using namespace std;




TEST_CASE("ChangeVector test")
{
	vector<double> inputVector = {};
	vector<double> resultVector = {};
	vector<double> changeVector = ChangeVector(inputVector);

	REQUIRE(changeVector == resultVector);

	inputVector = { -1, 0, 2, 3.4 };
	resultVector = { (-1)*(-1), (-1)*0, (-1)*2, (-1)*(3.4) };
	REQUIRE(resultVector == ChangeVector(inputVector));
}


