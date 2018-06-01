#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CTriangle :
	public ISolidShape
{
public:
	CTriangle(CPoint const & firstVerix, CPoint const& secondVertix, CPoint const& thirdVertix);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	CPoint m_vertex1, m_vertex2, m_vertex3;
	double GetSideLength(CPoint const & firstVerix, CPoint const& secondVertix) const;
};

