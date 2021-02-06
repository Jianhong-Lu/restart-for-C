#include <stdio.h>

#define SIZE    10000

void ShellSort(int *a)
{
	int i, j, h;
	for (h = SIZE / 2; h >= 1; h = h / 2)
	{
		for (i = h; i < SIZE; i += h)
		{
			int tmp = a[i];
			for (j = i - h; j >= 0; j -= h)
			{
				if (a[j] > tmp)
				{
					a[j + h] = a[j];
				}
				else
				{
					break;
				}
			}
			a[j + h] = tmp;
		}
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

	ShellSort(a);

	for (i = 0; i < SIZE; i++)
	{
		//printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
