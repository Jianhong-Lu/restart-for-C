#include <stdio.h>

#define SIZE    10

int main()
{
	int a[SIZE] = {0};

	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < SIZE - 1; i++)
	{
		for (j = 0; j < SIZE - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				/*int t;
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = a[j];*/

				a[j] = a[j] + a[j + 1];
				a[j + 1] = a[j] - a[j + 1];
				a[j] = a[j] - a[j + 1];     //引用 异或 
			}
		}
	}

	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
