#include "stdafx.h"
#include "../Fourth-degreeEquation/CardanoMethod.h"
#include "../Fourth-degreeEquation/FerrariMethod.h"
#include "../Fourth-degreeEquation/Second-degreeEquation.h"
#include "../Fourth-degreeEquation/root2.h"
#include "../Fourth-degreeEquation/Root3.h"
#include "../Fourth-degreeEquation/root4.h"
#include "../../catch/catch.hpp"
#include <iterator>

TEST_CASE("Quadratic can have two roots")
{
	std::vector<double> result = { 0, 2 };
	CRoot2 root = Solve2(1, -2, 0);
	CHECK(root.GetRoot2() == result);
}

TEST_CASE("Quadratic can have one root")
{
	std::vector<double> result = { 2 };
	CRoot2 root = Solve2(1, -4, 4);
	CHECK(root.GetRoot2() == result);
}

TEST_CASE("Quadratic can have null roots")
{
	std::vector<double> result;
	CRoot2 root = Solve2(1, 4, 5);
	CHECK(root.GetRoot2() == result);
}

TEST_CASE("Cubic can have 3 roots")
{
	std::vector<double> result = { 1.0, 2.0, 3.0 };
	CRoot3 root = Solve3(1, -6, 11, -6);
	CHECK(root.GetRoot3()[0] == result[0]);
	CHECK(root.GetRoot3()[1] == Approx(result[1]).epsilon(0.0001));
	CHECK(root.GetRoot3()[2] == result[2]);
}

TEST_CASE("Cubic can have 2 roots")
{
	std::vector<double> result = { -1, 1 };
	CRoot3 root = Solve3(1, 1, -1, -1);
	CHECK(root.GetRoot3() == result);
}

TEST_CASE("Cubic can have 1 3-tuple root")
{
	std::vector<double> result = { 1 };
	CRoot3 root = Solve3(1, -3, 3, -1);
	CHECK(root.GetRoot3() == result);
}

TEST_CASE("Cubic can have 1 roots")
{
	std::vector<double> result = { -1 };
	CRoot3 root = Solve3(1, 1, 1, 1);
	CHECK(root.GetRoot3() == result);
}

TEST_CASE("Fourth-degree equation can have 4 roots")
{
	std::vector<double> result = { 0, 1, 2, 3 };
	std::vector<double> coef = { 1, -6, 11, -6, 0 };
	CRoot4 root = Solve4(coef);
	CHECK(root.GetRoot4()[0] == Approx(result[0]).epsilon(0.01));
	CHECK(root.GetRoot4()[1] == Approx(result[1]).epsilon(0.01));
	CHECK(root.GetRoot4()[2] == Approx(result[2]).epsilon(0.01));
	CHECK(root.GetRoot4()[3] == Approx(result[3]).epsilon(0.01));
}

TEST_CASE("Fourth-degree equation can have 3 roots")
{
	std::vector<double> result = { 1, 1, 2, 3 };
	std::vector<double> coef = { 1, -7, 17, -17, 6 };
	CRoot4 root = Solve4(coef);
	CHECK(root.GetRoot4()[0] == Approx(result[0]).epsilon(0.01));
	CHECK(root.GetRoot4()[1] == Approx(result[1]).epsilon(0.01));
	CHECK(root.GetRoot4()[2] == Approx(result[2]).epsilon(0.01));
	CHECK(root.GetRoot4()[3] == Approx(result[3]).epsilon(0.01));
}

TEST_CASE("Fourth-degree equation can have 2 roots")
{
	std::vector<double> result = { 0, 1 };
	std::vector<double> coef = { 1, -2, 1, 0, 0 };
	CRoot4 root = Solve4(coef);
	CHECK(root.GetRoot4() == result);
}

TEST_CASE("Fourth-degree equation can have 0 roots")
{
	std::vector<double> result;
	std::vector<double> coef = { 1, 0, 3, 0, 2 };

	CHECK_THROWS_AS(Solve4(coef), std::domain_error);
}

TEST_CASE("Fourth-degree equation leading coefficient can not be zero")
{
	std::vector<double> result;
	std::vector<double> coef = { 0, 0, 3, 0, 2 };
	CHECK_THROWS_AS(Solve4(coef), std::invalid_argument);
}