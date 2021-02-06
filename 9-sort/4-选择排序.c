#include <stdio.h>

#define SIZE    10000

void SelectSort(int *a)
{
	int i, j;
	for (i = 0; i < SIZE - 1; i++)
	{
		int index = i;
		int min = a[i];
		for (j = i + 1; j < SIZE; j++)
		{
			if (a[j] < min)
			{
				index = j;
				min = a[j];
			}
		}

		a[index] = a[i];
		a[i] = min;
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

	SelectSort(a);

	for (i = 0; i < SIZE; i++)
	{
		//printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
