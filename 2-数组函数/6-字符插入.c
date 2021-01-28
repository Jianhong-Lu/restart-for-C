#include <stdio.h>
#include <string.h>

int main()
{
	char str[32] = {0};
	int num, i;
	char ch;

	scanf("%s%d %c", str, &num, &ch);
	int length = strlen(str);

	for (i = 0; i < length - num + 1; i++)
	{
		str[length - i] = str[length - 1 - i];
	}
	str[num - 1] = ch;

	printf("%s\n", str);

	return 0;
}
