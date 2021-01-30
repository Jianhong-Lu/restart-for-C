#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

#define LEN1    10
#define LEN2    15

pNode merge(pNode h1, pNode h2)
{
	pNode p1 = h1->next, p2 = h2->next;
	pNode q = h1;
	int flag = 0;

	while (p1 != NULL && p2 != NULL)
	{
		
		while (p1 != NULL && p2 != NULL && p1->data <= p2->data)
		{
			q->next = p1;
			q = p1;
			p1 = p1->next;
			flag = 1;
		}

		if (p1 != NULL && p2 != NULL && flag)
		{
			q->next = p2;
			q = p2;
			p2 = p2->next;
		}

		flag = 0;
		while (p1 != NULL && p2 != NULL && p1->data > p2->data)
		{
			q->next = p2;
			q = p2;
			p2 = p2->next;
			flag = 1;
		}

		if (p1 != NULL && p2 != NULL && flag)
		{
			q->next = p1;
			q = p1;
			p1 = p1->next;
		}
	}

	if (p1 == NULL)
	{
		q->next = p2;
	}
	else if (p2 == NULL)
	{
		q->next = p1;
	}
	free(h2);
	return h1;
}

int main()
{
	pNode head1 = NULL, head2 = NULL;

	if (InitLink(&head1) == FAILURE || InitLink(&head2) == FAILURE)
	{
		printf("链表初始化初始化失败\n");
		return -1;
	}

	srand(time(NULL));
	int i, num, tmp = 0;
	//往链表1插入有序数据
	for (i = 0; i < LEN1; i++)
	{
		num = rand() % ((i + 1) * 10);
		while (num < tmp)
		{
			num = rand() % ((i + 1) * 10);
		}
		tmp = num;

		if (InsertLink(head1, i + 1, num) == FAILURE)
		{
			printf("链表1插入失败\n");
		}
	}

	tmp = 0;
	//往链表2插入有序数据
	for (i = 0; i < LEN2; i++)
	{
		num = rand() % ((i + 1) * 10);
		while (num < tmp)
		{
			num = rand() % ((i + 1) * 10);
		}
		tmp = num;

		if (InsertLink(head2, i + 1, num) == FAILURE)
		{
			printf("链表1插入失败\n");
		}
	}

	TraverseLink(head1);
	TraverseLink(head2);

	pNode h = merge(head1, head2);

	TraverseLink(h);

	return 0;
}


