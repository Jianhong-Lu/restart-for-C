#include <stdio.h>

void sort(char *s[], int size)
{
	int i, j;
	char *t;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (strcmp(s[j], s[j + 1]) > 0)
			{
				t = s[j];
				s[j] = s[j + 1];
				s[j + 1] = t;
			}
		}
	}
}

int main()
{
	char *string[] = {"i love china", "i am"};
	char *str[] = {"hello", "world", "aaa", "zzzz", "ddddd"};
	//aaa ddddd hello world zzzz

	printf("%s\n", string[0]);
	printf("%c\n", *(string[0] + 7));
	printf("%c\n", string[0][7]);


	sort(str, sizeof(str) / sizeof(str[0]));

	int i;
	for (i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		printf("%s ", str[i]);
	}
	printf("\n");

	return 0;
}
