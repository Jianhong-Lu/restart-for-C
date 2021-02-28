#include <stdio.h>
#include "queue.h"

int main()
{
	Queue queue;

	int ret = InitQueue(&queue);

	if(SUCCESS == ret)
	{
		printf("初始化成功 \n");
	}
	else
	{
		printf("初始化失败 \n");
	}

	printf("队列长度 %d\n", LengthQueue(queue));
	
	//进队列
	int i, num;
	srand(time(NULL));
	for(i = 0; i < 10; i++)
	{
		num = rand() % 20;
		ret = push(&queue, num);
		if(FAILURE == ret)
		{
			printf("%2d 进队失败 \n", num);
		}
		else
		{
			printf("%2d 进队成功 \n", num);
		}
	}

	ret = IsEmpty(queue);
	if(SUCCESS == ret)
	{
		printf("队列为空 \n");
	}
	else
	{
		printf("队列不为空 \n");
		printf("队头元素 %d\n", GetTop(queue));
	}

	printf("队列长度 %d\n", LengthQueue(queue));


	for(i = 0; i < 9; i++)
	{
		ret = pop(&queue);
		if(FAILURE == ret)
		{
			printf("出队列失败 \n");
		}
		else
		{
			printf("%2d 出队成功 \n", ret);
		}
	}

	//清空
	ret = ClearQueue(&queue);
	if(SUCCESS == ret)
	{
		printf("清空成功 \n");
	}
	else
	{
		printf("清空失败 \n");
	}
	
	printf("队列长度 %d\n", LengthQueue(queue));

	ret = DestroyQueue(&queue);
	if(SUCCESS == ret)
	{
		printf("销毁成功 \n");
	}
	else
	{
		printf("销毁失败 \n");
	}
	return 0;
}
