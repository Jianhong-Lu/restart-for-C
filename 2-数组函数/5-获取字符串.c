#include <stdio.h>

int main()
{
	char str1[32] = {0};
	char str2[32] = {0};
	char ch;
	int num;

	//scanf("%s%s", str1, str2);

	//scanf("%s %c", str1, &ch);   //%s和%c之间加上空格，输入的时候也加上空格
	//printf("%s %c\n", str1, ch);

	scanf("%s %d", str1, &num);  //%s和%d之间的空格可加可不加
	printf("%s %d\n", str1, num);

	return 0;
}
