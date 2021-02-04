#include <stdio.h>
#include "linklist.h"
#include <stdlib.h>

void welcome()
{
//	system("clear");
	printf("\t\t 欢迎使用 \n");
	sleep(1);
}

void menu()
{
//	system("clear");
	printf("\t\t 1. 添加学生信息	2.显示学生信息\n");
	printf("\t\t 3. 查找学生信息	4.修改学生信息\n");
	printf("\t\t 5. 删除学生信息	6.退出系统\n");
}

#define SIZE 1024;
char *name[5] = {"aaa", "bbb", "ccc", "ddd", "eee"};
char *tel[5] = {"11111111111", "22222222222", "33333333333",
				"44444444444", "55555555555"};

pNode head = NULL;
int ret = 0;

void init_info()
{
	srand(time(NULL));
	ret = InitLink(&head);
	if(SUCCESS == ret)
	{
		printf("初始化成功\n");
		int i, tempId;
		for(i = 0; i < 5; i ++)
		{
			//1.参数类型不同
			ret = 0;
			while(SUCCESS != ret)
			{
				tempId = rand() % 10;
				ret = check_id(head, tempId);		
			}	
			InsertLink(head, tempId, name[i], tel[i]);
		}
	}
	else
	{
		printf("初始化失败\n");
	}
}

void add_info()
{
	srand(time(NULL));
	int id;
	int tempId;
//存放待放置的位置
	char name[32] = {0};
	char tel[12] = {0};
	printf("请输入 学号，姓名，电话号码: \n");
	scanf("%d %s %s", &id, name, tel);
	ret = 0;
	ret = check_id(head, id);
	if(ret == FAILURE)
	{
		printf("添加失败 \n");
		return ;
	}
	ret = check_tel(tel);
	if(ret == FAILURE)
	{
		printf("tel不是11位\n");
	}
	else
	{
		InsertLink(head, id, name, tel);
		printf("添加成功\n");
	}
}

void show_info()
{
	TraverseLink(head);
}

void search_info()
{
	int way;
	printf("选择查询方式\n 1：id查询  2：name查询  3：tel查询\n");
	int tempId;
	char tempName[32];
	char tempTel[12];
	scanf("%d", &way );
	if(way == 1)
	{
		scanf("%d", &tempId);
	}
	else if(way == 2)
	{
		scanf("%s", tempName);
	}
	else if(way == 3)
	{
		scanf("%s", tempTel);
	}

	int i;
	for(i = 0; i < 20; i ++)
	{
	 	pNode q = (pNode)GetElem(&head, i);
		if(NULL == q)
		{
			break;
		}
		if(!strcmp(tempName, (q -> name)) ||
				tempId == (q -> id) ||
				!strcmp(tempTel, (q -> tel)))
			{
				printf("得到查询结果:%d,%s,%s\n", q -> id,
					q -> name, q -> tel);
				return ;
			}
	}
	printf("查询失败 \n");
}

void update_info()
{
	int count;
	int tempId;
	char tempName[32];
	char tempTel[12];
	show_info();
	printf("请选择修改第几个：\n");
	scanf("%d", &count);

	pNode q = (pNode)GetElem(&head, count);
	pNode n = (pNode)GetElem(&head,  (count - 1));
	printf("修改前：%d,%s,%s\n请输入修改后的数值\n"
		, q -> id, q -> name, q -> tel);
	scanf("%d %s %s" ,&tempId, tempName, tempTel);
	ret = check_id(head, tempId);
	if(FAILURE == ret )
	{
//		printg("")
		printf("修改失败\n");
		return ;
	}
	ret = check_tel(tempTel);
	if( FAILURE == ret)
	{
		printf("tel不是11位\n");
		return ;
	}
	n -> next = q -> next;
	InsertLink(head, tempId, tempName, tempTel);
	printf("\n修改后：\n");
	show_info();
}

void delete_info()
{
	int count;
	show_info();
	printf("请选择删除第几个：\n");
	scanf("%d", &count);
	pNode q = (pNode)GetElem(&head,  count);
	pNode n = (pNode)GetElem(&head,  (count - 1));
	n -> next = q -> next;
	free(q);
	printf("将显示现有成员: \n");
	show_info();
}

int main()
{
	welcome();
	init_info();
	int count;

	while(1)
	{
		menu();
		scanf("%d", &count);		

		switch(count)
		{
			case 1:
				add_info();
				break;
			case 2:
				show_info();
				break;
			case 3:
				search_info();
				break;
			case 4:
				update_info();
				break;
			case 5:
				delete_info();
				break;
			case 6:
				exit(1);
			default:
				printf("系统关闭 \n");
				sleep(1);
				exit(1);
		}
	}
	return 0;
}
