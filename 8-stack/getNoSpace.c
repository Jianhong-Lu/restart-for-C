#include <stdio.h>

int main()
{
	char ch;
	char opt[256] = {0};
	int i = 0;
	while((ch = getchar()) != '\n')
	{
		if(' ' != ch)
			opt[i++] = ch;
	}
	printf("%s\n", opt);
}
