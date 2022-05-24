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


//创建新节点
BTNode* BinaryTreeNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));//动态开辟内存空间，大小是一个结构体类型BTnode
	if (newnode == NULL)
	{
		perror("the mistake");
	}
	newnode->data = x;//将想存放的数据放入节点里
	newnode->left = NULL;//创建的新节点里的指针left和right要先置为NULL，方便后面的修改
	newnode->right = NULL;//也是因为当这个节点作为根的时候，其左子树和右子树都为NULL

	return newnode; //用返回值返回创建的新节点，这样形参就不用创建二级指针了
}


//前序遍历( 根 左子树 右子树 )
void PrevOrder(BTNode* root)//指向根的指针进入
{
	if (root == NULL) //两种情况：1、二叉树无节点，直接打印NULL，并结束函数
					  //2、当递归的作为 根节点 的 左子树 或者 根节点 的 右子树 为空指针NULL的时候，
					  //这个递归结束，返回上一个递归
	{
		printf("NULL ");
		return;//结束函数
	}
	printf("%c ", root->data);//打印该节点的存放的数据
	PrevOrder(root->left);//这个节点的左子树作为根再进入
	PrevOrder(root->right);//这个节点的右子树作为根再进入
}


//中序遍历( 左子树 根 右子树 )
void InOrder(BTNode* root)//第一个根节点
{
	if (root == NULL)//两种情况：1、二叉树无节点，直接打印NULL，并结束函数
					  //2、当递归的作为 根节点 的 左子树 或者 根节点 的 右子树 为空指针NULL的时候，
					  //这个递归结束，返回上一个递归

	{
		printf("NULL ");
		return;//结束函数
	}

	InOrder(root->left);//这个节点的左子树作为根再进入
	printf("%c ", root->data);//打印该节点的存放的数据
	InOrder(root->right);//这个节点的右子树作为根再进入
}



//后序遍历( 左子树 右子树 根 )
void PostOrder(BTNode* root)//第一个根节点
{
	if (root == NULL)//两种情况：1、二叉树无节点，直接打印NULL，并结束函数
					  //2、当递归的作为 根节点 的 左子树 或者 根节点 的 右子树 为空指针NULL的时候，
					  //这个递归结束，返回上一个递归

	{
		printf("NULL ");
		return;//结束函数
	}

	PostOrder(root->left);//这个节点的左子树作为根再进入
	PostOrder(root->right);//这个节点的右子树作为根再进入
	printf("%c ", root->data);//打印该节点的存放的数据
}


//求二叉树的数据个数，二叉树每个节点只存放一个数据，
//所以也可以说求二叉树的节点个数（用的遍历后序的思维）
int TreeSize(BTNode* root)
{
	//三目操作符：exp1？exp2：exp3
	//如果 表达式exp1 为真，则 整个表达式 的结果为 表达式exp2；如果为假，则 整个表达式 的结果为 表达式exp3
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}


//求二叉树叶子节点(度为0的节点)的个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)//二叉树里没有节点
		return 0;

	if (root->left == NULL && root->right == NULL)//二叉树里只有一个节点，那么这个节点就是叶子节点
		return 1;

	//进入递归，找左子树的叶子节点+找右子树的叶子节点
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

// 二叉树第k层节点的个数
//转换成子问题：求 左子树的第k-1层 + 右子树的第k-1层
int TreekSize(BTNode* root, int k)
{
	assert(k >= 1);//断言好习惯,因为二叉树的层数从1开始

	if (root == NULL)//结束条件之一
		return 0;

	if (k == 1)//结束条件之二
		return 1;

	//分治到 求 左子树的第k-1层 + 右子树的第k-1层
	return TreekSize(root->left, k - 1) + TreekSize(root->right, k - 1);
}

