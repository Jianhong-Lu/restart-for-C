#include <stdio.h>

int main()
{
	char ch = -128;   //signed char ch = 127   有符号char
	unsigned char aa = 66;
	char num = ch - 1;

	printf("%d\n", num);

	//127 + 1 = -128 a

	int  i =  -20;
	//unsigned  int j = 10;
	unsigned int j = 20;
	
	printf("%u\n", i + j);   //%u表示无符号整形

	return 0;
}
