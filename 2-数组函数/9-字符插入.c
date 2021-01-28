#include <stdio.h>
#include <string.h>

int main()
{
	char str[32] = {0}; 
	int num;
	char ch;
	char t[32] = {0};

	scanf("%s%d %c", str, &num, &ch);

	strncpy(t, str, num - 1);
	strncat(t, &ch, 1);   //参数一定是地址
	strcat(t, str + num - 1);

	strcpy(str, t);
	printf("%s\n", str);

	return 0;
}
