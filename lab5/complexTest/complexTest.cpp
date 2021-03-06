#include "stdafx.h"
#include "../complex/CComplex.h"
#include "../complex/AddedTool.h"
#include <cstdint>
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

	CHECK(AreEqualRealNumbers((z + w).Re(), 3.6));
	CHECK(AreEqualRealNumbers((z + w).Im(), -1.8));

	CHECK(AreEqualRealNumbers((w + x).Re(), 2.0));
	CHECK(AreEqualRealNumbers((w + x).Im(), -4.3));
}

TEST_CASE("Complex numbers can be subtracted")
{
	CComplex z(3.0, 2.5);
	CComplex w(0.6, -4.3);
	double x = 1.4;

	CHECK(AreEqualRealNumbers((z - w).Re(), 2.4));
	CHECK(AreEqualRealNumbers((z - w).Im(), 6.8));

	CHECK(AreEqualRealNumbers((w - x).Re(), -0.8));
	CHECK(AreEqualRealNumbers((w - x).Im(), -4.3));
}

TEST_CASE("Complex numbers can be multiplied")
{
	CComplex z(3.0, 2.5);
	CComplex w(0.6, -4.3);
	double x = 1.4;

	CHECK(AreEqualRealNumbers((z * w).Re(), 12.55));
	CHECK(AreEqualRealNumbers((z * w).Im(), -11.4));

	CHECK(AreEqualRealNumbers((x * w).Re(), 0.84));
	CHECK(AreEqualRealNumbers((x * w).Im(), -6.02));
}

TEST_CASE("Complex numbers can use operation of division")
{
	CComplex z(5.0, 3.0);
	CComplex w(4.0, -2.0);
	double x = 7.0;

	CHECK(AreEqualRealNumbers((z / w).Re(), 0.7));
	CHECK(AreEqualRealNumbers((z / w).Im(), 1.1));

	CHECK(AreEqualRealNumbers((x / w).Re(), 1.4));
	CHECK(AreEqualRealNumbers((x / w).Im(), 0.7));
}

TEST_CASE("Complex numbers can use operation +=")
{
	CComplex z(3.0, 2.5);
	CComplex w(0.6, -4.3);

	z += w;
	CHECK(AreEqualRealNumbers(z.Re(), 3.6));
	CHECK(AreEqualRealNumbers(z.Im(), -1.8));
}

TEST_CASE("Complex numbers can use operation -=")
{
	CComplex z(3.0, 2.5);
	CComplex w(0.6, -4.3);

	z -= w;

	CHECK(AreEqualRealNumbers(z.Re(), 2.4));
	CHECK(AreEqualRealNumbers(z.Im(), 6.8));
}

TEST_CASE("Complex numbers can use operation *=")
{
	CComplex z(3.0, 2.5);
	CComplex w(0.6, -4.3);

	z *= w;

	CHECK(AreEqualRealNumbers(z.Re(), 12.55));
	CHECK(AreEqualRealNumbers(z.Im(), -11.4));
}

TEST_CASE("Complex numbers can use operation /=")
{
	CComplex z(5.0, 3.0);
	CComplex w(4.0, -2.0);
	
	z /= w;

	CHECK(AreEqualRealNumbers(z.Re(), 0.7));
	CHECK(AreEqualRealNumbers(z.Im(), 1.1));
}


TEST_CASE("Complex numbers can use operations == and !=")
{
	CComplex z(5.0, -6.5);
	CComplex x(5.0, -6.5);
	CComplex w(3.14, 0.0);
	CComplex y(-3.2, 5.4);
	double pi = 3.14;

	CHECK(z == x);
	CHECK(pi == w);
	CHECK(!(x == y));
	CHECK(!(pi == y));
	CHECK(z != y);
	CHECK(pi != x);
	CHECK(!(z != x));
	CHECK(!(pi != w));
}