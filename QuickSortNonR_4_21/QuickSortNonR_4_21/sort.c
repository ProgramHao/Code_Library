#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//����������
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// �ڿӷ�
int PartSort1(int* a, int left, int right)
{

	int begin = left, end = right;
	int pivot = begin;
	int key = a[begin];

	// O��N��
	while (begin < end)
	{
		// �ұ���С���ŵ����
		while (begin < end && a[end] >= key)
			--end;

		// С�ķŵ���ߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[end];
		pivot = end;

		// ����Ҵ�
		while (begin < end && a[begin] <= key)
			++begin;

		// ��ķŵ���ߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[begin];
		pivot = begin;
	}

	pivot = begin;
	a[pivot] = key;

	return pivot;
}

// �ݹ��ȱ�ݣ�ջ֡���̫�ջ�ռ䲻���ã����ܻ����
// �ǵݹ�
// �ݹ�ķǵݹ飺1��ֱ�Ӹ�ѭ��(��) 2������ ���ݽṹջ ģ��ݹ����(����һ��)
//��Ϊ���ݽṹ��ջ ��malloc�� ���� ȡ��̬�ڴ棬���ڴ�� ���� ���ֵĿռ�ܴ����Բ��ᷢ���ռ䲻������
void QuickSortNonR(int* a, int n)
{
	ST st;//����һ��ջ(�ýṹ���ʾ)
	StackInit(&st);//��ʼ�����ջ����mallocһ�� �����С�Ŀռ��ջ������������
	StackPush(&st, n - 1);//�Ƚ� ��Ҫ������������һ��Ԫ�� ���±����ջ���Ϊջ�Ǻ���ȳ���
	StackPush(&st, 0);//�ٽ� ��Ҫ����������һ��Ԫ�� ���±����ջ��

	while (!StackEmpty(&st))//�ж�ջ�Ƿ�Ϊ�գ���Ϊ�վͽ���ѭ��
	{
		int left = StackTop(&st);//ȡ��ջ����Ԫ�أ������� ��Ҫ����������һ��Ԫ�ص��±꣬��Ϊ�������
		StackPop(&st);//��ջ����Ҫ����������һ��Ԫ�ص��±� ��ջ

		int right = StackTop(&st);//�ٴ�ȡ��ջ����Ԫ�أ������� ��Ҫ������������һ��Ԫ�ص��±꣬��Ϊ�����Ѿ���ջ��һ��
		StackPop(&st);//��ջ����Ҫ������������һ��Ԫ�ص��±� ��ջ

		int keyIndex = PartSort1(a, left, right);//���ǵ�������һ���ڿӷ������ص����Ѿ��źõ������±�
		// ������[left, keyIndex-1] �Ѿ��źõ������±�keyIndex ������[keyIndex+1, right]


		//�ж��������Ƿ���ڣ�������������������Ԫ�أ���Ϊ����ֻ��һ��Ԫ�ص�ʱ���������±�����±����ȣ�
		//����Ϊ ����ֻ��һ��Ԫ�ص�ʱ����ʵ��Ϊ��������Ѿ��ź��ˣ���Ϊ �źõ����� ���������������������С��
		//�����������������������������Ѿ��źõ����� ���������������ֻ��һ��Ԫ�ص�ʱ����ʵ���Ѿ��ź��ˣ���������ջ
		if (keyIndex + 1 < right)
		{
			StackPush(&st, right);//�Ƚ� ��Ҫ������������һ��Ԫ�� ���±����ջ���Ϊջ�Ǻ���ȳ���
			StackPush(&st, keyIndex + 1);//�ٽ� ��Ҫ����������һ��Ԫ�� ���±����ջ��
		}

		//�ж��������Ƿ���ڣ�������������������Ԫ�أ���Ϊ����ֻ��һ��Ԫ�ص�ʱ���������±�����±�����
		if (left < keyIndex - 1)//����Ϊ ����ֻ��һ��Ԫ�ص�ʱ����ʵ��Ϊ��������Ѿ��ź��ˣ���û��Ҫ��ջ��
		{
			StackPush(&st, keyIndex - 1);//�Ƚ� ��Ҫ������������һ��Ԫ�� ���±����ջ���Ϊջ�Ǻ���ȳ���
			StackPush(&st, left);//�ٽ� ��Ҫ����������һ��Ԫ�� ���±����ջ��
		}
	}

	StackDestory(&st);//ѭ�������󣬼���Ҫ�����������ȫ�źú󣬾����ٴ��������ջ
}

void TestQuickSort()
{
	int a[] = { 49, 38, 65, 97, 76, 13, 27, 49 };

	printf("δʹ�÷ǵݹ������������ ǰ ����Ԫ�ص�˳��\n");
	PrintArray(a, sizeof(a) / sizeof(int));


	QuickSortNonR(a, sizeof(a) / sizeof(int));//�ǵݹ������������
	printf("δʹ�÷ǵݹ������������ �� ����Ԫ�ص�˳��\n");
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestQuickSort();//���Էǵݹ������������
	return 0;
}