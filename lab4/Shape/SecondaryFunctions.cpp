#include "stdafx.h"
#include "SecondaryFunctions.h"

double GetLength(CPoint const & firstPoint, CPoint const & secondPoint)
{
	double dx = secondPoint.x() - firstPoint.x();
	double dy = secondPoint.y() - firstPoint.y();
	return std::sqrt(dx * dx + dy * dy);
}
