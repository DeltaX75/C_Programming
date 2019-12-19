//Complex.cpp
#include "Complex.h"
Complex::Complex()
{
	re = im = 0;
}
Complex::Complex(double a,double b)
{
	re = a, im = b;
}
double Complex::module()
{
	return ( sqrt(re * re + im * im) );
}

Complex Complex::Conjugate()
{	
	im = -im;
	return *this;
}

Complex Complex::operator*(Complex z)
{
	float a,b,c,d;
	a = this->re;
	b = this->im;
	c = z.re;
	d = z.im;
	this->re = a*c - b*d;
	this->im = a*d + b*c;
	return *this;
}

Complex Complex::operator/(Complex z)
{
	if(z.re == z.im && z.re ==0)
		return Complex(0,0);
	float a,b,c,d,m,n,p;
	a = this->re;
	b = this->im;
	c = z.re;
	d = z.im;
	p = 1 / (c*c + d+d);
	m = a*c + b*d;
	n = b*c - a*d;
	this->re = p*m;
	this->im = p*n;
	return *this;
}


Complex Complex::operator=(Complex z)
{
	this->re = z.re;
	this->im = z.im;
	return *this;
}

