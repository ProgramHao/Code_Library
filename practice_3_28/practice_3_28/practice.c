#define _CRT_SECURE_NO_WARNINGS 1
//��һ���������У��������ظ�������������ɾ��ָ����ĳһ�����������ɾ��ָ������֮������У�������δ��ɾ�����ֵ�ǰ��λ��û�з����ı䡣
//���ݷ�Χ�����г��Ⱥ������е�ֵ������ 1 \le n \le 501��n��50
//����������
//��һ������һ������(0��N��50)��
//�ڶ�������N�������������ÿո�ָ���N��������
//������������Ҫ����ɾ����һ��������
//���������
//���Ϊһ�У�ɾ��ָ������֮������С�
 //��δ��������⣬̽�����ٸ�
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





//����
//���������������е����У����������кϲ�Ϊһ���������в������
//���ݷ�Χ�� 1 \le n, m \le 1000 \1��n, m��1000  �� �����е�ֵ���� 0 \le val \le 30000 \0��val��30000
//����������
//����������У�
//��һ�а�������������n, m���ÿո�ָ���n��ʾ�ڶ��е�һ���������������ֵĸ�����m��ʾ�����еڶ����������������ֵĸ�����
//�ڶ��а���n���������ÿո�ָ���
//�����а���m���������ÿո�ָ���
//���������
//���Ϊһ�У��������Ϊn + m���������У�������Ϊn���������кͳ���Ϊm�����������е�Ԫ�����½��������������кϲ���
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




//ʵ��һ�����������������ַ����е�k���ַ���
//
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
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




//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O(N);
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
            printf("�ҵ��ˣ������ǣ�(%d,%d)\n", (x+1), (y+1));
            return 1;
        }
    }
    printf("�Ҳ��������\n");
}

int main()
{
    int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int k = 0;
    int input = 0;
    do
    {
        menu();
        printf("�Ƿ�ʼѰ��->");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("������Ҫ�ҵ�����->");
            scanf("%d", &k);
            Find(a, 3, 3, k);
            break;
        case 0:
            printf("����\n");
            break;
        default:
            printf("������ѡ��\n");
            break;
        } 
    }while (input);
    return 0;
}




//����Ա�����ֳ���֡���7λ���٣��Ӽ�������������ɼ���ÿ��7���������ٷ��ƣ���ȥ��һ����߷ֺ�һ����ͷ֣����ÿ���ƽ���ɼ���
//��ע�������ж������룩
//����������
//ÿһ�У�����7��������0~100��������7���ɼ����ÿո�ָ���
//���������
//ÿһ�У����ȥ����߷ֺ���ͷֵ�ƽ���ɼ���С�������2λ��ÿ���������
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




//����
//KiKi����ĳ��ĳ���ж����죬��������ʵ�֡�������ݺ��·ݣ�������һ��������ж����졣
//����������
//�������룬һ���������������ֱ��ʾ��ݺ��·ݣ��ÿո�ָ���
//���������
//���ÿ�����룬���Ϊһ�У�һ����������ʾ��һ��������ж����졣
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






//����ˮ�ɻ��� - Lily Number������������֣����м��ֳ��������֣�����1461 ����
//��ֳɣ�1��461��, ��14��61��, ��146��1), ������в�ֺ�ĳ˻�֮�͵�����������һ��Lily Number��
//���磺
//655 = 6 * 55 + 65 * 5
//1461 = 1 * 461 + 14 * 61 + 146 * 1
//��� 5λ���е����� Lily Number��
//����������
//��
//���������
//һ�У�5λ���е����� Lily Number��ÿ������֮����һ���ո�
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




