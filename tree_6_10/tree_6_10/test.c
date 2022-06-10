#define _CRT_SECURE_NO_WARNINGS 1


typedef char TreeDataType;//����������������

//�ýṹ���ʾ�������Ľڵ�
typedef struct TreeNode
{
	TreeDataType data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;


#include"Queue.h"

//�������
void LevelOrder(TreeNode* root)
{
	Queue q;//����һ���ṹ�����͵ı���
	QueueInit(&q);//��ʼ������

	if (root != NULL)//�ж϶������Ƿ��нڵ�
	{
		QueuePush(&q, root);//���������ĵ�һ���ڵ�ĵ�ַ �����
	}

	while (!QueueEmpty(&q))//��while(front)
	{
		TreeNode* front = QueueFront(&q);//��������׵� ����
		printf("%c ", front->data);//��ӡ���д�ŵ�����
		QueuePop(&q);//�����󽫶����׵����� ������

		if(front->left != NULL)//��������Ϊ�գ������
		QueuePush(&q, front->left);

		if (front->right != NULL)//��������Ϊ�գ������
		QueuePush(&q, front->right);
	}

	printf("\n");

	QueueDestroy(&q);
}

//�ж϶������Ƿ�Ϊ��ȫ������
bool TreeComplete(TreeNode* root)
{
	Queue q;//����һ���ṹ�����͵ı���
	QueueInit(&q);//��ʼ������

	if (root)//�ж� �������Ƿ�Ϊ����
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		TreeNode* front = QueueFront(&q);//��������׵� ����
		QueuePop(&q);//�����󽫶����׵����� ������
		if (front != NULL)//�����׵����ݲ��ǿ�ָ��
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else
		{
			break;//�����׵������ǿ�ָ��ֱ������ѭ��
		}
	}

	//�����ʱ�����������ȫ�ǿ�ָ��NULL��������ȫ������
	//�����ʱ����������ݴ��ڲ�Ϊ��ָ������ݣ�����
	while (!QueueEmpty(&q))//������һ��ѭ��������ڶ���ѭ���ж�
	{
		TreeNode* front = QueueFront(&q);//��������׵� ����
		
		if (front==NULL)
		{
			QueuePop(&q);//�����󽫶����׵����� ������
		}
		else//��ʱ������ �����ݲ��ǿ�ָ��NULL��ֻҪ����������Ͳ��� ��ȫ������
		{
			QueueDestroy(&q);
			return false;
		}
	}

	QueueDestroy(&q);
	return true;
}

int main()
{
	//��Ϊ����һ��������
	TreeNode* A = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* B = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* C = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* D = (TreeNode*)malloc(sizeof(TreeNode));

	A->data = 'A';
	A->left = B;
	A->right = C;

	B->data = 'B';
	B->left = NULL;
	B->right = D;

	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	D->data = 'D';
	D->left = NULL;
	D->right = NULL;
	
	//�������
	LevelOrder(A);
	
	//�ж϶������Ƿ�Ϊ��ȫ������
	bool ret = TreeComplete(A);
	printf("%d", ret);
	return 0;
}