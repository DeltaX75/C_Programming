#include "stdio.h"
#include <string.h>
#define N 100
int main()
{
	char a[N],x[N],y[N];
	int i,b;
	printf("字符串处理函数使用举例,按以下操作进行\n");
	printf("测试字符串gets及puts函数,请按1回车\n");
	printf("测试字符串连接函数strcat(cut and tie),请按2回车\n");
	printf("测试字符串比较函数strcmp(compare),请按3回车\n");
	printf("测试字符串长度计算函数strlen(length),请按4回车\n");
	printf("测试字符串拷贝函数1-strcpy(copy),请按5回车\n");
	printf("测试字符串拷贝函数2-strncpy(copy),请按6回车\n");
	scanf("%d",&b);
	getchar();
	switch(b)
	{
	case 1:
		printf("此处用于输入输出字符串gets及puts函数\n");
		printf("请输入一个字符串,然后输出结果\n");
		gets(a);
		puts(a);
		break;
	case 2:
		printf("\n此处用于字符串连接函数的测试strcat(cut and tie)\n");
		printf("请输入两个字符串,然后输出结果\n");
		gets(x);gets(y);
		puts(strcat(x,y));
		break;
	case 3:
		printf("\n此处用于字符串比较函数的测试strcmp(compare)\n");
		printf("请输入两个字符串,然后输出结果\n");
		gets(x);gets(y);
		i=strcmp(x,y);
		printf("比较返回值为%d\n",i);
		break;
	case 4:
		printf("\n此处用于字符串长度计算函数的测试strlen(length)\n");
		printf("请输入一个字符串,然后输出结果\n");
		gets(a);
		i=strlen(a);
		printf("字符串长度为%d\n",i);
		break;
	case 5:
		printf("\n此处用于字符串拷贝函数1的测试strcpy(copy)\n");
		printf("请输入两个字符串,将会把第二个字符串拷贝到第一个里\n");
		gets(x);gets(y);
		puts(strcpy(x,y));
		break;
	case 6:
		printf("\n此处用于字符串拷贝函数2的测试strncpy(copy)\n");
		printf("请输入两个字符串\n");
		gets(x);gets(y);
		printf("请输入你想把第二个字符串的前几个字符拷贝\ni=");
		scanf("%d",&i);
		puts(strncpy(x,y,i));
		break;
	default:
		printf("Error!\n");
	}
/*
	printf("\n此处用于输入输出字符串,原理是scanf,注意空格会截断\n");
	scanf("%s",a);
	printf("%s",a);
*/

	printf("\n测试结束!\n");
	return 0;
}

/*
char Gets(char 'a',char 'b')
{
	printf("请输入两个字符串,然后输出结果\n");
	char a[N],b[N];
	gets(a);
	gets(b);
}
*/



