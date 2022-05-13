#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

void TestStack()
{
	ST st;//����һ���ṹ�����st
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

	StackDestroy(&st);
}

int main()
{
	TestStack();
	return 0;
}