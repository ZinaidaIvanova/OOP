#include "stdafx.h"
#include "CComplex.h"
#include "AddedTool.h"
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

CComplex CComplex::GetComplexConjugate() const
{
	return CComplex(m_re, -m_im);
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
	return CComplex(m_re - left.Re(), m_im - left.Im());
}

CComplex const CComplex::operator*(const CComplex & left) const
{
	return CComplex(m_re*left.Re() - m_im * left.Im(), m_re*left.Im() + m_im * left.Re());
}

CComplex const CComplex::operator/(const CComplex& left) const
{
	return (1.0 / (left.GetMagnitude() * left.GetMagnitude())) * CComplex(m_re, m_im) * left.GetComplexConjugate();
}

CComplex CComplex::operator+=(const CComplex & num)
{
	m_re += num.Re();
	m_im += num.Im();
	return *this;
}

CComplex CComplex::operator-=(const CComplex & num)
{
	m_re -= num.Re();
	m_im -= num.Im();
	return *this;
}

CComplex CComplex::operator*=(const CComplex & num)
{
	return *this = *this * num;
}

CComplex CComplex::operator/=(const CComplex & num)
{
	return *this = *this / num;
}

bool CComplex::operator==(const CComplex & left) const
{
	return AreEqualRealNumbers(m_re, left.Re()) && AreEqualRealNumbers(m_im, left.Im());
}

bool CComplex::operator!=(const CComplex & left) const
{
	return !(*this == left);
}


CComplex const operator+(const CComplex & right, const double & left)
{
	return CComplex(right.Re() + left, right.Im());
}

CComplex const operator-(const CComplex & right, const double & left)
{
	return CComplex(right.Re() - left, right.Im());
}

CComplex const operator*(const double& right, const CComplex & left)
{
	return CComplex(right* left.Re(), right * left.Im());
}

CComplex const operator/(const double& right, const CComplex & left)
{
	return (1 / (left.GetMagnitude() * left.GetMagnitude())) * right * left.GetComplexConjugate();
}

bool const operator==(const double & right, const CComplex & left)
{
	return AreEqualRealNumbers(right, left.Re()) && AreEqualRealNumbers(0.0, left.Im());
}

bool const operator!=(const double & right, const CComplex & left)
{
	return !(right == left);
}
