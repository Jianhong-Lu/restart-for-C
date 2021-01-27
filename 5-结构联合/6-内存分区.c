#include <stdio.h>

char *g_ptr = NULL;         //数据段

int main()
{
	char *str = NULL;           //栈
	char *p = "helloworld";     //栈空间    字符串常量 只读数据区（数据段）p4个字节存地址
	char ch[32] = "12345";      //ch32字节存字符串
	//p = "xxxxx";  ch = 'xxxxx';
	//p[1]='x';  ch[1]='x';
	static int num;             //数据段 （静态数据区）

	str = (char *)malloc(sizeof(char) * 128);  
	g_ptr = (char *)malloc(sizeof(char) * 32);
	strcpy(str, "nanjing");
	char *s = g_ptr;



	return 0;
}
