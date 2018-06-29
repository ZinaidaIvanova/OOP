#pragma once
#include "root2.h"
#include "root4.h"
#include <iterator>
#include "root2.h"
#include "Root3.h"
#include "CardanoMethod.h"

#include "Second-degreeEquation.h"
#include <sstream>
#include <iostream>

void AddNextRoots(CRoot2& solution2, CRoot4& solution4);

CRoot4 Solve4(std::vector<double>& coef);

void PrintRoot(CRoot4 root);