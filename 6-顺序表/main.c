#include <stdio.h>
#include "sequencelist.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_all(int x)
{
	printf("%d ", x);
}

void print_even(int x)
{
	if (x % 2 == 0)
	{
		printf("%d ", x);
	}
}

void print_odd(int x)
{
	if (x % 2 == 1)
	{
		printf("%d ", x);
	}
}

int main()
{
	//定义一个顺序表
	sqList list;
	//sqList *list;

	//初始化顺序表
	int ret = InitList(&list);   //如果需要修改实参的内容，一定传地址
	if (SUCCESS == ret)
	{
		printf("初始化成功\n");
	}
	else
	{
		printf("初始化失败\n");
	}

	//顺序表插入
	srand(time(NULL));
	int i, num;
	for (i = 0; i < 11; i++)
	{
		num = rand() % 20;
		ret = InsertList(&list, i + 1, num);
		if (SUCCESS == ret)
		{
			printf("插入 %2d 成功\n", num);
		}
		else
		{
			printf("插入 %2d 失败\n", num);
		}
	}

	TraverseList(list, print_all);

	func(&list);
	TraverseList(list, print_all);

	//给定位置返回具体的元素（查找）
	int p = 11;
	ret = FindElem(list, p, &num);
	if (SUCCESS == ret)
	{
		printf("第 %2d 个元素是 %2d\n", p, num);
	}
	else
	{
		printf("第 %2d 个元素不存在\n", p);
	}

	//给定元素返回位置 （定位）
	num = 10;
	int result[10] = {0};   //如果需要返回数组，可以把数组作为参数传到函数中
	ret = LocateElem(list, num, result);
	if (FAILURE == ret)
	{
		printf("元素 %2d 不存在\n", num);
	}
	else
	{
		printf("元素 %2d 的位置是：", num);
		int i;
		for (i = 0; result[i] != 0; i++)
		{
			printf("%d ", result[i]);
		}
		printf("\n");
	}

	for (i = 0; i < 5; i++)
	{
		p = rand() % 20;      //随机产生一个位置
		num = DelList(&list, p);
		if (FAILURE == num)
		{
			printf("删除第 %d 个失败\n", p);
		}
		else
		{
			printf("删除第 %d 个元素成功 %d\n", p, num);
		}
	}

	ret = ClearList(&list);
	if (SUCCESS == ret)
	{
		printf("清空成功\n");
	}
	else
	{
		printf("清空失败\n");
	}

	TraverseList(list, print_all);

	ret = DestroyList(&list);
	if (SUCCESS == ret)
	{
		printf("销毁成功\n");
	}
	else
	{
		printf("销毁失败\n");
	}

	for (i = 0; i < 11; i++)
	{
		num = rand() % 20;
		ret = InsertList(&list, i + 1, num);
		if (SUCCESS == ret)
		{
			printf("插入 %2d 成功\n", num);
		}
		else
		{
			printf("插入 %2d 失败\n", num);
		}
	}

	return 0;
}
