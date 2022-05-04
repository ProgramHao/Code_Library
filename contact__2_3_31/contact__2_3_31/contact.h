#pragma once
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//类型的声明

#define MAX 1000  //定义常量，后面最好不要加分号

#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30

//通讯录初始状态的容量大小
#define DEFAULT_SZ 3

enum Option  //注意，枚举里是逗号，因为相当于常量
{
	EXIT,//0,枚举默认从为0，并依次加1
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SORT,//5
	PRINT//6
};

typedef struct PeoInfo
{
	char name[NAME_MAX];//结构体里面是分号；，因为里面是变量，相当于语句
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
} PeoInfo;


//动态的版本
typedef struct Contact  //相当于一个节点，只不过是顺序表，物理结构是连续的，不需要通过指针链接每一个节点
{
	PeoInfo* data;//可以存放1000个人的信息
	int sz;//记录通讯中已经保存的信息个数
	int capacity;//记录通讯录当前的最大容量
}Contact;



//函数的声明

//初始化通讯录
void InitContact(Contact* pc);

//销毁通讯录
void DestroyContact(Contact* pc);

//增加联系人的信息
void AddContact(Contact* pc);

//打印通讯录中的信息
void PrintContact(const Contact* pc);

//删除指定联系人
void DelContact(Contact* pc);

//查找指定联系人
void SearchContact(const Contact* pc);

//保存通讯录到文件
void SaveContact(Contact* pc);

//是否增加容量
void CheckCapacity(Contact* pc);

//加载文件内容到通讯录
void LoadContact(Contact* pc);