#include <stdio.h>

#define SIZE    10

int less(int x, int y)
{
	return (x > y) ? 1 : 0;
}
int greater(int x, int y)
{
	return (x < y) ? 1 : 0;
}

void sort(int a[], int (*p)(int, int))   //   p = less
{
	int i, j;
	for (i = 0; i < SIZE - 1; i++)
	{
		for (j = 0; j < SIZE - i - 1; j++)
		{
			//if (a[j] < a[j + 1])
			if (p(a[j], a[j + 1]))   //less(a[j], a[j + 1])
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
}

int main()
{
	int a[SIZE] = {0};

	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		scanf("%d", &a[i]);
	}

	sort(a, less);  //回调函数：把函数名作为另一个函数的参数
	
	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
