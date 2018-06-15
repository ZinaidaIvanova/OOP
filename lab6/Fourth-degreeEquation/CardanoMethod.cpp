#include "stdafx.h"
#include "CardanoMethod.h"
#include "Second-degreeEquation.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <algorithm>

int sgn(double a)
{
	if (a > 0)
	{
		return 1;
	}
	else if (a < 0)
	{
		return -1;
	}
	return 0;
}

std::vector<double> Solve3(double a, double b, double c, double d)
{
	std::vector<double> result;
	if (fabs(a) < DBL_EPSILON)
	{
		a /= a;
		b /= a;
		c /= a;
		d /= a;
	}
	const double p = c - b * b / 3.0;
	const double q = d + 2 * b * b * b / 27.0 - b * c / 3.0;
	const double Q = pow(p / 3, 3) + pow(q / 2, 2);
	if (fabs(Q) < DBL_EPSILON)
	{
		if (fabs(q) < DBL_EPSILON)
		{
			result.push_back(-b / 3);
		}
		else
		{
			result.push_back(-2 * sgn(q) * sqrt(-p/3) - b / 3);
			result.push_back(sgn(q) * sqrt(-p / 3) - b / 3);
		}
	}
	else if (Q > DBL_EPSILON)
	{
		double z = (q < 0) ? pow(-q / 2. + sqrt(Q), 1 / 3.) : -pow(q / 2. + sqrt(Q), 1 / 3.);
		result.push_back(z - p / 3. / z - b / 3);
	}
	else
	{
		double fi = fmod(atan2(-Q, -0.5 * q) + 2 * M_PI, 2 * M_PI);
		result.push_back(2 * sqrt(-p / 3) * cos(fi / 3) - b / 3);
		result.push_back(2 * sqrt(-p / 3) * cos((fi + 2 * M_PI) / 3) - b / 3);
		result.push_back(2 * sqrt(-p / 3) * cos((fi + 4 * M_PI) / 3) - b / 3);
	}
	return result;
}

double GetOneCubicRoot(std::vector<double> solution)
{
	return *solution.begin();
}