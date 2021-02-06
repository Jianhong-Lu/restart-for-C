#include <stdio.h>

#define SIZE    10000

void swap(int *x, int *y)
{
	int r = *x;
	*x = *y;
	*y = r;
}

void AdjustHeap(int *a, int root, int last)
{
	int child;
	while (2 * root + 1 <= last)
	{
		child = 2 * root + 1;   //左孩子
		if (child + 1 <= last && a[child] < a[child + 1])
		{
			child++;
		}

		if (a[child] > a[root])
		{
			swap(&a[child], &a[root]);
			root = child;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int *a)
{
	int i;
	for (i = SIZE / 2 - 1; i >= 0; i--)
	{
		AdjustHeap(a, i, SIZE - 1);     //数组  根  最后一个元素
	}
	
	for (i = 0; i < SIZE - 1; i++)
	{
		swap(&a[0], &a[SIZE - 1 - i]);
		AdjustHeap(a, 0, SIZE - 2 - i);
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

	HeapSort(a);

	for (i = 0; i < SIZE; i++)
	{
		//printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
