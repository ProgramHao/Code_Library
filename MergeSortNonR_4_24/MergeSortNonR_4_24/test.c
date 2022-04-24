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

//�ǵݹ�鲢��������( �������ֱ����ѭ�� )
// ʱ�临�Ӷȶ���O(N*logN)
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);//��̬����һ������Ŀռ�

	int gap = 1; // ÿ�����ݸ�����һ��ʼ�ȶ���Ϊ ÿ�� һ�� ����
	//������鲢���� ��һ��͵ڶ���鲢��������͵�����鲢��........
	while (gap < n)//gap���ܳ�������Ԫ�ظ���n����Ϊ��������鲢
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			// [i, i+gap-1] [i+gap,i+2*gap-1] ������Ƚ�
			int begin1 = i, end1 = i + gap - 1;//��һ����±�
			int begin2 = i + gap, end2 = i + 2 * gap - 1;//�ڶ�����±�


			//����������������һ���е㲻���룬��ע��
			// 1���鲢�������Ұ�������ܾͲ�����
			if (begin2 >= n)//˵���Ͳ���Ҫ�鲢�ˣ���Ϊ��ʱ��������Ѿ�������
				break;
			// 2���鲢�������Ұ����������, ����һ��
			if (end2 >= n)
			{
				end2 = n - 1;//���������� �������һ��Ԫ�ص� �±�
			}


			int index = i;//��̬���ٵ�������±�
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


			// ������ȥ,ֻ�ǽ��鲢�����ݿ�����ȥ(û�й鲢�ľ����追��)����Ϊ��Ҫ�Թ鲢�����ݵ���һ�ε����飬����һ�ι鲢
			for (int j = i; j <= end2; ++j)
			{
				a[j] = tmp[j];
			}
		}//forѭ�����������ţ�����̫�࣬���׿���

		gap *= 2;//��һ�ι鲢gap��1���ڶ��ι鲢��gap��2���ڶ��ι鲢��gap��4.........

	}//whileѭ�����������ţ�����̫�࣬���׿���

	free(tmp);//�ͷŵ�����Ķ�̬�ռ�
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