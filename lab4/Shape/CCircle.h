#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CCircle :
	public ISolidShape
{
public:
	CCircle(CPoint center, double radius);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetCenter() const;
	double GetRadius() const;

private:
	CPoint m_center;
	double m_radius;
};

