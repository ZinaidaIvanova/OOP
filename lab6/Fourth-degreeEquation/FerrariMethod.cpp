#include "stdafx.h"
#include "FerrariMethod.h"

void AddNextRoots(CRoot2& solution2, CRoot4& solution4)
{
	std::vector<double> vec = solution2.GetRoot2();
	for (double elem : vec)
	{
		if (!solution4.SetNextRoot(elem))
		{
			std::cout << "Fourth-degree equation can have only 4 roots";
		}
	}
}

CRoot4 Solve4(std::vector<double>& coef)
{
	CRoot4 solution;
	if (fabs(*coef.begin()) < DBL_EPSILON)
	{
		throw std::invalid_argument("First coefficient can't be 0\n");
	}

	double a = *coef.begin();
	for (auto& c : coef)
	{
		c /= a;
	}

	CRoot3 cubicRoot = Solve3(1, (-coef[2]), (coef[1] * coef[3] - 4 * coef[4]), (-pow(coef[1], 2) * coef[4] + 4 * coef[2] * coef[4] - pow(coef[3], 2)));
	double y0 = cubicRoot.GetOneRoot3();

	double p = sqrt(pow(coef[1], 2) / 4 - coef[2] + y0);
	double q = sqrt(pow(y0, 2) / 4 - coef[4]);

	if ((coef[1] / 2 * y0 - coef[3]) < 0)
		q = -q;

	CRoot2 solution1 = Solve2(1, coef[1] / 2 + p, y0 / 2 + q);
	CRoot2 solution2 = Solve2(1, coef[1] / 2 - p, y0 / 2 - q);

	AddNextRoots(solution1, solution);
	AddNextRoots(solution2, solution);

	if (solution.GetRootsNum() == 0)
	{
		throw std::domain_error("The equation has no real solutions");
	}
	return solution;
}

void PrintRoot(CRoot4 root)
{
	std::cout << "Equation has " << root.GetRootsNum() << " roots\n";
	if (root.GetRootsNum() != 0)
	{
		std::vector<double> result = root.GetRoot4();
		std::copy(result.begin(), result.end(), std::ostream_iterator<double>(std::cout, " "));
		std::cout << std::endl;
	}
}