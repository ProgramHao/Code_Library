#pragma once


#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdio.h>

//��Ϊ�����õĵ�������ʵ�ֶ��У�����һ���ṹ���ʾ������Ľڵ�
//���ⶨ��Ľṹ���ʾ����

typedef int QDataType;//typedef������������
//������Ľڵ������ýṹ���ʾ
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;


//��Ϊ����������ָ��head��ʾ��һ���ڵ㣬��ָ��tail��ʾβ�ڵ㣬���������ٶ���һ���ṹ���ʾ����
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

//��ʼ������
void QueueInit(Queue* pq);

//���ٶ���
void QueueDestroy(Queue* pq);

//��β��
void QueuePush(Queue* pq, QDataType x);

//��ͷ��
void QueuePop(Queue* pq);

//���ض�ͷ������
QDataType QueueFront(Queue* pq);

//���ض�β������
QDataType QueueBack(Queue* pq);

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

//���ض��е����ݸ���
int QueueSize(Queue* pq);