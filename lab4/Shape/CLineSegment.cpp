#include "stdafx.h"
#include "CLineSegment.h"


CLineSegment::CLineSegment(CPoint const & firstVerix, CPoint const & secondVertix) :
	m_firstVerix(firstVerix),
	m_secondVertix(secondVertix)
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
	/*std::stringstream str;
	str << std::fixed << std::setprecision(1);
	str << "Line segment:" << std::endl  
		<< "\tStart point: (" << GetStartPoint().x() << ", " << GetStartPoint().y() << ")" << std::endl
		<< "\tEnd point: (" << GetEndPoint().x() << ", " << GetEndPoint().y() << ")" << std::endl
		<< "\tArea: " << GetArea() << std::endl
		<< "\tPerimeter: " << GetPerimeter() << std::endl
		<< "\tColor: " << GetOutlineColor() << std::endl;
	return str.str();*/
	return std::string();
}


CPoint CLineSegment::GetStartPoint() const
{
	return m_firstVerix;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_secondVertix;
}
