#include "stdafx.h"
#include "../lab7-1/FindMaxEx.h"

struct athlete
{
	std::string name;
	int growth = 0;
	float weight = 0.0;
};

bool LessGrowth(athlete first, athlete second)
{
	return (first.growth < second.growth);
}

bool LessWeight(athlete first, athlete second)
{
	return (first.weight < second.weight);
}

const std::vector<athlete> AthleteList = {
	{ "Andrew", 180, 85.7f },
	{ "Ann", 168, 61.1f },
	{ "Jeana", 165, 56.9f },
	{ "Roman", 181, 80.0f },
	{ "Nicholay", 175, 86.1f }
};

TEST_CASE("Get the most growth athlete whith template")
{
	athlete maxGrowth;
	CHECK(FindMax(AthleteList, maxGrowth, LessGrowth));
	CHECK(maxGrowth.name == "Roman");
	CHECK(maxGrowth.growth == 181);
	CHECK(maxGrowth.weight == 80.0);
}

TEST_CASE("Get the most weight athlete whith template")
{
	athlete maxWeight;
	CHECK(FindMax(AthleteList, maxWeight, LessWeight));
	CHECK(maxWeight.name == "Nicholay");
	CHECK(maxWeight.growth == 175);
	CHECK(maxWeight.weight == 86.1);
}

TEST_CASE("A variable doesn't change and function return false if array is empty")
{
	athlete max = { "Andrew", 180, 85.7f };
	athlete maxCopy = max;
	std::vector<athlete> emptyList;
	CHECK_FALSE(FindMax(emptyList, max, LessWeight));
	CHECK(max.name == maxCopy.name);
	CHECK(max.growth == maxCopy.growth);
	CHECK(max.weight == maxCopy.weight);
}