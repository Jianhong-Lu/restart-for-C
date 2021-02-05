#ifndef LINKLIST_H
#define LINKLIST_H

#define SUCCESS    10000
#define FAILURE    10001

typedef int T;      //用T来表示元素的类型

//表示链表的结点
struct Node
{
	T data;                  //数据域
	struct Node *next;       //指针域
	struct Node *prior;      //指针域
};
typedef struct Node Node;
typedef Node *pNode;         //用pNode代表Node *

int InitLink(pNode *h);
int InsertLink(pNode h, int p, int num);
void TraverseLink(pNode h);
int PriorElem(pNode h, int num);
int LengthLink(pNode h);
int GetElem(pNode h, int p);
void ReverseLink(pNode h);
int DelLink(pNode h, int p);
int ClearLink(pNode h);
int DestroyLink(pNode *h);

#endif
