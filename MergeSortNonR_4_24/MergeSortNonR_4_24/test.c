#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void PrintArray(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

//非递归归并排序整体( 这个可以直接用循环 )
// 时间复杂度都是O(N*logN)
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);//动态开辟一个数组的空间

	int gap = 1; // 每组数据个数，一开始先定义为 每组 一个 数据
	//两两组归并就是 第一组和第二组归并；第三组和第四组归并；........
	while (gap < n)//gap不能超过数组元素个数n，因为是两两组归并
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			// [i, i+gap-1] [i+gap,i+2*gap-1] 两两组比较
			int begin1 = i, end1 = i + gap - 1;//第一组的下标
			int begin2 = i + gap, end2 = i + 2 * gap - 1;//第二组的下标


			//两种特殊情况，这个一般有点不好想，多注意
			// 1、归并过程中右半区间可能就不存在
			if (begin2 >= n)//说明就不需要归并了，因为此时左半区间已经有序了
				break;
			// 2、归并过程中右半区间算多了, 修正一下
			if (end2 >= n)
			{
				end2 = n - 1;//重新修正成 数组最后一个元素的 下标
			}


			int index = i;//动态开辟的数组的下标
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


			// 拷贝回去,只是将归并的数据拷贝回去(没有归并的就无需拷贝)，因为需要对归并好数据的这一次的数组，再下一次归并
			for (int j = i; j <= end2; ++j)
			{
				a[j] = tmp[j];
			}
		}//for循环结束的括号，括号太多，容易看混

		gap *= 2;//第一次归并gap是1，第二次归并是gap是2，第二次归并是gap是4.........

	}//while循环结束的括号，括号太多，容易看混

	free(tmp);//释放到申请的动态空间
}

void TestMergeSort()
{
	int a[] = { 10, 6, 7 ,1, 3, 9, 4, 2 };
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestMergeSort();
	return 0;
}