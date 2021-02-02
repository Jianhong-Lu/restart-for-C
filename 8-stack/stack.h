#ifndef STACK_H
#define STACK_H

#define SIZE	100
#define SUCCESS 1000
#define FAILURE 1001

struct Stack
{
	int *data;	//栈的起始地址
	int top;
};
typedef struct Stack Stack;

int InitStack(Stack **s);
int push(Stack *s, int num);
int isEmpty(Stack *s);
int getTop(Stack *s);
int pop(Stack *s);
int ClearStack(Stack *s);
int DestroyStack(Stack **s);

#endif
