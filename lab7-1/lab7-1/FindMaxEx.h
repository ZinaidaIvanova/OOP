#pragma once

template <typename T, typename Less>
bool FindMax(std::vector<T> const& arr, T& maxValue, Less const& less = Less())
{
	if (arr.empty())
	{
		return false;
	}

	T maxElem = *arr.begin();
	for (T elem : arr)
	{
		if (less(maxElem, elem))
		{
			maxElem = elem;
		}
	}

	maxValue = maxElem;

	return true;
}