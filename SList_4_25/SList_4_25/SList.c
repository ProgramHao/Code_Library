#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"


//创建一个新节点
SLTNode* BuySListNode(SLDateType x)//x是想要创建的数据
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));//创建一个新节点
	if (newnode == NULL)//判断新节点是否开辟成功，温柔检查
	{
		printf("malloc fail");
		return;
	}
	newnode->data = x;//开辟成功，将想插入的数据放进新节点里
	newnode->next = NULL;//初始化节点里的指针next

	return newnode;//返回创建的新节点
}


//打印链表
void SListPrint(SLTNode* phead)//给的是这个单链表的第一个节点,打印不会改变第一个节点，即不会改变实参，所以值传递即可
{
	SLTNode* cur = phead;
	while (cur != NULL)//打印最后一个节点里的数据，就跳出循环
	{
		printf("%d", cur->data);//打印对应节点里的数据
		printf(" -> ");//再打印一个箭头，可以更好的理解
		cur = cur->next;//指向下一个节点
	}
	printf("NULL\n");//再最后打印一个NULL，也是方便理解
}


//尾插
//给的是这个单链表的第一个节点本身的地址，即一级指针本身的地址,所以会二级指针接收，也就是地址传递，因为可能会改变 实参即一级指针；x是需要插入的数据
void SListPushBack(SLTNode** pphead, SLDateType x)
{
	SLTNode* newnode = BuySListNode(x);//创建一个新节点

	if (*pphead == NULL)//即这个单链表一个节点都没有，那么*pphead肯定是NULL
	{
		*pphead = newnode;//那么这个新节点就变为 单链表的第一个节点，形参为 二级指针pphead 的原因就是这个，因为这里要改变链表的第一节点
		                 //因为如果这里只用一级指针phead，而又因为传递过来的实参也是一级指针，所以是值传递
		                 //所以形参的改变是 不影响 实参的，而这里是要改变 实参的，因为要改变这个链表的 第一个节点
		                 //所以这里必须是 地址传递，才可以改变实参，所以用二级指针 用来接收 一级指针即第一个节点 本身的地址
		return;//这种情况改变链表的第一个节点后，直接return结束函数
	}

	//下面是链表至少有一个节点的情况
	SLTNode* tail = *pphead;//这里和下面需要找到尾节点
	while (tail->next != NULL)//找尾节点,找到后跳出循环
	{
		tail = tail->next;//循环指向下一个节点
	}
	
	tail->next = newnode;//尾节点里的指针指向新节点，就链接上了
}


//头插
//给的是这个单链表的第一个节点本身的地址，即一级指针本身的地址,所以会二级指针接收，也就是地址传递，因为可能会改变 实参即一级指针；x是需要插入的数据
void SListPushFront(SLTNode** pphead, SLDateType x)
{
	SLTNode* newnode = BuySListNode(x);//创建一个新节点

	newnode->next = *pphead;//将新节点 头插 进去，就是新节点里的指针 指向链表的 第一个节点

	*pphead = newnode;//这里就是地址传递，形参用二级指针的原因，因为头插一个节点，链表的第一个节点发生了改变，所以要地址传递
	                  //即二级指针 接收 一级指针(第一个节点)本身的地址，是本身的地址
}


//尾删
//给的是这个单链表的第一个节点本身的地址，即一级指针本身的地址,所以会二级指针接收，也就是地址传递，因为可能会改变 实参即一级指针；x是需要插入的数据
void SListPopBack(SLTNode** pphead)//因为如果只有一个节点的时候，尾删后，就无节点了，第一个节点就改变了，所以依旧形参是二级指针
{
	assert(*pphead);//暴力检查，链表里一个节点都没有，就不需要尾删，推荐暴力检查，有问题直接可以得出原因
    //if (*pphead == NULL)//温柔检查，链表里一个节点都没有，就不需要尾删
    //{
    //	return;
    //}

	if ((*pphead)->next == NULL)
	{
		free(*pphead); //只有一个节点的时候，尾删后，就无节点了，第一个节点就改变了，这就是形参是二级指针的原因
		*pphead = NULL;//只有一个节点，尾删后(free后)，要将*pphead置空
		return;//直接return，结束函数
	}

	//链表里至少两个节点，执行下面操作
	SLTNode* prev = NULL;//找到尾节点的 前一个节点，因为尾删后(即free后)，前一个节点就变成了尾节点，所以这个节点里的指针next需要置空，不置空next就会变成野指针
	SLTNode* tail = *pphead;//先定义尾节点
	while (tail->next != NULL)
	{
		prev = tail;//存放当前节点
		tail = tail->next;//指向下一个节点
	}
	free(tail);
	prev->next = NULL;//将此时的 尾节点 里的指针next置空
}


