#include <stdio.h>

int main()
{
	int a = 1, b = 2;
	//a++;     //单目运算符
	//a + b;   //双目运算符
	(a > b) ? a : b;   //三目运算符
	printf("%d\n", (a > b) ? a : b);

	//(a > b) ? a : b = 100;//C语言中条件运算符不能作为左值 因为C语言中，表达式的结果是数值
						   //但是在C++中，表达式的结果是b
						   //C语言   2 = 100   C++  b = 100
	printf("b = %d\n", b);

	return 0;
}
