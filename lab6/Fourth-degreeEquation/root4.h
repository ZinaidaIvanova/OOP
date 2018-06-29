#pragma once
#include <vector>

class CRoot4
{
public:
	CRoot4() = default;

	bool SetNextRoot(double root);

	std::vector<double> GetRoot4() const;
	int GetRootsNum() const;
	//void PrintRoot() const;

private:
	double m_root1 = 0;
	double m_root2 = 0;
	double m_root3 = 0;
	double m_root4 = 0;
	int m_rootNum = 0;
};