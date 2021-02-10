#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//判断sub的前size字节是否str子串 是返回1
int sub_string(char *sub, char *str, int size)
{
	int i;
	for(i = 0; i < strlen(str) - size + 1; i ++)
	{
	//10.比较相等前面不变 后面可以加 i
		if(!strncmp(sub, str + i, size))
		{
			return 1;
		}
	}

	return 0;
}

int main()
{
	char *str1 = (char *)malloc(sizeof(char) * 128);
	char *str2 = (char *)malloc(sizeof(char) * 128);

	printf("input 2 string\n");
	scanf("%s%s", str1, str2);
	
	int i, j;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int short_len;

	//判断大小的：
	char *short_str, *long_str;
	(len1 > len2) ? (short_len = len2, short_str = str2, long_str = str1):
		(short_len = len1, short_str = str1, long_str = str2);
//11.for循环与函数判断条件
	for(i = short_len; i >= 1; i -- )
	{
		for(j = 0; j < short_len; j ++)
		{
			if(sub_string(short_str + j, long_str, i))
			{
				*(short_str + j + i) = '\0';
				printf("最长子串 %s \n", short_str + j);
				free(str1);
				free(str2);
				return 0;
			}
		}
	}

	printf("不存在公共子串\n");
	free(str1);
	free(str2);
	return 0;
}
