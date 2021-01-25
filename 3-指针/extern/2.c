#include <stdio.h>

extern int g_num;   //声明外部变量（或函数）（告诉编译器该变量在其他文件中被定义）
//extern int g_num = 0;   //定义（定义需要分配空间的，声明不需要分配空间）

//static void p()//static修饰函数：改变函数的作用域，只能在本文件中被调用，其他文件不能调用
void p()
{
	printf("g_num = %d\n", g_num);
}
