#include <stdio.h>

//static int g_num = 0;   //static修饰全局变量：改变变量的作用域，只能在本文件中被使用
int g_num = 0;

extern void p();

int main()
{
	p();

	return 0;
}
