#include "stdafx.h"
#include "CCircle.h"
#include <iomanip>
#include <sstream>

//#include <cmath>
//#define _USE_MATH_DEFINES

constexpr double M_PI = 3.141592;

CCircle::CCircle(CPoint center, double radius):
m_center(center),
m_radius(radius)
{
}

double CCircle::GetArea() const
{
	return m_radius * m_radius * M_PI;
}

double CCircle::GetPerimeter() const
{
	return 2*m_radius * M_PI;
}

std::string CCircle::ToString() const
{
	std::ostringstream str;
	str << std::fixed << std::setprecision(1);
	str << "Circle" << std::endl
		<< "Center: (" << GetCenter().x() << ", " << GetCenter().y() << ")" << std::endl
		<< "Radius: " << GetRadius() << std::endl
		<< "Area: " << GetArea() << std::endl
		<< "Perimeter: " << GetPerimeter() << std::endl
		<< "Line color: " << GetOutlineColor() << std::endl
		<< "Fill color: " << GetFillColor() << std::endl;
	return str.str();
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}
