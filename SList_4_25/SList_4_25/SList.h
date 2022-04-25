#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDateType;//类型名重定义

typedef struct SListNode //单链表的节点(结点),用结构体表示
{
	SLDateType data; //每个节点存放的数据
	struct SListNode* next;//指向下一个节点的指针
}SLTNode;


//创建一个新节点
SLTNode* BuySListNode(SLDateType x);//x是想要创建的数据


//打印单链表
void SListPrint(SLTNode* phead);//给的是这个单链表的 第一个节点,打印不会改变第一个节点，即不会改变实参，所以值传递即可


//尾插
//给的是这个单链表的第一个节点本身的地址，即一级指针本身的地址,所以会二级指针接收，也就是地址传递，因为可能会改变 实参即一级指针；x是需要插入的数据
void SListPushBack(SLTNode** pphead, SLDateType x);


//头插
//给的是这个单链表的第一个节点本身的地址，即一级指针本身的地址,所以会二级指针接收，也就是地址传递，因为可能会改变 实参即一级指针；x是需要插入的数据
void SListPushFront(SLTNode** pphead, SLDateType x);


//尾删
//给的是这个单链表的第一个节点本身的地址，即一级指针本身的地址,所以会二级指针接收，也就是地址传递，因为可能会改变 实参即一级指针；x是需要插入的数据
void SListPopBack(SLTNode** pphead);


//头删
//给的是这个单链表的第一个节点本身的地址，即一级指针本身的地址,所以会二级指针接收，也就是地址传递，因为可能会改变 实参即一级指针；x是需要插入的数据
void SListPopFront(SLTNode** pphead);


//给一个数据，查找这个数据所在的节点，并返回这个节点
SLTNode* SListFind(SLTNode* phead, SLDateType x);//这里只是查找，并不会改变第一个节点，和打印一样，所以直接值传递就行，即形参用一级指针即可


//在节点pos前插入一个数据
//这里也是用的二级指针，也是用来接收一级指针(第一个节点)本身的地址，因为第一个节点也可能会改变的情况
//这个情况就是在第一个节点前插入数据，这样链表的第一个节点就发生了改变，所以依旧是要地址传递才行
//这个函数会和 查找函数SListFind( )配合使用
void SListInsert(SLTNode** pphead, SLTNode* pos, SLDateType x);//这里假设参数pos是找到了这个节点
                                                               


//删除找到的节点pos
//这里也是用的二级指针，也是用来接收一级指针(第一个节点)本身的地址，因为第一个节点也可能会改变的情况
//这个情况就是在删除的节点是第一个节点，这样链表的第一个节点就发生了改变，所以依旧是要地址传递才行
//这个函数会和 查找函数SListFind( )配合使用
void SListErase(SLTNode** pphead, SLTNode* pos);//这里假设参数pos是找到了这个节点