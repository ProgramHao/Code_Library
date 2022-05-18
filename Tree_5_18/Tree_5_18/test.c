#define _CRT_SECURE_NO_WARNINGS 1

#include"heap.h"

int main()
{
	HP hp;
	HeapInit(&hp);
	int arr[] = { 12,3,7,15,9,2,1,0 };
	for (int i = 0; i < 8; i++)
	{
		HeapPush(&hp, arr[i]);
	}
	HeapPrint(&hp);
	printf("%d\n",HeapTop(&hp));
	HeapPop(&hp);
	HeapPrint(&hp);
	printf("%d\n", HeapTop(&hp));
	return 0;
}