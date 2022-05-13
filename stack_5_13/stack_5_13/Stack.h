#pragma once

////��̬��һ�㲻��
//#define N 100 //����һ���꣬ע����ò�Ҫ�ӷֺţ���Ϊ����ȫ�滻
//typedef int STDataType;//���������͵�����
//
////��Ϊ������ʵ��ջ�������ýṹ���ʾ ջ
//typedef struct Stack
//{
//	STDataType a[N];//����������ʾջ
//	int top;//top�Ǳ�ʾʵ�ʴ洢�����ݸ���������Ч���ݸ���
//};


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//��̬
typedef int STDataType;//���������͵�����

//��Ϊ������ʵ��ջ�������ýṹ���ʾ ջ
typedef struct Stack
{
	STDataType* a;//���������������,��Ϊ�Ƕ�̬���ٿռ䣬���Կ���һ������Ŀռ䣬ָ��aָ�����ռ�
	int top;//top�Ǳ�ʾʵ�ʴ洢�����ݸ���������Ч���ݸ���
	int capacity;//����������������Դ�ŵ����ݵĸ���
}ST;

//��ʼ��ջ
void StackInit(ST* ps);

//����ջ
void StackDestroy(ST* ps);

//��ջ
void StackPush(ST* ps, STDataType x);

//��ջ
void StackPop(ST* ps);

//ջ���� Ԫ��
STDataType StackTop(ST* ps);

//�ж�ջ��Ϊ��
bool StackEmpty(ST* ps);

//����ջ����ЧԪ�ظ���
int StackSize(ST* ps);