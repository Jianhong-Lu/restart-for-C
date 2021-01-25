#include <stdio.h>
#include <string.h>

int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	int *p = a;   //int *p = &a;   

	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", *(p + i));   //用指针表示数组
		printf("%d ", *(a + i));   //a[i]  ===== *(a + i)   []等价于*()
	}

	char *s = "helloworld";   //字符串常量  把字符串的首地址赋值给指针s
	//*(s + 1) s[1]
	printf("%c\n", s[1]);   //用数组表示指针   把指针当做了数组名使用
	//s[1] = 'x';

	char *s1;   s1 = "helloworld";    
	char s2[16];  //s2 = "helloworld";   //数组名是常指针，不能被修改
	strcpy(s2, "helloworld");
	printf("%d\n", sizeof(s1));    //4
	printf("%d\n", sizeof(s2));    //16
	printf("%d\n", strlen(s1));    //10
	printf("%d\n", strlen(s2));    //10

	return 0;
}
