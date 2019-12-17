#include "mppx.h"

void Swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

void Sort(int x[])
{
	int i,j;
	for(i=0;i<N;++i)
		for(j=0;j<N-i;++j)
			if(x[j] > x[j+1])
				Swap(&x[j],&x[j+1]);
}
