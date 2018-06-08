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

TEST_CASE("Complex number can use unary + and unary -")
{
	CComplex z(3.0, 2.5);
	CComplex w(0.6, -4.3);

	CHECK((+z).Re() == 3.0);
	CHECK((+z).Im() == 2.5);

	CHECK((+w).Re() == 0.6);
	CHECK((+w).Im() == -4.3);

	CHECK((-z).Re() == -3.0);
	CHECK((-z).Im() == -2.5);

	CHECK((-w).Re() == -0.6);
	CHECK((-w).Im() == 4.3);
}

TEST_CASE("Complex numbers can be added to the complex and real numbers")
{
	CComplex z(3.0, 2.5);
	CComplex w(0.6, -4.3);
	double x = 1.4;

	CHECK(fabs((z + w).Re() - 3.6) < FLT_EPSILON);
	CHECK(fabs((z + w).Im() + 1.8) < FLT_EPSILON);

	CHECK(fabs((w + x).Re() - 2.0) < FLT_EPSILON);
	CHECK(fabs((w + x).Im() + 4.3) < FLT_EPSILON);
}

TEST_CASE("Complex numbers can be subtracted")
{
	CComplex z(3.0, 2.5);
	CComplex w(0.6, -4.3);
	double x = 1.4;

	CHECK(fabs((z - w).Re() - 2.4) < FLT_EPSILON);
	CHECK(fabs((z - w).Im() - 6.8) < FLT_EPSILON);

	CHECK(fabs((w - x).Re() + 0.8) < FLT_EPSILON);
	CHECK(fabs((w - x).Im() + 4.3) < FLT_EPSILON);
}

TEST_CASE("Complex numbers can be multiplied")
{
	CComplex z(3.0, 2.5);
	CComplex w(0.6, -4.3);
	double x = 1.4;

	CHECK(fabs((z * w).Re() - 12.55) < FLT_EPSILON);
	CHECK(fabs((z * w).Im() + 11.4) < FLT_EPSILON);

	CHECK(fabs((x * w).Re() - 0.84) < FLT_EPSILON);
	CHECK(fabs((x * w).Im() + 6.02) < FLT_EPSILON);
}