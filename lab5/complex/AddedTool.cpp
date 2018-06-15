#include "stdafx.h"
#include "AddedTool.h"

constexpr double myEpsilon = 1e-12;

bool AreEqualRealNumbers(const double a, const double b)
{
	return (fabs(a - b) < myEpsilon);
}