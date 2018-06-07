#pragma once
class CPoint
{
public:
	CPoint() = default;
	CPoint(double const &x, double const &y);

	double x() const;
	double y() const;
	void SetPoint(double const &x, double const &y);

private:
	double m_x = 0;
	double m_y = 0;
};

