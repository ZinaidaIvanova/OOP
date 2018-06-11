#pragma once
#include <vector>
#include <iostream>

struct EquationRoot4
{
	double numRoot;
	double roots[4];
};

std::vector<double> GetCoef(std::iostream &input);

EquationRoot4 Solve4(std::vector<double> coef);


