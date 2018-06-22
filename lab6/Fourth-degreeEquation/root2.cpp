#include "stdafx.h"
#include "root2.h"
#include <iostream>
#include <iterator>


std::vector<double> CRoot2::GetRoot2() const
{
	std::vector<double> result;
	if (m_rootNum > 0)
	{
		result.push_back(m_root1);
	}
	if (m_rootNum > 1)
	{
		result.push_back(m_root2);
	}
	std::sort(result.begin(), result.end());
	return result;
}

void CRoot2::SetRoot2(double root)
{
	m_root1 = root;
	m_root2 = 0;
	m_rootNum = 1;
}

void CRoot2::SetRoot2(double root1, double root2)
{
	m_root1 = root1;
	m_root2 = root2;
	m_rootNum = 2;
}