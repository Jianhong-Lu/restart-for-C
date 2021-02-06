#include <stdio.h>

#define SIZE    10000

void InsertSort(int *a)
{
	int i, j;
	for (i = 1; i < SIZE; i++)
	{
		int tmp = a[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j] > tmp)
			{
				a[j + 1] = a[j];
			}
			else
			{
				break;
			}
		}
		a[j + 1] = tmp;
	}
}

int main()
{
	int a[SIZE] = {0};

	int i;
	srand(time(NULL));
	for (i = 0; i < SIZE; i++)
	{
		a[i] = rand() % 1000;
	}

	InsertSort(a);

	for (i = 0; i < SIZE; i++)
	{
		//printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
