#include "stdafx.h"
#include "CTriangle.h"


CTriangle::CTriangle(CPoint const & firstVerex, CPoint const & secondVertex, CPoint const & thirdVertex):
m_vertex1(firstVerex),
m_vertex2(secondVertex),
m_vertex3(thirdVertex)
{
}


double CTriangle::GetArea() const
{
	double halfPerimeter = 0.5*GetPerimeter();
	return std::sqrt(halfPerimeter*(halfPerimeter - GetSideLength(m_vertex1, m_vertex2))*(halfPerimeter - GetSideLength(m_vertex2, m_vertex3))
		*(halfPerimeter - GetSideLength(m_vertex3, m_vertex1)));
}

double CTriangle::GetPerimeter() const
{
	return GetSideLength(m_vertex1, m_vertex2) + GetSideLength(m_vertex2, m_vertex3) + GetSideLength(m_vertex3, m_vertex1);
}

std::string CTriangle::ToString() const
{
	/*std::ostringstream str;
	str << std::fixed << std::setprecision(1);
	str << "Triangle" << std::endl
		<< "First vertex: (" << GetVertex1().x() << ", " << GetVertex1().y() << ")" << std::endl
		<< "Second vertex: (" << GetVertex2().x() << ", " << GetVertex2().y() << ")" << std::endl
		<< "Third vertex: (" << GetVertex3().x() << ", " << GetVertex3().y() << ")" << std::endl
		<< "Area: " << GetArea() << std::endl
		<< "Perimeter: " << GetPerimeter() << std::endl
		<< "Line color: " << GetOutlineColor() << std::endl
		<< "Fill color: " << GetFillColor() << std::endl;
	return str.str();*/
	return std::string();
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

double CTriangle::GetSideLength(CPoint const & firstVerix, CPoint const & secondVertix) const
{
	double X = secondVertix.x() - firstVerix.x();
	double Y = secondVertix.y() - firstVerix.y();
	return std::sqrt(X * X + Y * Y);
}
