#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	for(i=0;i<128;++i)
	{
		if( (i>='0'&&i<='9') || (i>='a'&&i<='z') || (i>='A'&&i<='Z') )
		{
		printf("%c\t十进制%d\t八进制%o\t十六进制%x\n",i,i,i,i);
		}
	}
	system("pause");
	return 0;
}
