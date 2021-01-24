#include <stdio.h>

int main()
{
	int a[4] = {1, 2, 3, 4};
	int *p = a;
	int (*q)[4] = &a;

	int i;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", (*q)[i]);
	}

	return 0;
}
