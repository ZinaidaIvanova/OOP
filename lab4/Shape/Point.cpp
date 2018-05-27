#include "stdafx.h"
#include "Point.h"


CPoint::CPoint(double const & x, double const & y):m_x(x), m_y(y)
{
}

double CPoint::x() const
{
	return m_x;
}

double CPoint::y() const
{
	return m_y;
}
