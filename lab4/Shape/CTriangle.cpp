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
	return 0.0;
}

double CTriangle::GetPerimeter() const
{
	return GetSideLength(m_vertex1, m_vertex2) + GetSideLength(m_vertex2, m_vertex3) + GetSideLength(m_vertex3, m_vertex1);
}

std::string CTriangle::ToString() const
{
	return std::string();
}

CPoint CTriangle::GetVertex1() const
{
	return CPoint(0, 0);
}

CPoint CTriangle::GetVertex2() const
{
	return CPoint(0, 0);
}

CPoint CTriangle::GetVertex3() const
{
	return CPoint(0, 0);
}

double CTriangle::GetSideLength(CPoint const & firstVerix, CPoint const & secondVertix) const
{
	double X = secondVertix.x() - firstVerix.x();
	double Y = secondVertix.y() - firstVerix.y();
	return std::sqrt(X * X + Y * Y);
}
