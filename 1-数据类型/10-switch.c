#include <stdio.h>
#include <stdlib.h>

int main()
{
	float num1 = 0.0, num2 = 0.0;
	char opt;
	float result = 0.0;

	scanf("%f%c%f", &num1, &opt, &num2);

	switch(opt)
	{
		case '+':   //字符或者数字 不能是字符串 ==
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		default:
		//xx:
			result = num1 / num2;
			break;
	}
	printf("%-5.2f\n", result);  //5表示总长度  2表示小数位数  -表示左对齐
	printf("%-.2f\n", result);

	return 0;
}
