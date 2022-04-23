#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//#define N 200 //��һ�������������޸ģ���ò��ӷֺ�
//typedef int SLDataType; //�������ֵ��ض���
////���Ǿ�̬�汾��ȱ��̫�࣬��������ֱ���ö�̬�汾
//struct SeqList //�ýṹ���ʾ���˳���(��̬�汾)
//{
//	SLDataType a[N];
//	int size;
//};



typedef int SLDataType; //�������ֵ��ض���

//�ýṹ���ʾ���˳���(��̬�汾)
typedef struct SeqList 
{
	SLDataType* a;//ָ��ָ��̬���ٵĿռ�
	int size;   //�Ѿ���ŵ����ݵĸ���
	int capacity; //��̬���ٵ����������--�ռ�Ĵ�С
}SL;//����������ṹ�����͵�����


//��ɾ���

//˳���ĳ�ʼ������Ϊmalloc���ٵĶ�̬�ռ������ֵ�����ֵ
void SLInit(SL* ps);

//��ӡ����Ԫ�ظ���
void SLPrintArray(SL* ps);

//����˳���
void SLDestroy(SL* ps);

//����Ƿ�����
void SLCheckCapacity(SL* ps);

//β�� ʱ�临�Ӷ�O(1)
void SLPushBack(SL* ps, SLDataType x);

//ͷ�� ʱ�临�Ӷ�O(1)
void SLPushFront(SL* ps, SLDataType x);

//βɾ ʱ�临�Ӷ�O(N)
void SLPopBack(SL* ps);

//ͷɾ ʱ�临�Ӷ�O(N)
void SLPopFront(SL* ps);

//����λ��(�����±�) ���� ����
void SLInsert(SL* ps, int pos, SLDataType x);//pos���������λ�õ��±�

//ɾ�� �������λ��(�����±�)
void SLErase(SL* ps, int pos);//pos���������λ�õ��±�

//��һ�����ݣ�����������Ч������±꣬������
int SLFind(SL* ps, SLDataType x);

//��һ���±꣬�Ҵ�����¶Զ�Ӧ�����ݣ�Ȼ��������x�޸�
void SLModify(SL* ps, int pos, SLDataType x);//pos���±