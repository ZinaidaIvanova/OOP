#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CRectangle :
	public ISolidShape
{
public:
	CRectangle(CPoint leftTopPoint, double width, double height);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

private:
	CPoint m_leftTop;
	double m_width, m_height;

};

