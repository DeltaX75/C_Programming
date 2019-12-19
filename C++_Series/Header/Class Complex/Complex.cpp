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

Complex Complex::operator=(Complex z)
{
	this->re = z.re;
	this->im = z.im;
	return *this;
}

