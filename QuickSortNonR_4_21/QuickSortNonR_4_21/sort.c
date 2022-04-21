#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//交换两个数
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 挖坑法
int PartSort1(int* a, int left, int right)
{

	int begin = left, end = right;
	int pivot = begin;
	int key = a[begin];

	// O（N）
	while (begin < end)
	{
		// 右边找小，放到左边
		while (begin < end && a[end] >= key)
			--end;

		// 小的放到左边的坑里，自己形成新的坑位
		a[pivot] = a[end];
		pivot = end;

		// 左边找大
		while (begin < end && a[begin] <= key)
			++begin;

		// 大的放到左边的坑里，自己形成新的坑位
		a[pivot] = a[begin];
		pivot = begin;
	}

	pivot = begin;
	a[pivot] = key;

	return pivot;
}

// 递归的缺陷：栈帧深度太深，栈空间不够用，可能会溢出
// 非递归
// 递归改非递归：1、直接改循环(简单) 2、借助 数据结构栈 模拟递归过程(复杂一点)
//因为数据结构的栈 是malloc从 堆区 取动态内存，而内存给 堆区 划分的空间很大，所以不会发生空间不足的情况
void QuickSortNonR(int* a, int n)
{
	ST st;//定义一个栈(用结构体表示)
	StackInit(&st);//初始化这个栈，即malloc一块 数组大小的空间给栈。。。。。。
	StackPush(&st, n - 1);//先将 需要排序的数组最后一个元素 的下标放入栈里，因为栈是后进先出的
	StackPush(&st, 0);//再将 需要排序的数组第一个元素 的下标放入栈里

	while (!StackEmpty(&st))//判断栈是否为空，不为空就进入循环
	{
		int left = StackTop(&st);//取出栈顶的元素，这里是 需要排序的数组第一个元素的下标，因为后入的它
		StackPop(&st);//出栈：需要排序的数组第一个元素的下标 出栈

		int right = StackTop(&st);//再次取出栈顶的元素，这里是 需要排序的数组最后一个元素的下标，因为上面已经出栈了一次
		StackPop(&st);//出栈：需要排序的数组最后一个元素的下标 出栈

		int keyIndex = PartSort1(a, left, right);//就是单趟排序即一次挖坑法，返回的是已经排好的数的下标
		// 左区间[left, keyIndex-1] 已经排好的数的下标keyIndex 右区间[keyIndex+1, right]


		//判断右区间是否存在，即右区间至少有两个元素，因为区间只有一个元素的时候，区间左下标和右下标会相等，
		//再因为 区间只有一个元素的时候，其实认为这个区间已经排好了，因为 排好的数的 左区间所有数都比这个数小，
		//右区间的所有数都比这个数大，所以已经排好的数的 左区间或者右区间只有一个元素的时候，其实是已经排好了，就无需入栈
		if (keyIndex + 1 < right)
		{
			StackPush(&st, right);//先将 需要排序的区间最后一个元素 的下标放入栈里，因为栈是后进先出的
			StackPush(&st, keyIndex + 1);//再将 需要排序的区间第一个元素 的下标放入栈里
		}

		//判断左区间是否存在，即右区间至少有两个元素，因为区间只有一个元素的时候，区间左下标和右下标会相等
		if (left < keyIndex - 1)//再因为 区间只有一个元素的时候，其实认为这个区间已经排好了，就没必要入栈了
		{
			StackPush(&st, keyIndex - 1);//先将 需要排序的区间最后一个元素 的下标放入栈里，因为栈是后进先出的
			StackPush(&st, left);//再将 需要排序的区间第一个元素 的下标放入栈里
		}
	}

	StackDestory(&st);//循环结束后，即需要排序的数组完全排好后，就销毁创建的这个栈
}

void TestQuickSort()
{
	int a[] = { 49, 38, 65, 97, 76, 13, 27, 49 };

	printf("未使用非递归快速排序整体 前 数组元素的顺序：\n");
	PrintArray(a, sizeof(a) / sizeof(int));


	QuickSortNonR(a, sizeof(a) / sizeof(int));//非递归快速排序整体
	printf("未使用非递归快速排序整体 后 数组元素的顺序：\n");
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestQuickSort();//测试非递归快速排序整体
	return 0;
}