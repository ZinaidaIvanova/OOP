#include "stdafx.h"
#include "CardanoMethod.h"
#include "FerrariMethod.h"
#include "Second-degreeEquation.h"
#include <sstream>
#include <iterator>

void AddSolution(std::vector<double>& solution2, EquationRoot4& solution4)
{
	if (!solution2.empty())
	{
		for (double el : solution2)
		{
			solution4.roots.push_back(el);
			solution4.numRoot++;
		}
	}
}

EquationRoot4 Solve4(std::vector<double> coef)
{
	EquationRoot4 solution;
	if (fabs(*coef.begin()) < DBL_EPSILON)
	{
		throw std::invalid_argument("First coefficient can't be 0\n");
	}

	double a = *coef.begin();
	for (auto& c : coef)
	{
		c /= a;
	}

	double y0 = GetOneCubicRoot(Solve3(1, -coef[2], coef[1] * coef[3] - 4 * coef[4], -pow(coef[1], 2) * coef[4] + 4 * coef[2] * coef[4] - pow(coef[3], 2)));

	double p = sqrt(pow(coef[1], 2) / 4 - coef[2] + y0);
	double q = sqrt(pow(y0, 2) / 4 - coef[4]);

	if ((coef[1] / 2 * y0 - coef[3]) < 0)
		q = -q;

	std::vector<double> solution1 = Solve2(1, coef[1] / 2 + p, y0 / 2 + q);
	std::vector<double> solution2 = Solve2(1, coef[1] / 2 - p, y0 / 2 - q);

	AddSolution(solution1, solution);
	AddSolution(solution2, solution);

	if (solution.numRoot == 0)
	{
		throw std::domain_error("The equation has no real solutions");
	}
	return solution;
}

void PrintSolution(EquationRoot4 solution)
{
	std::cout << "Equation has " << solution.numRoot << "roots\n";
	if (!solution.roots.empty())
	{
		for (double root : solution.roots)
		{
			std::cout << root << "\n";
		}
	}
}