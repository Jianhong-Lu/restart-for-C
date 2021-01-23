#include <stdio.h>

int main()
{
	int a = 0;

	printf("%d\n", a++);  //后置 执行完a所在语句之后，a的值加一
	printf("%d\n", ++a);  //前置 执行a所在语句之前，a的值加一

	a = 4;
	a   += a++; 
	printf("a = %d\n", a);

	a = 4;
	a += ++a;   
	printf("a = %d\n", a);

	a = 4;
	++a += a;  
	printf("a = %d\n", a);

	a = 4;
	++a += a++; 
	printf("a = %d\n", a);

	a = 4;
	++a += ++a;
	printf("a = %d\n", a);


	printf("******\n");

	int i = 3, k;
    k = (++i) + (++i) + (i++);
    printf("i = %d, k = %d\n", i, k);

    i = 3;
    k = (++i) + (++i) + (++i);
    printf("i = %d, k = %d\n", i, k);

    i = 3;
    k = (i++) + (i++) + (i++);
    printf("i = %d, k = %d\n", i, k);


	return 0;
}
