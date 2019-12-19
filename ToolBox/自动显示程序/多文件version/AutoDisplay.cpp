#include "AutoDisplay.h"

void UI(){
	system("title 自动显示程序-By Walter Brien");
	system("mode con cols=45 lines=15");
}

void testDisplay()
{
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
}

void single_display(char a[],int t)
{
	printf(a);
	Sleep(t);
}

void Xh()
{
	printf("用于输出星花\n");
	printf("请输入你需要几行:");
	int k1,k2,n;
	scanf("%d",&n);
		for(k1=1;k1<=n;k1++)
		{
			printf("\t\t\t");
				for(k2=1;k2<=k1;k2++)
						putchar('\b');
				for(k2=1;k2<=k1*2-1;k2++)
					single_display("*",50);
			printf("\n");
		}
}
