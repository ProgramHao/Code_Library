#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdint.h>


//https://leetcode.cn/problems/reverse-bits/submissions/
uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    for (int i = 0; i < 32; i++)
    {
        ret = (ret << 1) | (n & 1);
        n = n >> 1;
    }
    return ret;
}

int main()
{
    uint32_t n = 43261596;
    printf("%u\n", reverseBits(n));
    return 0;
}


//https://leetcode.cn/problems/number-of-1-bits/submissions/
int hammingWeight(uint32_t n) {
    int num = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((n >> i) & 1 == 1)
            num++;
    }
    return num;
}


#include<stdbool.h>
//https://leetcode.cn/problems/palindrome-linked-list/
struct ListNode {
    int val;
    struct ListNode* next;
    
};


struct ListNode* findmidnode(struct ListNode* head)
{
    //定义快慢指针
    struct ListNode* slow = head, * fast = head;
    while (fast != NULL && fast->next != NULL)//第一种情况是节点为偶数的时候，第二种是节点为奇数的时候
    {
        //慢指针走一步，快指针走两步
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;//结束循环的时候，此时的慢指针就是指向中间节点
}

struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode* cur = head;
    struct ListNode* newhead = NULL;//定义新的头，并初始化为空指针
    while (cur != NULL)
    {
        struct ListNode* next = cur->next;//先保存此节点的下一个节点，防止找不到
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    return newhead;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL)
    {
        return true;
    }

    struct ListNode* mid = findmidnode(head);//查找中间节点的位置
    struct ListNode* midhead = reverse(mid);//倒置链表，并返回这个倒置的链表的第一个节点
    while (midhead != NULL)
    {
        if (head->val != midhead->val)
            return false;
        head = head->next;
        midhead = midhead->next;
    }
    return true;
}




//https://leetcode.cn/problems/delete-node-in-a-linked-list/submissions/
struct ListNode {
    int val;
    struct ListNode* next;
    
};

void deleteNode(struct ListNode* node) {
    struct ListNode* nextnode = node->next;//找到删除节点的后一个节点
    *node = *nextnode;//将指向删除节点的指针解引用，就能改变这个删除节点的空间里面的变量，即用下一个节点里的内容覆盖删除节点的内容
}