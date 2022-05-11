#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"


//�����½ڵ�ĺ���
LTNode* BuyListNode(LTDataType x)
{
	//��̬����һ���ڵ�(�ṹ��)�Ŀռ�
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)//�ж��Ƿ񿪱ٳɹ�
	{
		perror("fail");//perror()���������ڶ�̬����ʧ�ܵ�ʱ��ֱ�ӽ��������������ش���ط�����Ϣ
	}

	//���ٳɹ��󣬳�ʼ���ṹ�����ָ�������
	node->data = x;
	node->next = NULL;//���ڵ����ָ���ʼ��ΪNULL����������޸�
	node->prev = NULL;

	return node;//���ش������½ڵ�
}


//��ʼ�� ͷ�ڵ� ��Ϊ������� ��ͷ��˫��ѭ������
//ͷ�ڵ�����ڱ�λ�����ã������˾�ʼ����Ϊ�����ͷ�ڵ㣬ָ��ͷ�ڵ� ��ָ�뱾��ĵ�ַ ���ܸı䣬�������治��������
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1);//�����������-1��ֻ��Ϊ���������������ʵ����-1��û���ã���Ϊͷ�ڵ㲻�������
	phead->next = phead;//��Ϊ��ѭ���������Գ�ʼ��ͷ�ڵ��ʱ��ͷ�ڵ����ָ�붼Ҫָ���Լ�
	phead->prev = phead;

	return phead;//�������ָ�룬�÷���ֵ�������βξͲ���Ҫ�ö���ָ�룬���ӷ���
}


//��ӡ����
void ListPrint(LTNode* phead)
{
	assert(phead);//���Ժ�ϰ�ߣ���ֹ���ݹ����� ͷ�ڵ��ǿ�ָ��

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//β��
//�����û�з���ָ�룬���ββ����õĶ���ָ�룬����Ϊ ָ��ͷ�ڵ� ��ָ��ı���ĵ�ַ ���ܱ��ı�
//��Ϊͷ�ڵ����ڱ�λ�����ã����������ָ��ͷ�ڵ��ָ��󣬱���ĵ�ַ�Ͳ��ܱ��ı���
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);//���Ժ�ϰ�ߣ���ֹ���ݹ����� ͷ�ڵ��ǿ�ָ��

	//β�壬�ȴ�����Ҫ�Ľڵ�
	LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;//���������β�ڵ㣬��ʹ���� ֻ��ͷ�ڵ� ��ʱ��Ҳ����

	tail->next = newnode;//���������½ڵ㡢ͷ�ڵ��β�ڵ�
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;


	////β�巽����
	//ListInsert(phead, x);
}


//ͷ��
//�����û�з���ָ�룬���ββ����õĶ���ָ�룬����Ϊ ָ��ͷ�ڵ� ��ָ��ı���ĵ�ַ ���ܱ��ı�
//��Ϊͷ�ڵ����ڱ�λ�����ã����������ָ��ͷ�ڵ��ָ��󣬱���ĵ�ַ�Ͳ��ܱ��ı���
void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);//���Ժ�ϰ�ߣ���ֹ���ݹ����� ͷ�ڵ��ǿ�ָ��

	//ͷ�壬�ȴ�����Ҫ�Ľڵ�
	LTNode* newnode = BuyListNode(x);
	LTNode* first = phead->next;//��������ĵ�һ���ڵ㣬��ʹ���� ֻ��ͷ�ڵ� ��ʱ��Ҳ����

	phead->next = newnode;//���������ӵ�һ���ڵ㡢ͷ�ڵ���½ڵ�
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;

	////ͷ��ķ�����
	//ListInsert(phead->next, x);
}



//βɾ
//�����û�з���ָ�룬���ββ����õĶ���ָ�룬����Ϊ ָ��ͷ�ڵ� ��ָ��ı���ĵ�ַ ���ܱ��ı�
//��Ϊͷ�ڵ����ڱ�λ�����ã����������ָ��ͷ�ڵ��ָ��󣬱���ĵ�ַ�Ͳ��ܱ��ı���
void ListPopBack(LTNode* phead)
{
	assert(phead);//���Ժ�ϰ�ߣ���ֹ���ݹ����� ͷ�ڵ��ǿ�ָ��

	LTNode* tail = phead->prev;//���������β�ڵ�
	LTNode* prev = tail->prev;//����β�ڵ��ǰһ���ڵ�

	if (tail != phead)//��ֹ����һ���ڵ㶼û�е�ʱ�򣬷�ֹ��ɾ�� ͷ�ڵ㣬���ԼӸ��ж�����
	{
		free(tail);//ɾ��β�ڵ㣬���ͷŵ����Ŀռ�
		tail = NULL;

		prev->next = phead;
		phead->prev = prev;
	}
	else //��������û��һ���ڵ��ʱ��ֱ�ӽ������Ͳ���ɾ���� ͷ�ڵ�
	{
		return;
	}


	////βɾ������
	//ListErase(phead->prev);
}



//ͷɾ
//�����û�з���ָ�룬���ββ����õĶ���ָ�룬����Ϊ ָ��ͷ�ڵ� ��ָ��ı���ĵ�ַ ���ܱ��ı�
//��Ϊͷ�ڵ����ڱ�λ�����ã����������ָ��ͷ�ڵ��ָ��󣬱���ĵ�ַ�Ͳ��ܱ��ı���
void ListPopFront(LTNode* phead)
{
	assert(phead);//���Ժ�ϰ�ߣ���ֹ���ݹ����� ͷ�ڵ��ǿ�ָ��

	LTNode* first = phead->next;//�����һ���ڵ�
	LTNode* next = first->next;//�����һ���ڵ����һ���ڵ�

	if (first != phead)//��ֹ����һ���ڵ㶼û�е�ʱ�򣬷�ֹ��ɾ�� ͷ�ڵ㣬���ԼӸ��ж�����
	{
		free(first);
		first = NULL;

		phead->next = next;
		next->prev = phead;
	}
	else//��������û��һ���ڵ��ʱ��ֱ�ӽ������Ͳ���ɾ���� ͷ�ڵ�
	{
		return;
	}


	////ͷɾ������
	//ListErase(phead->next);
}



//�ڽڵ�posǰ����һ���ڵ�
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);//���Ժ�ϰ�ߣ���ֹ���ݹ����� ͷ�ڵ��ǿ�ָ��

	LTNode* prev = pos->prev;//�ҵ��ڵ�posǰһ���ڵ�
	LTNode* newnode = BuyListNode(x);//������Ҫ���½ڵ�

	prev->next = newnode;//�����������ڵ�
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}



//ɾ���ڵ�pos
void ListErase(LTNode* pos)
{
	assert(pos);//���Ժ�ϰ�ߣ���ֹ���ݹ����� ͷ�ڵ��ǿ�ָ��

	LTNode* prev = pos->prev;//�ҵ��ڵ�posǰһ���ڵ�
	LTNode* next = pos->next;//�ҵ��ڵ�pos��һ���ڵ�

	free(pos);
	pos = NULL;

	prev->next = next;
	next->prev = prev;
}



//��������x�Ľڵ�pos
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