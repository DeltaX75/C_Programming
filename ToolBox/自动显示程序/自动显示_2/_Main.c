#include "Display.h"

int main()
{
	UI();
	int i;
	//for(i=1;i<=1000;++i)
	//{
	//	nBackspace(3);
	//	printf("%d",i);
	//	Sleep(1);
	//}
	One_by_one("Loading...\n",100);
	One_by_one("Learning...\n",100);
	One_by_one("Preparing...\n",100);
	One_by_one("Reviewing...\n",100);
	for(i=1;i<=100;++i)
	{
		nBackspace(30);
		printf("%d%%",i);
		Sleep(f(i)+10);
	}
	putchar('\n');
	Sleep(1000);
	printf("I'm Ready!\n");

	system("pause");
	return 0;
}
