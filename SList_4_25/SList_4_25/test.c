#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"


//测试单链表 如何链接每个节点，这个测试是为了理解如何链接的
void TestSList1()
{
	//用对应的结构体指针接收这块空间，就可以通过指针 进行访问 并且 可以修改
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));//malloc一个结构体类型SLTNoded的大小，即创建一个但单链表的节点
	assert(n1);//暴力检查是否开辟成功，也可以用if语句温柔检查

	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));//malloc一个结构体类型SLTNoded的大小，即创建一个但单链表的节点
	assert(n2);//暴力检查是否开辟成功，也可以用if语句温柔检查

	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));//malloc一个结构体类型SLTNoded的大小，即创建一个但单链表的节点
	assert(n3);//暴力检查是否开辟成功，也可以用if语句温柔检查

	SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTNode));//malloc一个结构体类型SLTNoded的大小，即创建一个但单链表的节点
	assert(n4);//暴力检查是否开辟成功，也可以用if语句温柔检查

	n1->data = 1;//给每个节点里面的data初始化数据
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;

	n1->next = n2;//给每个节点的里的指针next初始化，并且初始化为指向下一个节点的空间，所以赋值的是写一个节点的地址
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;//这个节点n4是最后一个节点，因为是单链表，所以节点n4里的指针next初始化空指针NULL

	SListPrint(n1);//打印链表
}

void TestSList2()//测试尾插
{
	SLTNode* plist = NULL;//定义 单链表第一个节点，直接空指针，意思是一开始这个单链表一个节点都没有
	SListPushBack(&plist, 1);//实参是第一个节点 本身的地址，即一级指针 本身的地址，注意是一级指针本身的地址，是本身的，所以用二级指针接收
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);

	SListPrint(plist);//打印链表，这里值传递即可，因为不会改变实参，即不会改变第一个节点
}

void TestSList3()//测试尾插
{
	SLTNode* plist = NULL;//定义 单链表第一个节点，直接空指针，意思是一开始这个单链表一个节点都没有
	SListPushFront(&plist, 11);//实参是第一个节点 本身的地址，即一级指针 本身的地址，注意是一级指针本身的地址，是本身的，所以用二级指针接收
	SListPushFront(&plist, 22);
	SListPushFront(&plist, 33);
	SListPushFront(&plist, 44);
	SListPushFront(&plist, 55);

	SListPrint(plist);//打印链表，这里值传递即可，因为不会改变实参，即不会改变第一个节点
}

void TestSList4()//测试尾删
{
	SLTNode* plist = NULL;//定义 单链表第一个节点，直接空指针，意思是一开始这个单链表一个节点都没有
	SListPushBack(&plist, 11);//实参是第一个节点 本身的地址，即一级指针 本身的地址，注意是一级指针本身的地址，是本身的，所以用二级指针接收
	SListPushBack(&plist, 22);
	SListPushBack(&plist, 33);
	SListPushBack(&plist, 44);
	SListPushBack(&plist, 55);
	SListPrint(plist);//打印链表，这里值传递即可，因为不会改变实参，即不会改变第一个节点

	SListPopBack(&plist);//尾删
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	
	SListPrint(plist);//打印链表，这里值传递即可，因为不会改变实参，即不会改变第一个节点
}

void TestSList5()//测试头删
{
	SLTNode* plist = NULL;//定义 单链表第一个节点，直接空指针，意思是一开始这个单链表一个节点都没有
	SListPushBack(&plist, 1);//实参是第一个节点 本身的地址，即一级指针 本身的地址，注意是一级指针本身的地址，是本身的，所以用二级指针接收
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);//打印链表，这里值传递即可，因为不会改变实参，即不会改变第一个节点

	SListPopFront(&plist);//头删
	SListPopFront(&plist);
	SListPrint(plist);//打印链表，这里值传递即可，因为不会改变实参，即不会改变第一个节点
}

