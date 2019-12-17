#include <iostream>
using namespace std;
class Point{
public:
	Point(){x=0,y=0;}
	Point(float a,float b);
	void set(float m,float n);
	void display();
	float getX(){return x;}
	float getY(){return y;}
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

class Line{
public:
	Line():p1(2,25),p2(){}
	Line(Point a,Point b):p1(a),p2(b){}
	void display();
private:
	Point p1,p2;
};
void Line::display(){
	cout<<"Point A: "<<"("<<p1.getX()<<','<<p1.getY()<<")"<<endl;
	cout<<"Point B: "<<"("<<p2.getX()<<','<<p2.getY()<<")"<<endl;
}

int main(){

    system("pause");
    return 0;
}
