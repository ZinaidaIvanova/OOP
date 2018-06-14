#include "stdafx.h"
#include "../Fourth-degreeEquation/Second-degreeEquation.h"


TEST_CASE("Quadratic can have two roots")
{
	std::vector<double> result = { 2, 0 };
	CHECK(Solve2(1, -2, 0) == result);
}

TEST_CASE("Quadratic can have one root")
{
	std::vector<double> result = { 2 };
	CHECK(Solve2(1, -4, 4) == result);
}

TEST_CASE("Quadratic can have null roots")
{
	std::vector<double> result;
	CHECK(Solve2(1, 4, 5) == result);
}
