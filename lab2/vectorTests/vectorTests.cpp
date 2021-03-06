// vectorTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../lab2/VectorsLab.h"

using namespace std;




TEST_CASE("ProcessVector should not modify empty vector")
{
	vector<double> inputVector = {};
	vector<double> resultVector = {};
	ChangeVector(inputVector);
	REQUIRE(inputVector == resultVector);
}

TEST_CASE("ProcessVector multiplies each element by the minimum value")
{
	vector<double> inputVector = { -1, 0, 2, 3.4 };
	vector<double> resultVector = { (-1)*(-1), (-1) * 0, (-1) * 2, (-1)*(3.4) };
	ChangeVector(inputVector);
	REQUIRE(inputVector == resultVector);

}


