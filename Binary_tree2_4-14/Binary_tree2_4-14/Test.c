#include <stdlib.h>
#include <stdio.h>

#include "Queue.h"

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;

	BTDataType data;
}BTNode;


//�����½ڵ�
BTNode* BinaryTreeNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));//��̬�����ڴ�ռ䣬��С��һ���ṹ������BTnode
	if (newnode == NULL)
	{
		perror("the mistake");
	}
	newnode->data = x;//�����ŵ����ݷ���ڵ���
	newnode->left = NULL;//�������½ڵ����ָ��left��rightҪ����ΪNULL�����������޸�
	newnode->right = NULL;//Ҳ����Ϊ������ڵ���Ϊ����ʱ��������������������ΪNULL

	return newnode; //�÷���ֵ���ش������½ڵ㣬�����βξͲ��ô�������ָ����
}


//ǰ�����( �� ������ ������ )
void PrevOrder(BTNode* root)//ָ�����ָ�����
{
	if (root == NULL) //���������1���������޽ڵ㣬ֱ�Ӵ�ӡNULL������������
					  //2�����ݹ����Ϊ ���ڵ� �� ������ ���� ���ڵ� �� ������ Ϊ��ָ��NULL��ʱ��
					  //����ݹ������������һ���ݹ�
	{
		printf("NULL ");
		return;//��������
	}
	printf("%c ", root->data);//��ӡ�ýڵ�Ĵ�ŵ�����
	PrevOrder(root->left);//����ڵ����������Ϊ���ٽ���
	PrevOrder(root->right);//����ڵ����������Ϊ���ٽ���
}


//�������( ������ �� ������ )
void InOrder(BTNode* root)//��һ�����ڵ�
{
	if (root == NULL)//���������1���������޽ڵ㣬ֱ�Ӵ�ӡNULL������������
					  //2�����ݹ����Ϊ ���ڵ� �� ������ ���� ���ڵ� �� ������ Ϊ��ָ��NULL��ʱ��
					  //����ݹ������������һ���ݹ�

	{
		printf("NULL ");
		return;//��������
	}

	InOrder(root->left);//����ڵ����������Ϊ���ٽ���
	printf("%c ", root->data);//��ӡ�ýڵ�Ĵ�ŵ�����
	InOrder(root->right);//����ڵ����������Ϊ���ٽ���
}



//�������( ������ ������ �� )
void PostOrder(BTNode* root)//��һ�����ڵ�
{
	if (root == NULL)//���������1���������޽ڵ㣬ֱ�Ӵ�ӡNULL������������
					  //2�����ݹ����Ϊ ���ڵ� �� ������ ���� ���ڵ� �� ������ Ϊ��ָ��NULL��ʱ��
					  //����ݹ������������һ���ݹ�

	{
		printf("NULL ");
		return;//��������
	}

	PostOrder(root->left);//����ڵ����������Ϊ���ٽ���
	PostOrder(root->right);//����ڵ����������Ϊ���ٽ���
	printf("%c ", root->data);//��ӡ�ýڵ�Ĵ�ŵ�����
}


//������������ݸ�����������ÿ���ڵ�ֻ���һ�����ݣ�
//����Ҳ����˵��������Ľڵ�������õı��������˼ά��
int TreeSize(BTNode* root)
{
	//��Ŀ��������exp1��exp2��exp3
	//��� ���ʽexp1 Ϊ�棬�� �������ʽ �Ľ��Ϊ ���ʽexp2�����Ϊ�٣��� �������ʽ �Ľ��Ϊ ���ʽexp3
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}


//�������Ҷ�ӽڵ�(��Ϊ0�Ľڵ�)�ĸ���
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)//��������û�нڵ�
		return 0;

	if (root->left == NULL && root->right == NULL)//��������ֻ��һ���ڵ㣬��ô����ڵ����Ҷ�ӽڵ�
		return 1;

	//����ݹ飬����������Ҷ�ӽڵ�+����������Ҷ�ӽڵ�
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

