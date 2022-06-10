#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

//����һ�����е��½ڵ㣬����������½ڵ�
QNode* BuyQueueNode(QDataType x)
{
	QNode* tmp = (QNode*)malloc(sizeof(QNode));//��̬����һ���ṹ������QNode�Ŀռ�
	if (tmp == NULL)//��̬���ٿռ�ʧ��
	{
		printf("malloc fail");
		exit(-1);//ֱ�ӽ�������
	}

	//���ٳɹ�
	QNode* newnode = tmp;
	newnode->data = x;//��ֵ��ʼ���½ڵ�
	newnode->next = NULL;

	return newnode;//��������½ڵ�
}

//��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);//���Ժ�ϰ��

	pq->head = pq->tail = NULL;//��ʼ���ṹ����ı���
}

//���ٶ���
void QueueDestroy(Queue* pq)
{
	assert(pq);//���Ժ�ϰ��
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

//��β��
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);//���Ժ�ϰ��

	QNode* newnode = BuyQueueNode(x);//����һ�����е��½ڵ㣬��������������½ڵ�

	if (pq->tail == NULL)//һ��ʼ������û�����ݣ���û�нڵ��ʱ��
	{
		pq->head = pq->tail = newnode;//������½ڵ㵱����һ���ڵ��β�ڵ�
	}
	else//�����������ݣ����нڵ��ʱ��
	{
		pq->tail->next = newnode;//���½ڵ��β�뵽β�ڵ�ĺ��棬��β��
		pq->tail = newnode;//�ٽ��½ڵ���Ϊ�µ�β�ڵ㣬������һ�ζ�β�룬��β��
	}
}

//��ͷ��
void QueuePop(Queue* pq)
{
	assert(pq);//���Ժ�ϰ��

	////�������
	//assert(!QueueEmpty);
	//������
	//�������޽ڵ㣬���������޽ڵ��ʱ��
	if (pq->head == NULL)
	{
		return;//û�ж�ͷ���Ľڵ��ˣ�ֱ�ӽ�������
	}


	//���ﻹҪ�ж�ֻ��һ���ڵ��ʱ����Ϊ���Ƕ����ָ��pq����head��tail����ָ��
	//����ֻ��һ���ڵ��ʱ��ָ��head��tail����ָ���һ���ڵ㣬����free��ָ��headָ��Ŀռ��ʱ��
	//ָ��tail�ͱ��Ұָ���ˣ�����������������Ҫ����˵��һ��
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = NULL;
		pq->tail = NULL;//ָ��tailҲҪ��ֵΪ�գ�����������Ұָ������
	}
	else//�������ڵ㼰���ϵ����
	{
		//�нڵ��ʱ�򣬶�ͷ��
		QNode* next = pq->head->next;//�ȱ����һ���ڵ����һ���ڵ�
		free(pq->head);//�ͷŵ�һ���ڵ�Ŀռ�
		pq->head = NULL;
		pq->head = next;//��ֵ�µĵ�һ���ڵ�
	}
}

//���ض�ͷ������
QDataType QueueFront(Queue* pq)
{
	assert(pq);//���Ժ�ϰ��

	////�������
	//assert(!QueueEmpty);
	//������
	//�������޽ڵ㣬���������޽ڵ��ʱ��
	if (pq->head == NULL)
	{
		return;//û�нڵ��ˣ�ֱ�ӽ�������
	}

	return pq->head->data;//���ض�ͷ�ڵ��������
}

//���ض�β������
QDataType QueueBack(Queue* pq)
{
	assert(pq);//���Ժ�ϰ��

	////�������
	//assert(!QueueEmpty);
	//������
	//�������޽ڵ㣬���������޽ڵ��ʱ��
	if (pq->head == NULL)
	{
		return;//û�нڵ��ˣ�ֱ�ӽ�������
	}

	return pq->tail->data;//���ض�β�ڵ��������
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);//���Ժ�ϰ��

	if (pq->head == NULL)//����pq->tail=NULL
	{
		return true;
	}
	else
	{
		return false;
	}
}

//���ض��е����ݸ���
//���ַ�ʽ����һ�־��Ǳ���һ��
//�����־��Ǳ�ʾ���еĽṹ��Queue���һ������size,ÿ�ζ�β���size++,ÿ�ζ�ͷ����size--
int QueueSize(Queue* pq)
{
	assert(pq);//���Ժ�ϰ��
	QNode* cur = pq->head;
	int size = 0;
	while (cur == NULL)//����һ��
	{
		size++;
		cur = cur->next;
	}
	return size;
}