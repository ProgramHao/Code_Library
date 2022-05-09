#define _CRT_SECURE_NO_WARNINGS 1
//有一个整数序列（可能有重复的整数），现删除指定的某一个整数，输出删除指定数字之后的序列，序列中未被删除数字的前后位置没有发生改变。
//数据范围：序列长度和序列中的值都满足 1 \le n \le 501≤n≤50
//输入描述：
//第一行输入一个整数(0≤N≤50)。
//第二行输入N个整数，输入用空格分隔的N个整数。
//第三行输入想要进行删除的一个整数。
//输出描述：
//输出为一行，删除指定数字之后的序列。
 //这段代码有问题，探讨完再改
#include<stdio.h>
#include<string.h>
int main()
{
    int n=0;
    int i=0;
    int j=0;
    int a = 0;
    int b = 0;
    char arr[20][20][3]={0};
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == 0 || i == n - 1 || i == j)
            {
                strcpy(arr[i][j],"* ");
            }
            else
            {
                strcpy(arr[i][j], "  ");
            }
        }
    }
    for(a=0;a<n;a++)
    {
        for(b=0;b<n;b++)
        {
            printf("%s",arr[a][b]);
        }
        printf("\n");
    }
    return 0;
}




#include<stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[50] = { 0 };
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int num = 0;
    scanf("%d", &num);
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            for (int j = i; j < n; j++)
            {
                arr[j] = arr[j + 1];
            }
            i--;
            m++;
        }
    }
    for (int i = 0; i < n - m; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}





//描述
//输入两个升序排列的序列，将两个序列合并为一个有序序列并输出。
//数据范围： 1 \le n, m \le 1000 \1≤n, m≤1000  ， 序列中的值满足 0 \le val \le 30000 \0≤val≤30000
//输入描述：
//输入包含三行，
//第一行包含两个正整数n, m，用空格分隔。n表示第二行第一个升序序列中数字的个数，m表示第三行第二个升序序列中数字的个数。
//第二行包含n个整数，用空格分隔。
//第三行包含m个整数，用空格分隔。
//输出描述：
//输出为一行，输出长度为n + m的升序序列，即长度为n的升序序列和长度为m的升序序列中的元素重新进行升序序列排列合并。
#include<stdio.h>
int main()
{
    int arr1[100] = { 0 };
    int arr2[100] = { 0 };
    int arr3[100] = { 0 };
    int n = 0;
    int m = 0;
    int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
        arr3[i] = arr1[i];
    }
    for (j = 0; j < m; j++)
    {
        scanf("%d", &arr2[j]);
        arr3[n+j] = arr2[j];
    }
    for (a = 0; a < m + n; a++)
    {
        for (b = 0; b < m + n - 1 - a; b++)
        {
            if (arr3[b] > arr3[b + 1])
            {
                int tmp = arr3[b];
                arr3[b] = arr3[b + 1];
                arr3[b + 1] = tmp;
            }
        }
    }
    for (int c = 0; c < m + n; c++)
    {
        printf("%d ", arr3[c]);
    }
    return 0;
}




//实现一个函数，可以左旋字符串中的k个字符。
//
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
#include<stdio.h>
void my_turnleft(char arr[], int k, int sz)
{
	int i = 0;
	for (i = 0; i < k; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 ; j++)
		{
			if (arr[j + 1] != 0)
			{
				char tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int i = 0;
	char arr[100] = { 0 };
	int k = 0;
	scanf("%s %d", arr, &k);
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_turnleft(arr, k, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%c", arr[i]);
	}
	return 0;
}




//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);
#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("******************************\n");
    printf("***** 1.find   0.not find*****\n");
    printf("******************************\n");
}
void Find(int a[3][3], int row, int col, int k)
{
    int x = 0;
    int y = col - 1;
    while (x < row && y >= 0)
    {
        if (a[x][y] < k)
            x++;
        else if (a[x][y] > k)
            y--;
        else
        {
            printf("找到了，坐标是：(%d,%d)\n", (x+1), (y+1));
            return 1;
        }
    }
    printf("找不到这个数\n");
}

int main()
{
    int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int k = 0;
    int input = 0;
    do
    {
        menu();
        printf("是否开始寻找->");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("请输入要找的数字->");
            scanf("%d", &k);
            Find(a, 3, 3, k);
            break;
        case 0:
            printf("不找\n");
            break;
        default:
            printf("请重新选择\n");
            break;
        } 
    }while (input);
    return 0;
}




//公务员面试现场打分。有7位考官，从键盘输入若干组成绩，每组7个分数（百分制），去掉一个最高分和一个最低分，输出每组的平均成绩。
//（注：本题有多组输入）
//输入描述：
//每一行，输入7个整数（0~100），代表7个成绩，用空格分隔。
//输出描述：
//每一行，输出去掉最高分和最低分的平均成绩，小数点后保留2位，每行输出后换行
#include<stdio.h>
int main()
{
    int i = 0;
    int j = 0;
    int arr[7] = { 0 };
    while (~scanf("%d%d%d%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6]))
    {
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 6 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
        float aver = (arr[1] + arr[2] + arr[3] + arr[4] + arr[5]) / 5.0;
        printf("%.2f\n", aver);
    }
    return 0;
}




//描述
//KiKi想获得某年某月有多少天，请帮他编程实现。输入年份和月份，计算这一年这个月有多少天。
//输入描述：
//多组输入，一行有两个整数，分别表示年份和月份，用空格分隔。
//输出描述：
//针对每组输入，输出为一行，一个整数，表示这一年这个月有多少天。
#include<stdio.h>
int main()
{
    int year = 0;
    int mon = 0;
    int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    while (~scanf("%d %d", &year, &mon))
    {
        int day = 0;
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            if (mon == 2)
            {
                day = month[mon - 1] + 1;
            }
            else
            {
                day = month[mon - 1];
            }
        }
        else 
        {
            day = month[mon - 1];
        }
        printf("%d\n", day);
    }
    return 0;
}






//变种水仙花数 - Lily Number：把任意的数字，从中间拆分成两个数字，比如1461 可以
//拆分成（1和461）, （14和61）, （146和1), 如果所有拆分后的乘积之和等于自身，则是一个Lily Number。
//例如：
//655 = 6 * 55 + 65 * 5
//1461 = 1 * 461 + 14 * 61 + 146 * 1
//求出 5位数中的所有 Lily Number。
//输入描述：
//无
//输出描述：
//一行，5位数中的所有 Lily Number，每两个数之间间隔一个空格。
#include<stdio.h>
int main()
{
    int n = 0;
    for (n = 10000; n < 100000; n++)
    {
        int i = 1;
        int sum = 0;
        for (i = 10; i <= 10000; i *= 10)
        {
            int a = n % i;
            int b = n / i;
            sum += a * b;
        }
        if (sum == n)
        {
            printf("%d ", n);
        }
    }
    return 0;
}




