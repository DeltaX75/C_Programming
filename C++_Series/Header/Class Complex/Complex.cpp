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
	return (re * re + im * im);
}
