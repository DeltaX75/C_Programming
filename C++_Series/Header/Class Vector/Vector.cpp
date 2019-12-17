//Vector.cpp
#include "Vector.h"
#define PI 3.14159265
double Deg_Rad(double t);
double Rad_Deg(double t);
vector::vector(double a,double b,double c){
	x=a,y=b,z=c;
}
void vector::display(){
	//cout<<"x= "<<x<<"	y="<<y<<"	z="<<z<<endl;
	cout<<x<<"\t"<<y<<"\t"<<z<<endl;
}
vector vector::operator*(vector v)	//叉乘重载
{
	double newX,newY,newZ;
	newX = this->y * v.z - this->z * v.y;
	newY = this->z * v.x - this->x * v.z;
	newZ = this->x * v.y - this->y * v.x;
	return vector(newX,newY,newZ);
}

vector vector::operator+(vector v)	//加法重载 向量加法
{
	double newX,newY,newZ;
	newX = this->x + v.x;
	newY = this->y + v.y;
	newZ = this->z + v.z;
	return vector(newX,newY,newZ);
}

double vector::module()
{
	return sqrt(x*x+y*y+z*z);
}

void vector::haokan()
{
	if(x<0.00001 && x>-0.00001)
		x=0;
	if(y<0.00001 && y>-0.00001)
		y=0;
	if(z<0.00001 && z>-0.00001)
		z=0;
}

void vector::zhijiao()	//如果输入球坐标则转换成直角坐标
{
	double r,theta,phi;
	r=x;	theta=Deg_Rad(y);	phi=Deg_Rad(z);
	x = r * sin(theta) * cos(phi);
	y = r * sin(theta) * sin(phi);
	z = r * cos(theta);
}

double Deg_Rad(double t)
{
	return t * PI / 180;
}

double Rad_Deg(double t)
{
	return t * 180 / PI;
}
