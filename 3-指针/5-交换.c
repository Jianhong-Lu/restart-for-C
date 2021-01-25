#include <stdio.h>

void swap(int *x, int *y)   //*x就是a  *y就是b   通过指针x和y间接的交换了a和b
{
	int t = *x;
	*x = *y;
	*y = t;
}

int main()
{	
	int a = 1, b = 2;

	swap(&a, &b);

	printf("a = %d b = %d\n", a, b);
	return 0;
}
