#include "stdafx.h"
#include "CCircle.h"
#include <iomanip>
#include <sstream>

//#include <cmath>
//#define _USE_MATH_DEFINES

constexpr double M_PI = 3.141592;

CCircle::CCircle(CPoint& center, double radius, std::string& outLineColor, std::string& fillColor):
m_center(center),
m_radius(radius),
m_color(outLineColor),
m_fillColor(fillColor)
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


std::string CCircle::GetOutlineColor() const
{
	return m_color;
}

void CCircle::SetOutlineColor(const std::string& color)
{
	m_color = color;
}

void CCircle::SetFillColor(const std::string& color)
{
	m_fillColor = color;
}

std::string CCircle::GetFillColor() const
{
	return m_fillColor;
}