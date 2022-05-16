#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void TestQueue()
{
	Queue q;//定义一个结构体类型Queue的变量
	
	QueueInit(&q);//初始化队列，这里是一级指针是因为我们的队列是定义的结构体变量，
	              //而不是指针，所以要改变这个变量的值，只需要传递这个变量的地址就行
	
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
}

int main()
{
	TestQueue();
	return 0;
}