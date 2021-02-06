#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE    10000

void Merge(int *a, int start, int mid, int end)
{
	int left_len = mid - start + 1;
	int right_len = end - mid;

	int *L = (int *)malloc(sizeof(int) * left_len);
	int *R = (int *)malloc(sizeof(int) * right_len);

	int i, j, k;

	for (i = 0, k = start; i < left_len; i++, k++)
	{
		L[i] = a[k];
	}

	for (j = 0, k = mid + 1; j < right_len; j++, k++)
	{
		R[j] = a[k];
	}

	for (i = 0, j = 0, k = start; i < left_len && j < right_len; k++)
	{
		if (L[i] < R[j])
		{
			a[k] = L[i++];
		}
		else
		{
			a[k] = R[j++];
		}
	}

	if (j == right_len)
	{
		while (i < left_len)
		{
			a[k++] = L[i++];
		}
	}
	else if (i == left_len)
	{
		while (j < right_len)
		{
			a[k++] = R[j++];
		}
	}

	free(L);
	free(R);
}

void Sort(int *a, int start, int end)
{
	if (start >= end)
		return;

	int mid = (start + end) / 2;
	Sort(a, start, mid);
	Sort(a, mid + 1, end);

	Merge(a, start, mid, end);
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

	Sort(a, 0, SIZE - 1);

	for (i = 0; i < SIZE; i++)
	{
		//printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
