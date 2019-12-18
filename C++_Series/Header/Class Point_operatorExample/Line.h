#include "Point_operatorExample.h"
#ifndef _LINE_
	#define _LINE_
	class Line{
public:
	Line():p1(2,25),p2(){}
	Line(Point a,Point b):p1(a),p2(b){}	//初始化Line中的对象a和b
	void display();
private:
	Point p1,p2;
};
#endif

