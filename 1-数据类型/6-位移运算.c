#include <stdio.h>

int main()
{
	char ch;
	scanf("%c", &ch);

	int i, count = 0;
	for (i = 0; i < 8; i++)
	{
		if (ch & 1 == 1)
		{
			count++;
		}
		ch = ch >> 1;    //ch >>= 1;
	}
	printf("%d\n", count);

	return 0;
}
