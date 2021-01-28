#include <stdio.h>

void f(/*填写函数的参数，没有就不填*/)  //没有返回值 没有参数   
{
	printf("this is f..\n");
}

int add(int x, int y)  //形参和实参的要求：个数一样 类型一样（形参就是在定义变量）
{						//2、给形参分配空间   3、传参
	int sum = x + y;   //4、执行函数体
	return sum;        //5、返回       6、释放空间（局部变量）
}

int main()
{
	f(/*填写实参，没有可以不填*/);   //调用函数

	int a = 1, b = 2;
							//1、根据函数名找到函数的入口地址
	int ret = add(a, b);   //a 和 b称作实参（实际参数）  ret接收add函数的返回值
	printf("%d\n", ret);
	printf("%p\n", add);   //函数名也是地址

	return 0;
}
