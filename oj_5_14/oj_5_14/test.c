#define _CRT_SECURE_NO_WARNINGS 1

#include<stdbool.h>
#include<string.h>
#include<stdio.h>


//https://leetcode.cn/problems/valid-palindrome/submissions/
//bool isPalindrome(char* s) {
//    //空字符串的特殊情况
//    if (*s == '\0')
//    {
//        return true;
//    }
//    char* tmp = s;
//    while (*tmp)
//    {
//        if ((*tmp >= 'a' && *tmp <= 'z') || (*tmp >= 'A' && *tmp <= 'Z') || (*tmp >= '0' && *tmp <= '9'))
//            break;
//        tmp++;
//    }
//    if (*tmp == '\0')
//        return true;
//
//    int len = strlen(s);//字符串的长度
//    int left = 0, right = len - 1;//数组的左右下标
//    while (left < right)
//    {
//        while (!((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z') || (s[left] >= '0' && s[left] <= '9')))
//        {
//            left++;
//            if (left > right && s[left - 1] != s[right])
//                return false;
//            if (left > right && s[left - 1] == s[right])
//            {
//                left--;
//                break;
//            }
//        }
//        while (!((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z') || (s[right] >= '0' && s[right] <= '9')))
//        {
//            right--;
//            if (right < left && s[left] != s[right + 1])
//                return false;
//            if (right < left && s[left] == s[right + 1])
//            {
//                right++;
//                break;
//            }
//        }
//        if (s[left] == s[right] || tolower(s[left]) == s[right] || toupper(s[left]) == s[right])
//        {
//            left++;
//            right--;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main()
//{
//    char* s = ",; W;:GlG:;l ;,";
//    if (isPalindrome(s))
//    {
//        printf("ture");
//    }
//    else
//    {
//        printf("false");
//    }
//    return 0;
//}




//https://leetcode.cn/problems/single-number/submissions/
// //此方法的时间复杂度O(N^2)，效率太低
// int singleNumber(int* nums, int numsSize){
//     int ret=0;
//     int flag=0;
//     for(int i=0;i<numsSize;i++)
//     {
//         flag=0;
//         for(int j=0;j<numsSize;j++)
//         {
//             if(nums[i]==nums[j])
//             flag++;
//         }
//         if(flag==1)
//         ret=nums[i];
//     }
//     return ret;
// }

//异或 任何数与0异或是本身 自己与自己异或为0 异或满足交换律
int singleNumber(int* nums, int numsSize)
{
    int ret = 0;
    for (int i = 0; i < numsSize; i++)
    {
        ret = ret ^ nums[i];
    }
    return ret;
}
int main()
{
    int arr[] = { 4,1,2,1,2 };
    printf("%d\n",singleNumber(arr, 5));
    return 0;
}