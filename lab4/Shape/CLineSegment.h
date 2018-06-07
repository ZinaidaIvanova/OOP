#pragma once
#include <string>
#include "CPoint.h"
#include "IShape.h"

class CLineSegment final:
	public IShape
{
public:
	CLineSegment(CPoint const & firstVertex, CPoint const& secondVertix, std::string color);

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;

	std::string GetOutlineColor() const override;
	void SetOutlineColor(const std::string& color) override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_firstVertex, m_secondVertex;
	std::string m_color = "000000";
};

