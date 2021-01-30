#include "sequencelist.h"
#include <stdlib.h>
#include <stdio.h>

int InitList(sqList *l)
{
	//入参判断
	if (NULL == l)
	{
		return FAILURE;
	}

	l->data = (int *)malloc(sizeof(int) * SIZE);
	if (NULL == l->data)
	{
		return FAILURE;
	}

	l->length = 0;

	return SUCCESS;
}

/*
函数描述：指定位置插入元素
函数参数：顺序表 插入的位置 插入的元素
函数返回值：插入成功返回SUCCESS  插入失败返回FAILURE
*/
int InsertList(sqList *l, int p, int num)
{
	if (NULL == l || NULL == l->data)
	{
		return FAILURE;
	}

	if (l->length >= SIZE)   //长度判断
	{
		return FAILURE;
	}

	if (p > l->length + 1)   //位置判断
	{
		return FAILURE;
	}

	int i;
	for (i = 0; i < l->length - p + 1; i++)
	{
		l->data[l->length - i] = l->data[l->length - 1 - i];
	}
	l->data[p - 1] = num;
	l->length++;

	return SUCCESS;
}

void TraverseList(sqList l, void (*p)(int))
{
	int i;
	for (i = 0; i < l.length; i++)
	{
		p(l.data[i]);
	}
	printf("\n");
}

/*
函数描述：根据位置查找具体的元素
函数参数：顺序表 位置 保存找到的元素
返回值：找到返回SUCCESS 找不到返回FAILURE
*/
int FindElem(sqList l, int p, int *n)
{
	if (NULL == n)
	{
		return FAILURE;
	}

	if (p > l.length)   //位置判断
	{
		return FAILURE;
	}

	*n = l.data[p - 1];

	return SUCCESS;
}

int LocateElem(sqList l, int num, int *r)
{
	int index = 0;
	int i;
	for (i = 0; i < l.length; i++)
	{
		if (num == l.data[i])
		{
			r[index++] = i + 1;
		}
	}
	if (index == 0)
	{
		return FAILURE;
	}
	else
	{
		return SUCCESS;
	}
}

/*
函数描述：删除指定位置的元素
函数参数：顺序表   位置p   保存删除的元素
函数返回值：成功返回SUCCESS 失败返回FAILURE
*/
int DelList(sqList *l, int p)
{
	if (NULL == l)
	{
		return FAILURE;
	}

	if (p > l->length || p <= 0)
	{
		return FAILURE;
	}

	int n = l->data[p - 1];
	int i;
	for (i = 0; i < l->length - p; i++)
	{
		l->data[p - 1 + i] = l->data[p + i];
	}

	l->length--;

	return n;
}

int ClearList(sqList *l)
{
	if (NULL == l)
	{
		return FAILURE;
	}

	l->length = 0;

	return SUCCESS;
}

int DestroyList(sqList *l)
{
	if (NULL == l)
	{
		return FAILURE;
	}

	free(l->data);
	l->data = NULL;

	return SUCCESS;
}

//返回1表示空，返回0表示非空
int isEmpty(sqList l)
{
	return (l.length == 0) ? 1 : 0;
}

void func(sqList *l)
{
	if (NULL == l)
	{
		return;
	}
	
	if (isEmpty(*l))
	{
		return;
	}

	int num = DelList(l, 1);
	func(l);
	InsertList(l, l->length + 1, num);
}
