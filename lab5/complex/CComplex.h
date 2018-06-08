#pragma once
class CComplex
{
public:
	CComplex(double re = 0, double im = 0);

	double Re() const;
	double Im() const;

	double GetMagnitude() const;
	double GetArgument() const;
	CComplex GetComplexConjugate() const;

	CComplex const operator +() const;
	CComplex const operator +(const CComplex& left) const;

	CComplex const operator -() const;
	CComplex const operator -(const CComplex& left) const;

	CComplex const operator *(const CComplex& left) const;
	CComplex const operator /(const CComplex& left) const;

	CComplex operator +=(const CComplex& num);
	CComplex operator -=(const CComplex& num);
	CComplex operator *=(const CComplex& num);
	CComplex operator /=(const CComplex& num);

	bool operator == (const CComplex& left) const;
	bool operator != (const CComplex& left) const;

private:
	double m_re;
	double m_im;
};

CComplex const operator +(const CComplex& right, const double& left);
CComplex const operator -(const CComplex& right, const double& left);
CComplex const operator *(const double& right, const CComplex& left);
CComplex const operator /(const double& right, const CComplex& left);





