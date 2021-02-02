#include <stdio.h>

int main()
{
	char *s = (char *)malloc(128);
	free(s);
	*(s + 1000000000) = 'x';
	return 0;
}
