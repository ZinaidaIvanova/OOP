#include "stdafx.h"
#include "CLineSegment.h"


CLineSegment::CLineSegment(CPoint const & firstVerix, CPoint const & secondVertix, std::string const & color) :
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
	return 1.0;
}

std::string CLineSegment::ToString() const
{
	return std::string();
}

std::string CLineSegment::GetOutlineColor() const
{
	return std::string();
}

CPoint CLineSegment::GetStartPOint() const
{
	return CPoint(0, 0);
}

CPoint CLineSegment::GetEndPoint() const
{
	return CPoint(0, 0);
}
