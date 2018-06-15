#pragma once
#include <vector>
#include <iostream>

struct EquationRoot4
{
	int numRoot = 0;
	std::vector<double> roots;
};

void AddSolution(std::vector<double>& solution2, EquationRoot4& solution4);

EquationRoot4 Solve4(std::vector<double> coef);

void PrintSolution(EquationRoot4 solution);