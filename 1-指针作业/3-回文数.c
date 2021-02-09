#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *str = (char *)malloc(sizeof(char) * 128);
	printf("input the huiwen: \n");
	scanf("%s", str);

//8:访问最后一元素：找到长度，定义末尾指针
	int length = strlen(str);
	int i;
	char *end = str + length - 1;

//9.ex2: *str++ != *end --
	for(i = 0; i < (length - 1) / 2; i ++)
	{
		if(*(str + i) != *(end - i))
		{
			printf("查找失败\n");
			return -1;
		}
	}

	printf("查找成功\n");
}
