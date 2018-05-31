#pragma once
#include "IShape.h"

class ISolidShape :
	public IShape
{
public:
	void SetFillColor(std::string color);
	std::string GetFillColor() const;

	virtual ~ISolidShape();

private:
	std::string m_fillColor;
};