// ��������k��ڵ�ĸ���
//ת���������⣺�� �������ĵ�k-1�� + �������ĵ�k-1��
int TreekSize(BTNode* root, int k)
{
	assert(k >= 1);//���Ժ�ϰ��,��Ϊ�������Ĳ�����1��ʼ

	if (root == NULL)//��������֮һ
		return 0;

	if (k == 1)//��������֮��
		return 1;

	//���ε� �� �������ĵ�k-1�� + �������ĵ�k-1��
	return TreekSize(root->left, k - 1) + TreekSize(root->right, k - 1);
}

//�����������Ȼ�߶�
int TreeDepth(BTNode* root)
{
	////����һ��vs�ܹ���leetcode����
	//if (root == NULL)
	//	return 0;

	//if (root->left == NULL && root->right == NULL)
	//	return 1;

	//return TreeDepth(root->left) > TreeDepth(root->right) ?
	//	TreeDepth(root->left) + 1 : TreeDepth(root->right) + 1;


	//�����������ܹ�
	if (root == NULL)
		return 0;

	int leftDepth = TreeDepth(root->left);//�Ƚ����ڵ�����������������ʱ�����������,����ݹ鷵��
	int rightDepth = TreeDepth(root->right);//�Ƚ����ڵ�����������������ʱ�����������

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;//˭��ͷ���˭,��1�ǽڵ㱾��������1
}

//��������x���ڵĽڵ㣬����������ڵ�
//�����ǰ�������˼�룬���
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1 != NULL)
		return ret1;//���ҵ�������ڵ㣬Ҫ��������ڵ㣬���ص���һ���ݹ�

	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2 != NULL)
		return ret2;//���ҵ�������ڵ㣬Ҫ��������ڵ㣬���ص���һ���ݹ�

	return NULL;
}

//���ٶ�����ÿ���ڵ�����Ķ�̬�ռ�,�ú��������˼��
void DestroyTree(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	DestroyTree(root->left);//����ǰ�ڵ����������Ϊ���ڵ�ݹ�
	DestroyTree(root->right);//����ǰ�ڵ����������Ϊ���ڵ�ݹ�

	free(root);//�ͷŵ�ڵ�Ŀռ�
	//root = NULL;//���ｫroot��Ϊ��ָ��û�����壬��Ϊ��������Ĳ����� ֵ���� ��
	//�ǽ�ָ��root��ŵĵ�ַ������һ�ݸ������ڲ�������ָ��root���������뽫�������ָ��root��Ϊ��ָ�룬
	//������Ϊ��ֵ���ݣ�����ֻ�ǽ������ڲ���������ʱָ��root��Ϊ�գ�ֵ�����βεĸı䲻Ӱ��ʵ�Σ�
	//���Ժ����ⲿ��ָ��root���ɴ�ŵ��Ƕ�̬���ٵ� ��С�ǽṹ������ �Ŀռ�ĵ�ַ����û�б�Ϊ��ָ��NULL��
	//���������Ҫ�ı䣬��ô���ö���ָ�룬���߲��ùܣ���Ϊ���������������������пռ䶼������(����)
}


