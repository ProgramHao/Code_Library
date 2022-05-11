#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;//重命名数据类型

//链表的节点依旧用结构体表示
typedef struct ListNode
{
	struct ListNode* next;//结构体的两个指针，分别指向上一个节点和下一个节点
	struct ListNode* prev;
	LTDataType data;
}LTNode;



//创建新节点的函数
LTNode* BuyListNode(LTDataType x);


//初始化 头节点 因为这里的是 带头的双向循环链表
//头节点就是哨兵位的作用，定义了就始终作为链表的头节点，指向头节点 的指针本身的地址 不能改变，并且里面不会存放数据
LTNode* ListInit();


//尾插
//这里既没有返回指针，又形参不是用的二级指针，是因为 指向头节点 的指针的本身的地址 不能被改变
//因为头节点是哨兵位的作用，定义了这个指向头节点的指针后，本身的地址就不能被改变了
void ListPushBack(LTNode* phead, LTDataType x);


//头插
//这里既没有返回指针，又形参不是用的二级指针，是因为 指向头节点 的指针的本身的地址 不能被改变
//因为头节点是哨兵位的作用，定义了这个指向头节点的指针后，本身的地址就不能被改变了
void ListPushFront(LTNode* phead, LTDataType x);


//尾删
//这里既没有返回指针，又形参不是用的二级指针，是因为 指向头节点 的指针的本身的地址 不能被改变
//因为头节点是哨兵位的作用，定义了这个指向头节点的指针后，本身的地址就不能被改变了
void ListPopBack(LTNode* phead);


//头删
//这里既没有返回指针，又形参不是用的二级指针，是因为 指向头节点 的指针的本身的地址 不能被改变
//因为头节点是哨兵位的作用，定义了这个指向头节点的指针后，本身的地址就不能被改变了
void ListPopFront(LTNode* phead);


//在节点pos前插入一个节点
void ListInsert(LTNode* pos, LTDataType x);


//删除节点pos
void ListErase(LTNode* pos);


//查找数据x的节点pos
LTNode* FindNode(LTNode* phead, LTDataType x);