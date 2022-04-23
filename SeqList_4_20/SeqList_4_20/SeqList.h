#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//#define N 200 //宏一个常量，方便修改，最好不加分号
//typedef int SLDataType; //类型名字的重定义
////但是静态版本的缺陷太多，所以我们直接用动态版本
//struct SeqList //用结构体表示这个顺序表(静态版本)
//{
//	SLDataType a[N];
//	int size;
//};



typedef int SLDataType; //类型名字的重定义

//用结构体表示这个顺序表(动态版本)
typedef struct SeqList 
{
	SLDataType* a;//指针指向动态开辟的空间
	int size;   //已经存放的数据的个数
	int capacity; //动态开辟的数组的容量--空间的大小
}SL;//重命名这个结构体类型的名字


//增删查改

//顺序表的初始化，因为malloc开辟的动态空间里面的值是随机值
void SLInit(SL* ps);

//打印数据元素个数
void SLPrintArray(SL* ps);

//销毁顺序表
void SLDestroy(SL* ps);

//检查是否增容
void SLCheckCapacity(SL* ps);

//尾插 时间复杂度O(1)
void SLPushBack(SL* ps, SLDataType x);

//头插 时间复杂度O(1)
void SLPushFront(SL* ps, SLDataType x);

//尾删 时间复杂度O(N)
void SLPopBack(SL* ps);

//头删 时间复杂度O(N)
void SLPopFront(SL* ps);

//任意位置(给的下标) 插入 数据
void SLInsert(SL* ps, int pos, SLDataType x);//pos是这个任意位置的下标

//删除 这个任意位置(给的下标)
void SLErase(SL* ps, int pos);//pos是这个任意位置的下标

//给一个数据，查找它在有效数组的下标，并返回
int SLFind(SL* ps, SLDataType x);

//给一个下标，找打这个下对对应的数据，然后用数据x修改
void SLModify(SL* ps, int pos, SLDataType x);//pos是下标