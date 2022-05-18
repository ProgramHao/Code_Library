#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"

//初始化堆
void HeapInit(HP* php)
{
	assert(php);//断言好习惯

	php->a = NULL;
	php->capacity = php->size = 0;
}

//销毁堆
void HeapDestroy(HP* php)
{
	assert(php);//断言好习惯

	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}

//交换俩个数的函数
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

//向上调整算法
//child是插入数据的下标
void AdjustUp(HPDataType* a, int child)
{
	//其父节点的下标
	int parent = (child - 1) / 2;
	while (child != 0)//或者child>0,因为最后它的下标会为0
	{
		//这里建立小堆，孩子小于父亲就交换
		if (a[child] < a[parent])
		{
			//交换这两个数
			Swap(&a[child], &a[parent]);
			child = parent;//下标向上走
			parent = (child - 1) / 2;
		}
		else
		{
			break;//除了循环到下标child到0结束循环，这是孩子不小于父亲的情况也结束循环
			//因为我们没插入一个数，就会用一次这个算法，如果遇见孩子不小于父亲，那么就可以直接跳出循环
		}
	}
}

//入堆，因为是数组，所以肯定是从数组后面入数据
void HeapPush(HP* php, HPDataType x)
{
	assert(php);//断言好习惯

	//判断是否需要扩容
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		//判断是否扩容成功
		//扩容失败
		if (tmp == NULL)
		{
			printf("realloc fail");
			exit(-1);//结束函数
		}

		//扩容成功
		php->a = tmp;
		php->capacity = newcapacity;
	}

	//将数据插入数组
	php->a[php->size] = x;
	php->size++;

	//没插入一次，就用一次向上调整算法，这样就能保证可以建立小堆或者大堆
	//php->size-1 是插入的那个数据的下标
	int tmp = php->size - 1;
	AdjustUp(php->a, tmp);//php->size--是因为size从下标0开始，插入一个后，就自增一个，所以插入的那个数据 的下标要--一次才是
}

//向下调整算法
void Adjustdown(HPDataType* a, int n)//n是存放的数据的个数
{
	int parent = 0;
	int child = parent * 2 + 1;//默认为左孩子
	while (child < n)
	{
		//找出左孩子和右孩子中小的那一个的下标
		if (child + 1 < n && a[child + 1] < a[child])//child+1<n是防止数组越界
		{
			child = child + 1;
		}

		//判断小的那一个孩子 和 父亲 的大小
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

//出堆,出的堆顶的数据，即数组第一个有效数据的个数
void HeapPop(HP* php)
{
	assert(php);//断言好习惯

	assert(php->size);//数组里没有有效数据

	int tmp = php->size - 1;
	Swap(&php->a[0], &php->a[tmp]);
	Adjustdown(php->a, --php->size);//这里数据减1，相当于删除了这个交换后的最后一个数据，注意要先减再用，所以是前置--
}

//堆顶的数据，即数组第一个数据
HPDataType HeapTop(HP* php)
{
	assert(php);//断言好习惯

	assert(php->size);//数组里没有有效数据

	return php->a[0];
}

//判断用数组表示的堆是否为空
bool HeapEmpty(HP* php)
{
	assert(php);//断言好习惯

	return php->size == 0;
}

//用数组表示的堆的有效数据的个数
int HeapSize(HP* php)
{
	assert(php);//断言好习惯

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