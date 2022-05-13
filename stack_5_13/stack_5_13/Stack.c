#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

//初始化栈
void StackInit(ST* ps)
{
	assert(ps);//断言好习惯

	ps->a = NULL;//初始化结构体(栈)
	ps->capacity = 0;
	ps->top = 0;
}


//销毁栈
void StackDestroy(ST* ps)
{
	assert(ps);//断言好习惯

	free(ps->a);//释放动态开辟的内存
	ps->capacity = 0;
	ps->top = 0;//这里初始化top为0，即可理解为数组的下标，因为下标从0开始放数据，放一个数据，就自增1
	            //所以top是等于存放的元素个数的，因为从0开始，放一个数据，自增1，所以top是栈顶下一个元素的下标
}


//入栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);//断言好习惯

	//是否增容
	if (ps->top == ps->capacity)
	{
		//定义新的容量
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//动态开辟新的空间，注意realloc和malloc的区别
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		//判断是否开辟成功
		if (tmp == NULL)
		{
			printf("realloc fail");
			exit(-1);
		}

		//开辟成功
		ps->a = tmp;
		ps->capacity = newcapacity;
	}

	//放入数据
	ps->a[ps->top] = x;//因为top从0开始，即可作为数组下标，放一个数据自增一个，即top是栈顶的下一个元素的下标
	ps->top++;
}



//出栈
void StackPop(ST* ps)
{
	assert(ps);//断言好习惯

	//判断栈里有效元素个数是否为0，为0就不需要出栈
	assert(!StackEmpty(ps));

	//出栈，top是可以表示栈里的有效元素的个数，所以直接top--，就相当于访问不到栈顶的元素个，效果上和出栈一样
	ps->top--;
}


//栈顶的 元素
STDataType StackTop(ST* ps)
{
	assert(ps);//断言好习惯

	//判断栈里有效元素个数是否为0，为0就没有栈顶元素
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];//因为top表示有效元素的个数，又可以表示为下标，所以下标top的前一个数据就是栈顶的数据
}


//判断栈是为空
bool StackEmpty(ST* ps)
{
	assert(ps);//断言好习惯

	if (ps->top == 0)//因为top即可以是表示有效元素的个数，又可以表示数组的下标，因为它是初始化为0
	{
		return true;
	}
	else
	{
		return false;
	}
}


//返回栈的有效元素个数
int StackSize(ST* ps)
{
	assert(ps);//断言好习惯

	return ps->top;//因为top即可以是表示有效元素的个数，又可以表示数组的下标，因为它是初始化为0
}