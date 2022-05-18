#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"

//��ʼ����
void HeapInit(HP* php)
{
	assert(php);//���Ժ�ϰ��

	php->a = NULL;
	php->capacity = php->size = 0;
}

//���ٶ�
void HeapDestroy(HP* php)
{
	assert(php);//���Ժ�ϰ��

	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}

//�����������ĺ���
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

//���ϵ����㷨
//child�ǲ������ݵ��±�
void AdjustUp(HPDataType* a, int child)
{
	//�丸�ڵ���±�
	int parent = (child - 1) / 2;
	while (child != 0)//����child>0,��Ϊ��������±��Ϊ0
	{
		//���ｨ��С�ѣ�����С�ڸ��׾ͽ���
		if (a[child] < a[parent])
		{
			//������������
			Swap(&a[child], &a[parent]);
			child = parent;//�±�������
			parent = (child - 1) / 2;
		}
		else
		{
			break;//����ѭ�����±�child��0����ѭ�������Ǻ��Ӳ�С�ڸ��׵����Ҳ����ѭ��
			//��Ϊ����û����һ�������ͻ���һ������㷨������������Ӳ�С�ڸ��ף���ô�Ϳ���ֱ������ѭ��
		}
	}
}

//��ѣ���Ϊ�����飬���Կ϶��Ǵ��������������
void HeapPush(HP* php, HPDataType x)
{
	assert(php);//���Ժ�ϰ��

	//�ж��Ƿ���Ҫ����
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		//�ж��Ƿ����ݳɹ�
		//����ʧ��
		if (tmp == NULL)
		{
			printf("realloc fail");
			exit(-1);//��������
		}

		//���ݳɹ�
		php->a = tmp;
		php->capacity = newcapacity;
	}

	//�����ݲ�������
	php->a[php->size] = x;
	php->size++;

	//û����һ�Σ�����һ�����ϵ����㷨���������ܱ�֤���Խ���С�ѻ��ߴ��
	//php->size-1 �ǲ�����Ǹ����ݵ��±�
	int tmp = php->size - 1;
	AdjustUp(php->a, tmp);//php->size--����Ϊsize���±�0��ʼ������һ���󣬾�����һ�������Բ�����Ǹ����� ���±�Ҫ--һ�β���
}

//���µ����㷨
void Adjustdown(HPDataType* a, int n)//n�Ǵ�ŵ����ݵĸ���
{
	int parent = 0;
	int child = parent * 2 + 1;//Ĭ��Ϊ����
	while (child < n)
	{
		//�ҳ����Ӻ��Һ�����С����һ�����±�
		if (child + 1 < n && a[child + 1] < a[child])//child+1<n�Ƿ�ֹ����Խ��
		{
			child = child + 1;
		}

		//�ж�С����һ������ �� ���� �Ĵ�С
		if (a[child] < a[parent])
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

//����,���ĶѶ������ݣ��������һ����Ч���ݵĸ���
void HeapPop(HP* php)
{
	assert(php);//���Ժ�ϰ��

	assert(php->size);//������û����Ч����

	int tmp = php->size - 1;
	Swap(&php->a[0], &php->a[tmp]);
	Adjustdown(php->a, --php->size);//�������ݼ�1���൱��ɾ�����������������һ�����ݣ�ע��Ҫ�ȼ����ã�������ǰ��--
}

//�Ѷ������ݣ��������һ������
HPDataType HeapTop(HP* php)
{
	assert(php);//���Ժ�ϰ��

	assert(php->size);//������û����Ч����

	return php->a[0];
}

//�ж��������ʾ�Ķ��Ƿ�Ϊ��
bool HeapEmpty(HP* php)
{
	assert(php);//���Ժ�ϰ��

	return php->size == 0;
}

//�������ʾ�Ķѵ���Ч���ݵĸ���
int HeapSize(HP* php)
{
	assert(php);//���Ժ�ϰ��

	return php->size;
}

void HeapPrint(HP* php)
{
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}