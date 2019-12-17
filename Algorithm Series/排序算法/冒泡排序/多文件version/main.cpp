#include "mppx.h"
int main()
{
	int a[N]={4,8,-8,3,5,7,-5,11,6,15};
	int i,j;
/*	
	for(i=0;i<N;++i)
		for(j=0;j<N-i;++j)
			if(a[j] > a[j+1])
				Swap(&a[j],&a[j+1]);
*/
	Sort(a);
	for(i=0;i<N;++i)
	printf("%d \n",a[i]);
	return 0;
}
