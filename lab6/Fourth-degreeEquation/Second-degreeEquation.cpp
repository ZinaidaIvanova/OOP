#include "stdafx.h"
#include "Second-degreeEquation.h" 
#include "root2.h"
#include <iostream>


CRoot2 Solve2(double a, double b, double c)
{
	const double d = b * b - 4 * a * c;
	CRoot2 result;
	if (fabs(d) < DBL_EPSILON)
	{
		result.SetRoot2(-1 * b / (2 * a));
	} 
	else
	{
		if (d > DBL_EPSILON)
		{
			result.SetRoot2(((-1 * b + sqrt(d)) / (2 * a)), ((-1 * b - sqrt(d)) / (2 * a)));
		}
	}
	return result;
}