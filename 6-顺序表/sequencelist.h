#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#define SIZE     10    //顺序表的容量
#define SUCCESS  1000
#define FAILURE  1001

//用结构体来表示顺序表
struct SequenceList
{
	int *data;      //顺序表的地址
	int length;     //顺序表的长度
};
typedef struct SequenceList sqList;

int InitList(sqList *l);
int InsertList(sqList *l, int p, int num);
void TraverseList(sqList l, void (*p)(int));
int FindElem(sqList l, int p, int *n);
int LocateElem(sqList l, int num, int *r);
int DelList(sqList *l, int p);
int ClearList(sqList *l);
int DestroyList(sqList *l);

#endif
