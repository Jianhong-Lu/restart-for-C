#include <stdio.h>

//1、结构体总长度一定是最长成员的整数倍
//2、每个成员的偏移量一定是该成员长度的整数倍

struct Student
{
	int age;
	char sex;
};

struct Test
{
	//int d[3];
	char c;
	struct Student s;
	short a;
	short b;
};

int main()
{
	struct Test t;
	printf("%d\n", sizeof(struct Test));
	return 0;
}
