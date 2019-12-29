#include "Display.h"
void UI()
{
	system("title Are You Ready?");
	system("mode con cols=45 lines=15");
}
void nBackspace(int n)
{
	for(int i=1;i<=n;++i)
		putchar('\b');
}

void SingleD(char a[],int n)
{
	printf(a);
	Sleep(n);
}

void One_by_one(char a[],int n)
{
	int l,i;
	l = strlen(a);
	for(i=0;i<l;++i)
	{
		putchar(a[i]);
		Sleep(n);
	}
}

int f(int x)
{
	return -0.04*(x+100)*(x-100);
}