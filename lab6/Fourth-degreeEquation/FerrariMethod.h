#pragma once
#include "root2.h"
#include "root4.h"

void AddNextRoots(CRoot2& solution2, CRoot4& solution4);

CRoot4 Solve4(std::vector<double>& coef);

void PrintRoot(CRoot4 root)