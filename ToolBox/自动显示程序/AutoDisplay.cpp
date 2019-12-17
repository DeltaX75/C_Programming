#include "stdio.h"
#include <stdlib.h>
#include <windows.h>
void main()
{
	system("title 自动显示程序-By Walter Brien");
	system("mode con cols=45 lines=15");
	Sleep(500);
	printf("Loading");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".\n");
	Sleep(500);
	system("color f0");
	printf("Hello!\n");
	Sleep(1000);
	printf("Opening Files");
	Sleep(800);
	system("color f1");
	printf(".");
	Sleep(800);
	system("color f2");
	printf(".");
	Sleep(800);
	system("color f3");
	printf(".\n");
	Sleep(1000);
	system("color f9");
	printf("Analyzing");
	Sleep(1000);
	system("color f4");
	printf(".");
	Sleep(800);
	system("color f5");
	printf(".");
	Sleep(800);
	system("color f6");
	printf(".\n");
	Sleep(1000);
	system("color f1");
	printf("OK!\n");
	Sleep(1000);
	printf("You arE a Pig!\n\n");
	Sleep(2000);
	system("pause");
}
