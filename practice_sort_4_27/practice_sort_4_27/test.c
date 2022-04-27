#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//打印数组
void PrintArray(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//插入排序 之 直接插入排序 时间复杂度O(N^2)
void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)//这里也可以等于0，等于0就相当于也往后走，但是会不稳定，所以不等于0会稳定
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

//插入排序 之 希尔排序
//时间复杂度 O(logN*N) 或 O(log3N*N)
//
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;//O(logN)
		//gap = gap /3 + 1;O(log3N)这是以3为底的对数
		int i = 0;
		for (i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end-=gap;
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

//向下调整算法，这里排大堆
void AdjustDown(int* a, int n, int root)//root是根节点的下标
{
	int parent = root;
	int child = parent * 2 + 1;//默认为左孩子

	while (child < n) //孩子下标最多是 n-1，n是数组元素的个数
	{
	    if (child + 1 < n && a[child] < a[child + 1])//右孩子大，就换成右孩子，等于没必要换
	    {
		    child += 1;
	    }

		if (a[parent] < a[child])//判断父节点和孩子节点的大小
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}

//选择排序 之 堆排序
void HeapSort(int* a, int n)
{
	//建堆
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//对建立好的堆进行排序，排升序要建立大堆，排降序要建立小堆，这里我们排升序
	int end = n - 1;//数组最后一个元素的下标
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);//这里的end是把当成 数组元素个数 传递给形参的，因为形参的这个位置就是数组元素个数
		end--;
	}//这里end不能等于0的原因是：会把end作为数组元素的个数 传递给 函数AdjustDown，因为这里的形参就是数组元素的个数，所以end最小要为1

}


//选择排序 之 直接选择排序
void SelectSort(int* a, int n)
{
	int begin = 0;
	while (begin < n)
	{
		int mini = begin;
		for (int i = begin; i < n; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		begin++;
	}
}


//交换排序 之 冒泡排序
void BubbleSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int j = 0;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}

int main()
{
	int arr[] = { 6,3,0,7,8,2,5,9,3,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	PrintArray(arr, n);
	//InsertSort(arr, n);//插入排序 之 直接插入排序
	//ShellSort(arr, n);//插入排序 之 希尔排序
	//HeapSort(arr, n);//选择排序 之 堆排序
	//SelectSort(arr, n);//选择排序 之 直接选择排序
	BubbleSort(arr, n);//交换排序 之 冒泡排序
	PrintArray(arr, n);
	return 0;
}

