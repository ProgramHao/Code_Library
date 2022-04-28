#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
struct ListNode {
    int val;
    struct ListNode* next;
    
};
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here

    if (k == 0)//��kΪ0��ʱ�򣬷��ؿ�ָ��
    {
        return NULL;
    }

    int count = 1;
    struct ListNode* cur = pListHead;
    while (cur)//����һ�飬�ó�����Ľڵ���
    {
        if (cur->next != NULL)
        {
            count++;
        }
        cur = cur->next;
    }

    if (k > count)//k��������Ľڵ�����ʱ�򣬷��ؿ�ָ��
    {
        return NULL;
    }

    struct ListNode* now = pListHead;
    for (int i = 0; i < count - k; i++)//������k�������Ǵ�ǰ����count-k+1����
                              //�������Ƕ���ڵ�nowΪ��һ���ڵ㣬����now������count-k������
    {
        now = now->next;
    }

    return now;//�����ҵ�������ڵ� 
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
    while (fast && fast->next)//���������������������ڵ㣬����ż�����ڵ㣬������
    {
        slow = slow->next;//slowѭ��һ����һ��
        fast = fast->next->next;//fastѭ��������һ�� �����������ֿ�д
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
//�Լ�д��Ҳ����
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
        //1��2 ��ע�͵ĵȼ�
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
    if (head == NULL)//�޽ڵ��ʱ��ֱ�ӷ���NULL
    {
        return NULL;
    }

    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    while (cur != NULL)
    {
        if (cur->val == val)//ɾ���Ľڵ�����ĿҪ���
        {
            if (cur == head)//��ֹɾ���Ľڵ��ǵ�һ���ڵ㣬��ͷɾ
            {
                head = cur->next;
                free(cur);
                cur = head;
            }
            else    //ɾ���Ľڵ㲻�ǵ�һ���ڵ�
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else   //������ĿҪ��ɾ���Ľڵ�
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}