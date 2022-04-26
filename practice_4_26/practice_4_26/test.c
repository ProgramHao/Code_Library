#define _CRT_SECURE_NO_WARNINGS 1



////描述
////输入一个整数，将这个整数以字符串的形式逆序输出
////程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
////数据范围： 0 \le n \le 2 ^ {30} - 1 \0≤n≤2
////30
////?1
////输入描述：
////输入一个int整数
////输出描述：
////将这个整数以字符串的形式逆序输出
//#include<stdio.h>
//#include<string.h>
//
//char* reverse(char* a, int len)
//{
//    int left = 0;
//    int right = len - 1;
//    while (left < right)
//    {
//        char tmp = a[left];
//        a[left] = a[right];
//        a[right] = tmp;
//        left++;
//        right--;
//    }
//    return a;
//}
//
//int main()
//{
//    int n = 0;
//    char arr[10] = { 0 };
//    scanf("%d", &n);
//    sprintf(arr, "%d", n);
//    int len = strlen(arr);
//    char* a = reverse(arr, len);
//    printf("%s\n", a);
//    return 0;
//}




////https://www.nowcoder.com/practice/48b3cb4e3c694d9da5526e6255bb73c3?tpId=37&tags=&title=&difficulty=&judgeStatus=&rp=1&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D37&gioEnter=menu
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    char str[10000];
//    int a, len, i;
//    gets(str);
//    len = strlen(str);
//    for (i = len - 1; i >= 0; i--)
//    {
//        if (str[i] == ' ')
//        {
//            a = i + 1;
//            while (str[a] != ' ')
//            {
//                if (a == len)
//                    break;
//                printf("%c", str[a]);
//                a++;
//            }
//            printf(" ");
//        }
//
//    }
//    i = 0;
//    while (str[i] != ' ')
//    {
//        printf("%c", str[i]);
//        i++;
//    }
//    return 0;
//}