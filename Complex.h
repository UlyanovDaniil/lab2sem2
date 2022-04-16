#pragma once
#include <iostream>

class TComplex
{
public:

	TComplex();
	TComplex(double _re, double _im);
	TComplex(const TComplex& name);

	double GetRe();
	double GetIm();
	void SetRe(double x);
	void SetIm(double x);

	TComplex operator+(TComplex& a);
	TComplex operator-(TComplex& a);
	TComplex operator*(TComplex& a);
	TComplex operator/(TComplex& a);
	TComplex& operator=(const TComplex& a);
	bool operator==(TComplex& a);

	double z();
	TComplex complPow(double x);
	TComplex complToComplPow(TComplex c);
	void printTrignmForm();

	friend std::ostream& operator<<(std::ostream& a, TComplex& b);
	friend std::istream& operator>>(std::istream& a, TComplex& b);

private:

	double re, im;

};