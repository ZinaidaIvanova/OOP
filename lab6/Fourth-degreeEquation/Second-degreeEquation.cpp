#include "stdafx.h"
#include "Second-degreeEquation.h" 
#include <iostream>


std::vector<double> Solve2(double a, double b, double c)
{
	std::vector<double> result;
	const double d = b * b - 4 * a * c;
	if (fabs(d) < DBL_EPSILON)
	{
		result.push_back((-1 * b / (2 * a)));
	} 
	else
	{
		if (d > DBL_EPSILON)
		{
			result.push_back(((-1 * b + sqrt(d)) / (2 * a)));
			result.push_back(((-1 * b - sqrt(d)) / (2 * a)));
		}
	}
	return result;
}