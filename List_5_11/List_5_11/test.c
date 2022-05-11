#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

//验证尾插
void TestList1()
{
	LTNode* plist = ListInit();//初始化一个 头节点
	ListPushBack(plist, 1);//尾插几个数
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);//打印
}

//验证头插
void TestList2()
{
	LTNode* plist = ListInit();//初始化一个 头节点
	ListPushFront(plist, 1);//尾插几个数
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPushFront(plist, 5);
	ListPrint(plist);//打印
}

//验证尾删
void TestList3()
{
	LTNode* plist = ListInit();//初始化一个 头节点
	ListPushBack(plist, 1);//尾插几个数
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);//打印

	ListPopBack(plist);//尾删几个数
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);//打印

	ListPushBack(plist, 1);
	ListPrint(plist);//打印
}

//验证头删
void TestList4()
{
	LTNode* plist = ListInit();//初始化一个 头节点
	ListPushBack(plist, 1);//尾插几个数
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);//打印

	ListPopFront(plist);//尾删几个数
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);//打印

	ListPushBack(plist, 1);
	ListPrint(plist);//打印
}

int main()
{
	//TestList1();
	//TestList2();
	//TestList3();
	TestList4();
}