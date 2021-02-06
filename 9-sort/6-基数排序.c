#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE    10000

void RadixSort(int *a)
{
	int i, max = a[0];
	for (i = 1; i < SIZE; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	int radix = 1;
	int *data = (int *)malloc(SIZE * 4);
	if (NULL == data)
	{
		printf("申请内存失败\n");
		return;
	}

	while (max > 0)
	{
		int bucket[10] = {0};

		for (i = 0; i < SIZE; i++)    //分配
		{
			bucket[a[i] / radix % 10]++;	
		}

		for (i = 1; i < SIZE; i++)
		{
			bucket[i] = bucket[i] + bucket[i - 1];
		}

		for (i = SIZE - 1; i >= 0; i--)
		{
			data[bucket[a[i] / radix % 10] - 1] = a[i];
			bucket[a[i] / radix % 10]--;
		}

		memcpy(a, data, SIZE * sizeof(int));

		max /= 10;
		radix *= 10;
	}

	free(data);
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

	RadixSort(a);

	for (i = 0; i < SIZE; i++)
	{
		//printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
