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




//模拟实现库函数strlen( )的功能
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




//模拟实现库函数strcpy
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



//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。
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




//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
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



//写一个函数打印arr数组的内容，不使用数组下标，使用指针。
//arr是一个整形一维数组。
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



//写一个函数，可以逆序一个字符串的内容。
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



//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
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




//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如 : 153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。
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




用C语言在屏幕上输出以下图案：
 
 
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