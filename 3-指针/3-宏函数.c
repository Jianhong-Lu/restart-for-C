#include <stdio.h>

#define A   100
#define P    printf("helloworld\n")   //无参宏函数
#define F(S) printf("%s\n", S);       //有参宏函数
#define SQR(x) (x) * (x)        //写宏函数的时候，尽量多用括号

/*普通函数和宏函数的优缺点：
普通函数缺点：执行效率低、浪费空间
普通函数优点：编译快 安全
			  
宏函数缺点：没有语法检查不安全 编译慢
宏函数优点：执行效率高、节省空间   */

int main()
{
	P;
	F("hello");
	//F(100);
	int m = 1, n = 2;
	printf("%d\n", SQR(m + n));   //1 + 2 * 1 + 2
	
	return 0;
}
