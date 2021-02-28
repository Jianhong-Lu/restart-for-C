#ifndef QUEUE_H
#define QUEUQ_H

#define SUCCESS 	1000
#define FAILURE 	1001
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node Node;

struct LinkQueue
{
	Node * front;
	Node * rear;
};
typedef struct LinkQueue Queue;

int InitQueuq(Queue *q);
int IsEmpty(Queue q);
int GetTop(Queue q);
int LengthQueue(Queue q);
int push(Queue *q, int num);
int CLearQueue(Queue *q);
int DestroyQueue(Queue *q);

#endif
