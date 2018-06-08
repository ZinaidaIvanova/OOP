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
	return CComplex(0, 0);
}

CComplex const CComplex::operator-() const
{
	return CComplex(0, 0);
}

CComplex const operator+(const CComplex & right, const CComplex & left)
{
	return CComplex(0,0);
}

CComplex const operator+(const float & right, const CComplex & left)
{
	return CComplex(0, 0);
}

CComplex const operator+(const CComplex & right, const float & left)
{
	return CComplex(0, 0);
}

CComplex const operator*(const CComplex & right, const CComplex & left)
{
	return CComplex(0, 0);
}

CComplex const operator*(const float & right, const CComplex & left)
{
	return CComplex(0, 0);
}

CComplex const operator*(const CComplex & right, const float & left)
{
	return CComplex(0, 0);
}
