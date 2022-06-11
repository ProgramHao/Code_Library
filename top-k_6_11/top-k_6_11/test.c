#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//����������
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//���µ����㷨��ʱ�临�Ӷ���O(logN)
//n������Ԫ�صĸ�����parent����Ҫ�������µ����� �±�
//�������Ǽ��轨��С��
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;//��Ĭ��Ϊ����

	while (child < n)//��ֹ�±�childԽ��
	{
		//�ҳ����Һ���С����һ��
		//child+1<n�Ƿ�ֹ �Һ����±� Խ��
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child = child + 1;
		}

		//�Ƚϸ��׺ͺ��ӵĴ�С
		if (a[child] < a[parent])
		{
			Swap(&a[child], & a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;//����ѭ���ĵڶ��ַ�ʽ�����׵Ĵ�С����С�ڵ��ں���
		}
	}
}

//top-k���⣬ͨ������k�����Ķѣ��������Ǽ�����n������ǰk�������
void PrintTopk(int* a, int n, int k)
{
	//����һ����k����������
	int* KminHeap = (int*)malloc(sizeof(int) * k);

	//������a��ǰk�������붯̬���ٵ��Ǹ�������
	for (int i = 0; i < k; i++)
	{
		KminHeap[i] = a[i];
	}

	//�����µ����㷨�����ѣ��������ǽ���С�ѣ���Ϊ�� ����ǰk���������Խ���С�� 
	//�����µ����㷨�����ѵ�ʱ�临�Ӷ���O(logN),N�����ݸ���
	for (int i = (k - 1 - 1) / 2; i < k; i++)//�����һ������Ҷ��������ʼ����
	{
		AdjustDown(KminHeap, k, i);
	}

	//��ʣ�µ�n-k�������κͽ�����С�ѵĶѶ����ݱȽϴ�С
	//��Ϊ��������С�ѣ����ԶѶ�����������С��
	for (int i = k; i < n; i++)
	{
		//�ж�ʣ�µ�n-k�����д�� �ͺͶѶ����ݽ���
		//Ϊʲô�Ǵ�ģ���ΪҪ�� ����ǰk����
		if (a[i] > KminHeap[0])
		{
			Swap(&a[i], &KminHeap[0]);
			AdjustDown(KminHeap, k, 0);//��������Ҫ�������ѵ���ΪС��
		}
	}

	//ʣ�µ�n-k����ȫ���ж���󣬴�ʱ��С����ľ�������ǰk����
	//��ʱ��ӡ��������
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