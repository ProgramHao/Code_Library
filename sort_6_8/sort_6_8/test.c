#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"

int main()
{
	int a[] = { 2,5,1,9,4,7,0,6 };
	int size = sizeof(a) / sizeof(a[0]);
	//IsertSort(a, size);
	ShellSort(a, size);
	PrintArray(a, size);
	return 0;
}