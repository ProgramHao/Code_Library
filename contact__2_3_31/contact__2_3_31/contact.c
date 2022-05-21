#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


void LoadContact(Contact* pc)
{
	FILE* pf = fopen("text.txt", "r");
	if (pf == NULL)
	{
		perror("the mistake is");
		return;
	}
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))//fread读取数据函数，会返回读取数据元素成功的个数，这里我们一个一个元素读，
		                                       //如果读取成功，那么返回值为1，读取不成功，返回值为0，这时全部从文件读取完，跳出循环
	{
		//考虑是否增加容量
		CheckCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;
}

//动态的版本
void InitContact(Contact* pc)
{
	assert(pc);//断言，防止空指针
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;//当前通讯录的最大容量
	pc->data = (PeoInfo*)malloc(pc->capacity * sizeof(PeoInfo));//动态申请一块空间，date相当于数组名，每个元素是结构体类型 
	//pc->data = (PeoInfo*)calloc(pc->capacity, sizeof(PeoInfo));或者直接用calloc姐可以代替malloc和memset函数
	if (pc->data == NULL)//动态申请空间失败，函数malloc会返回空指针
	{
		perror("InitContact::malloc");
		return;
	}
	memset(pc->data, 0, pc->capacity * sizeof(PeoInfo));//总字节：通讯录最大容量*存放个人信息结构体类型的所占空间，数组date里总字节用0替换
                                                        //将数组的内容初始化

	//加载文件内容到通讯录
	LoadContact(pc);

}                                                       

void SaveContact(Contact* pc)//保存通讯录到文件
{
	int i = 0;
	FILE* pf = fopen("text.txt", "w");
	if (pf == NULL)
	{
		perror("the mistake is");
		return;
	}

	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}

void DestroyContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
	printf("销毁通讯率成功\n");
}


void CheckCapacity(Contact* pc)
{
	//增容的代码
	if (pc->sz == pc->capacity)
	{
		PeoInfo* tmp = (PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInfo));//两个结构体PeoInfo类型的空间的增加
		if (tmp != NULL)//判断是否开辟成功
		{
			pc->data = tmp;
		}
		else
		{
			perror("CheckCapacity::realloc");
			return;
		}
		pc->capacity += 2;
		printf("增容成功\n");
	}
}

void AddContact(Contact* pc)
{
	assert(pc);

	//动态的版本
	CheckCapacity(pc);

	//录入信息
	printf("请输入名字:>");             //date就是数组的数组名，是首元素地址，数组里的元素是结构体PeoInfo类型
	scanf("%s", pc->data[pc->sz].name); //指针p  p[0]===*(p+0) 相当于把指针当数组来看
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
		printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[i].name, 
			pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
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

void DelContact(Contact* pc,FILE* pf)
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
	fscanf(pf, "%s %d %s %s %s", pc->data[pc->sz].name, &(pc->data[pc->sz].age), pc->data[pc->sz].sex, pc->data[pc->sz].tele, pc->data[pc->sz].addr);
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
	printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[pos].name, 
		pc->data[pos].age, pc->data[pos].sex,
		pc->data[pos].tele, pc->data[pos].addr);
}
