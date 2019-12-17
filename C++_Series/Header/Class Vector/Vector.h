//Vector.h
#include <iostream>
#include <cmath>
using namespace std;
#ifndef _VECTOR_
	#define _VECTOR_
	class vector{
	public:
		vector(){x=y=z=0;}		//默认构造函数零向量
		vector(double a,double b,double c);
		void setX(double t){x=t;}
		void setY(double t){y=t;}
		void setZ(double t){z=t;}
		void set(double a,double b,double c){x=a,y=b,z=c;}
		void display();
		double getX(){return x;}
		double getY(){return y;}
		double getZ(){return z;}
		void Default(){x=y=z=0;}	//初始化向量
		vector operator *(vector v);
		vector operator +(vector v);
		void zhijiao();		//转化为直角坐标
		void haokan();		//把约等于0的数变成0
		double module();	//向量的模长计算
	private:
		double x,y,z;
	};
#endif
