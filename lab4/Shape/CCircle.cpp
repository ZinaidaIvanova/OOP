#include "stdafx.h"
#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <cmath>


CCircle::CCircle(CPoint center, double radius)
{
}

double CCircle::GetArea() const
{
	return 0.0;
}

double CCircle::GetPerimeter() const
{
	return 0.0;
}

std::string CCircle::ToString() const
{
	return std::string();
}

CPoint CCircle::GetCenter() const
{
	return CPoint(0, 0);
}

double CCircle::GetRadius() const
{
	return 0.0;
}
