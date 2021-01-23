#include <stdio.h>

int main()
{
	//int a;

	/*scanf("%d", &a);   //逗号后面跟上地址序列
	printf("%d\n", a);*/

	int b;

	/*scanf("%d%d", &a, &b);    //输入的时候需要空格隔开
	printf("%d %d\n", a, b);*/

	/*char ch1, ch2;
	scanf("%c%c", &ch1, &ch2);   //输入的时候不要空格
	printf("%c %c\n", ch1, ch2);*/

	/*char ch1, ch2;
	scanf("%c", &ch1);
	getchar();          //获取缓冲区里面的换行符
	scanf("%c", &ch2);

	printf("%c %c\n", ch1, ch2);*/

	/*int a;
	char ch;

	scanf("%c%d", &ch, &a);
	printf("%d %c\n", a, ch);*/

	char a[32] = {0};
	char ch;
	scanf("%s %c", a, &ch);
	printf("%s %c\n", a, ch);



	return 0;
}
