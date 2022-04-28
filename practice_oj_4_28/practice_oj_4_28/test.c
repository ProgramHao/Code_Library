#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
struct ListNode {
    int val;
    struct ListNode* next;
    
};
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here

    if (k == 0)//当k为0的时候，返回空指针
    {
        return NULL;
    }

    int count = 1;
    struct ListNode* cur = pListHead;
    while (cur)//遍历一遍，得出链表的节点数
    {
        if (cur->next != NULL)
        {
            count++;
        }
        cur = cur->next;
    }

    if (k > count)//k大于链表的节点数的时候，返回空指针
    {
        return NULL;
    }

    struct ListNode* now = pListHead;
    for (int i = 0; i < count - k; i++)//倒数第k个，就是从前数第count-k+1个，
                              //但是我们定义节点now为第一个节点，所以now往后走count-k个就行
    {
        now = now->next;
    }

    return now;//返回找到的这个节点 
}



//https://leetcode-cn.com/problems/reverse-linked-list/description/
 struct ListNode {
    int val;
    struct ListNode* next;
    
};
struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct ListNode* newhead = NULL;
    struct ListNode* cur = head;
    while (cur != NULL)
    {
        struct ListNode* next = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    return newhead;
}





//https://leetcode-cn.com/problems/middle-of-the-linked-list/description/
 struct ListNode {
    int val;
    struct ListNode* next;
    
};
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)//结束条件不管是奇数个节点，还是偶数个节点，都满足
    {
        slow = slow->next;//slow循环一次走一步
        fast = fast->next->next;//fast循环两次走一步 或者走两步分开写
                              //fast=fast->next;
                              //fast=fast->next;
    }
    return slow;
}






//https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 struct ListNode {
    int val;
    struct ListNode* next;
    
};
//自己写的也过了
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* cur1 = list1;
    struct ListNode* cur2 = list2;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = tail;

    while (cur1 != NULL && cur2 != NULL)
    {
        if (cur1->val <= cur2->val)
        {
            tail->next = cur1;
            tail = cur1;
            cur1 = cur1->next;
        }
        else
        {
            tail->next = cur2;
            tail = cur2;
            cur2 = cur2->next;
        }
    }
    if (cur1 == NULL)
    {
        //1和2 和注释的等价
        tail->next = cur2;//1
        // while(cur2!=NULL)
        // {
        //     tail->next=cur2;
        //     tail=cur2;
        //     cur2=cur2->next;
        // }
    }
    if (cur2 == NULL)
    {
        tail->next = cur1;//2
        // while(cur1!=NULL)
        // {
        //     tail->next=cur1;
        //     tail=cur1;
        //     cur1=cur1->next;
        // }
    }
    //tail->next=NULL;
    return head->next->next;
}







//https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 struct ListNode {
    int val;
    struct ListNode* next;
    
};
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL)//无节点的时候，直接返回NULL
    {
        return NULL;
    }

    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    while (cur != NULL)
    {
        if (cur->val == val)//删除的节点是题目要求的
        {
            if (cur == head)//防止删除的节点是第一个节点，即头删
            {
                head = cur->next;
                free(cur);
                cur = head;
            }
            else    //删除的节点不是第一个节点
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else   //不是题目要求删除的节点
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}