#include <stdio.h>

int main()
{
	char str[32] = "helloworld";
	char str1[32] = {0};

	//puts(str);  //输出一个字符串

	//gets(str1);   //输入的字符串可以包含空格
	//scanf("%[^\n]", str1);  //遇到\n才结束 等同于gets

	char ch;
	int i = 0;
	while ((ch = getchar()) != '\n')   //等同于gets
	{
		str1[i++] = ch;
	}

	printf("%s\n", str1);

	return 0;
}
