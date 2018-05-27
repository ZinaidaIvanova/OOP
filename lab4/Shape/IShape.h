#pragma once
class IShape
{
public:
	virtual double GetArea() = 0;
	virtual double GetPerimetr() = 0;
	virtual std::string ToString() = 0;
	virtual std::string GetOutlineColor() = 0;
	virtual ~IShape();
};

