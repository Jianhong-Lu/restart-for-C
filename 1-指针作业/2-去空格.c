#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//6.指针往前移动 后面也要移动！！
void move_forward(char *begin)
{
//7.用begin去移动
	int length = strlen(begin);
	int i;

	for(i = 0; i < length - 1; i ++)
	{
		*begin = *(begin + 1);
		begin ++;
	}
	*begin = '\0';
}

void del_space(char *s)
{
	//5.指针++ 意味着什么
	while(*s != '\0')
	{
		if(*s == ' ')
		{
			move_forward(s);	
		}
		else
		{
			s ++;
		}
	}
}

int main()
{
	char *str = (char *)malloc(sizeof(char) * 128);

	//2.scanf 无视空格的方法
	printf("intput with space\n");
	char ch;
	int i = 0;
	while((ch = getchar()) != '\n')
	{
	//3.指针 ＋数字和 指针 ＋＋ 区别
		*(str + i)= ch; 
		i ++;
	}

	del_space(str);
//	scanf("%s", str);
	printf("output is %s\n", str);
	free(str);
	//4.申请内存要释放内存
	return 0;
}
