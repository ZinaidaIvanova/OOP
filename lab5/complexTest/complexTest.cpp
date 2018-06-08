#include "stdafx.h"
#include "../complex/CComplex.h"
#define _USE_MATH_DEFINES
#include <math.h>


TEST_CASE("Complex number has real and imaginary parts")
{
	CComplex z(3, -1.6);
	
	CHECK(z.Re() == 3);
	CHECK(z.Im() == -1.6);
}

TEST_CASE("Complex number has magnitude and argument")
{
	CComplex z(0, -3);
	CComplex w(1, 0);
	CComplex x(-5, 0);
	CComplex y(0, 2);
	double a = sqrt(2);
	CComplex t(a, a);

	CHECK(z.GetMagnitude() == 3.0);
	CHECK(z.GetArgument() == 3 * M_PI / 2);

	CHECK(w.GetMagnitude() == 1.0);
	CHECK(w.GetArgument() == 0);

	CHECK(x.GetMagnitude() == 5.0);
	CHECK(x.GetArgument() == M_PI);

	CHECK(y.GetMagnitude() == 2.0);
	CHECK(y.GetArgument() == M_PI / 2);

	CHECK(t.GetMagnitude() == 2.0);
	CHECK(t.GetArgument() == M_PI / 4);
}