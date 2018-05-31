#include "stdafx.h"
#include "IShape.h"



std::string IShape::GetOutlineColor() const
{
	return m_color;
}

void IShape::SetOutlineColor(std::string color)
{
	m_color = color;
}
