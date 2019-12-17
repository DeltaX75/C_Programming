#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
void UI();
void Shutdown(char i[]);
int char_int(char i[]);
float char_float(char i[]);
int i_or_f(char in[]);
void Message1();
void int_to_char(int in,char x[]);

int main()
{
	UI();
	int flag,t;
	char input[20],output[20];
	float time=0;

	Message1();
	scanf("%d",&flag);
	getchar();

	printf("请输入延迟时间\n");
	gets(input);

	if(i_or_f(input))
		time = char_float(input);
	else
		time = char_int(input);
	printf("Your choice is No.%d\n",flag);
//	printf("Shutdown will work \n");
	switch(flag)
	{
		case 1:
			time *= 3600;
			t = int(time);
			break;
		case 2:
			t = int(time);
			break;
		case 3:
			time *= 60;
			t = int(time);
			break;
	}
	int_to_char(t,output);

	Shutdown(output);

//	printf("Your computer will shutdown in \n");


	printf("如想终止关机进程，请输入1并回车\n");
	scanf("%d",&flag);
	if(flag==1)
	{
		system("shutdown -a");
		printf("关机程序已终止!\n");
	}
	else
		printf("关机程序已设置完成!\n");
	printf("程序将在3秒后自动退出!\n");
	Sleep(3000);
	return 0;
}



void UI()
{
	system("title 延迟关机程序-By Walter Brien");
	system("mode con cols=45 lines=16");
	system("color f0");
}


void Shutdown(char input[])
{
	char m[25]={"shutdown -s -t "};
	system(strcat(m,input));
}


int char_int(char input[])
{

	int length=0,i=0,x[10],num=0,tenN=1;
	length = strlen(input);
	for(i=0;i<length;++i)
		tenN *= 10;

	if(length>7)
		return -1;

	for(i=0;i<length;++i)
		x[i] = input[i] - '0';
	
	for(i=0;i<length;++i)
	{
		tenN /= 10;
		num += tenN * x[i];
	}
	return num;

}


float char_float(char input[])
{
	int length,i,dot,a[10],b[10],an,bn;
	float num,x,y;
	x=y=0;
	length = strlen(input);
	for(i=0;i<length;++i)
	{	if(input[i] == '.')
		{
			dot = i;
			break;
		}
	}
	an = dot;
	bn = length - dot -1;

	for(i=0;i<dot;++i)
		a[i] = input[i] - '0';
	for(i=dot+1;i<length;++i)
		b[i-dot-1] = input[i] - '0';

	for(i=0;i<an;++i)
		x += pow(10,an-i-1) * a[i];

	for(i=0;i<bn;++i)
		y += pow(0.1,i+1) * b[i];
	num = x + y;
	return num;

}


int i_or_f(char in[])
{
	int flag=0;		//整数返回0，浮点数返回1
	int length,i;
	length = strlen(in);
	for(i=0;i<length;++i)
		if(in[i]=='.')
		{
			flag = 1;
			break;
		}
	return flag;
}


void Message1()
{
	printf("请选择延迟关机的模式\n");
	printf("1.按 小时 进行延迟关机\n");
	printf("2.按   秒 进行延迟关机\n");
	printf("3.按 分钟 进行延迟关机\n");
	printf("输入数字进行选择\n");
}


void int_to_char(int in,char x[])
{

	int i=0,length;
	char temp[20];
	while(in)
	{
		*(x+i) = in % 10 + '0';
		++i;
		in /= 10;
	}
	*(x+i) = '\0';
	
	length = strlen(x);

	for(i=0;i<length;++i)
		temp[i] = *(x+i);
	temp[i] = '\0';

	for(i=0;i<length;++i)
	{
		*(x+i) = temp[length - i - 1];
	}

}
