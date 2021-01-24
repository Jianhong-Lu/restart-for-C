#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Init(char **q)
{
	*q = (char *)malloc(128);
}

int main()
{
	char *s; 

	Init(&s);   //值传递      当需要修改实参值的时候，需要地址传递

	strcpy(s, "hello");

	return 0;
}
