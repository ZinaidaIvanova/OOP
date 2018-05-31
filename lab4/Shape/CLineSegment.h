#pragma once
#include <string>
#include "CPoint.h"
#include "IShape.h"

class CLineSegment final:
	public IShape
{
public:
	CLineSegment(CPoint const & firstVerix, CPoint const& secondVertix, std::string const & color);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	CPoint GetStartPOint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_firstVerix, m_secondVertix;
	std::string m_color;
};

