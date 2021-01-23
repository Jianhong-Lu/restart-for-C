#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 1;

	//if (0 == a)
	//{
	//}

	float num1, num2;
	char opt;
	float result;

	scanf("%f%c%f", &num1, &opt, &num2);

	if ('+' == opt)
	{
		result = num1 + num2;
	}
	else if ('-' == opt)
	{
		result = num1 - num2;
	}
	else if ('*' == opt)
	{
		result = num1 * num2;
	}
	else if ('/' == opt)
	{
		result = num1 / num2;
	}
	else 
	{
		printf("error\n");
		exit(1);                      //退出程序
	}

	printf("%-5.2f\n", result);  //5表示总长度  2表示小数位数  -表示左对齐
	printf("%-.2f\n", result);

	return 0;
}
