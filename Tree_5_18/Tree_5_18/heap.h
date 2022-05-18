#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int HPDataType;

//����һ���ѣ��ýṹ���ʾ
typedef struct Heap
{
	HPDataType* a;//��Ϊ������ȫ��������������˳��洢����������
	int size;//��Ч���ݵĸ���
	int capacity;//����
}HP;

//��ʼ����
void HeapInit(HP* php);

//���ٶ�
void HeapDestroy(HP* php);

//�����������ĺ���
void Swap(HPDataType* a, HPDataType* b);

//���ϵ����㷨
//child�ǲ������ݵ��±�
void AdjustUp(HPDataType* a, int child);

//��ѣ���Ϊ�����飬���Կ϶��Ǵ��������������
void HeapPush(HP* php, HPDataType x);

//����
void HeapPop(HP* php);

//�Ѷ������ݣ��������һ������
HPDataType HeapTop(HP* php);

//
bool HeapEmpty(HP* php);

int HeapSize(HP* php);

void HeapPrint(HP* php);