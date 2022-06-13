#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"

//��ӡ����
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//ֱ������ ֮ ֱ�Ӳ�������
//����������
//ʱ�临�Ӷ� O(N^2)
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//ǰ��0,end���������±�end+1����һ�����ݣ�ʹ�á�0��end+1������
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


//ֱ������ ֮ ϣ����������������
//ʱ�临�Ӷ�O(N^1.3) ---��ס���У�������
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//gap��΢������ı仯�ĸ��죬��������
		//��gap = gap / 2;

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


//����������
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//ѡ������ ֮ ֱ��ѡ������
//ʱ�临�Ӷ� O(N^2) ������õ������������������
//������ʱ�临�Ӷ�ͬΪ O(N^2)��ֱ�Ӳ������� �Ƚϣ�ֱ�Ӳ�������Ҫ��һЩ
//��Ϊֱ�Ӳ������� ��õ������O(N)
void SelectSort(int* a, int n)
{
	//�±�
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//��������Сֵ�����ֵ���±�
		int mini = begin, maxi = begin;
		//�ҳ�������Сֵ�����ֵ���±�
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
		Swap(&a[begin], &a[mini]);//����Сֵ���ڵ�һλ

		//�޶�һ�£�������ֵ�ڴ�ʱ����ĵ�һλ�����±�begin��maxi�ص�
		//��ôͨ������Ľ����󣬻ᵼ�´�ʱ�±�maxi���������ֵ�Ͳ������ֵ��
		if (begin == maxi)
		{
			maxi = mini;
		}

		Swap(&a[end], &a[maxi]);//�����ֵ�������һλ

		//��������ĳ�����ѭ��
		++begin;
		--end;
	}
}


//ѡ������ ֮ ð������
//ʱ�临�Ӷ���O(N^2),��õ��������O(N),ֱͬ�Ӳ�������
//��ô�������Ƚ��ˣ�����ֱ�Ӳ�������ȽϺ�
//����ֱ�Ӳ������� Ҫ��ֱ��ѡ�������ð������Ҫ��
//��ôֱ��ѡ�������ð������Ƚ��ˣ�������Ѿ�����������ݣ�ð���������
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

		//����ĳһ��û�����ݵĽ�����ʱ����ô��ʱ������ʵ���Ѿ��ź��ˣ��Ϳ�������ѭ��
		if (exchange == 0)
		{
			break;
		}
	}
}