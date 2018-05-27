#pragma once
class CPoint
{
public:
	CPoint(double const &x, double const &y);
	double x() const;
	double y() const;

private:
	double m_x, m_y;
};

