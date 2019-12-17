//Complex.h
#include <iostream>
#include <cmath>
using namespace std;
#ifndef COMPLEX
#define COMPLEX
class Complex{
public:
	Complex();
	Complex(double re,double im);
	void display();
	void set(double r,double i);
	void setRe(double r);
	void setIm(double i);
	double getRe();
	double getIm();
	Complex operator*(Complex a);
	Complex operator+(Complex a);
	Complex operator-(Complex a);
	Complex operator/(Complex a);
	double module();
	~Complex();
private:
	double re,im;
};

#endif
