#pragma once

template <size_t MaxRoots>
class CRoots
{
public:
	explicit CRoots(const std::vector<double>& roots)
	{
		if (roots.size() > MaxRoots)
		{
			throw std::invalid_argument("Vector elements number exceeds the possible equation roots number");
		}
		m_roots = roots;
	}

	std::vector<double> GetRoot const
	{
		std::sort(m_roots.begin(), m_roots.end());
		return m_roots;
	}

	double GetOneRoot() const
	{
		return *std::max_element(m_roots.begin(), m_roots.end());
	}

private : std::vector<double> m_roots;
};