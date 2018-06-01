#include "stdafx.h"
#include "CRectangle.h"
#include <iomanip>
#include <sstream>

CRectangle::CRectangle(CPoint& leftTopPoint, double width, double height, std::string& outLineColor, std::string& fillColor):
	m_leftTop(leftTopPoint),
	m_width(width),
	m_height(height),
	m_color(outLineColor),
	m_fillColor(fillColor)
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
	std::ostringstream str;
	str << std::fixed << std::setprecision(1);
	str << "Rectangle" << std::endl
		<< "Left top vertex: (" << GetLeftTop().x() << ", " << GetLeftTop().y() << ")" << std::endl
		<< "Right bottom vertex: (" << GetRightBottom().x() << ", " << GetRightBottom().y() << ")" << std::endl
		<< "Width: " << GetWidth() << std::endl
		<< "Height: " << GetHeight() << std::endl
		<< "Area: " << GetArea() << std::endl
		<< "Perimeter: " << GetPerimeter() << std::endl
		<< "Line color: " << GetOutlineColor() << std::endl
		<< "Fill color: " << GetFillColor() << std::endl;
	return str.str();
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

std::string CRectangle::GetOutlineColor() const
{
	return m_color;
}

void CRectangle::SetOutlineColor(std::string color)
{
	m_color = color;
}

void CRectangle::SetFillColor(std::string color)
{
	m_fillColor = color;
}

std::string CRectangle::GetFillColor() const
{
	return m_fillColor;
}
