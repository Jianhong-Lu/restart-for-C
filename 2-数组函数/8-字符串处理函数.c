#include <stdio.h>
#include <string.h>

int main()
{
	char s1[128] = {0};
	char s2[128] = "helloworld";
	char s3[128] = "this is helloworld";

	//字符串拷贝
	/*strcpy(s1, s2);   //把s2里面的数据拷贝到s1中
	printf("%s\n", s1);
	strcpy(s3, s2);   //拷贝的数据包含'\0'
	printf("%s\n", s3);
	memset(s1, 0, sizeof(s1));  //从s1（地址）开始，往后sizeof(s1)个字节，全部设置为0
	strcpy(s1, "11111");   //"11111"编译器会处理成地址
	printf("%s\n", s1);
	memset(s1, 0, sizeof(s1));  //从s1（地址）开始，往后sizeof(s1)个字节，全部设置为0
	strncpy(s1, "helloworld", 5);  //只拷贝 5 个字节
	printf("%s\n", s1);*/

	//字符串连接
	strcat(s2, s3);   //把s3接到s2的后面
	printf("%s\n", s2);
	strcat(s2, "ooo");
	printf("%s\n", s2);
	strncat(s2, s3, 7);
	printf("%s\n", s2);

	char s4[32] = "helloworld";
	char s5[32] = "hellonanjing";
	//字符串比较
	if (strcmp(s4, s5) > 0)   //strcmp返回值 大于0 小于0 等于0
	{
		printf("%s > %s\n", s4, s5);
	}

	if (!strncmp(s4, s5, 5))
	{
		printf("%s == %s\n", s4, s5);
	}

	return 0;
}
