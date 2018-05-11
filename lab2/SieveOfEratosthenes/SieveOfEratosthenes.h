#pragma once

#include <set>

bool IsNotInvalidArgument(int argc, char * argv[], int upperBound);

std::vector<bool> PrimeNumbersSelection(const int upperBound);

std::set<int> GeneratePrimeNumbersSet(const int upperBound);

void PrintPrimeNumbersSet(const std::set<int> &PrimeNumbersSet);
