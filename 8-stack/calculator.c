#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

int Priority(char ch)
{
	switch(ch)
	{
		case '(':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}

int main()
{
	Stack *ps_num, *ps_opt;

	if(FAILURE == InitStack(&ps_num) || InitStack(&ps_opt) == FAILURE)
	{
		printf("栈初始化失败 \n");
		exit(1);
	}
	
	char opt[256] = {0};
	int i = 0, temp = 0;
//	scanf("%s", opt);
//获取元素 能够非空判断
	char ch;
	int count = 0;
	while((ch = getchar()) != '\n')
	{
		if(ch != ' ')
		{
			opt[count++] = ch;
		}
	}
	printf("规范化的计算式为 %s \n", opt);

/*
opt待操作数不为空 或 输入的也不为空 循环继续

*/
	while(opt[i] != '\0' || isEmpty(ps_opt) != SUCCESS)
{
/*
判断数字，这里计算是几位数 
if短 else长：符号位需要判断入栈与出栈
*/
	if(opt[i] >= '0' && opt[i] <= '9')
	{
		temp = temp * 10 + opt[i] - '0';
		i ++;
		if(opt[i] < '0' || opt[i] > '9')
		{
			push(ps_num, temp);
			printf("数字进栈 %d\n", temp);
			temp = 0;
		}
	}
	else
	{
/*
三种情况符号入栈：
1.空栈入栈
2.优先级高的入栈
3.遇到 ） 且栈顶不为（
*/
		if(isEmpty(ps_opt) == SUCCESS || (Priority(opt[i]) >
		Priority(getTop(ps_opt))) || (getTop(ps_opt) == '('
		&& opt[i] != ')'))
		{
			push(ps_opt, opt[i]);
			printf("符号进栈 %c \n", opt[i]);
			i ++;
			continue;
		}

//去掉 （）的可能
		if(getTop(ps_opt) == '(' && opt[i] == ')')
		{
			printf("符号出栈 %c\n", ps_opt);
			pop(ps_opt);
			i ++;
			continue;
		}
/*
以下情况需要出栈计算
1.优先级小于等于栈顶符号
2.栈顶不为（ ，）要如栈
3.输入的opt无内容 ＋ 操作栈为空
*/
		if(Priority(opt[i]) <= Priority(getTop(ps_opt)) ||
			(opt[i] == ')' && getTop(ps_opt) != '(') ||
			(opt[i] == '\0' && isEmpty(ps_opt) != SUCCESS))
			{
				char ch = pop(ps_opt);
//				printf("进行计算 符号 %c\n", ch);
				int num1 = pop(ps_num);
				int num2 = pop(ps_num);
//				printf("进行计算num1 num2: %d %d \n", num1, num2);

//这里 ／ － 都是num2被num1 /或－
				switch(ch)
				{
					case '+':
						push(ps_num, num1 + num2);
						break;
					case '-':
						push(ps_num, num2 - num1);
						break;
					case '*':
						push(ps_num, num1 * num2);
						break;
					case '/':
						push(ps_num, num2 / num1);
						break;
				}
			}
	}
	}
	//循环退出 此时opt为空 操作栈为空 操作数取栈顶防止有多个数
	printf("%d\n", pop(ps_num));
}
