#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
定义指针 初始化指针 使用指针
*/

int main()
{
	int a = 100;
	int *q = &a;   //q指向操作系统分配的内存，可以使用

	int *p;       //野指针
	printf("%p\n", p);
	//*p = 100;

	//int *n = (int *)100000;   //不能自己指定地址
	//*n = 1;

	char *s = NULL;    //空指针就是0地址，也是不能用
	//strcpy(s, "hel");  //把"hel"拷贝到s指向的内存中（不是把hel拷贝s中）
	s = (char *)malloc(sizeof(char) * 128);  //返回这块内存开始的地址
	if (NULL == s)
	{
		printf("malloc failure\n");
	}
	strcpy(s, "hellloworld");

	free(s);  //malloc申请的内存需要手动释放 如果不释放，会造成内存泄漏

	hello   world       111111

	return 0;
}
