#include <stdio.h>
#define N 10
void Swap(int *a,int *b);
int main()
{
	int a[N]={4,8,-8,3,5,7,-5,11,6,15};

	int i,j;

	for(i=0;i<N;++i)
		for(j=0;j<N-i;++j)
			if(a[j] > a[j+1])
				Swap(&a[j],&a[j+1]);

	for(i=0;i<N;++i)
		printf("%d \n",a[i]);

	return 0;
}

void Swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
