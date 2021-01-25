#include <stdio.h>

void mystrcpy(char *dest, const char *src)   //const作用：防止修改src指向的内容 
{
	/*while (*src != '\0')
	{
		*dest++ = *src++;
	}*/

	while ((*dest++ = *src++) != '\0');   //会复制'\0'
}

int main()
{	
	char s1[32] = "111111111111111111";
	char s2[32] = "helloworld";

	mystrcpy(s1, s2);

	printf("%s\n", s1);

	int a = 100;

	//就近原则
	const int *p = &a;   //p指向的内容不能改
	p++;
	//(*p)++;

	int *const q = &a;   //指针p不能改，但是p指向的内容可以改
	//q++;
	(*q)++;

	const int *const n = &a;
	//n++;
	//(*n)++;

	return 0;
}
