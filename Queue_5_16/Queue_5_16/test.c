#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void TestQueue()
{
	Queue q;//����һ���ṹ������Queue�ı���
	
	QueueInit(&q);//��ʼ�����У�������һ��ָ������Ϊ���ǵĶ����Ƕ���Ľṹ�������
	              //������ָ�룬����Ҫ�ı����������ֵ��ֻ��Ҫ������������ĵ�ַ����
	
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