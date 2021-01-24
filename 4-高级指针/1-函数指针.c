#include <stdio.h>

typedef unsigned char uchar;
typedef int (*F)(int, int);   //定义一种新的类型F 来表示函数指针

void show()
{
	printf("hello\n");
}

int add(int a, int b)
{
	return a + b;
}

int main()
{
	void (*p)();  //定义一个函数指针p  p指向函数，函数没有参数，没有返回值
	
	p = show;    //直接把函数名（地址）赋值给函数指针
	p();         //通过函数指针调用函数

	//p = add;     //类型不兼容
	int (*p2)(int, int);  //定义一个函数指针p2
	p2 = add;
	int (*p3)(int, int);
	p3 = add;
	F p4 = add;
	printf("%d\n", p4(1, 2));

	//如何让程序跳转到0x100000地址开始执行
	/*typedef void (*T)();
	T p5;
	p5 = (T)0x1000000;
	p5();*/

	return 0;
}
