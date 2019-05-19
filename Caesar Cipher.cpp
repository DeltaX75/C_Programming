#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 2048
void Encrypt()
{
char in[N];
int d,length,i;
int t[N];
printf("请输入明文\n");
gets(in);
printf("请输入偏移量(注:向后取正,向前取负)\n");
scanf("%d",&d);
d%=26; //如果大于26无意义
d+=26;
d%=26; //这两步是为了让d恒为正,比如向前2相当于向后24
length=strlen(in);
for(i=0;i<=length;i++) //对in[N]进行复制
{
t[i]=in[i];
}
for(i=0;i<=length;i++)
{
if(in[i]>=('a')&&in[i]<=('z'))
{
t[i]+=d;
if(t[i]>'z') //这样就只需要判断一次向后超过'z'的情况
t[i]-=26; // char类型哪怕临时都不能越界128,所以用整数t[N]先代替
in[i]=t[i];
}
else if(in[i]>=('A')&&in[i]<=('Z'))
{
in[i]+=d;
if(in[i]>'Z') //这样就只需要判断一次向后超过'Z'的情况
in[i]-=26;
}
}
puts(in);
}
void Decrypt()
{
FILE *fp;
char ch[N];
int i=0,length,t,j,copy[N];
fp=fopen("password.txt","r");
if(fp!=NULL)
{
while(fscanf(fp,"%c",&ch[i])!=EOF) //读取数据到数组，直到文件结尾(返回EOF)
i++; //注意字符长度就是i的值
ch[i]='\0'; //可加可不加
fclose(fp);
}
length=i;
for(i=0;i<=length;i++)
{
copy[i]=ch[i];
}
for(t=1;t<=26;t++) //循环26次出来所有结果
{
	for(i=0;i<length;i++)
	{
		if(ch[i]>='a'&&ch[i]<='z')
		{
			copy[i]+=1;  //这个地方是+=1而不是=+t因为每次ch都会变动
			if(copy[i]>'z')
			{copy[i]-=26;}
			ch[i]=copy[i];
		}
		else if(ch[i]>='A'&&ch[i]<='Z')
		{
			ch[i]+=1;
			if(ch[i]>'Z')
			{ch[i]-=26;}
		}
	}
printf("第%2d次结果:",t);
puts(ch);
}
}
void Welcome()
{
printf("本程序用于加密/解密凯撒密码\n");
printf("请选择功能\n");
printf("1.加密\t2.解密\t3.说明\t4.退出\n");
}
void Help()
{
printf("把密文输入到同文件夹内password.txt中,直接选择\"解密\"即可\n");
}
void UI()
{
system("title Caesar Cipher");
system("mode con cols=80 lines=35");
system("color f0");
}
int main()
{
int choice;
UI();
Welcome();
scanf("%d%*c",&choice);
switch(choice)
{
case 1:Encrypt();system("pause");break;
case 2:Decrypt();system("pause");break;
case 3:Help();system("pause");break;
default:break;
}
return 0;
}
