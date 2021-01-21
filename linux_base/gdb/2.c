#include <stdio.h>

int add(int a, int b)
{
	int sum;
	sum = a + b;

	return sum;
}

int main()
{
	int a = 1, b = 2;
	int result;

	printf("call func ..\n");
	result = add(a, b);
	printf("%d\n", result);

	return 0;
}