//头删
//给的是这个单链表的第一个节点本身的地址，即一级指针本身的地址,所以会二级指针接收，也就是地址传递，因为可能会改变 实参即一级指针；x是需要插入的数据
void SListPopFront(SLTNode** pphead)
{
	assert(*pphead);//暴力检查，链表里一个节点都没有，就不需要头删，推荐暴力检查，有问题直接可以得出原因
	//if (*pphead == NULL)//温柔检查，链表里一个节点都没有，就不需要头删
	//{
	//	return;
	//}

	SLTNode* next = (*pphead)->next;//这里要先创建一个指针变量 存放 第一个节点里的指针，即第一个节点的下一个节点
	                                //我们我们删除，需要free点第一个节点，但是如果直接free，那么第一个节点这个结构体的空间就被释放了，存放在里的指针next就找不到了，就找不到 下一个节点了
	free(*pphead);//释放点第一个节点，即头删

	*pphead = next;//头删后，链表的 第一个节点发生改变，所以这也是形参 用二级指针的 原因，我们要改变第一个节点
}


//给一个数据，查找这个数据所在的节点，并返回这个节点
SLTNode* SListFind(SLTNode* phead, SLDateType x)//这里只是查找，并不会改变第一个节点，和打印一样，所以直接值传递就行，即形参用一级指针即可
{
	SLTNode* cur = phead;//创建一个指针变量
	while (cur != NULL)//遍历一遍进行查找
	{
		if (cur->data == x)
		{
			return cur;//找到数据所在的节点，并 返回这个节点
		}

		cur = cur->next;//指向下一个节点
	}
	return NULL;//遍历一遍没找到就返回空指针NULL 或者 链表一个节点都没有要放回空指针
}


//在节点pos前插入一个数据
//这里也是用的二级指针，也是用来接收一级指针(第一个节点)本身的地址，因为第一个节点也可能会改变的情况
//这个情况就是在第一个节点前插入数据，这样链表的第一个节点就发生了改变，所以依旧是要地址传递才行
//这个函数会和 查找函数SListFind( )配合使用
void SListInsert(SLTNode** pphead, SLTNode* pos, SLDateType x)//这里假设参数pos是找到了这个节点
{
	SLTNode* newnode = BuySListNode(x);//创建一个新节点

	if (*pphead == pos)//即找到的节点pos就是第一个节点
	{
		newnode->next = pos;//将新节点的里的next 指向 节点pos
		*pphead = newnode;//新节点变为第一个节点，这里就是第一个节点的改变，这是这种情况，所以才需要形参用二级指针
		return;//然后直接return，结束函数
	}

	//找的节点pos不是第一个节点
	SLTNode* prev = NULL;//要找到节点pos的前一个节点prev
	SLTNode* cur = *pphead;
	while (cur != pos)//遍历一遍，找到节点pos
	{
		prev = cur;//prev存放当前节点
		cur = cur->next;//指向下一个节点
	}
	prev->next = newnode;//将节点里的指针分别指向对应的节点
	newnode->next = pos;
}


//删除找到的节点pos
//这里也是用的二级指针，也是用来接收一级指针(第一个节点)本身的地址，因为第一个节点也可能会改变的情况
//这个情况就是在删除的节点是第一个节点，这样链表的第一个节点就发生了改变，所以依旧是要地址传递才行
//这个函数会和 查找函数SListFind( )配合使用
void SListErase(SLTNode** pphead, SLTNode* pos)//这里假设参数pos是找到了这个节点
{
	if (*pphead == pos)//即找到的节点pos就是第一个节点
	{
		SLTNode* next = (*pphead)->next;//这里要先创建一个指针变量 存放 第一个节点里的指针，即第一个节点的下一个节点
	                                //我们我们删除，需要free点第一个节点，但是如果直接free，那么第一个节点这个结构体的空间就被释放了，存放在里的指针next就找不到了，就找不到 下一个节点了
		free(*pphead);//或free(pos) 释放掉第一个节点的空间，即删除
		*pphead = next;////删除后，链表的 第一个节点发生改变，所以这也是形参 用二级指针的 原因，我们要改变第一个节点
		return;//然后直接return，结束函数
	}

	//删除的节点pos 不是 第一个节点
	SLTNode* prev = NULL;//要找到节点pos的前一个节点prev
	SLTNode* next = NULL;//要找到节点pos的后一个节点next
	SLTNode* cur = *pphead;
	while (cur != pos)
	{
		prev = cur;//当前节点
		cur = cur->next;//指向下一个节点
		next = cur->next;//当前节点 下一个节点 的 下一个节点
	}
	prev->next = next;//将节点pos的 前一个节点prev 和 后一个节点next 链接起来
}