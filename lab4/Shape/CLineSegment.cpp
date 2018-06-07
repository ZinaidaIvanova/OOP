#include "stdafx.h"
#include "CLineSegment.h"
#include "SecondaryFunctions.h"
#include <iomanip>
#include <sstream>

CLineSegment::CLineSegment(CPoint const & firstVertex, CPoint const & secondVertex, std::string color) :
	m_firstVertex(firstVertex),
	m_secondVertex(secondVertex),
	m_color(color)
{
}


double CLineSegment::GetArea()const
{
	return 0.0;
}

double CLineSegment::GetPerimeter() const
{
	return GetLength(m_firstVertex, m_secondVertex);
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
	return m_firstVertex;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_secondVertex;
}

std::string CLineSegment::GetOutlineColor() const
{
	return m_color;
}

void CLineSegment::SetOutlineColor(const std::string& color)
{
	m_color = color;
}