//求二叉树的深度或高度
int TreeDepth(BTNode* root)
{
	////方法一：vs能过，leetcode不行
	//if (root == NULL)
	//	return 0;

	//if (root->left == NULL && root->right == NULL)
	//	return 1;

	//return TreeDepth(root->left) > TreeDepth(root->right) ?
	//	TreeDepth(root->left) + 1 : TreeDepth(root->right) + 1;


	//方法二：都能过
	if (root == NULL)
		return 0;

	int leftDepth = TreeDepth(root->left);//先将根节点的左子树的深度用临时变量存放起来,方便递归返回
	int rightDepth = TreeDepth(root->right);//先将根节点的右子树的深度用临时变量存放起来

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;//谁大就返回谁,加1是节点本身的深度是1
}

//查找数据x所在的节点，并返回这个节点
//最好用前序遍历的思想，最方便
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1 != NULL)
		return ret1;//将找到的这个节点，要带出这个节点，返回到上一个递归

	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2 != NULL)
		return ret2;//将找到的这个节点，要带出这个节点，返回到上一个递归

	return NULL;
}

//销毁二叉树每个节点申请的动态空间,用后序遍历的思想
void DestroyTree(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	DestroyTree(root->left);//将当前节点的左子树作为根节点递归
	DestroyTree(root->right);//将当前节点的左子树作为根节点递归

	free(root);//释放点节点的空间
	//root = NULL;//这里将root置为空指针没有意义，因为这个函数的参数是 值传递 ，
	//是将指针root存放的地址拷贝了一份给函数内部创建的指针root，我们是想将函数外的指针root置为空指针，
	//这里因为是值传递，所以只是将函数内部创建的临时指针root置为空，值传递形参的改变不影响实参，
	//所以函数外部的指针root依旧存放的是动态开辟的 大小是结构体类型 的空间的地址，并没有变为空指针NULL。
	//这里如果非要改变，那么就用二级指针，或者不用管，因为整个程序结束后，申请的所有空间都会销毁(返还)
}


//层序遍历二叉树的节点的数据(需要用到队列)
void LevelOrder(BTNode* root)//传指向二叉树根节点的指针
{
	// 核心思路：上一层出的时候带下一层节点进；
	//队列里的元素是指向二叉树节点的指针

	Queue q;//创建一个结构体类型Queue的变量，这个结构体里放的是
			//一个指向第一个节点的指针head和一个指向尾节点的指针tail

	QueueInit(&q);//初始化这个结构体，地址传递，可以改变实参

	if (root)//判断二叉树是否有节点
		QueuePush(&q, root);//将 指向二叉树根节点的指针 作为元素 队尾入队列里
					 //此时队列里 只有 指向二叉树根节点的指针这一个元素

	while (!QueueEmpty(&q))//队列里非空，就继续；队列空，就跳出循环
	{
		BTNode* front = QueueFront(&q);//将对头的元素由临时变量存放
		QueuePop(&q);//对头出 队列对头的元素
		printf("%c ", front->data);//打印 对头的元素 里存放的元素
								   //即打印的二叉树节点里存放的数据

		if (front->left)//该节点的左子树不为空指针，则将左子树队尾入队列里
		{
			QueuePush(&q, front->left);
		}

		if (front->right)//该节点的右子树不为空指针，则将右子树队尾入队列里
		{
			QueuePush(&q, front->right);
		}
	}

	printf("\n");

	QueueDestory(&q);//销毁队列的空间
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
// 栈实现队列OJ题代码
typedef int STDataType;
struct Stack
{
	STDataType* a;
	int top;       // 栈顶
	int capacity;  // 容量，方便增容
};

//typedef struct Stack ST;
typedef struct Stack Stack;

void StackInit(Stack* pst);
void StackDestroy(Stack* pst);

// 性质就决定在栈顶出入数据
void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);
STDataType StackTop(Stack* pst);

// 空返回1 非空返回0
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

// 性质就决定在栈顶出入数据
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType)*pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1); // 结束整个程序
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

// 空返回1 非空返回0
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