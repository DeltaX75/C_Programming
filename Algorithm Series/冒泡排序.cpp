#include <stdio.h>
#define N 10
void Swap(int *a,int *b);
int main()
{
	int a[N];

	return 0;
}

void Swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=*t;
}