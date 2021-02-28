#include <stdio.h>
#include "queue.h"
#include <stdlib.h>

int InitQueue(Queue * q)
{
	if(NULL == q)
	{
		return FAILURE;
	}
	
	q -> front = (Node *)malloc(sizeof(Node) * 1);
	if(NULL == q -> front)
	{
		return FAILURE;
	}

	q -> front -> next = NULL;
	q -> rear = q -> front;

	return SUCCESS;
}

int push(Queue *q, int num)
{
	//进队队头队尾也要
	if(NULL == q || q -> front == NULL || q -> rear == NULL)
	{
		return FAILURE;
	}

	Node *n = (Node *)malloc(sizeof(Node) * 1);
	if(NULL == n)
	{
		return FAILURE;
	}
	//4次操作 赋值 尾结点
	n -> data = num;
	n -> next = NULL;
	q -> rear -> next = n;
	q -> rear = n;

	return SUCCESS;
}

int IsEmpty(Queue q)
{
	return (q.front == q.rear ) ? SUCCESS : FAILURE ;
}

int GetTop(Queue q) 
{
	return (q.front == q.rear) ? FAILURE : (q.front -> next -> data);
/*	if(q == NULL)
	{
		return FAILURE;
	}

	return q -> front -> data;
*/
}

int LengthQueue(Queue q)
{
	Node *p = (Node *)malloc(sizeof(Node) * 1);
	int length = 0;
	p = q.front -> next;//指向头的下一个
	while(p)
	{
		length ++;
		p = p -> next;
	}

	return length;
}

int pop(Queue *q)
{
	if(q == NULL)
	{
		return FAILURE;
	}

/*	Node *n = (Node *)malloc(sizeof(Node) * 1);
	if(n == NULL)
	{
		return FAILURE;
	}*/
//方便
//判断结束标志
	if(q -> front == q -> rear)
	{
		return FAILURE;
	}

	Node *n = q -> front -> next;
/*	if(n == NULL)
	{
		return FAILURE;
	}*/
	int num = n -> data;
	q -> front -> next = n -> next;

//重点，说明出队的最后一个元素
	if(q -> front -> next == NULL)
	{
		q -> rear = q -> front;
	}
	free(n);
	return num;
}

int ClearQueue(Queue *q)
{
	if(NULL == q)
	{
		return FAILURE;
	}

	Node *p = q -> front -> next;
	//循环看待
	while(p)
	{
		q -> front -> next = p -> next;
		free(p);
		p = q -> front -> next;
	}

	q -> rear = q -> front;

	return SUCCESS;
}

int DestroyQueue(Queue *q)
{
	if(NULL == q)
		return FAILURE;
	//front指向的内存清掉了 front的就会成为野指针 写为空
	free(q -> front);
	q -> front = NULL;
	q -> rear = NULL;

	return SUCCESS;
}
