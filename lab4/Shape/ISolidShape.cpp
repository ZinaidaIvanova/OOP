#include "stdafx.h"
#include "ISolidShape.h"


void ISolidShape::SetFillColor(std::string color)
{
	m_fillColor = color;
}

std::string ISolidShape::GetFillColor() const
{
	return m_fillColor;
}

ISolidShape::~ISolidShape()
{
}
