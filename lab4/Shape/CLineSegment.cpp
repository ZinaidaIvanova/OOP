#include "stdafx.h"
#include "CLineSegment.h"
#include <iomanip>
#include <sstream>

CLineSegment::CLineSegment(CPoint const & firstVerix, CPoint const & secondVertix, std::string color) :
	m_firstVerix(firstVerix),
	m_secondVertix(secondVertix),
	m_color(color)
{
}


double CLineSegment::GetArea()const
{
	return 0.0;
}

double CLineSegment::GetPerimeter() const
{
	double X = m_secondVertix.x() - m_firstVerix.x();
	double Y = m_secondVertix.y() - m_firstVerix.y();
	return std::sqrt(X * X + Y * Y);
}

std::string CLineSegment::ToString() const
{
	std::stringstream str;
	str << std::fixed << std::setprecision(1);
	str << "Line segment:" << std::endl  
		<< "Start point: (" << GetStartPoint().x() << ", " << GetStartPoint().y() << ")" << std::endl
		<< "End point: (" << GetEndPoint().x() << ", " << GetEndPoint().y() << ")" << std::endl
		<< "Area: " << GetArea() << std::endl
		<< "Perimeter: " << GetPerimeter() << std::endl
		<< "Color: " << GetOutlineColor() << std::endl;
	return str.str();
}


CPoint CLineSegment::GetStartPoint() const
{
	return m_firstVerix;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_secondVertix;
}

std::string CLineSegment::GetOutlineColor() const
{
	return m_color;
}

void CLineSegment::SetOutlineColor(std::string color)
{
	m_color = color;
}
