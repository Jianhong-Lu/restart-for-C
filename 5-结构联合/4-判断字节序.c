#include <stdio.h>

union Test
{
	char ch[2];
	short value;
};

int main()
{
	union Test t;
	t.value = 0x0102;

	if (t.ch[0] == 1 && t.ch[1] == 2)
	{
		printf("大端字节序\n");
	}
	else if (t.ch[0] == 2 && t.ch[1] == 1)
	{
		printf("小端字节序\n");
	}
	return 0;
}
