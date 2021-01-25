#include <stdio.h>
#include <stdlib.h>

void delect_space(char *s)
{
	int i = 0;
	while (*s != '\0')
	{
		*s++ = *(s + 1);
	}
	*(s - 1) = '\0';
}

int main()
{
	char *s = (char *)malloc(sizeof(char) * 128);
	char ch;
	char *start = s;

	while ((ch = getchar()) != '\n')
	{
		*s++ = ch;
	}
	s = start;

	while (*start != '\0')
	{
		if (*start == ' ')
		{
			delect_space(start);
			continue;
		}
		start++;
	}

	printf("%s\n", s);

	return 0;
}
