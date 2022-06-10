#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

//创建一个队列的新节点，即单链表的新节点
QNode* BuyQueueNode(QDataType x)
{
	QNode* tmp = (QNode*)malloc(sizeof(QNode));//动态开辟一个结构体类型QNode的空间
	if (tmp == NULL)//动态开辟空间失败
	{
		printf("malloc fail");
		exit(-1);//直接结束函数
	}

	//开辟成功
	QNode* newnode = tmp;
	newnode->data = x;//赋值初始化新节点
	newnode->next = NULL;

	return newnode;//返回这个新节点
}

//初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);//断言好习惯

	pq->head = pq->tail = NULL;//初始化结构体里的变量
}

//销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);//断言好习惯
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(pq->head);
		pq->head = NULL;
		cur = next;
	}

	pq->head = pq->tail = NULL;
}

//队尾入
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);//断言好习惯

	QNode* newnode = BuyQueueNode(x);//创建一个队列的新节点，即创建单链表的新节点

	if (pq->tail == NULL)//一开始队列里没有数据，即没有节点的时候
	{
		pq->head = pq->tail = newnode;//把这个新节点当作第一个节点和尾节点
	}
	else//即队列有数据，即有节点的时候
	{
		pq->tail->next = newnode;//将新节点队尾入到尾节点的后面，即尾插
		pq->tail = newnode;//再将新节点作为新的尾节点，方便下一次队尾入，即尾插
	}
}

//对头出
void QueuePop(Queue* pq)
{
	assert(pq);//断言好习惯

	////暴力检查
	//assert(!QueueEmpty);
	//温柔检查
	//即队列无节点，即单链表无节点的时候
	if (pq->head == NULL)
	{
		return;//没有对头出的节点了，直接结束函数
	}


	//这里还要判断只有一个节点的时候，因为我们定义的指针pq里有head和tail两个指针
	//所以只有一个节点的时候，指针head和tail都是指向第一个节点，所过free掉指针head指针的空间的时候，
	//指针tail就变成野指针了，所以针对这种情况，要单独说明一下
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = NULL;
		pq->tail = NULL;//指针tail也要赋值为空，避免它出现野指针的情况
	}
	else//有两个节点及以上的情况
	{
		//有节点的时候，对头出
		QNode* next = pq->head->next;//先保存第一个节点的下一个节点
		free(pq->head);//释放第一个节点的空间
		pq->head = NULL;
		pq->head = next;//赋值新的第一个节点
	}
}

//返回对头的数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);//断言好习惯

	////暴力检查
	//assert(!QueueEmpty);
	//温柔检查
	//即队列无节点，即单链表无节点的时候
	if (pq->head == NULL)
	{
		return;//没有节点了，直接结束函数
	}

	return pq->head->data;//返回对头节点里的数据
}

//返回队尾的数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);//断言好习惯

	////暴力检查
	//assert(!QueueEmpty);
	//温柔检查
	//即队列无节点，即单链表无节点的时候
	if (pq->head == NULL)
	{
		return;//没有节点了，直接结束函数
	}

	return pq->tail->data;//返回队尾节点里的数据
}

//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);//断言好习惯

	if (pq->head == NULL)//或者pq->tail=NULL
	{
		return true;
	}
	else
	{
		return false;
	}
}

//返回队列的数据个数
//两种方式，第一种就是遍历一遍
//第两种就是表示队列的结构体Queue里加一个变量size,每次队尾入就size++,每次对头出就size--
int QueueSize(Queue* pq)
{
	assert(pq);//断言好习惯
	QNode* cur = pq->head;
	int size = 0;
	while (cur == NULL)//遍历一遍
	{
		size++;
		cur = cur->next;
	}
	return size;
}