#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"


//创建新节点的函数
LTNode* BuyListNode(LTDataType x)
{
	//动态开辟一个节点(结构体)的空间
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)//判断是否开辟成功
	{
		perror("fail");//perror()函数是用于动态开辟失败的时候，直接结束函数，并返回错误地方的信息
	}

	//开辟成功后，初始化结构体里的指针和数据
	node->data = x;
	node->next = NULL;//将节点里的指针初始化为NULL，方便后面修改
	node->prev = NULL;

	return node;//返回创建的新节点
}


//初始化 头节点 因为这里的是 带头的双向循环链表
//头节点就是哨兵位的作用，定义了就始终作为链表的头节点，指向头节点 的指针本身的地址 不能改变，并且里面不会存放数据
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1);//这里给了数据-1，只是为了用上这个函数，实际上-1并没有用，因为头节点不存放数据
	phead->next = phead;//因为是循环链表，所以初始化头节点的时候，头节点里的指针都要指向自己
	phead->prev = phead;

	return phead;//返回这个指针，用返回值，函数形参就不需要用二级指针，更加方便
}


//打印链表
void ListPrint(LTNode* phead)
{
	assert(phead);//断言好习惯，防止传递过来的 头节点是空指针

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//尾插
//这里既没有返回指针，又形参不是用的二级指针，是因为 指向头节点 的指针的本身的地址 不能被改变
//因为头节点是哨兵位的作用，定义了这个指向头节点的指针后，本身的地址就不能被改变了
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);//断言好习惯，防止传递过来的 头节点是空指针

	//尾插，先创建需要的节点
	LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;//定义链表的尾节点，即使链表 只有头节点 的时候也满足

	tail->next = newnode;//重新链接新节点、头节点和尾节点
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;


	////尾插方法二
	//ListInsert(phead, x);
}


//头插
//这里既没有返回指针，又形参不是用的二级指针，是因为 指向头节点 的指针的本身的地址 不能被改变
//因为头节点是哨兵位的作用，定义了这个指向头节点的指针后，本身的地址就不能被改变了
void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);//断言好习惯，防止传递过来的 头节点是空指针

	//头插，先创建需要的节点
	LTNode* newnode = BuyListNode(x);
	LTNode* first = phead->next;//定义链表的第一个节点，即使链表 只有头节点 的时候也满足

	phead->next = newnode;//重新来链接第一个节点、头节点和新节点
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;

	////头插的方法二
	//ListInsert(phead->next, x);
}



//尾删
//这里既没有返回指针，又形参不是用的二级指针，是因为 指向头节点 的指针的本身的地址 不能被改变
//因为头节点是哨兵位的作用，定义了这个指向头节点的指针后，本身的地址就不能被改变了
void ListPopBack(LTNode* phead)
{
	assert(phead);//断言好习惯，防止传递过来的 头节点是空指针

	LTNode* tail = phead->prev;//定义链表的尾节点
	LTNode* prev = tail->prev;//定义尾节点的前一个节点

	if (tail != phead)//防止链表一个节点都没有的时候，防止会删除 头节点，所以加个判断条件
	{
		free(tail);//删除尾节点，即释放掉它的空间
		tail = NULL;

		prev->next = phead;
		phead->prev = prev;
	}
	else //即链表里没有一个节点的时候，直接结束，就不会删除掉 头节点
	{
		return;
	}


	////尾删方法二
	//ListErase(phead->prev);
}



//头删
//这里既没有返回指针，又形参不是用的二级指针，是因为 指向头节点 的指针的本身的地址 不能被改变
//因为头节点是哨兵位的作用，定义了这个指向头节点的指针后，本身的地址就不能被改变了
void ListPopFront(LTNode* phead)
{
	assert(phead);//断言好习惯，防止传递过来的 头节点是空指针

	LTNode* first = phead->next;//定义第一个节点
	LTNode* next = first->next;//定义第一个节点的下一个节点

	if (first != phead)//防止链表一个节点都没有的时候，防止会删除 头节点，所以加个判断条件
	{
		free(first);
		first = NULL;

		phead->next = next;
		next->prev = phead;
	}
	else//即链表里没有一个节点的时候，直接结束，就不会删除掉 头节点
	{
		return;
	}


	////头删方法二
	//ListErase(phead->next);
}



//在节点pos前插入一个节点
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);//断言好习惯，防止传递过来的 头节点是空指针

	LTNode* prev = pos->prev;//找到节点pos前一个节点
	LTNode* newnode = BuyListNode(x);//创建需要的新节点

	prev->next = newnode;//链接这三个节点
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}



//删除节点pos
void ListErase(LTNode* pos)
{
	assert(pos);//断言好习惯，防止传递过来的 头节点是空指针

	LTNode* prev = pos->prev;//找到节点pos前一个节点
	LTNode* next = pos->next;//找到节点pos后一个节点

	free(pos);
	pos = NULL;

	prev->next = next;
	next->prev = prev;
}



//查找数据x的节点pos
LTNode* FindNode(LTNode* phead, LTDataType x)
{
	LTNode* cur = phead->next;
	LTNode* pos = NULL;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			pos = cur;
		}
		cur = cur->next;
	}
	return pos;
}