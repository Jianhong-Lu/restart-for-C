#include <stdio.h>

#define A  100   //宏常量  在代码执行的过程中不能被修改
#define B  1.111
#define C  'a'
#define D  "hellowrold"

int main()
{
	int a = 1;   //变量在执行的过程中可以被修改
	a = 2;

	//A = 1;      //100 = 1;

	const int b = 2;   //修改只读变量 不能通过变量名b来修改对应内存的值，可以通过其他方式
	//b = 100;   //不能通过变量名修改
	int *p = (int *)&b;
	*p = 100;     //可以通过地址修改
	printf("%d\n", b);

	return 0;
}
