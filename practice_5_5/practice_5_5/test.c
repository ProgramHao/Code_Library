#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//https://www.nowcoder.com/practice/440f16e490a0404786865e99c6ad91c9?tpId=37&tags=&title=&difficulty=&judgeStatus=&rp=1&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D37&gioEnter=menu
int OneNumber(int num)
{
    int i = 0;
    int count = 0;
    for (i = 0; i < 32; i++)
    {
        if ((num >> i & 1) == 1)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int num = 0;
    scanf("%d", &num);
    int ret = OneNumber(num);
    printf("%d\n", ret);
    return 0;
}







//https://www.nowcoder.com/practice/fe298c55694f4ed39e256170ff2c205f?tpId=37&tags=&title=&difficulty=&judgeStatus=&rp=1&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D37&gioEnter=menu
#include <stdio.h>
#include <string.h>

int main()
{
    int num, n, total = 0;
    while (scanf("%d", &num) != EOF)
    {
        total = 0;
        if (num == 0)
        {
            break;
        }
        else
        {
            total += num / 3;
            n = num % 3 + total;
        }
        while (n != 0)
        {
            if (n == 1)
            {
                break;
            }
            else if (n == 2)
            {
                total += 1;
                break;
            }
            else
            {
                total += n / 3;
                n = n % 3 + n / 3;
            }
        }
        printf("%d\n", total);
    }
}