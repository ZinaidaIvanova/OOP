#pragma once

template <typename T, typename Less = std::less<T>>
bool FindMax(std::vector<T> const& arr, T& maxValue, Less const& less = Less())
{
	if (arr.empty())
	{
		return false;
	}

	const T *maxElem = &arr[0];
	for (auto &elem : arr)
	{
		if (less(*maxElem, elem))
		{
			maxElem = &elem;
		}
	}

	maxValue = *maxElem;

	return true;
}