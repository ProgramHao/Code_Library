#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//交换两个数
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//向下调整算法的时间复杂度是O(logN)
//n是数组元素的个数，parent是需要从上往下调整的 下标
//这里我们假设建立小堆
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;//先默认为左孩子

	while (child < n)//防止下标child越界
	{
		//找出左右孩子小的那一个
		//child+1<n是防止 右孩子下标 越界
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child = child + 1;
		}

		//比较父亲和孩子的大小
		if (a[child] < a[parent])
		{
			Swap(&a[child], & a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;//跳出循环的第二种方式，父亲的大小满足小于等于孩子
		}
	}
}

//top-k问题，通过建立k个数的堆，这里我们假设排n个数的前k个最大数
void PrintTopk(int* a, int n, int k)
{
	//创建一个放k个数的数组
	int* KminHeap = (int*)malloc(sizeof(int) * k);

	//将数组a的前k个数放入动态开辟的那个数组里
	for (int i = 0; i < k; i++)
	{
		KminHeap[i] = a[i];
	}

	//用向下调整算法建立堆，这里我们建立小堆，因为找 最大的前k个数，所以建立小堆 
	//用向下调整算法建立堆的时间复杂度是O(logN),N是数据个数
	for (int i = (k - 1 - 1) / 2; i < k; i++)//从最后一个非子叶的子树开始调整
	{
		AdjustDown(KminHeap, k, i);
	}

	//用剩下的n-k个数依次和建立的小堆的堆顶数据比较大小
	//因为建立的是小堆，所以堆顶的数据是最小的
	for (int i = k; i < n; i++)
	{
		//判断剩下的n-k个数中大的 就和堆顶数据交换
		//为什么是大的，因为要找 最大的前k个数
		if (a[i] > KminHeap[0])
		{
			Swap(&a[i], &KminHeap[0]);
			AdjustDown(KminHeap, k, 0);//交换后需要继续将堆调整为小堆
		}
	}

	//剩下的n-k个数全部判断完后，此时的小堆里的就是最大的前k个数
	//此时打印出来就行
	for (int i = 0; i < k; i++)
	{
		printf("%d ", KminHeap[i]);
	}
	printf("\n");
}

int main()
{
	int a[] = { 1,10,5,2,8,3,7,4,6,16,12,20,18,0 };
	int n = sizeof(a) / sizeof(a[0]);
	PrintTopk(a,n,5);
	return 0;
}