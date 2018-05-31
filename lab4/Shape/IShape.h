#pragma once
class IShape
{
public:
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	std::string GetOutlineColor() const;
	void SetOutlineColor(std::string color);
private:
	std::string m_color;
};

