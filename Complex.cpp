#include "Complex.h"
#include <string>

TComplex::TComplex()
{
	re = 0;
	im = 0;
}

TComplex::TComplex(double _re, double _im)
{
	this->re = _re;
	this->im = _im;
}

TComplex::TComplex(const TComplex& name)
{
	re = name.re;
	im = name.im;
}

double TComplex::GetRe()
{
	return re;
}

double TComplex::GetIm()
{
	return im;
}

void TComplex::SetRe(double _re)
{
	re = _re;
}

void TComplex::SetIm(double _im)
{
	im = _im;
}

TComplex TComplex::operator+(TComplex& a)
{
	TComplex res;
	res.re = re + a.re;
	res.im = im + a.im;
	return res;
}

TComplex TComplex::operator-(TComplex& a)
{
	TComplex res;
	res.re = re - a.re;
	res.im = im - a.im;
	return res;
}

TComplex TComplex::operator*(TComplex& a)
{
	TComplex res;
	res.re = re * a.re - im * a.im;
	res.re = re * a.im + a.re * im;
	return res;
}

TComplex TComplex::operator/(TComplex& a)
{
	TComplex res;
	res.re = (re * a.re + im * a.im) / (a.re * a.re + a.im * a.im);
	res.im = (im * a.re - re * a.im) / (a.re * a.re + a.im * a.im);
	return res;
}

TComplex& TComplex::operator=(const TComplex& a)
{
	this->re = a.re;
	this->im = a.im;
	return *this;
}

bool TComplex::operator==(TComplex& a)
{
	if ((re == a.re) && (im == a.im))
	{
		return true;
	}
	else
	{
		return false;
	}
}

double TComplex::z()
{
	return std::sqrt(GetRe() * GetRe() + GetIm() * GetIm());
}

TComplex TComplex::complPow(double x)
{
	TComplex c, res;
	double f;
	c.re = GetRe();
	c.im = GetIm();
	f = std::atan(c.im / c.re);
	res.re = std::pow(c.z(), x) * std::cos(x * f);
	res.im = std::pow(c.z(), x) * std::sin(x * f);
	return res;
}

TComplex TComplex::complToComplPow(TComplex c)
{
	TComplex a, res;
	double f;
	a.re = GetRe();
	a.im = GetIm();
	f = std::atan(a.im / a.re);
	res.re = std::exp(c.re * std::log(a.z()) - c.im * f) * std::cos(c.im * std::log(a.z()) + c.re * f);
	res.im = std::exp(c.re * std::log(a.z()) - c.im * f) * std::sin(c.im * std::log(a.z()) + c.re * f);
	return res;
}

void TComplex::printTrignmForm()
{
	double f = std::atan(GetIm() / GetRe()),
	z = std::sqrt(GetRe() * GetRe() + GetIm() * GetIm());
	std::cout << z << "(cos(" << f << ") + sin(" << f << ")i)";
}

std::ostream& operator<<(std::ostream& a, TComplex& b)
{
	if (b.im == 0) // a+0i -> a
	{
		a << b.re;
	}
	else if (b.re == 0) // 0+bi -> bi
	{
		a << b.im << "i";
	}
	else
	{
		if (b.im > 0)
		{
			a << b.re << "+" << b.im << "i";
		}
		else
		{
			a << b.re << b.im << "i";
		}
	}
	return a;
}

std::istream& operator>>(std::istream& a, TComplex& b)
{
	std::string c;
	std::string s_re, s_im;
	double _re, _im;

	a >> c;
	
	if (c.find("-") != 0) // c -> +c
	{
		c = "+" + c;
	}

	if ((c.find("i") - c.rfind("+") == 1) || (c.find("i") - c.rfind("-") == 1)) // a+i -> a+1i, a-i -> a-1i
	{
		c.insert(c.find("i"), "1");
	}

	if (c.find("i") != size(c) - 1) // a -> a+0i, -a -> -a+0i
	{
		c = c + "+0i";
	}

	if ((c.find("+") == c.rfind("+") && (c.find("-") > size(c))) || (c.find("-") == c.rfind("-") && (c.find("+") > size(c)))) // +bi -> 0+bi, -bi -> 0-bi
	{
		c = "+0" + c;
	}

	if (c.find("+") != c.rfind("+") && c.find("-") > size(c)) // +a+bi
	{
		s_im = c.substr(c.rfind("+") + 1, c.find("i") - c.rfind("+") - 1);
		c.erase(c.rfind("+"));
		s_re = c.substr(1);
		c = "";
	}
	else if ((c.find("+") == c.rfind("+")) && (c.find("+") == 0) && (c.find("-") == c.rfind("-"))) // +a-bi
	{
		s_im = c.substr(c.rfind("-"), c.find("i") - c.rfind("-"));
		c.erase(c.rfind("-"));
		s_re = c.substr(1);
		c = "";
	}
	else if ((c.find("-") == c.rfind("-")) && (c.find("-") == 0) && (c.find("+") == c.rfind("+"))) // -a+bi
	{
		s_im = c.substr(c.rfind("+") + 1, c.find("i") - c.rfind("+") - 1);
		c.erase(c.rfind("+"));
		s_re = c;
		c = "";
	}
	else if (c.find("-") != c.rfind("-") && c.find("+") > size(c)) // -a-bi
	{
		s_im = c.substr(c.rfind("-"), c.find("i") - c.rfind("-"));
		c.erase(c.rfind("-"));
		s_re = c;
		c = "";
	}
	else
	{
		s_im = "0";
		s_re = "0";
		c = "";
	}

	try
	{
		_re = std::stof(s_re);
	}
	catch (std::exception)
	{
		_re = 0;
	}
	try
	{
		_im = std::stof(s_im);
	}
	catch (std::exception)
	{
		_im = 0;
	}

	b.SetIm(_im);
	b.SetRe(_re);

	return a;
}