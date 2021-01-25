#include <stdio.h>

int main()
{
	printf("%d\n", sizeof(int *));
	printf("%d\n", sizeof(char *));
	printf("%d\n", sizeof(float *));
	printf("%d\n", sizeof(double *));

	int a = 1;
	int *p = &a;
	*p = 100;     //等价于  a = 100
	printf("a = %d\n", a);

	//char *q = &a;  //类型不兼容

	char ch = 'a';
	char *q = &ch;

	//int *m, n;  //m是整形指针  n是整形
	int *m, *n;
	m = &a;
	n = m;       //指针可以被赋值，n同m，n指向a
	*n = 100;    //等价于 a = 100

	printf("%p\n", p);
	printf("%p\n", q);

	printf("%p\n", p + 1);
	printf("%p\n", q + 1);



	return 0;
}
