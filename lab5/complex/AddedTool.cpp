#include "stdafx.h"
#include "AddedTool.h"

bool AreEqualRealNumbers(const double a, const double b)
{
	return ((a - b) < DBL_EPSILON);
}
