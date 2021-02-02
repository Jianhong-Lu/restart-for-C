#include "stack.h"
#include <stdio.h>

int InitStack(Stack **s)
{
	if(NULL == s)
	{
		return FAILURE;
	}

	*s = (Stack *)malloc(sizeof(Stack) * 1);
	if(NULL == *s)
	{
		return FAILURE;
	}
	(*s) -> data = (int *)malloc(sizeof(int) * SIZE);
	if(NULL == (*s) -> data)
	{
		return FAILURE;
	}

	(*s) ->top = -1;
	return SUCCESS;
}

int push(Stack *s, int num)
{
	if(NULL == s)
	{
		return FAILURE;
	}

	//判断栈是否满
	if(s -> top >= SIZE - 1)
	{
		return FAILURE;
	}

	s -> top ++;
	s -> data[s -> top] = num;
//	printf("%d\n", s -> top);

	return SUCCESS;
}

int isEmpty(Stack *s)
{
	if(NULL == s)
	{
		return SUCCESS;
	}
	
	if(s -> top == -1)
	{
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}

}

int getTop(Stack *s)
{
	//判断空栈
	if(NULL == s || s -> top == -1)
	{
		return FAILURE;
	}
	else
	{
		return s -> data[s -> top];
	}
}

int pop(Stack *s)
{
	if(NULL == s)
	{
		return FAILURE;
	}
	if(-1 == s -> top)
	{
		return FAILURE;
	}

	return s -> data[s -> top --];
}

int ClearStack(Stack *s)
{
	if(NULL == s)
	{
		return FAILURE;
	}
	
	s -> top = -1;
	return SUCCESS;
}

int DestroyStack(Stack **s)
{
	if(NULL == s)
	{
		return FAILURE;
	}

	free((*s) -> data);
	free(*s);
	*s = NULL;

	return SUCCESS;
}
