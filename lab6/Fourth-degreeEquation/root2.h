#pragma once

class CRoot2
{
public:
	CRoot2() = default;

	void SetRoot2(double root);
	void SetRoot2(double root1, double root2);

	std::vector<double> GetRoot2() const;

private:
	double m_root1 = 0;
	double m_root2 = 0;
	int m_rootNum = 0;
};