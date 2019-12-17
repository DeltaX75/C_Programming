#include<iostream>	// 标准流
#include<fstream>		// 文件流
#include<string>		// 字符串
#include <sstream>
using namespace std;	// 使用std命名空间
int main()
{
	float a[100];
	int i=0;        //列
	string str;    	//字符串
	ifstream inFile;
	inFile.open("number.txt");	//打开文件

	if(inFile.is_open())	//若成功打开文件
	{
		while( !inFile.eof() )	//若未到文件结束
		{
			i=0;
			getline(inFile, str, '\n');	// 读取一行内容，存入存str中
			istringstream istr(str);
    		while( !istr.eof() )
    		{
      			istr >> a[i];
				cout << a[i] <<endl ;
        		i++;
   			}
		}
	// 		for(int ii=0;ii<i;ii++) 
	//        	cout << a[ii] <<endl ;
	}
	inFile.close();  // 关闭文件

	system("pause");
	return 0;
}

