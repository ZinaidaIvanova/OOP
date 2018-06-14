#include "stdafx.h"
#include "CardanoMethod.h"
#include "Second-degreeEquation.h"


std::vector<double> Solve3(double a, double b, double c, double d)
{
	if (fabs(a) < DBL_EPSILON)
	{
		a /= a;
		b /= a;
		c /= a;
		d /= a;
	}
	const double p = c - b * b / 3;
	const double q = d + 2 * pow(b, 3) / 27 - b * c / 3;

}