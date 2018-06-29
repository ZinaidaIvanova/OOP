#include "stdafx.h"
#include "Root3.h"
#include <iostream>
#include <iterator>


void CRoot3::SetRoot3(double root)
{
	m_root1 = root;
	m_root2 = 0;
	m_root3 = 0;
	m_rootNum = 1;
}

void CRoot3::SetRoot3(double root1, double root2)
{
	m_root1 = root1;
	m_root2 = root2;
	m_root3 = 0;
	m_rootNum = 2;
}

void CRoot3::SetRoot3(double root1, double root2, double root3)
{
	m_root1 = root1;
	m_root2 = root2;
	m_root3 = root3;
	m_rootNum = 3;
}

double CRoot3::GetOneRoot3() const
{
	std::vector<double> result = GetRoot3();
	return *std::max_element(result.begin(), result.end());
}

std::vector<double> CRoot3::GetRoot3() const
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

	if (m_rootNum > 2)
	{
		result.push_back(m_root3);
	}

	std::sort(result.begin(), result.end());
	return result;
}