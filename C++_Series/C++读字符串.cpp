#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string a[100];	//采用string类型,存100行的文本,不要用数组
    int i=0;
    ifstream infile;
    infile.open("D:\\DeltaX\\iStudy\\Competition\\数学建模\\SelfMade\\_04集训4\\Temp\\Temp\\data.txt",ios::in);
 	//注意在"字符串双引号内"反斜线是\\两个一起
    while(!infile.eof())            // 若未到文件结束一直循环 
    {
        getline(infile, a[i],'\n');//读取一行，以换行符结束，存入a[]中
        i++;		//下一行
    }

    for(int ii=0;ii<i;ii++)		// 显示读取的txt内容 
    {  
        cout<<a[ii]<< endl;
    }
	infile.close();

	system("pause");
	return 0;
}

