#include <stdio.h>

#define SIZE    10000

void QuickSort(int *a, int start, int end)
{
	int i = start;
	int j = end;

	if (i >= j)
		return;

	int base = a[start];

	while (i < j)
	{
		while (i < j && a[j] > base)
		{
			j--;
		}

		if (i < j)
		{
			a[i++] = a[j];
		}

		while (i < j && a[i] < base)
		{
			i++;
		}
		if (i < j)
		{
			a[j--] = a[i];
		}
	}

	a[i] = base;

	QuickSort(a, start, i - 1);
	QuickSort(a, i + 1, end);
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

	QuickSort(a, 0, SIZE - 1);

	for (i = 0; i < SIZE; i++)
	{
		//printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
