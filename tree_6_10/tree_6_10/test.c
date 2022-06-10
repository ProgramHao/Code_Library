#define _CRT_SECURE_NO_WARNINGS 1


typedef char TreeDataType;//重命名数据类型名

//用结构体表示二叉树的节点
typedef struct TreeNode
{
	TreeDataType data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;


#include"Queue.h"

//层序遍历
void LevelOrder(TreeNode* root)
{
	Queue q;//创建一个结构体类型的变量
	QueueInit(&q);//初始化队列

	if (root != NULL)//判断二叉树是否有节点
	{
		QueuePush(&q, root);//将二叉树的第一个节点的地址 入队列
	}

	while (!QueueEmpty(&q))//或while(front)
	{
		TreeNode* front = QueueFront(&q);//储存队列首的 数据
		printf("%c ", front->data);//打印队列存放的数据
		QueuePop(&q);//遍历后将队列首的数据 出队列

		if(front->left != NULL)//左子树不为空，入队列
		QueuePush(&q, front->left);

		if (front->right != NULL)//右子树不为空，入队列
		QueuePush(&q, front->right);
	}

	printf("\n");

	QueueDestroy(&q);
}

//判断二叉树是否为完全二叉树
bool TreeComplete(TreeNode* root)
{
	Queue q;//创建一个结构体类型的变量
	QueueInit(&q);//初始化队列

	if (root)//判断 二叉树是否为空数
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		TreeNode* front = QueueFront(&q);//储存队列首的 数据
		QueuePop(&q);//遍历后将队列首的数据 出队列
		if (front != NULL)//队列首的数据不是空指针
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else
		{
			break;//队列首的数据是空指针直接跳出循环
		}
	}

	//如果此时队列里的数据全是空指针NULL，则是完全二叉树
	//如果此时队列里的数据存在不为空指针的数据，则不是
	while (!QueueEmpty(&q))//跳出第一个循环，进入第二个循环判断
	{
		TreeNode* front = QueueFront(&q);//储存队列首的 数据
		
		if (front==NULL)
		{
			QueuePop(&q);//遍历后将队列首的数据 出队列
		}
		else//此时队列首 的数据不是空指针NULL，只要出现这棵树就不是 完全二叉树
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
	//人为创建一个二叉树
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
	
	//层序遍历
	LevelOrder(A);
	
	//判断二叉树是否为完全二叉树
	bool ret = TreeComplete(A);
	printf("%d", ret);
	return 0;
}