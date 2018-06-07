#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CRectangle :
	public ISolidShape
{
public:
	CRectangle(CPoint& leftTopPoint, double width, double height, std::string& outLineColor, std::string& fillColor);
	
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	
	std::string GetOutlineColor() const override;
	void SetOutlineColor(std::string color) override;
	void SetFillColor(std::string color) override;
	std::string GetFillColor() const override;
	
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

private:
	CPoint m_leftTop;
	double m_width, m_height;
	std::string m_color = "000000";
	std::string m_fillColor = "000000";
};

