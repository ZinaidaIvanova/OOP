#pragma once
class CComplex
{
public:
	CComplex(double re = 0, double im = 0);

	double Re() const;
	double Im() const;

	double GetMagnitude() const;
	double GetArgument() const;

	CComplex const operator +() const;
	CComplex const operator -() const;
	CComplex const operator *() const;
	CComplex const operator /(const CComplex) const;



private:
	double m_re;
	double m_im;
};

CComplex const operator +(const CComplex& right, const CComplex& left);
CComplex const operator +(const float& right, const CComplex& left);
CComplex const operator +(const CComplex& right, const float& left);

CComplex const operator -(const CComplex& right, const CComplex& left);
CComplex const operator -(const float& right, const CComplex& left);
CComplex const operator -(const CComplex& right, const float& left);

CComplex const operator *(const CComplex& right, const CComplex& left);
CComplex const operator *(const float& right, const CComplex& left);
CComplex const operator *(const CComplex& right, const float& left);

CComplex const operator /(const CComplex& right, const CComplex& left);
CComplex const operator /(const float& right, const CComplex& left);





