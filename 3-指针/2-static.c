#include <stdio.h>

void add()
{
	static int i = 0;    //静态变量 （存储的空间不一样，静态变量存放在静态数据区，函数执行完不会被释放）
	i++;
	printf("%d\n", i);
}

int main()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		add();	
	}

	return 0;
}
