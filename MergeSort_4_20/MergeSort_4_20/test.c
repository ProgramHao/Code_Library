#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//归并排序排序整体   思想上类型 二叉数的 后序遍历: 左子树 右子树 根
//left是数组第一个元素的下标；right最后一个元素的下标；tmp是一个指针，指向的是malloc开辟的一个数组的空间
void _MergeSort(int* a, int left, int right, int* tmp)
{
	//这是递归停止的条件，当左区间 和 右区间 只有一个元素 的时候，停止递归
	if (left == right)//区间只有一个元素，即就是区间 第一个元素下标 和 最后一个元素下标 相等
		return;

	int mid = (left + right) >> 1;//右移一位相当于除2

	// 假设 [left, mid] [mid+1, right] 分成两个数组元素相等(或者相差1，因为可能数组元素为奇数)的左右区间
	//继续递归，直到 左区间 和 右区间的元素个数为1，就停止递归，开始归并 并开始返回上一个递归继续归并，直到结束
	_MergeSort(a, left, mid, tmp);//左区间继续分治递归
	_MergeSort(a, mid + 1, right, tmp);//右区间继续分治递归

	// 当停止递归，即区间只有一个元素的时候，开始归并
	int begin1 = left, end1 = mid;//对应左区间的相关下标
	int begin2 = mid + 1, end2 = right;//对应右区间的相关下标
	int index = left;//对应新数组的第一个元素下标

	while (begin1 <= end1 && begin2 <= end2)//判断哪个区间的下标begin先到头，就结束循环
	{
		//不管是哪个区间的元素放到新数组，在一个元素放在新数组后，新数组的下标index要++
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}


	//循环结束，判断哪个区间的元素还剩下，需要接到新数组后面
	while (begin1 <= end1)//如果是右区间的begin2先到头，就把另一个区间 左区间剩下的元素放到 新数组后面
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)//如果是左区间的begin1先到头，就把另一个区间 右区间剩下的元素放到 新数组后面
	{
		tmp[index++] = a[begin2++];
	}


	//将新数组的元素 拷贝回去 到需要排序的数组里面去
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int* a, int n)//n是需要排序的数组元素的个数
{
	int* tmp = (int*)malloc(sizeof(int) * n);//malloc动态申请空间，指针tmp指向开辟的新数组的空间
	_MergeSort(a, 0, n - 1, tmp);//递归排序整体
	free(tmp);//递归排序完整体后，释放动态开辟的新数组的空间
}

//打印排好序的数组
void PrintArray(int* a, int n)//n是数组元素的个数
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void TestMergeSort()//测试递归排序整体
{
	int a[] = { 10, 6, 7 ,1, 3, 9, 4, 2, 5 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//// 测试排序的性能对比
//void TestOP()
//{
//	srand(time(0));
//	const int N = 1000000;
//	int* a1 = (int*)malloc(sizeof(int) * N);
//	int* a2 = (int*)malloc(sizeof(int) * N);
//	int* a3 = (int*)malloc(sizeof(int) * N);
//	int* a4 = (int*)malloc(sizeof(int) * N);
//	int* a5 = (int*)malloc(sizeof(int) * N);
//	int* a6 = (int*)malloc(sizeof(int) * N);
//	int* a7 = (int*)malloc(sizeof(int) * N);
//
//	for (int i = 0; i < N; ++i)
//	{
//		a1[i] = rand();
//		//a1[i] = i;
//		a2[i] = a1[i];
//		a3[i] = a1[i];
//		a4[i] = a1[i];
//		a5[i] = a1[i];
//		a6[i] = a1[i];
//		a7[i] = a1[i];
//	}
//
//	int begin1 = clock();
//	//InsertSort(a1, N);
//	int end1 = clock();
//
//	int begin2 = clock();
//	ShellSort(a2, N);
//	int end2 = clock();
//
//	int begin3 = clock();
//	//SelectSort(a3, N);
//	int end3 = clock();
//
//	int begin4 = clock();
//	HeapSort(a4, N);
//	int end4 = clock();
//
//	int begin5 = clock();
//	QuickSort(a5, 0, N - 1);
//	//QuickSort(a4, 0, N - 1);
//	int end5 = clock();
//
//	int begin6 = clock();
//	//MergeSort(a6, N);
//	int end6 = clock();
//
//	int begin7 = clock();
//	//BubbleSort(a7, N);
//	//BubbleSort(a4, N);
//	int end7 = clock();
//
//	printf("InsertSort:%d\n", end1 - begin1);
//	printf("ShellSort:%d\n", end2 - begin2);
//	printf("SelectSort:%d\n", end3 - begin3);
//	printf("HeapSort:%d\n", end4 - begin4);
//	printf("BubbleSort:%d\n", end7 - begin7);
//
//	printf("QuickSort:%d\n", end5 - begin5);
//	/*printf("MergeSort:%d\n", end6 - begin6);*/
//
//	free(a1);
//	free(a2);
//	free(a3);
//	free(a4);
//	free(a5);
//	free(a6);
//	free(a7);
//
//}

int main()
{
	//TestOP();

	//TestShellSort();
	//TestHeapSort();
	//TestSelectSort();
	//TestBubbleSort();
	//TestQuickSort();
	TestMergeSort();

	return 0;
}