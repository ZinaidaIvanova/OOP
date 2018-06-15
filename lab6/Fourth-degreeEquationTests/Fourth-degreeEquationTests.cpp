#include "stdafx.h"
#include "../Fourth-degreeEquation/CardanoMethod.h"
#include "../Fourth-degreeEquation/FerrariMethod.h"
#include "../Fourth-degreeEquation/Second-degreeEquation.h"
#include <iterator>

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

TEST_CASE("Cubic can have 3 roots")
{
	std::vector<double> result = { 3.0, 1.0, 2.0 };
	CHECK(Solve3(1, -6, 11, -6)[0] == result[0]);
	CHECK(Solve3(1, -6, 11, -6)[1] == result[1]);
	CHECK(Solve3(1, -6, 11, -6)[2] == Approx(result[2]).epsilon(0.0001));
}

TEST_CASE("Cubic can have 2 roots")
{
	std::vector<double> result = { 1, -1 };
	CHECK(Solve3(1, 1, -1, -1) == result);
}

TEST_CASE("Cubic can have 1 3-tuple root")
{
	std::vector<double> result = { 1 };
	CHECK(Solve3(1, -3, 3, -1) == result);
}

TEST_CASE("Cubic can have 1 roots")
{
	std::vector<double> result = { -1 };
	CHECK(Solve3(1, 1, 1, 1) == result);
}

TEST_CASE("Fourth-degree equation can have 4 roots")
{
	std::vector<double> result = { 1, 0, 3, 2 };
	std::vector<double> coef = { 1, -6, 11, -6, 0 };
	CHECK(Solve4(coef).roots[0] == Approx(result[0]).epsilon(0.01));
	CHECK(Solve4(coef).roots[1] == Approx(result[1]).epsilon(0.01));
	CHECK(Solve4(coef).roots[2] == Approx(result[2]).epsilon(0.01));
	CHECK(Solve4(coef).roots[3] == Approx(result[3]).epsilon(0.01));
}

TEST_CASE("Fourth-degree equation can have 3 roots")
{
	std::vector<double> result = { 0, 1, -1 };
	std::vector<double> coef = { 1, 0, -1, 0, 0 };
	CHECK(Solve4(coef).roots == result);
}

TEST_CASE("Fourth-degree equation can have 2 roots")
{
	std::vector<double> result = { 0, 1 };
	std::vector<double> coef = { 1, -2, 1, 0, 0 };
	CHECK(Solve4(coef).roots == result);
}

TEST_CASE("Fourth-degree equation can have 0 roots")
{
	std::vector<double> result;
	std::vector<double> coef = { 1, 0, 3, 0, 2 };
	CHECK_THROWS_AS(Solve4(coef).roots, std::domain_error);
}

TEST_CASE("Fourth-degree equation leading coefficient can not be zero")
{
	std::vector<double> result;
	std::vector<double> coef = { 0, 0, 3, 0, 2 };
	CHECK_THROWS_AS(Solve4(coef).roots, std::invalid_argument);
}