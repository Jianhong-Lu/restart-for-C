#include <stdio.h>

int main()
{
	//int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	//int a[3][4] = {{1, 2}, {1}, {1, 2, 3}};
	//int a[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	//int a[][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int a[3][4] = {{0}};

	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("%p\n", &a[0][0]);   //数组首行首元素地址
	printf("%p\n", a[0]);       //数组首行首元素地址   printf("%p\n", a[1]);
	printf("%p\n", a);          //a表示首行的地址   printf("%p\n", a+1);  第二行地址
	printf("%p\n", &a);         //表示数组的地址 

	printf("****\n");

	printf("%p\n", &a[0][0] + 1);
	printf("%p\n", a[0] + 1);
	printf("%p\n", a + 1);
	printf("%p\n", &a + 1);

	

	return 0;
}
