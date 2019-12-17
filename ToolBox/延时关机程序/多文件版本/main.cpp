#include "Shutdown.h"
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


