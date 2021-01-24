#include <stdio.h>

int main()
{
	int a[3][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}};

	//用指针数组表示二维数组
	int *p1[3] = {a[0], a[1], a[2]};
	//p1[0]  就是   a[0]
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", p1[i][j]);
		}
		printf("\n");
	}

	//用数组指针表示二维数组
	int (*p2)[4] = a;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ",(*(p2 + i))[j]);
		}
		printf("\n");
	}

	return 0;
}
