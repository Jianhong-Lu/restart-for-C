#include <stdio.h>
#include <stdlib.h>

//表示点的信息
struct Box
{
	int x;
	int y;
	int dir;	//判断方向
};
//1.不写会怎样？
typedef struct Box Box;

//存放点的栈
struct Queue
{
	Box data[1024];
	int  front;
	int  rear;
};
typedef struct Queue Queue;

int map[8][8] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0, 1, 1, 0},
		{0, 1, 0, 0, 1, 0, 1, 0},
	    {0, 1, 1, 0, 0, 1, 1, 0},
		{0 ,0, 1, 0, 1, 1, 1, 0},
		{0, 1, 0, 0, 0, 0, 1, 0},
    	{0, 1, 1, 1, 1, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}
};

//2.data 为什么不初始化?
void InitQueue(Queue *q)
{
	q -> front = q -> rear = 0;
}

//先top ++ 再在这个位置增加点的信息
void push(Queue *q, Box b)
{
	q -> data[q -> rear] = b;
	q -> rear ++;
}

Box pop(Queue *q)
{
	return q -> data[q -> front ++];
}

void show_path(Queue *q, int index, int start_x, int start_y)
{
	if(q -> data[index].x == start_x && q -> data[index].y == start_y)
	{
		printf("(%d %d) ->", q -> data[index].x, q -> data[index].y);
		return;
	}
	show_path(q, q -> data[index].dir, start_x, start_y);
	printf("(%d %d) ->", q -> data[index].x, q -> data[index].y);
}

void walk(Queue *q, int start_x, int start_y, int end_x, int end_y)
{
	Box now;
	Box tmp;
	now.x = start_x;
	now.y = start_y;
	now.dir = -1;

	push(q, now);
	map[now.x][now.y] = -1;

	while(1)
	{
		now = pop(q);
		if(now.x == end_x && now.y == end_y)
		{
			show_path(q, q ->front - 1, start_x, start_y);
			break;
		}

//判断移动的方向
		int i;
		for(i = 0; i < 4; i ++)
		{	
			switch(i)
			{
				case 0:
					tmp.x = now.x - 1;
					tmp.y = now.y;
					break;
				case 1:
					tmp.x = now.x;
					tmp.y = now.y + 1;
					break;
				case 2:
					tmp.x = tmp.x + 1;
					tmp.y = tmp.y;
					break;
				case 3:
					tmp.x = tmp.x;
					tmp.y = tmp.y - 1;
					break;
			}
			if(tmp.x >= 0 && tmp.x <= 7 && tmp.y >= 0 &&
					tmp.y <= 7 && map[tmp.x][tmp.y] == 0)
			{
				printf("%d\t", q -> front);
				tmp.dir = q -> front - 1;
				push(q, tmp);
				map[tmp.x][tmp.y] = -1;
			}
		}
	}
}

int main()
{
	Queue queue;
	InitQueue(&queue);
	walk(&queue, 0, 0, 7, 7);
	return 0;
}
