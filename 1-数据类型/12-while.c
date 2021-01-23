#include <stdio.h>

int main()
{
	/*while (表达式（非0成立）)
	{
		循环体
	}*/

	//while (1);    //如果循环体为空，后面加分号  当不知道循环次数的时候，用while循环

	//房价200万，程序员工资40万，房价每年涨10%，问几年买房

	float price = 200;
	int num = 0;
	int year = 0;

	while (num < price)   //while (1)
	{
		year++;
		num += 40;
		price = price * 1.1;
		printf("第 %d 买不起房\n", year);
	}

	printf("第 %d 年买房成功\n", year);
	
	return 0;
}
