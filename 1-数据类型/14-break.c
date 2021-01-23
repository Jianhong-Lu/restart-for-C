#include <stdio.h>

int main()
{	
	int i, j;
	for (i = 0; i < 5; i++)
	{
		if (2 == i)
		{
			//break;     //结束这一层循环
			continue;    //结束这一次循环，继续下一次循环
		}
		printf("helloworld\n");
	}

	i = 5, j = 5;
	while (i--)
	{
		j = 5;
		while (j--)    //先判断，再减一，最后执行循环体
		{
			if (3 == j)
			{
				break;   //break或者continue不影响外层的循环
			}
			printf("this is %d\n", j);
		}
	}

	for (i = 0; i < 2000; i++)
	{
		for (j = 0; j < 2; j++);
	}

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2000; j++);
	}

	return 0;
}
