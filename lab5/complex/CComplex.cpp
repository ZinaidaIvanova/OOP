#include "stdafx.h"
#include "CComplex.h"
#define _USE_MATH_DEFINES
#include <math.h>

CComplex::CComplex(double re, double im) :
	m_re(re),
	m_im(im)
{
}

double CComplex::Re() const
{
	return m_re;
}

double CComplex::Im() const
{
	return m_im;
}

double CComplex::GetMagnitude() const
{
	return sqrt(m_re * m_re + m_im * m_im);
}

double CComplex::GetArgument() const
{
	return fmod(atan2(m_im, m_re) + 2 * M_PI, 2 * M_PI);
}

CComplex const CComplex::operator+() const
{
	return *this;
}

CComplex const CComplex::operator+(const CComplex & left) const
{
	return CComplex(m_re + left.Re(), m_im + left.Im());
}

CComplex const CComplex::operator-() const
{
	return CComplex(-m_re, -m_im);
}

CComplex const CComplex::operator-(const CComplex & left) const
{
	return CComplex();
}

CComplex const CComplex::operator*(const CComplex & left) const
{
	return CComplex();
}

CComplex const CComplex::operator/(const CComplex) const
{
	return CComplex();
}

CComplex const operator+(const CComplex & right, const double & left)
{
	return CComplex(right.Re() + left, right.Im());
}

CComplex const operator-(const CComplex & right, const double & left)
{
	return CComplex();
}

CComplex const operator*(const float & right, const CComplex & left)
{
	return CComplex();
}

CComplex const operator/(const float & right, const CComplex & left)
{
	return CComplex();
}
