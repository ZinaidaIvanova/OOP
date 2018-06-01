#include "stdafx.h"
#include "CPoint.h"
#include <iomanip>
#include <sstream>

CPoint::CPoint()
{
}

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

void CPoint::SetPoint(double const & x, double const & y)
{
	m_x = x;
	m_y = y;
}
