#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//1、按照学号排序    2、电话长度判断（11）重复判断 3、结构体指针数组
//增加学生信息  查看学生信息 查找学生信息   修改学生信息   删除学生信息  
//程序启动后随即增加5个学生的信息

#define SIZE     1024
char *name[5] = {"aaaa", "bbbb", "cccc", "ddddd", "eeeee"};
char *tel[5] = {"11111111111",
				"22222222222",
				"33333333333", 
				"44444444444",
				"55555555555"};

struct Student
{
	int id;
	char name[32];
	char tel[12];
};
typedef struct Student stu;

stu *g_StuInfo[SIZE] = {0};
int g_person = 0;

void welcome()
{
	system("clear");
	printf("\t\t欢迎\n");
	sleep(1);
}

void menu()
{
	system("clear");
	printf("\t\t1、添加学生信息      2、显示学生信息\n");
	printf("\t\t3、查找学生信息      4、修改学生信息\n");
	printf("\t\t5、删除学生信息      6、退出系统\n");
}
	
void init_system()
{
	srand(time(NULL));
	int i;
	for (i = 0; i < 5; i++)
	{
		g_StuInfo[g_person] = (stu *)malloc(sizeof(stu) * 1);
		if (NULL == g_StuInfo[g_person])
		{
			printf("申请失败\n");
			return;
		}
		g_StuInfo[g_person]->id = rand() % 10;
		strcpy(g_StuInfo[g_person]->name, name[rand() % 5]);
		strcpy(g_StuInfo[g_person]->tel, tel[g_person]);
		g_person++;
	}
}

void show_info()
{
	int i;
	for (i = 0; i < g_person; i++)
	{
		printf("\t\t id %d name %s tel %s\n", g_StuInfo[i]->id, 
							g_StuInfo[i]->name, g_StuInfo[i]->tel);
	}
	printf("按任意键继续\n");
	getchar();
	getchar();
}

void add_info()
{
	printf("\t\t输入学生信息（学号 姓名 电话）\n");
	g_StuInfo[g_person] = (stu *)malloc(sizeof(stu) * 1);
	if (NULL == g_StuInfo[g_person])
	{
		printf("申请失败\n");
	}

	scanf("%d%s%s", &g_StuInfo[g_person]->id, g_StuInfo[g_person]->name, 
							g_StuInfo[g_person]->tel);
	
	printf("\t\t添加信息成功\n");
	g_person++;
	sleep(1);
}

int main()
{
	welcome();
	int id;

	init_system();

	while (1)
	{
		menu();

		scanf("%d", &id);
		switch(id)
		{
			case 1:
				add_info();
				break;
			case 2:
				show_info();
				break;
			case 6:
				exit(1);
		}
	}
	return 0;
}
