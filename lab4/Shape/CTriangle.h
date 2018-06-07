#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CTriangle :
	public ISolidShape
{
public:
	CTriangle(CPoint const & firstVerix, CPoint const& secondVertix, CPoint const& thirdVertix, std::string& outLineColor, std::string& fillColor);
	
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	
	std::string GetOutlineColor() const override;
	void SetOutlineColor(std::string color) override;
	void SetFillColor(std::string color) override;
	std::string GetFillColor() const override;
	
	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	CPoint m_vertex1, m_vertex2, m_vertex3;
	std::string m_color = "000000";
	std::string m_fillColor = "000000";
	double GetSideLength(CPoint const & firstVerix, CPoint const& secondVertix) const;
};

