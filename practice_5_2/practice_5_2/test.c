#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>



//https://leetcode-cn.com/problems/symmetric-tree/submissions/
struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

bool compare(struct TreeNode* left, struct TreeNode* right)
{
	if (left == NULL && right == NULL)
	{
		return true;
	}
	if (left == NULL || right == NULL)
	{
		return false;
	}
	if (left->val != right->val)
	{
		return false;
	}
	return compare(left->left, right->right) && compare(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	return compare(root->left, root->right);
}

int main()
{
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	struct TreeNode* p1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	struct TreeNode* p2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->left = p1;
	root->right = p2;
	root->val = 1;

	p1->left = NULL;
	p1->right = NULL;
	p1->val = 2;

	p2->left = NULL;
	p2->right = NULL;
	p2->val = 2;

	bool judge = isSymmetric(root);
	if (judge == 1)//或judge == true ,注意前面和这个等价只能是1。或judge
	{
		fprintf(stdout, "是对称二叉树\n");
	}
	if (judge == false)//或judge == 0;或true
	{
		fprintf(stdout, "不是对称二叉树\n");
	}
	return 0;
}





//https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
struct TreeNode* helper(int* nums, int left, int right)
{
	if (left > right)
	{
		return NULL;
	}

	// 总是选择中间位置左边的数字作为根节点
	int mid = (left + right) / 2;

	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = nums[mid];
	root->left = helper(nums, left, mid - 1);
	root->right = helper(nums, mid + 1, right);
	return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
	return helper(nums, 0, numsSize - 1);
}