//��������������Ľڵ������(��Ҫ�õ�����)
void LevelOrder(BTNode* root)//��ָ����������ڵ��ָ��
{
	// ����˼·����һ�����ʱ�����һ��ڵ����
	//�������Ԫ����ָ��������ڵ��ָ��

	Queue q;//����һ���ṹ������Queue�ı���������ṹ����ŵ���
			//һ��ָ���һ���ڵ��ָ��head��һ��ָ��β�ڵ��ָ��tail

	QueueInit(&q);//��ʼ������ṹ�壬��ַ���ݣ����Ըı�ʵ��

	if (root)//�ж϶������Ƿ��нڵ�
		QueuePush(&q, root);//�� ָ����������ڵ��ָ�� ��ΪԪ�� ��β�������
					 //��ʱ������ ֻ�� ָ����������ڵ��ָ����һ��Ԫ��

	while (!QueueEmpty(&q))//������ǿգ��ͼ��������пգ�������ѭ��
	{
		BTNode* front = QueueFront(&q);//����ͷ��Ԫ������ʱ�������
		QueuePop(&q);//��ͷ�� ���ж�ͷ��Ԫ��
		printf("%c ", front->data);//��ӡ ��ͷ��Ԫ�� ���ŵ�Ԫ��
								   //����ӡ�Ķ������ڵ����ŵ�����

		if (front->left)//�ýڵ����������Ϊ��ָ�룬����������β�������
		{
			QueuePush(&q, front->left);
		}

		if (front->right)//�ýڵ����������Ϊ��ָ�룬����������β�������
		{
			QueuePush(&q, front->right);
		}
	}

	printf("\n");

	QueueDestory(&q);//���ٶ��еĿռ�
}


int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	//BTNode* F = (BTNode*)malloc(sizeof(BTNode));
	//F->data = 'F';
	//F->left = NULL;
	//F->right = NULL;

	//BTNode* G = (BTNode*)malloc(sizeof(BTNode));
	//G->data = 'G';
	//G->left = NULL;
	//G->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;
	//C->right = F;
	//F->right = G;

	PrevOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	/*TreeSize(A);
	printf("TreeSize:%d\n", size);

	size = 0;
	TreeSize(B);
	printf("TreeSize:%d\n", size);*/

	/*int Asize = 0;
	TreeSize(A, &Asize);
	printf("TreeSize:%d\n", Asize);

	int Bsize = 0;
	TreeSize(B, &Bsize);
	printf("TreeSize:%d\n", Bsize);*/


	//printf("TreeSize:%d\n", TreeSize(A));

	//printf("TreeSize:%d\n", TreeSize(B));

	//LevelOrder(A);

	printf("%d\n", TreeDepth(A));

	return 0;
}




/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
// ջʵ�ֶ���OJ�����
typedef int STDataType;
struct Stack
{
	STDataType* a;
	int top;       // ջ��
	int capacity;  // ��������������
};

//typedef struct Stack ST;
typedef struct Stack Stack;

void StackInit(Stack* pst);
void StackDestroy(Stack* pst);

// ���ʾ;�����ջ����������
void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);
STDataType StackTop(Stack* pst);

// �շ���1 �ǿշ���0
//int StackEmpty(Stack* pst);
bool StackEmpty(Stack* pst);
int StackSize(Stack* pst);

void StackInit(Stack* pst)
{
	assert(pst);

	//pst->a = NULL;
	//pst->top = 0;
	//pst->capacity = 0;

	pst->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	pst->top = 0;
	pst->capacity = 4;
}

void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

// ���ʾ;�����ջ����������
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType)*pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1); // ������������
		}

		pst->a = tmp;
		pst->capacity *= 2;
	}

	pst->a[pst->top] = x;
	pst->top++;
}

void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	pst->top--;
}

STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	return pst->a[pst->top - 1];
}

// �շ���1 �ǿշ���0
//int StackEmpty(Stack* pst);
bool StackEmpty(Stack* pst)
{
	assert(pst);

	return pst->top == 0;
}

int StackSize(Stack* pst)
{
	assert(pst);

	return pst->top;
}

typedef struct {
	Stack pushST;
	Stack popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->pushST);
	StackInit(&q->popST);

	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	/*if(StackEmpty(&obj->popST))
	{
	while(!StackEmpty(&obj->pushST))
	{
	StackPush(&obj->popST, StackTop(&obj->pushST));
	StackPop(&obj->pushST);
	}
	}
	*/

	int top = myQueuePeek(obj);
	StackPop(&obj->popST);
	return top;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}

	return StackTop(&obj->popST);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);
	free(obj);
}

/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/