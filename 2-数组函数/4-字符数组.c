#include <stdio.h>
#include <string.h>

int main()
{
	//int a[];
	/*char a[5] = {'h', 'e', 'l', 'l', 'o'};
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%c", a[i]);
	}
	printf("\n");*/

	char a[6] = "hello"; //定义字符数组，尽量大
	printf("%s\n", a);   //输出字符串，需要提供字符串的首地址

	char ch[] = "helloworld";
	printf("%d\n", sizeof(ch));
	printf("%d\n", strlen(ch));   //strlen求字符串长度

	return 0;
}
