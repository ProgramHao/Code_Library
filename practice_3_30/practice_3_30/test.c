#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int i = 0;
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    for (i = 0; i <= 12; i++)
    {
        arr[i] = 0;
        printf("hello bit\n");
    }
    return 0;
}


#include<stdio.h>
struct S 
{
	char arr[10];
	int a ;
	float b;
};
int main()
{
	//struct S s = { "abcdef",2,5.00 };
	struct S c = { 0 };
	FILE* pf = fopen("test.dat", "r");
	if (pf == NULL)
	{
		perror("the mistake of fopen:");
		return;
	}
	//fwrite(&s, sizeof(struct S), 1, pf);
	fread(&c, sizeof(struct S), 1, pf);
	printf("%s %d %f\n", c.arr, c.a, c.b);
	fclose(pf);
	pf = NULL;
	return 0;
}




//ģ��ʵ�ֿ⺯��strlen( )�Ĺ���
#include<stdio.h>
int my_strlen(char arr[],int sz)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		if (arr[i] != '\0')
		{
			count++;
		}
	}
	return count;
}
int main()
{
	char arr[10] = "abcdef";
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = my_strlen(arr,sz);
	fprintf(stdout,"%d", ret);
	return 0;
}




//ģ��ʵ�ֿ⺯��strcpy
#include<stdio.h>
void my_strcpy(char* dest, char* src)
{
	while(*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	return;
}
int main()
{
	int i = 0;
	char arr1[10] = "qwertyu";
	char arr2[10] = "abcdef";
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	my_strcpy(arr1, arr2);
	for (i = 0; i < sz; i++)
	{
		fprintf(stdout, "%c",arr1[i]);
	}
	return 0;
}



#include<stdio.h>
int my_strlen(char* p)
{
	int count = 0;
	while (*p != '\0')
	{
		p++;
		count++;
	}
	return count;
}
int main()
{
	char* p = "abcdef";
	char arr[10] = "abcdefg";
	int i = 1;
	int ret = my_strlen(p);
	fprintf(stdout,"%d\n", ret);
	printf("%d", i);
	return 0;
}




#include<stdio.h>
struct S
{
	int a;
	int b;
};
int main()
{
	struct S s = { 0 };
	int size = sizeof(s.a);
	fprintf(stdout, "%d\n", size);
	return 0;
}



//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣���
#include<stdio.h>
int main()
{
	int money = 0;
	int empty = 0;
	int total = 0;
	while (~scanf("%d", &money))
	{
		empty = money;
		total = money;
		while (empty / 2)
		{
			total += empty / 2;
			empty = empty / 2 + empty % 2;

		}
		fprintf(stdout, "%d\n", total);
		printf("\n");
	}
	return 0;
}




//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
#include<stdio.h>
void my_sort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] % 2 == 0)
			{
				int tmp = arr[j + 1];
				arr[j+1]=arr[j];
				arr[j] = tmp;
			}
		}
	}
}
int main()
{
	int i = 0;
	int arr[10] = { 3,5,4,1,6,9,2,7,8,11 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_sort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		fprintf(stdout, "%d ", arr[i]);
	}
	return 0;
}



//дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
//arr��һ������һά���顣
#include<stdio.h>
void my_print(int* p, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		fprintf(stdout, "%d ", *(p + i));
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_print(arr, sz);
	return 0;
}



//дһ����������������һ���ַ��������ݡ�
#include<stdio.h>
void averver(char* p,int sz)
{
	int i = 0;
	for (i = 0; i < sz/2; i++)
	{
		char tmp = *(p + i);
		*(p + i) = *(p + sz - 1 - i);
		*(p + sz - 1 - i) = tmp;
	}
}
int main()
{
	char arr[20] = {0};
	int i = 0;
	scanf("%s", arr);
	int sz = sizeof(arr) / sizeof(arr[0]);
       averver(arr,sz);
	for(i = 0; i < sz; i++)
	{
		fprintf(stdout, "%c", arr[i]);
	}
	return 0;
}


void averver(char* p, int sz)
{
	int i = 0;
	for (i = 0; i < sz / 2; i++)
	{
		char tmp = *(p + i);
		*(p + i) = *(p + sz - 1 - i);
		*(p + sz - 1 - i) = tmp;
	}
}
int main()
{
	//char arr[20] = {0};
	//while (~scanf("%s", arr))
	//{
	//	int sz = sizeof(arr) / sizeof(arr[0]);
	//	averver(arr, sz);
	//	//for (int i = 0; i < sz; i++)
	//	//{
	//	//	printf("%c", arr[i]);
	//	//}
	//char* arr = "abcdgf";
	char arr[10] = "abcde";
		printf("%s", arr);
	//}
	return 0;
}



//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222
#include<stdio.h>
int main()
{
	int n = 0;
	while (~scanf("%d", &n))
	{
		int i = 0;
		int sum = 0;
		for (i = 1; i < 100000; i*=10)
		{
			sum =(sum+ n % (10 * i));
		}
		printf("%d\n", sum);
		printf("\n");
	}
	return 0;
}




//���0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ��������� : 153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������
#include<stdio.h>
#include<math.h>
void suan(int n)
{
	int b = n;
	int sum = 0;
	while (n)
	{
		int a = 0;
		a = n % 10;
		n = n / 10;
		sum += (int)pow(a, 3);
	}
	if (b == sum)
	{
		printf("%d ", b);
	}
}
int main()
{
	int n = 0;
	for (n = 0; n < 100001; n++)
	{
        suan(n);
	}
	return 0;
}




��C��������Ļ���������ͼ����
 
 
            * 
          * * * 
        * * * * * 
      * * * * * * * 
    * * * * * * * * * 
  * * * * * * * * * * *  
* * * * * * * * * * * * * 
  * * * * * * * * * * *  
    * * * * * * * * * 
      * * * * * * * 
        * * * * * 
          * * * 
            * 

#include <stdio.h>
int main()
{
    int a = 0;
    while (scanf("%d", &a) != EOF)
    {
        int i = 0;
        int j = 0;
        int m = 0;
        for (i = 0; i < a; i++)
        {
            for (j = 0; j < a - i; j++)
            {
                printf(" ");
            }
            for (m = 0; m <= i; m++)
            {
                printf("* ");
            }
            printf("\n");
        }
        for (i = 0; i < a + 1; i++)
        {
            for (j = 0; j < i; j++)
            {
                printf(" ");
            }
            for (m = 0; m < a + 1 - i; m++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }
    return 0;
}