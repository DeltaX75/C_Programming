//Point_operatorExample.h
#include <iostream>
using namespace std;
#ifndef POINT
	#define POINT
class Point{
public:
	Point();
	Point(float a,float b);
	void set(float m,float n);
	void display();
	float getX();
	float getY();
	Point operator +(Point p);
	Point operator -(Point p);
	Point operator ++(int);	//后缀自增p++
	Point operator ++();	//前置自增++p
	Point operator --(int);
	Point operator --();
	bool operator ==(Point p);
	Point operator =(Point p);
private:
	float x,y;
};

#endif