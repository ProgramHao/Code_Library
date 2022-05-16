#pragma once


#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdio.h>

//因为这里用的单链表来实现队列，所以一个结构体表示单链表的节点
//另外定义的结构体表示队列

typedef int QDataType;//typedef类型名重命名
//单链表的节点依旧用结构体表示
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;


//因为我们这里用指针head表示第一个节点，用指针tail表示尾节点，所以这里再定义一个结构体表示队列
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

//初始化队列
void QueueInit(Queue* pq);

//销毁队列
void QueueDestroy(Queue* pq);

//队尾入
void QueuePush(Queue* pq, QDataType x);

//对头出
void QueuePop(Queue* pq);

//返回对头的数据
QDataType QueueFront(Queue* pq);

//返回队尾的数据
QDataType QueueBack(Queue* pq);

//判断队列是否为空
bool QueueEmpty(Queue* pq);

//返回队列的数据个数
int QueueSize(Queue* pq);