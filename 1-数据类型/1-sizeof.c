#include <stdio.h>  //包含头文件 使用不同的函数需要包含不同的头文件


int main()          //void main()   int/void函数的返回值 main函数名，也是程序的入口 ()参数
{
	int a, d;          //定义变量
	char b;
	double c;

	printf("char %d\n", sizeof(char));   //sizeof关键字 求数据类型长度
	printf("char %d\n", sizeof(b));
	printf("short %d\n", sizeof(short));
	printf("int %d\n", sizeof(int));
	printf("long %d\n", sizeof(long));
	printf("float %d\n", sizeof(float));
	printf("double %d\n", sizeof(double));

	a = 1;
	printf("%d\n", sizeof(a++));  //sizeof是关键字，不会执行a++语句，只是判断a的类型
	printf("a = %d\n", a);

	return 0;       //return 0跟main前面的int呼应  函数遇到返回值就结束
}
