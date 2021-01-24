#include <stdio.h>

int main(int argc, char *argv[])  //argc表示参数个数  argv存放具体的参数
{
	int i;
	for (i = 1; i < argc; i++)
	{
		printf("%s %d\n", argv[i], strlen(argv[i]));
	}

	return 0;
}
