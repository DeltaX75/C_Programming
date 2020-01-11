#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100
#define M 50
void Info();
void UI();
int main()
{
	UI();
	Info();
	char x[N],y[M][N];
	int i,length=0;



	system("pause");
	return 0;
}

void UI()
{
	system("title LCD.h优化程序 - By Walter Brien");

}

void Info()
{
	printf("本程序基于STM32中的LCD.h文件\n");
	printf("主要功能为 对LCD_ShowString函数的优化\n");
	printf("主要有两种规格的屏幕\n");
	printf("4.3寸 800x480\n3.5寸 480x320\n");


}

void Rectangle(int size,int num)
{


}

struct Rect{


};

