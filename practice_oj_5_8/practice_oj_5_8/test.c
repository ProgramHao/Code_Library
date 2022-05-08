//https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        //创建两个哨兵位
        struct ListNode* greaterhead, * greatertail, * lesshead, * lesstail;
        greaterhead = greatertail = (struct ListNode*)malloc(sizeof(struct ListNode));
        lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));
        greatertail->next = NULL;
        lesstail->next = NULL;

        struct ListNode* cur = pHead;
        while (cur)//遍历一遍给的链表
        {
            if (cur->val < x)//比x小的节点，链接到哨兵位为 lesshead的链表
            {
                lesstail->next = cur;
                lesstail = cur;
            }
            else //比x大的节点，链接到哨兵位为 greaterhead的链表
            {
                greatertail->next = cur;
                greatertail = cur;
            }
            cur = cur->next;
        }

        lesstail->next = greaterhead->next;//首位链接这两个链表 形成需要返回的 新链表

        greatertail->next = NULL;//防止特殊情况，即放在哨兵位为greaterhead的链表的节点的最后一个节点
                         //不是给的链表的最后一个节点，那么这个节点里的next不为NULL
        struct ListNode* Head = lesshead->next;//将首位链接后的链表的第一个节点返回
        free(greaterhead);
        free(lesshead);

        return Head;
    }
};




//https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/
//方法一：双指针
// struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//     if(headA==NULL||headB==NULL)
//     {
//         return NULL;
//     }
//     struct ListNode *curA=headA;
//     struct ListNode *curB=headB;
//     while (curA != curB) 
//     {
//         curA = curA == NULL ? headB : curA->next;
//         curB = curB == NULL ? headA : curB->next;
//     }
//     return curA;
// }


//方法二：计算两个链表的长度，长的链表 先走 两个链表节点个数的差值，然后再循环走判断是否相交
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //其中有一个是空指针，就返回空指针
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }

    struct ListNode* curA = headA, * curB = headB;
    //求两个链表的长度
    int lenA = 1;
    int lenB = 1;
    while (curA->next)//即可以求长度，又可以找到链表的最后一个节点
    {
        curA = curA->next;
        lenA++;
    }
    while (curB->next)
    {
        curB = curB->next;
        lenB++;
    }

    if (curA != curB)//判断两个链表的最后以一个节点是否相交，因为如果有交点，那么一定最后一个节点会相交
    {
        return NULL;
    }

    //判断哪个链表为长链表，哪个为短链表
    struct ListNode* shortlist = headA, * longlist = headB;
    if (lenA > lenB)
    {
        shortlist = headB;
        longlist = headA;
    }

    int gap = abs(lenA - lenB);//abs()函数是绝对值函数

    //长链表先走gap步
    while (gap--)
    {
        longlist = longlist->next;
    }

    //遍历判断是否有交点
    while (shortlist != longlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }

    return shortlist;//返回交点，如果没有交点，那么shortlist和longlist都会遍历成NULL，
                    //也会跳出循环，所以依旧返回值为NULL也是对的
}