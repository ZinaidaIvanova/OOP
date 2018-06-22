#include "stdafx.h"
#include "CardanoMethod.h"
#include "Second-degreeEquation.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <algorithm>
#include "Root3.h"

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

CRoot3 Solve3(double a, double b, double c, double d)
{
	CRoot3 result;
	if (fabs(a) > DBL_EPSILON)
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
			result.SetRoot3(-b / 3);
		}
		else
		{
			result.SetRoot3((-2 * sgn(q) * sqrt(-p / 3) - b / 3), (sgn(q) * sqrt(-p / 3) - b / 3));
		}
	}
	else if (Q > DBL_EPSILON)
	{
		double z = (q < 0) ? pow(-q / 2. + sqrt(Q), 1 / 3.) : -pow(q / 2. + sqrt(Q), 1 / 3.);
		result.SetRoot3(z - p / 3. / z - b / 3);
	}
	else
	{
		double fi = fmod(atan2(-Q, -0.5 * q) + 2 * M_PI, 2 * M_PI);
		double root1 = 2 * sqrt(-p / 3) * cos(fi / 3) - b / 3;
		double root2 = 2 * sqrt(-p / 3) * cos((fi + 2 * M_PI) / 3) - b / 3;
		double root3 = 2 * sqrt(-p / 3) * cos((fi + 4 * M_PI) / 3) - b / 3;
		result.SetRoot3(root1, root2, root3);
	}
	return result;
}
