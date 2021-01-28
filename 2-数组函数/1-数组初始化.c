#include <stdio.h>

int main()
{
	//int a[10];
	//int k;
	//int a[k] = {0};    //定义数组的时候，长度一定是确定的

	//int a[5] = {1, 2, 3, 4, 5};   //全部初始化
	//int a[5] = {1, 2};            //没有初始化的都是0
	//int a[5];                     //未初始化的局部变量是随机值
	//int a[5] = {0};
	int a[] = {1, 2, 3, 4, 5};
	
	int i;
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("%p\n", &a[0]);  //数组首元素地址
	printf("%p\n", a);      //等价于 a[0]
	printf("%p\n", &a);     //数组的地址 加一相当于加了一个数组（20字节）

	printf("****\n");

	printf("%p\n", &a[0] + 1);
	printf("%p\n", a + 1);     //a++    a=a+1  数组名也是常指针
	printf("%p\n", &a + 1);

	return 0;
}
