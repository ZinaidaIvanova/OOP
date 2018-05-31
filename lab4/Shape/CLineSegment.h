#pragma once
#include <string>
#include "CPoint.h"
#include "IShape.h"

class CLineSegment final:
	public IShape
{
public:
	CLineSegment(CPoint const & firstVerix, CPoint const& secondVertix);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_firstVerix, m_secondVertix;
};

