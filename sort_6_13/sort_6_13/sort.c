#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"

//打印数组
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//直接排序 之 直接插入排序
//这里排升序
//时间复杂度 O(N^2)
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//前【0,end】有序，在下标end+1插入一个数据，使得【0，end+1】有序
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}


//直接排序 之 希尔排序，这里排升序
//时间复杂度O(N^1.3) ---记住就行，不好算
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//gap稍微比下面的变化的更快，推行这种
		//或gap = gap / 2;

		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end = end - gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}


//交换两个数
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//选择排序 之 直接选择排序
//时间复杂度 O(N^2) 不管最好的情况还是最坏的情况都是
//所以与时间复杂度同为 O(N^2)的直接插入排序 比较，直接插入排序要好一些
//因为直接插入排序 最好的情况是O(N)
void SelectSort(int* a, int n)
{
	//下标
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//数组中最小值和最大值的下标
		int mini = begin, maxi = begin;
		//找出数组最小值的最大值的下标
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[begin], &a[mini]);//将最小值放在第一位

		//修定一下，如果最大值在此时数组的第一位，即下标begin和maxi重叠
		//那么通过上面的交换后，会导致此时下标maxi所在数组的值就不是最大值了
		if (begin == maxi)
		{
			maxi = mini;
		}

		Swap(&a[end], &a[maxi]);//将最大值放在最后一位

		//缩短数组的长度再循环
		++begin;
		--end;
	}
}


//选择排序 之 冒泡排序
//时间复杂度是O(N^2),最好的情况下是O(N),同直接插入排序
//那么这俩个比较了，还是直接插入排序比较好
//所以直接插入排序 要比直接选择排序和冒泡排序要好
//那么直接选择排序和冒泡排序比较了，如果是已经快有序的数据，冒泡排序更好
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int exchange = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				exchange = 1;
			}
		}

		//即当某一趟没有数据的交换的时候，那么此时数组其实就已经排好了，就可以跳出循环
		if (exchange == 0)
		{
			break;
		}
	}
}