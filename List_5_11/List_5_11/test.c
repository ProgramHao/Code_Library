#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

//��֤β��
void TestList1()
{
	LTNode* plist = ListInit();//��ʼ��һ�� ͷ�ڵ�
	ListPushBack(plist, 1);//β�弸����
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);//��ӡ
}

//��֤ͷ��
void TestList2()
{
	LTNode* plist = ListInit();//��ʼ��һ�� ͷ�ڵ�
	ListPushFront(plist, 1);//β�弸����
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPushFront(plist, 5);
	ListPrint(plist);//��ӡ
}

//��֤βɾ
void TestList3()
{
	LTNode* plist = ListInit();//��ʼ��һ�� ͷ�ڵ�
	ListPushBack(plist, 1);//β�弸����
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);//��ӡ

	ListPopBack(plist);//βɾ������
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);//��ӡ

	ListPushBack(plist, 1);
	ListPrint(plist);//��ӡ
}

//��֤ͷɾ
void TestList4()
{
	LTNode* plist = ListInit();//��ʼ��һ�� ͷ�ڵ�
	ListPushBack(plist, 1);//β�弸����
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);//��ӡ

	ListPopFront(plist);//βɾ������
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);//��ӡ

	ListPushBack(plist, 1);
	ListPrint(plist);//��ӡ
}

int main()
{
	//TestList1();
	//TestList2();
	//TestList3();
	TestList4();
}