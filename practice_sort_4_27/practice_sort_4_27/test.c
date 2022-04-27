#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//��ӡ����
void PrintArray(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//�������� ֮ ֱ�Ӳ������� ʱ�临�Ӷ�O(N^2)
void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)//����Ҳ���Ե���0������0���൱��Ҳ�����ߣ����ǻ᲻�ȶ������Բ�����0���ȶ�
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

//�������� ֮ ϣ������
//ʱ�临�Ӷ� O(logN*N) �� O(log3N*N)
//
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;//O(logN)
		//gap = gap /3 + 1;O(log3N)������3Ϊ�׵Ķ���
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

//����������
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//���µ����㷨�������Ŵ��
void AdjustDown(int* a, int n, int root)//root�Ǹ��ڵ���±�
{
	int parent = root;
	int child = parent * 2 + 1;//Ĭ��Ϊ����

	while (child < n) //�����±������ n-1��n������Ԫ�صĸ���
	{
	    if (child + 1 < n && a[child] < a[child + 1])//�Һ��Ӵ󣬾ͻ����Һ��ӣ�����û��Ҫ��
	    {
		    child += 1;
	    }

		if (a[parent] < a[child])//�жϸ��ڵ�ͺ��ӽڵ�Ĵ�С
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

//ѡ������ ֮ ������
void HeapSort(int* a, int n)
{
	//����
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//�Խ����õĶѽ�������������Ҫ������ѣ��Ž���Ҫ����С�ѣ���������������
	int end = n - 1;//�������һ��Ԫ�ص��±�
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);//�����end�ǰѵ��� ����Ԫ�ظ��� ���ݸ��βεģ���Ϊ�βε����λ�þ�������Ԫ�ظ���
		end--;
	}//����end���ܵ���0��ԭ���ǣ����end��Ϊ����Ԫ�صĸ��� ���ݸ� ����AdjustDown����Ϊ������βξ�������Ԫ�صĸ���������end��СҪΪ1

}


//ѡ������ ֮ ֱ��ѡ������
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


//�������� ֮ ð������
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
	//InsertSort(arr, n);//�������� ֮ ֱ�Ӳ�������
	//ShellSort(arr, n);//�������� ֮ ϣ������
	//HeapSort(arr, n);//ѡ������ ֮ ������
	//SelectSort(arr, n);//ѡ������ ֮ ֱ��ѡ������
	BubbleSort(arr, n);//�������� ֮ ð������
	PrintArray(arr, n);
	return 0;
}

