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
struct Stack
{
	Box data[1024];
	int top;
};
typedef struct Stack Stack;

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

Stack s;

//2.data 为什么不初始化?
void InitStack(Stack *s)
{
	s -> top = -1;
}

//先top ++ 再在这个位置增加点的信息
void push(Stack *s, Box b)
{
	s -> top ++;
	s -> data[s -> top] = b;
}

int IsEmpty(Stack *s)
{
	return (s -> top == -1) ? 1 : 0;
}

Box pop(Stack *s)
{
	return s -> data[s -> top --];
}

Box GetTop(Stack *s)
{
	return s -> data[s -> top];
}

//判断box位置在map范围内
int check(Box b)
{
	if(b.x >= 0 && b.x <=7 && b.y >= 0 && b.y <= 7 && map[b.x][b.y] == 0)
	{
		return 1;
	}
	return 0;
}

//3.全局变量为什么要传参？
//把存放栈的元素Stack逐一打印
void show_path()
{
	show_pic();
	int i;
	printf("标点图为:\n");
	for(i = 0; i <= s.top; i ++)
	{
		printf("(%d, %d) ->", s.data[i].x, s.data[i].y);
	}
		printf("\n");
}

void show_pic()
{
	int i, j;
	int array[8][8] = {0};
	for(i = 0; i <= s.top; i ++)
	{
		array[s.data[i].x][s.data[i].y] = -1;
	}
	for(i = 0; i < 8; i ++)
	{
		for(j = 0; j < 8; j ++)
		{
			printf("%3d", array[i][j]);
		}
		printf("\n");
	}
}

//画线路
void walk(int x0, int y0, int x1, int y1)
{
	Box cur_box, next_box, box;
	cur_box.x = x0;
	cur_box.y = y0;
	cur_box.dir = -1;	//初始方向
	push(&s, cur_box);
	map[x0][y0] = -1;	//4. -1 作用

//不为空
	while(IsEmpty(&s) != 1)
	{
		cur_box = GetTop(&s);
	//	printf("cur_box is  %d %d %d\n", cur_box.x, cur_box.y, cur_box.dir);
	//完成线路 一定的初始化
		if(cur_box.x == x1 && cur_box.y == y1)
		{
//			printf("abcd");
			show_path();
			box = pop(&s);
			map[box.x][box.y] = 0;
			continue;
		}

		//4.初始值k为什么要 ＋ 1
		int k;
		for(k = cur_box.dir + 1; k < 4; k ++)
		{
			switch(k)
			{
				case 0:
					next_box.x = cur_box.x - 1;
					next_box.y = cur_box.y;
					break;
				case 1:
					next_box.x = cur_box.x;
					next_box.y = cur_box.y + 1;
					break;
				case 2:
					next_box.x = cur_box.x + 1;
					next_box.y = cur_box.y;
					break;
				case 3:
					next_box.x = cur_box.x;
					next_box.y = cur_box.y - 1;
					break;
			}
		
		//5.为什么修改元素方向
			if(check(next_box))
			{
			//	printf("next box is %d %d cur k is %d\n", 
//				next_box.x, next_box.y, k);
				s.data[s.top].dir = k;
				next_box.dir = -1;
				push(&s, next_box);
				map[next_box.x][next_box.y] = -1;
				break;
			}
		}

		if(4 == k)
		{
			box = pop(&s);
			map[box.x][box.y] = 0;
		}
	}
}

int main()
{
	InitStack(&s);
	walk(0, 0, 7, 7);
	return 0;
}
