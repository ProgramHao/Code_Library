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
        //���������ڱ�λ
        struct ListNode* greaterhead, * greatertail, * lesshead, * lesstail;
        greaterhead = greatertail = (struct ListNode*)malloc(sizeof(struct ListNode));
        lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));
        greatertail->next = NULL;
        lesstail->next = NULL;

        struct ListNode* cur = pHead;
        while (cur)//����һ���������
        {
            if (cur->val < x)//��xС�Ľڵ㣬���ӵ��ڱ�λΪ lesshead������
            {
                lesstail->next = cur;
                lesstail = cur;
            }
            else //��x��Ľڵ㣬���ӵ��ڱ�λΪ greaterhead������
            {
                greatertail->next = cur;
                greatertail = cur;
            }
            cur = cur->next;
        }

        lesstail->next = greaterhead->next;//��λ�������������� �γ���Ҫ���ص� ������

        greatertail->next = NULL;//��ֹ����������������ڱ�λΪgreaterhead������Ľڵ�����һ���ڵ�
                         //���Ǹ�����������һ���ڵ㣬��ô����ڵ����next��ΪNULL
        struct ListNode* Head = lesshead->next;//����λ���Ӻ������ĵ�һ���ڵ㷵��
        free(greaterhead);
        free(lesshead);

        return Head;
    }
};




//https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/
//����һ��˫ָ��
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


//��������������������ĳ��ȣ��������� ���� ��������ڵ�����Ĳ�ֵ��Ȼ����ѭ�����ж��Ƿ��ཻ
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //������һ���ǿ�ָ�룬�ͷ��ؿ�ָ��
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }

    struct ListNode* curA = headA, * curB = headB;
    //����������ĳ���
    int lenA = 1;
    int lenB = 1;
    while (curA->next)//�������󳤶ȣ��ֿ����ҵ���������һ���ڵ�
    {
        curA = curA->next;
        lenA++;
    }
    while (curB->next)
    {
        curB = curB->next;
        lenB++;
    }

    if (curA != curB)//�ж���������������һ���ڵ��Ƿ��ཻ����Ϊ����н��㣬��ôһ�����һ���ڵ���ཻ
    {
        return NULL;
    }

    //�ж��ĸ�����Ϊ�������ĸ�Ϊ������
    struct ListNode* shortlist = headA, * longlist = headB;
    if (lenA > lenB)
    {
        shortlist = headB;
        longlist = headA;
    }

    int gap = abs(lenA - lenB);//abs()�����Ǿ���ֵ����

    //����������gap��
    while (gap--)
    {
        longlist = longlist->next;
    }

    //�����ж��Ƿ��н���
    while (shortlist != longlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }

    return shortlist;//���ؽ��㣬���û�н��㣬��ôshortlist��longlist���������NULL��
                    //Ҳ������ѭ�����������ɷ���ֵΪNULLҲ�ǶԵ�
}