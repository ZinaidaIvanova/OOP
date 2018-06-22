#include "stdafx.h"
#include "root4.h"
#include <iostream>
#include <iterator>

bool CRoot4::SetNextRoot(double root)
{
	switch (m_rootNum)
	{
	case 0:
		m_root1 = root;
		break;
	case 1:
		m_root2 = root;
		break;
	case 2:
		m_root3 = root;
		break;
	case 3:
		m_root4 = root;
		break;
	default:
		return false;
	}
	m_rootNum++;
	return true;
}

std::vector<double> CRoot4::GetRoot4() const
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
	if (m_rootNum > 3)
	{
		result.push_back(m_root4);
	}
	return result;
}

void CRoot4::PrintRoot() const
{
	std::cout << "Equation has " << m_rootNum << " roots\n";
	if (m_rootNum != 0)
	{
		std::vector<double> result = GetRoot4();
		std::copy(result.begin(), result.end(), std::ostream_iterator<double>(std::cout, " "));
		std::cout << std::endl;
	}
}

double CRoot4::GetRootsNum() const
{
	return m_rootNum;
}