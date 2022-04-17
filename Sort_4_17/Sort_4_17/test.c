#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 假设都用升序来讲，降序就是反过来

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// 插入排序
// 时间复杂度是多少？O(N^2)
// 什么情况下最坏？逆序  1+2+3+...+n-1
// 什么情况下最好？顺序有序  O(N)
void InsertSort(int* a, int n)
{
	// [0, end]有序  end+1位置的值插入[0, end]，让[0, end+1]有序
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void TestInsertSort()
{
	int a[] = { 3, 5, 2, 7, 8, 6, 1, 9, 4, 0 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// 直接插入排序的基础上的优化
// 1、先进行预排序，让数组接近有序
// 2、直接插入排序
// 时间复杂度：O(logN*N) 或者 O(log3N*N)
// 平均的时间复杂度是O(N^1.3)
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		//gap = gap / 2;  // logN
		gap = gap / 3 + 1; // log3N 以3为底数的对数
		// gap > 1时都是预排序  接近有序
		// gap == 1时就是直接插入排序 有序

		// gap很大时，下面预排序时间复杂度O(N)
		// gap很小时，数组已经很接近有序了，这时差不多也是(N)

		// 把间隔为gap的多组数据同时排
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
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

void TestShellSort()
{
	int a[] = { 3, 5, 2, 7, 8, 6, 1, 9, 4, 0 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1; // 默认是左孩子
	while (child < n)
	{
		// 1、选出左右孩子中大的那一个
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child += 1;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)//n是数组元素个数
{
	// 建堆  O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}


	// 排升序，通过上面的代码将数组建成大堆了
	int end = n - 1;//end是数组最后一个元素的下标

	while (end > 0)//直到所有数排好
	{
		Swap(&a[0], &a[end]);//交换第一个元素和最后一个元素，地址传递
		AdjustDwon(a, end, 0);//end=n-1：数组元素个数减1，访问不到交换后的数组最后一个元素，
							  //就相当于把数组最后一个元素移除
		--end;//end减1继续循环
	}
}

void TestHeapSort()
{
	int a[] = { 3, 5, 2, 7, 8, 6, 1, 9, 4, 0 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// 测试排序的性能对比
void TestOP()
{
	srand(time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];

	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	//HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	//QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	/*printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);*/

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

int main()
{
	//TestShellSort();
	//TestOP();
	TestHeapSort();

	return 0;
}