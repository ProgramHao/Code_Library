#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//https://leetcode-cn.com/problems/add-binary/

char* addBinary(char* a, char* b) {
    int carry = 0;
    int lena = strlen(a);
    int lenb = strlen(b);
    int len = fmax(lena, lenb);//�����ֵ
    int i = lena - 1;
    int j = lenb - 1;
    char* res = (char*)malloc(sizeof(char) * (len + 2)); /* ���ȿ����Ǹ������ַ�����1 */
    int k = len + 1;
    res[k--] = '\0'; /* ��ӽ����� */

    /* ģ��ӷ����� */
    while (i >= 0 || j >= 0 || carry > 0) {
        carry += (i >= 0) ? a[i--] - '0' : 0;
        carry += (j >= 0) ? b[j--] - '0' : 0;
        res[k--] = carry % 2 + '0';
        carry /= 2;
    }
    return res + k + 1;
}




//https://leetcode-cn.com/problems/climbing-stairs/
int climbStairs(int n) {
    int p1 = 0, p2 = 0, p3 = 1;//p1���ߵ�һ��̨�׵��߷�����p2���ߵڶ���̨�׵��߷�����p3���ߵ�����̨�׵��߷���
    for (int i = 1; i <= n; ++i)
    {
        p1 = p2;
        p2 = p3;
        p3 = p1 + p2;
    }
    return p3;
}




//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/submissions/

 struct ListNode {
     int val;
     struct ListNode *next;
 };
 


struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode* cur = head;
    while (cur->next != NULL)
    {
        if (cur->val == cur->next->val)
        {
            cur->next = cur->next->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    return head;
}