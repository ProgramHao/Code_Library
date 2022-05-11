#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;//��������������

//����Ľڵ������ýṹ���ʾ
typedef struct ListNode
{
	struct ListNode* next;//�ṹ�������ָ�룬�ֱ�ָ����һ���ڵ����һ���ڵ�
	struct ListNode* prev;
	LTDataType data;
}LTNode;



//�����½ڵ�ĺ���
LTNode* BuyListNode(LTDataType x);


//��ʼ�� ͷ�ڵ� ��Ϊ������� ��ͷ��˫��ѭ������
//ͷ�ڵ�����ڱ�λ�����ã������˾�ʼ����Ϊ�����ͷ�ڵ㣬ָ��ͷ�ڵ� ��ָ�뱾��ĵ�ַ ���ܸı䣬�������治��������
LTNode* ListInit();


//β��
//�����û�з���ָ�룬���ββ����õĶ���ָ�룬����Ϊ ָ��ͷ�ڵ� ��ָ��ı���ĵ�ַ ���ܱ��ı�
//��Ϊͷ�ڵ����ڱ�λ�����ã����������ָ��ͷ�ڵ��ָ��󣬱���ĵ�ַ�Ͳ��ܱ��ı���
void ListPushBack(LTNode* phead, LTDataType x);


//ͷ��
//�����û�з���ָ�룬���ββ����õĶ���ָ�룬����Ϊ ָ��ͷ�ڵ� ��ָ��ı���ĵ�ַ ���ܱ��ı�
//��Ϊͷ�ڵ����ڱ�λ�����ã����������ָ��ͷ�ڵ��ָ��󣬱���ĵ�ַ�Ͳ��ܱ��ı���
void ListPushFront(LTNode* phead, LTDataType x);


//βɾ
//�����û�з���ָ�룬���ββ����õĶ���ָ�룬����Ϊ ָ��ͷ�ڵ� ��ָ��ı���ĵ�ַ ���ܱ��ı�
//��Ϊͷ�ڵ����ڱ�λ�����ã����������ָ��ͷ�ڵ��ָ��󣬱���ĵ�ַ�Ͳ��ܱ��ı���
void ListPopBack(LTNode* phead);


//ͷɾ
//�����û�з���ָ�룬���ββ����õĶ���ָ�룬����Ϊ ָ��ͷ�ڵ� ��ָ��ı���ĵ�ַ ���ܱ��ı�
//��Ϊͷ�ڵ����ڱ�λ�����ã����������ָ��ͷ�ڵ��ָ��󣬱���ĵ�ַ�Ͳ��ܱ��ı���
void ListPopFront(LTNode* phead);


//�ڽڵ�posǰ����һ���ڵ�
void ListInsert(LTNode* pos, LTDataType x);


//ɾ���ڵ�pos
void ListErase(LTNode* pos);


//��������x�Ľڵ�pos
LTNode* FindNode(LTNode* phead, LTDataType x);