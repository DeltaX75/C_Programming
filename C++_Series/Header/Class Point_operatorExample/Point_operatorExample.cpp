//Point_operatorExample.cpp
#include "Point_operatorExample.h"
Point::Point()
{
	x=0,y=0;
}
Point::Point(float a,float b)
{  
	x=a,y=b;
}
void Point::set(float m,float n){
	x=m,y=n;
}
void Point::display(){
	cout<<"("<<x<<','<<y<<")"<<endl;
}

Point Point::operator+(Point p){
	return Point(x+p.x,y+p.y);
}
Point Point::operator-(Point p){
	return Point(x-p.x,y-p.y);
}

Point Point::operator++(int)	//后缀p++
{
	Point old=*this;
	(this->x)++;
	(this->y)++;
	return old;
}
Point Point::operator++()	//前置++p
{
	this->x++;
	this->y++;
	return *this;
}

Point Point::operator--(int)	//后缀p--
{
	Point old=*this;
	(this->x)--;
	(this->y)--;
	return old;
}
Point Point::operator--()	//前置--p
{
	this->x--;
	this->y--;
	return *this;
}

bool Point::operator ==(Point p)
{
	if((this->x==p.x)&&(this->y==p.y))
		return 1;
	else
		return 0;
}
Point Point::operator=(Point p)
{
	this->x=p.x;
	this->y=p.y;
	return *this;
}

float Point::getX()
{
	return x;
}

float Point::getY()
{
	return y;
}