#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int HPDataType;

//建立一个堆，用结构体表示
typedef struct Heap
{
	HPDataType* a;//因为堆是完全二叉树，所以用顺序存储，即用数组
	int size;//有效数据的个数
	int capacity;//容量
}HP;

//初始化堆
void HeapInit(HP* php);

//销毁堆
void HeapDestroy(HP* php);

//交换俩个数的函数
void Swap(HPDataType* a, HPDataType* b);

//向上调整算法
//child是插入数据的下标
void AdjustUp(HPDataType* a, int child);

//入堆，因为是数组，所以肯定是从数组后面入数据
void HeapPush(HP* php, HPDataType x);

//出堆
void HeapPop(HP* php);

//堆顶的数据，即数组第一个数据
HPDataType HeapTop(HP* php);

//
bool HeapEmpty(HP* php);

int HeapSize(HP* php);

void HeapPrint(HP* php);