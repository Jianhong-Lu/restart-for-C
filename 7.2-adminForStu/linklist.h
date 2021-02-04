#ifndef LINKLIST_H
#define LINKLIST_H

#define SUCCESS 	1000
#define FAILURE 	1001

struct Node
{
	int id;
	char name[32];
	char tel[12];
	struct Node *next;
};
typedef struct Node Node;
typedef Node *pNode;

int InitLink(pNode *h);
//int InsertLink(pNode h, );
/*
void TraverseLink(pNode h);
int PriorElem(pNode h, int num);
int LengthLink(pNode h);
int GetElem(pNode h, int p);
void ReverseLink(pNode h);
int DelLink(pNode h, int p);
int ClearLink(pNode h);
int DestroyLink(pNode *h);
*/
#endif
