#include "stdafx.h"
#include "CRectangle.h"

CRectangle::CRectangle(CPoint leftTopPoint, double width, double height):
	m_leftTop(leftTopPoint),
	m_width(width),
	m_height(height)
{
}

double CRectangle::GetArea() const
{
	return m_height * m_width;
}

double CRectangle::GetPerimeter() const
{
	return 2 * (m_height + m_width);
}

std::string CRectangle::ToString() const
{
	/*std::ostringstream str;
	str << std::fixed << std::setprecision(1);
	str << "Rectangle" << std::endl
		<< "Left top vertex: (" << GetLeftTop().x() << ", " << GetLeftTop().y() << ")" << std::endl
		<< "Right bottom vertex: (" << GetRightBottom().x() << ", " << GetRightBottom().y() << ")" << std::endl
		<< "Area: " << GetArea() << std::endl
		<< "Perimeter: " << GetPerimeter << std::endl
		<< "Line color: " << GetOutlineColor() << std::endl
		<< "Fill color: " << GetFillColor() << std::endl;
	return str.str();*/
	return std::string();
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return CPoint(m_leftTop.x() + m_width, m_leftTop.y() - m_height);
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}
