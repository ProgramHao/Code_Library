#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>


//https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
//typedef struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right; 
//}TNode;
//
//
//void inorder(struct TreeNode* root, int* arr, int* returnSize)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//    inorder(root->left, arr,returnSize);
//    arr[(*returnSize)] = root->val;
//    (*returnSize)++;
//    inorder(root->right, arr, returnSize);
//}
//
//int* inorderTraversal(struct TreeNode* root, int* returnSize) {
//    int* a = (int*)malloc(sizeof(int) * 100);
//    inorder(root, a, returnSize);
//    return a;
//}
//
//int main()
//{
//    int i = 0;
//    TNode* root = (TNode*)malloc(sizeof(TNode));
//    TNode* p1 = (TNode*)malloc(sizeof(TNode));
//    TNode* p2 = (TNode*)malloc(sizeof(TNode));
//    root->left = NULL;
//    root->right = p1;
//    root->val = 1;
//
//    p1->left = p2;
//    p1->right = NULL;
//    p1->val = 2;
//
//    p2->left = NULL;
//    p2->right = NULL;
//    p2->val = 3;
//
//    int num = 0;
//    int* a = inorderTraversal(root, &num);
//    for ( i = 0; i < num; i++)
//    {
//        printf("%d  ", a[i]);
//    }
//	return 0;
//}





//https://leetcode-cn.com/problems/same-tree/submissions/
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    else if (p == NULL || q == NULL)
    {
        return false;
    }
    else if (p->val != q->val)
    {
        return false;
    }
    else
    {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}
int main()
{
    struct TreeNode* root1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* root2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->val = 1;
    root1->left = NULL;
    root1->right = p;



    root2->val = 1;
    root2->left = p;
    root2->right = NULL;

    p->val = 2;
    p->left = NULL;
    p = NULL;

    int a = isSameTree(root1, root2);
    if (a == 0)
    {
        printf("false");
    }
    else
    {
        printf("true");
    }
}