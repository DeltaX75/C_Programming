#include "mppx.h"
int main()
{
	int a[N]={4,8,-8,3,5,7,-5,11,6,15};
	int i,j;
	
	Sort(a);
	for(i=0;i<N;++i)
	printf("%d \n",a[i]);
	return 0;
}

