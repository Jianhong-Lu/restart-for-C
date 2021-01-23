#include <stdio.h>

int f1()
{
	printf("hello\n");
	return 1;
}
int f2()
{
	printf("world\n");
	return 0;
}

int main()
{
	if (f1() || f2())   //短路原则  如果第一个表达式成立，则不会判断第二个表达式
	{
		printf("1\n");
	}

	int a = 0, b = 1;
	if (a && b)  //要求a和b同时成立（都是非0）逻辑与
	{
		
	}

	if (a || b)  //逻辑或 a和b只要有一个非0就行
	{
		
	}




	return 0;
}
