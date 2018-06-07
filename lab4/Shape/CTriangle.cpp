#include "stdafx.h"
#include "CTriangle.h"
#include <iomanip>
#include <sstream>
#include "SecondaryFunctions.h"

CTriangle::CTriangle(CPoint const & firstVerex, CPoint const & secondVertex, CPoint const & thirdVertex, std::string& outLineColor, std::string& fillColor):
m_vertex1(firstVerex),
m_vertex2(secondVertex),
m_vertex3(thirdVertex),
m_color(outLineColor),
m_fillColor(fillColor)
{
}


double CTriangle::GetArea() const
{
	double halfPerimeter = 0.5*GetPerimeter();
	return std::sqrt(halfPerimeter*(halfPerimeter - GetLength(m_vertex1, m_vertex2))*(halfPerimeter - GetLength(m_vertex2, m_vertex3))
		*(halfPerimeter - GetLength(m_vertex3, m_vertex1)));
}

double CTriangle::GetPerimeter() const
{
	return GetLength(m_vertex1, m_vertex2) + GetLength(m_vertex2, m_vertex3) + GetLength(m_vertex3, m_vertex1);
}

std::string CTriangle::ToString() const
{
	std::ostringstream str;
	str << std::fixed << std::setprecision(1);
	str << "Triangle" << std::endl
		<< "First vertex: (" << GetVertex1().x() << ", " << GetVertex1().y() << ")" << std::endl
		<< "Second vertex: (" << GetVertex2().x() << ", " << GetVertex2().y() << ")" << std::endl
		<< "Third vertex: (" << GetVertex3().x() << ", " << GetVertex3().y() << ")" << std::endl
		<< "Area: " << GetArea() << std::endl
		<< "Perimeter: " << GetPerimeter() << std::endl
		<< "Line color: " << GetOutlineColor() << std::endl
		<< "Fill color: " << GetFillColor() << std::endl;
	return str.str();
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

std::string CTriangle::GetOutlineColor() const
{
	return m_color;
}

void CTriangle::SetOutlineColor(const std::string& color)
{
	m_color = color;
}

void CTriangle::SetFillColor(const std::string& color)
{
	m_fillColor = color;
}

std::string CTriangle::GetFillColor() const
{
	return m_fillColor;
}