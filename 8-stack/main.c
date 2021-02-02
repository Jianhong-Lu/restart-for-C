#include <stdio.h>
#include "stack.h"

int main()
{
	//创建一个栈
	Stack *ps = NULL;
	int ret = InitStack(&ps);
	if(SUCCESS == ret)
	{
		printf("初始化成功\n");
	}
	else
	{
		printf("初始化失败\n");
	}

	//进栈
	//ps不用取地址
	int i, num;
	srand(time(NULL));
	for( i = 0; i < 10; i ++)
	{
		num = rand() % 20;
		ret = push(ps, num);
	
	if(SUCCESS == ret)
	{
		printf("%2d 进栈成功 \n", num);
	}
	else
	{
		printf("%2d 进栈失败 \n", num);
	}

	}

	ret = isEmpty(ps);
	if(SUCCESS == ret)
	{
		printf("栈为空 \n");
	}
	else
	{
		printf("栈不为空 \n");
	}

	int p;
	ret = getTop(ps);
	if(ret)
	{
		printf("栈顶元素为 %d \n", ret);
	}
	else
	{
		printf("栈顶元素不存在 \n");
		return -1;
	}

	//出栈
	for(i = 0; i < 2; i ++)
	{
		ret = pop(ps);
		if(FAILURE == ret)
		{
			printf("出栈失败\n");
		}
		else
		{
			printf("%d 出栈成功 \n", ret);		
		}
	}

	//清空
	ret = ClearStack(ps);
	if(FAILURE == ret)
	{
		printf("清空失败\n");
	}
	else
	{
		printf("清空成功 \n");		
	}

	//销毁
	ret = DestroyStack(&ps);
	if(FAILURE == ret)
	{
		printf("销毁失败\n");
	}
	else
	{
		printf("销毁成功 \n");		
	}
	

	for( i = 0; i < 10; i ++)
	{
		num = rand() % 20;
		ret = push(ps, num);
	
	if(SUCCESS == ret)
	{
		printf("%2d 进栈成功 \n", num);
	}
	else
	{
		printf("%2d 进栈失败 \n", num);
	}

	}
	return 0;
}

