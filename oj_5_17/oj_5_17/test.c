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
    //�������ָ��
    struct ListNode* slow = head, * fast = head;
    while (fast != NULL && fast->next != NULL)//��һ������ǽڵ�Ϊż����ʱ�򣬵ڶ����ǽڵ�Ϊ������ʱ��
    {
        //��ָ����һ������ָ��������
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;//����ѭ����ʱ�򣬴�ʱ����ָ�����ָ���м�ڵ�
}

struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode* cur = head;
    struct ListNode* newhead = NULL;//�����µ�ͷ������ʼ��Ϊ��ָ��
    while (cur != NULL)
    {
        struct ListNode* next = cur->next;//�ȱ���˽ڵ����һ���ڵ㣬��ֹ�Ҳ���
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

    struct ListNode* mid = findmidnode(head);//�����м�ڵ��λ��
    struct ListNode* midhead = reverse(mid);//��������������������õ�����ĵ�һ���ڵ�
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
    struct ListNode* nextnode = node->next;//�ҵ�ɾ���ڵ�ĺ�һ���ڵ�
    *node = *nextnode;//��ָ��ɾ���ڵ��ָ������ã����ܸı����ɾ���ڵ�Ŀռ�����ı�����������һ���ڵ�������ݸ���ɾ���ڵ������
}