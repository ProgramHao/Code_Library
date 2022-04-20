#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//�鲢������������   ˼�������� �������� �������: ������ ������ ��
//left�������һ��Ԫ�ص��±ꣻright���һ��Ԫ�ص��±ꣻtmp��һ��ָ�룬ָ�����malloc���ٵ�һ������Ŀռ�
void _MergeSort(int* a, int left, int right, int* tmp)
{
	//���ǵݹ�ֹͣ���������������� �� ������ ֻ��һ��Ԫ�� ��ʱ��ֹͣ�ݹ�
	if (left == right)//����ֻ��һ��Ԫ�أ����������� ��һ��Ԫ���±� �� ���һ��Ԫ���±� ���
		return;

	int mid = (left + right) >> 1;//����һλ�൱�ڳ�2

	// ���� [left, mid] [mid+1, right] �ֳ���������Ԫ�����(�������1����Ϊ��������Ԫ��Ϊ����)����������
	//�����ݹ飬ֱ�� ������ �� �������Ԫ�ظ���Ϊ1����ֹͣ�ݹ飬��ʼ�鲢 ����ʼ������һ���ݹ�����鲢��ֱ������
	_MergeSort(a, left, mid, tmp);//������������εݹ�
	_MergeSort(a, mid + 1, right, tmp);//������������εݹ�

	// ��ֹͣ�ݹ飬������ֻ��һ��Ԫ�ص�ʱ�򣬿�ʼ�鲢
	int begin1 = left, end1 = mid;//��Ӧ�����������±�
	int begin2 = mid + 1, end2 = right;//��Ӧ�����������±�
	int index = left;//��Ӧ������ĵ�һ��Ԫ���±�

	while (begin1 <= end1 && begin2 <= end2)//�ж��ĸ�������±�begin�ȵ�ͷ���ͽ���ѭ��
	{
		//�������ĸ������Ԫ�طŵ������飬��һ��Ԫ�ط������������������±�indexҪ++
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}


	//ѭ���������ж��ĸ������Ԫ�ػ�ʣ�£���Ҫ�ӵ����������
	while (begin1 <= end1)//������������begin2�ȵ�ͷ���Ͱ���һ������ ������ʣ�µ�Ԫ�طŵ� ���������
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)//������������begin1�ȵ�ͷ���Ͱ���һ������ ������ʣ�µ�Ԫ�طŵ� ���������
	{
		tmp[index++] = a[begin2++];
	}


	//���������Ԫ�� ������ȥ ����Ҫ�������������ȥ
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int* a, int n)//n����Ҫ���������Ԫ�صĸ���
{
	int* tmp = (int*)malloc(sizeof(int) * n);//malloc��̬����ռ䣬ָ��tmpָ�򿪱ٵ�������Ŀռ�
	_MergeSort(a, 0, n - 1, tmp);//�ݹ���������
	free(tmp);//�ݹ�������������ͷŶ�̬���ٵ�������Ŀռ�
}

//��ӡ�ź��������
void PrintArray(int* a, int n)//n������Ԫ�صĸ���
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void TestMergeSort()//���Եݹ���������
{
	int a[] = { 10, 6, 7 ,1, 3, 9, 4, 2, 5 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//// ������������ܶԱ�
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