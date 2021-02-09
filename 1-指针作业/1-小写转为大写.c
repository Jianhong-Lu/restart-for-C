#include <stdio.h>
#include <stdlib.h>

void lower_to_upper(char *s)
{
	while(*s != '\0')//不等于终止
	{
		if(*s >= 'a' && *s <= 'z')
		{
			*s = *s - 32;
		}
		//1.指针只用一个变量移动字符串指向的位数
		s ++; 
	}
}

int main()
{
	char *str = (char *)malloc(sizeof(char) * 128);
	printf("input the string to change\n");
	scanf("%s", str);

	lower_to_upper(str);

	printf("after is %s\n", str);
	return 0;
}
