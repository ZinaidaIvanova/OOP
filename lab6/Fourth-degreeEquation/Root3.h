#pragma once
#include <vector>

class CRoot3
{
public:
	CRoot3() = default;

	void SetRoot3(double root);
	void SetRoot3(double root1, double root2);
	void SetRoot3(double root1, double root2, double root3);

	std::vector<double> GetRoot3() const;
	double GetOneRoot3() const;

private:
	double m_root1 = 0;
	double m_root2 = 0;
	double m_root3 = 0;
	int m_rootNum = 0;
};