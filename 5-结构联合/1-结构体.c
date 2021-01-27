#include <stdio.h>
#include <string.h>

//声明一个结构体
struct Student     //Student是结构体名
{
	char name[32];    //char name[32] = {0};   //结构体属于声明，不能初始化
	char sex;
	int age;
};
typedef struct Student stu;

int main()
{
	struct Student s1;    //定义结构体变量
	struct Student s2 = {"jack", 'm', 20};   //结构体初始化
	stu s3;
	//s1 = {"tom", 'm', 20};   //不能这样初始化
	//通过结构体变量访问结构体成员
	strcpy(s1.name, "tom");
	s1.sex = 'f';
	s1.age = 10;

	printf("name : %s sex : %c age : %d\n", s1.name, s1.sex, s1.age);

	stu *ps = (stu *)malloc(sizeof(stu) * 1);   //结构体指针  并且为结构体申请内存
	strcpy(ps->name, "xx");  //通过结构体指针访问结构体成员，使用 ->
	ps->sex = 'm';
	ps->age = 10;

	stu s4[5];   //结构体数组
	strcpy(s4[0].name, "aa");
	s4[0].age = 10;
	strcpy(s4->name, "aa");

	stu *s5[5] = {0};     //结构体指针数组
	s5[0] = malloc(sizeof(stu) * 1);
	s5[0]->name;



	return 0;
}
