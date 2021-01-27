#include <stdio.h>

//所有成员共享同一块内存  联合体长度就是最长成员的长度
union Test
{
	int a;
	char ch;
};

struct Student
{
	union Test t;
	int b;
	char ch;
};

int main()
{
	union Test t;
	t.a = 1;
	printf("%d\n", t.ch);

	return 0;
}
