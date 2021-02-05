#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

int InitLink(pNode *h)
{
	if (NULL == h)
		return FAILURE;

	*h = (pNode)malloc(sizeof(Node) * 1);
	if (NULL == *h)
	{
		return FAILURE;
	}

	(*h)->next = NULL;
	(*h)->prior = NULL;    //增加

	return SUCCESS;
}

/*
函数描述：往链表指定地方插入数据
函数参数：链表头指针 位置 插入的元素
函数返回值：成功返回SUCCESS 失败返回FAILURE
*/
int InsertLink(pNode h, int p, int num)
{
	if (NULL == h)
	{
		return FAILURE;
	}

	//移动指针到要插入位置的前一个位置
	int k = 1;
	pNode q = h;
	while (k < p && q)   //条件q保证q不为空（如果p值太大）
	{
		k++;            //记录移动的次数
		q = q->next;    //指向下一个结点
	}

	//判断插入的位置是否合法
	if (p < 1 || !q)   //q == NULL说明p值太大
	{
		return FAILURE;
	}

	pNode n = (pNode)malloc(sizeof(Node) * 1);
	if (NULL == n)
	{
		return FAILURE;
	}

	n->data = num;
	n->next = q->next;
	n->prior = q;          //增加
	q->next = n;
	if (n->next)
	{
		n->next->prior = n;    //增加
	}

	return SUCCESS;	
}

void TraverseLink(pNode h)
{
	if (NULL == h)
	{
		return;
	}

	pNode q = h->next;    //指向第一个结点
	while (q)
	{
		printf("%d ", q->data);
		q = q->next;
	}
	printf("\n");
}

/*
返回指定元素的前驱
*/
int PriorElem(pNode h, int num)
{
	if (NULL == h)
	{
		return FAILURE;
	}

	pNode m = h->next;    //m指针指向第一个结点
	if (!m || !m->next)
	{
		return FAILURE;
	}
	pNode q = m->next;    //q指向第二个结点
	while (q)
	{
		if (q->data == num)
		{
			return m->data;
		}
		q = q->next;
		m = m->next;
	}

	return FAILURE;
}

int LengthLink(pNode h)
{
	if (NULL == h)
	{
		return FAILURE;
	}
	int length = 0;
	pNode q = h->next;

	while (q)
	{
		length++;
		q = q->next;
	}

	return length;
}

int GetElem(pNode h, int p)
{
	if (NULL == h || p <= 0)
	{
		return FAILURE;
	}

	pNode q = h;
	int i;
	for (i = 0; i < p && q; i++)
	{
		q = q->next;
	}

	if (q)
	{
		return q->data;
	}
	else
	{
		return FAILURE;
	}
}

void ReverseLink(pNode h)
{
	if (NULL == h)
	{
		return;
	}

	pNode p = h->next;
	h->next = NULL;

	while (p)
	{
		pNode q = p;
		p = p->next;
		q->next = h->next;
		h->next = q;
	}
}

int DelLink(pNode h, int p)
{
	if (NULL == h)
	{
		return FAILURE;
	}

	//移动指针到要删除位置的前一个位置
	int k = 1;
	pNode q = h;
	while (k < p && q)   //条件q保证q不为空（如果p值太大）
	{
		k++;            //记录移动的次数
		q = q->next;    //指向下一个结点
	}

	//判断删除的位置是否合法
	if (p < 1 || !q || !q->next)   //q == NULL说明p值太大
	{
		return FAILURE;
	}

	pNode n = q->next;    //要删除的结点
	q->next = n->next;    
	n->next->prior = q;   //增加
	int num = n->data;
	free(n);
	return num;

}

int ClearLink(pNode h)
{
	if (NULL == h)
	{
		return FAILURE;
	}
	
	pNode q = h->next;
	while (q)
	{
		h->next = q->next;
		free(q);
		q = h->next;
	}

	return SUCCESS;
}

int DestroyLink(pNode *h)
{
	if (NULL == h)
		return FAILURE;

	free(*h);
	*h = NULL;

	return SUCCESS;
}