void TestSList6()//测试查找和 修改(附带)
{
	SLTNode* plist = NULL;//定义 单链表第一个节点，直接空指针，意思是一开始这个单链表一个节点都没有
	SListPushBack(&plist, 11);//实参是第一个节点 本身的地址，即一级指针 本身的地址，注意是一级指针本身的地址，是本身的，所以用二级指针接收
	SListPushBack(&plist, 22);
	SListPushBack(&plist, 33);
	SListPushBack(&plist, 44);
	SListPushBack(&plist, 55);
	SListPrint(plist);//打印链表，这里值传递即可，因为不会改变实参，即不会改变第一个节点

	SLTNode* ret = SListFind(plist, 55);//这里只是查找，并不会改变第一个节点，和打印一样，所以直接值传递就行，即形参用一级指针即可
	if (ret != NULL)
	{
		printf("找到了对应的节点\n");
		ret->data = 666;//查找出来后，还可以附带的 修改，完全不用单独修改，当然，也可以单独写一个
		SListPrint(plist);//打印链表，这里值传递即可，因为不会改变实参，即不会改变第一个节点
	}
	else
	{
		printf("没找到对应的节点\n");
	}
}

void TestSList7()//测试随机插(和查找函数配合使用)
{
	SLTNode* plist = NULL;//定义 单链表第一个节点，直接空指针，意思是一开始这个单链表一个节点都没有
	SListPushBack(&plist, 111);//实参是第一个节点 本身的地址，即一级指针 本身的地址，注意是一级指针本身的地址，是本身的，所以用二级指针接收
	SListPushBack(&plist, 222);
	SListPushBack(&plist, 333);
	SListPushBack(&plist, 444);
	SListPushBack(&plist, 555);
	SListPrint(plist);//打印链表，这里值传递即可，因为不会改变实参，即不会改变第一个节点

	SLTNode* ret = SListFind(plist, 111);//这里只是查找，并不会改变第一个节点，和打印一样，所以直接值传递就行，即形参用一级指针即可
	if (ret != NULL)
	{
		printf("找到了对应的节点\n");
		SListInsert(&plist, ret, 1234);//第一个节点可能会改变，所以实参是一级指针(第一个节点)本身的地址，用二级指针接收，是 地址传递
		SListPrint(plist);//打印链表，这里值传递即可，因为不会改变实参，即不会改变第一个节点
	}
	else
	{
		printf("没找到对应的节点\n");
	}

}

void TestSList8()//测试随机删(和查找函数配合使用)
{
	SLTNode* plist = NULL;//定义 单链表第一个节点，直接空指针，意思是一开始这个单链表一个节点都没有
	SListPushBack(&plist, 1111);//实参是第一个节点 本身的地址，即一级指针 本身的地址，注意是一级指针本身的地址，是本身的，所以用二级指针接收
	SListPushBack(&plist, 2222);
	SListPushBack(&plist, 3333);
	SListPushBack(&plist, 4444);
	SListPushBack(&plist, 5555);
	SListPrint(plist);//打印链表，这里值传递即可，因为不会改变实参，即不会改变第一个节点

	SLTNode* ret = SListFind(plist, 1111);//这里只是查找，并不会改变第一个节点，和打印一样，所以直接值传递就行，即形参用一级指针即可
	if (ret != NULL)
	{
		printf("找到了对应的节点\n");
		SListErase(&plist, ret);//第一个节点可能会改变，所以实参是一级指针(第一个节点)本身的地址，用二级指针接收，是 地址传递
		SListPrint(plist);//打印链表，这里值传递即可，因为不会改变实参，即不会改变第一个节点
	}
	else
	{
		printf("没找到对应的节点\n");
	}

}

int main()
{
	//TestSList1();//测试单链表 如何链接每个节点，这个测试是为了理解如何链接的
	//TestSList2();//测试尾插
	//TestSList3();//测试头插
	//TestSList4();//测试尾删
	//TestSList5();//测试头删
	//TestSList6();//测试查找和 修改(附带)
	//TestSList7();//测试随机插(和查找函数配合使用)
	TestSList8();//测试随机删(和查找函数配合使用)
	return 0;
}