#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//静态的版本
void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

//动态的版本
//void InitContact(Contact* pc)
//{
//	assert(pc);
//	pc->sz = 0;
//	pc->capacity = DEFAULT_SZ;
//	pc->data = (PeoInfo*)malloc(pc->capacity * sizeof(PeoInfo));
//
//	if (pc->data == NULL)
//	{
//		perror("InitContact::malloc");
//		return;
//	}
//	memset(pc->data, 0, pc->capacity * sizeof(PeoInfo));
//}

//void DestroyContact(Contact* pc)
//{
//	free(pc->data);
//	pc->data = NULL;
//	pc->capacity = 0;
//	pc->sz = 0;
//	printf("销毁成功\n");
//}


//void CheckCapacity(Contact* pc)
//{
//	//增容的代码
//	if (pc->sz == pc->capacity)
//	{
//		PeoInfo* tmp = (PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInfo));
//		if (tmp != NULL)
//		{
//			pc->data = tmp;
//		}
//		else
//		{
//			perror("CheckCapacity::realloc");
//			return;
//		}
//		pc->capacity += 2;
//		printf("增容成功\n");
//	}
//}

void AddContact(Contact* pc)
{
	assert(pc);

	//静态版本
	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}

	//动态的版本
	//CheckCapacity(pc);

	//录入信息
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("添加成功\n");
}


void PrintContact(const Contact* pc)
{
	assert(pc);

	int i = 0;
	printf("%-20s %-5s %-5s %-12s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");

	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}

//找到了返回下标
//找不到返回-1
int FindByName(const Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}

	return -1;
}

void DelContact(Contact* pc)
{
	assert(pc);

	if (pc->sz == 0)
	{
		printf("通讯录已空，无法删除\n");
		return;
	}
	//删除
	//1. 找到
	char name[NAME_MAX] = { 0 };
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//2. 删除
	int j = 0;
	for (j = pos; j < pc->sz - 1; j++)
	{
		pc->data[j] = pc->data[j + 1];
	}

	pc->sz--;
	printf("删除成功\n");
}

void SearchContact(const Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	printf("%-20s %-5s %-5s %-12s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex,
		pc->data[pos].tele, pc->data[pos].addr);
}
