#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	pNode head = NULL;      //定义头指针

	int ret = InitLink(&head);
	if (SUCCESS == ret)
	{
		printf("初始化成功\n");
	}
	else
	{
		printf("初始化失败\n");
	}

	srand(time(NULL));
	int num, i;
	for (i = 0; i < 10; i++)
	{
		num = rand() % 10;
		//ret = InsertLink(head, i + 1, num);   //尾插法
		ret = InsertLink(head, 1, num);   //头插法
		if (SUCCESS == ret)
		{
			printf("往第 %2d 个位置插入 %2d 成功\n", i + 1, num);
		}
		else
		{
			printf("插入 %2d 失败\n", num);
		}
	}

	TraverseLink(head);

	int p = 12;
	ret = InsertLink(head, p, num);   //头插法
	if (SUCCESS == ret)
	{
		printf("往第 %2d 个位置插入 %2d 成功\n", p, num);
	}
	else
	{
		printf("插入 %2d 失败\n", num);
	}

	TraverseLink(head);

	num = 8;
	ret = PriorElem(head, num);   //返回某个元素的前驱
	if (FAILURE == ret)
	{
		printf("查找前驱失败\n");
	}
	else
	{
		printf("元素 %d 的前驱是 %d\n", num, ret);
	}

	printf("链表的长度是 %d\n", LengthLink(head));

	p = 5;
	ret = GetElem(head, p);
	if (FAILURE == ret)
	{
		printf("元素不存在\n");
	}
	else
	{
		printf("第 %d 个元素是 %d\n", p, ret);
	}

	TraverseLink(head);
	ReverseLink(head);
	TraverseLink(head);

	for (i = 0; i < 3; i++)
	{
		p = rand() % 15;
		ret = DelLink(head, p);
		if (FAILURE == ret)
		{
			printf("删除第 %d 个元素失败\n", p);
		}
		else
		{
			printf("删除第 %d 个元素 %d 成功\n", p, ret);
		}
	}

	ret = ClearLink(head);
	if (FAILURE == ret)
	{
		printf("清空失败\n");
	}
	else
	{
		printf("清空成功\n");
	}

	TraverseLink(head);

	ret = DestroyLink(&head);
	if (FAILURE == ret)
	{
		printf("销毁失败\n");
	}
	else
	{
		printf("销毁成功\n");
	}

	for (i = 0; i < 10; i++)
	{
		num = rand() % 10;
		//ret = InsertLink(head, i + 1, num);   //尾插法
		ret = InsertLink(head, 1, num);   //头插法
		if (SUCCESS == ret)
		{
			printf("往第 %2d 个位置插入 %2d 成功\n", i + 1, num);
		}
		else
		{
			printf("插入 %2d 失败\n", num);
		}
	}

	return 0;
}
