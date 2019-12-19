//Complex.h
#include <iostream>
#include <cmath>
using namespace std;
#ifndef _COMPLEX_
	#define _COMPLEX_
class Complex{
public:
	Complex();
	Complex(double re,double im);
	void display();
	void set(double r,double i);
	void setRe(double r);
	void setIm(double i);
	Complex Conjugate();	//取共轭复数
	double getRe();
	double getIm();
	Complex operator*(Complex z);
	Complex operator+(Complex z);
	Complex operator-(Complex z);
	Complex operator/(Complex z);
	Complex operator=(Complex z);
	double module();
//	~Complex();
private:
	double re,im;
};

#endif
