#include <stdio.h>

int main()
{
	//for (第一个表达式; 第二个表达式; 第三个表达式)
	int i;
	/*for (i = 0; i < 5; i++) 
	{
		printf("\n");
	}*/
	//for (;;);  
	//for (; i < 10; )
	//{
	//}

	//printf("%d\n", printf("hello\n"));   //printf返回实际输出的字节数
	//return 0;

	for (i = 0,printf("1、i=%d\n",i);i<5,printf("2、%d\n",i);i++,printf("3、%d\n",i))
	{
		printf("4\n");
	}

	return 0;
}
