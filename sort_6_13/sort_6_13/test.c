#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"

int main()
{
	int a[] = { 7,2,8,5,9,1,6,0,10 };
	int n = sizeof(a) / sizeof(a[0]);
	PrintArray(a, n);

	//InsertSort(a, n);
	//PrintArray(a, n);

	//ShellSort(a, n);
	//PrintArray(a, n);

	//SelectSort(a, n);
	//PrintArray(a, n);

	BubbleSort(a, n);
	PrintArray(a, n);
	return 0;
}