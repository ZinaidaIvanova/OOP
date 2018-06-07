#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CCircle :
	public ISolidShape
{
public:
	CCircle(CPoint& center, double radius, std::string& outLineColor, std::string& fillColor);
	
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	
	std::string GetOutlineColor() const override;
	void SetOutlineColor(std::string color) override;
	void SetFillColor(std::string color) override;
	std::string GetFillColor() const override;
	
	CPoint GetCenter() const;
	double GetRadius() const;

private:
	CPoint m_center;
	double m_radius;
	std::string m_color = "000000";
	std::string m_fillColor = "000000";
};

