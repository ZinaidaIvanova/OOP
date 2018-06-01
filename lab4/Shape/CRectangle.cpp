#include "stdafx.h"
#include "CRectangle.h"

CRectangle::CRectangle(CPoint leftTopPoint, double width, double height)
{
}

double CRectangle::GetArea() const
{
	return 0.0;
}

double CRectangle::GetPerimeter() const
{
	return 0.0;
}

std::string CRectangle::ToString() const
{
	return std::string();
}

CPoint CRectangle::GetLeftTop() const
{
	return CPoint(0, 0);
}

CPoint CRectangle::GetRightBottom() const
{
	return CPoint(0, 0);
}

double CRectangle::GetWidth() const
{
	return 0.0;
}

double CRectangle::GetHeight() const
{
	return 0.0;
}
