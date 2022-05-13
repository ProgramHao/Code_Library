#pragma once

////静态，一般不用
//#define N 100 //定义一个宏，注意最好不要加分号，因为是完全替换
//typedef int STDataType;//重命名类型的名字
//
////因为用数组实现栈，所以用结构体表示 栈
//typedef struct Stack
//{
//	STDataType a[N];//数组用来表示栈
//	int top;//top是表示实际存储的数据个数，即有效数据个数
//};


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//动态
typedef int STDataType;//重命名类型的名字

//因为用数组实现栈，所以用结构体表示 栈
typedef struct Stack
{
	STDataType* a;//数组用来存放数据,因为是动态开辟空间，所以开辟一个数组的空间，指针a指向这块空间
	int top;//top是表示实际存储的数据个数，即有效数据个数
	int capacity;//数组的容量，即可以存放的数据的个数
}ST;

//初始化栈
void StackInit(ST* ps);

//销毁栈
void StackDestroy(ST* ps);

//入栈
void StackPush(ST* ps, STDataType x);

//出栈
void StackPop(ST* ps);

//栈顶的 元素
STDataType StackTop(ST* ps);

//判断栈是为空
bool StackEmpty(ST* ps);

//返回栈的有效元素个数
int StackSize(ST* ps);