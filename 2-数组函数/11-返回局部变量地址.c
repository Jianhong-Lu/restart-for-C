#include <stdio.h>
#include <string.h>

char *f()
{
	char str[32] = {0};   
	return str;   //不能返回局部变量的地址，函数结束后，局部变量会被释放
}

int main()
{
	strcpy(f(), "helloworld");   //回到main函数的时候，数组str已经不存在

	return 0;
}
