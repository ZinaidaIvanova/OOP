#pragma once
#include "IShape.h"

class ISolidShape :
	public IShape
{
public:
	virtual void SetFillColor(const std::string& color) = 0;
	virtual std::string GetFillColor() const = 0;

	~ISolidShape() = default;
};

