#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

//顺序表的初始化，因为malloc开辟的动态空间里面的值是随机值
void SLInit(SL* ps)//要传递地址，才能改变实参
{
	assert(ps);//或assert(ps!=NULL) 防御式检查，断言好习惯，防止传递到是空指针NULL

	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}



//打印数组元素
void SLPrintArray(SL* ps)
{
	assert(ps);//或assert(ps!=NULL) 防御式检查，断言好习惯，防止传递到是空指针NULL

	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}



//销毁顺序表
void SLDestroy(SL* ps)
{
	assert(ps);//或assert(ps!=NULL) 防御式检查，断言好习惯，防止传递到是空指针NULL

	if (ps->a != NULL)
	{
		free(ps->a);
	}

	ps->size = 0;
	ps->capacity = 0;

}


//检查是否增容
void SLCheckCapacity(SL* ps)
{

	assert(ps);//或assert(ps!=NULL) 防御式检查，断言好习惯，防止传递到是空指针NULL

	//如果空间不够，增容
	if (ps->size == ps->capacity)
	{
		//三目操作符，因为一开始初始化的size和capacity都是0
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;//每次以容量两倍的增加
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("the mistake");//开辟失败，给出原因，结束该函数
		}

		ps->a = tmp;//开辟成功，将新开辟的空间的地址赋给指针a
		ps->capacity = newcapacity;//将开辟成功的新容量赋给capacity
	}
}


//尾插
void SLPushBack(SL* ps, SLDataType x)
{

	assert(ps);//或assert(ps!=NULL) 防御式检查，断言好习惯，防止传递到是空指针NULL

	//检查是否需要增容，因为这里要插入数据
	SLCheckCapacity(ps);

	//尾插数据
	ps->a[ps->size] = x;//size是已经存放的数据个数，而接着可以存放的数组下标就是size
	ps->size++;//size是已经存放的数据的个数，所以存放一个数据就要自增1


	////尾插的升级版本
	////尾插就是在 下标为size的地方插入 数据x
	//SLInsert(ps, ps->size, x);//任意位置(给的下标) 插入 数据
}


//头插
void SLPushFront(SL* ps, SLDataType x)
{

	assert(ps);//或assert(ps!=NULL) 防御式检查，断言好习惯，防止传递到是空指针NULL

	//检查是否需要增容，因为这里要插入数据
	SLCheckCapacity(ps);

	//挪动数据
	int end = ps->size - 1;//已经存放的最后一个数据的下标
	while(end >= 0)
	{
		ps->a[end + 1] = ps->a[end];//往后移动
		end--;//当原来已经存放的第一个数据，下标为0，移动后，跳出循环
	}

	ps->a[0] = x;//因为是头插，将新数据放在下标为0的数组位置
	ps->size++;//size是已经存放的数据的个数，所以存放一个数据就要自增1


	////头插的升级版本
	////头插就是在 下标为0的地方插入 数据x
	//SLInsert(ps, 0, x);//任意位置(给的下标) 插入 数据
}


//尾删
void SLPopBack(SL* ps)
{

	assert(ps);//或assert(ps!=NULL) 防御式检查，断言好习惯，防止传递到是空指针NULL


	//温柔检查和暴力检查都可以，我个人倾向暴力检查，因为出错了可以直接告诉
	//温柔检查是否还有 有效数据
	if (ps->size == 0)//数组里面没有数据，无需删除的操作,防止指针a越界
	{
		return 0;
	}
	////暴力检查是否还有 有效数据
	//assert(ps->size > 0);//断言判断 数组是否还有 有效数据,防止指针a越界

	ps->size--;//因为是尾删，将已经存放的数据个数减1，这样就访问不到了最后一个数据了，效果上相当于从尾部删除



	////尾删的升级版
	////尾删就是在 下标size-1 的地方删除数据
	//SLErase(ps, ps->size-1);
}



//头删
void SLPopFront(SL* ps)
{

	assert(ps);//或assert(ps!=NULL) 防御式检查，断言好习惯，防止传递到是空指针NULL


	//温柔检查和暴力检查都可以，我个人倾向暴力检查，因为出错了可以直接告诉
	//温柔检查是否还有 有效数据
	if (ps->size == 0)//数组里面没有数据，无需删除的操作,防止指针a越界
	{
		return 0;
	}
	////暴力检查是否还有 有效数据
	//assert(ps->size > 0);//断言判断 数组是否还有 有效数据,防止指针a越界

	int first = 0;//第一个数据的下标是0，因为要头删
	while (first<=ps->size-1-1)//循环的最后一次是first等于倒数第二个数据的下标
	{
		//往前挪动数据
		ps->a[first] = ps->a[first + 1];
		first++;
	}
	ps->size--;//循环完后，因为也要删除一个，所以数据元素个数自减1



	////头删的升级版
	////头删就是在 下标0 的地方删除数据
	//SLErase(ps, 0);
}



//任意位置(给的下标) 插入 数据
void SLInsert(SL* ps, int pos, SLDataType x)//pos是这个任意位置的下标
{
	assert(ps);//或assert(ps!=NULL) 防御式检查，断言好习惯，防止传递到是空指针NULL

    //为什么下标pos可以等于下标为size，虽然下标size没在有效数据内，但是在这个地方插入数据，其实就是尾插，也是可以的
	assert(pos >= 0 && pos <= ps->size);//检查这个任意位置的下标 是否 在我们需要操作的 有效数据内

    //检查是否需要增容，因为这里要插入数据
	SLCheckCapacity(ps);

	int end = ps->size - 1;//有效数据 的 最后一个元素的下标
	while (end >= pos)//end等于pos时候，就是把下标pos的数据往后移动
	{ 
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;//循环结束，将想插入的数据x放在下标为pos的地方
	ps->size++;//别忘了，插入一个数据，有效数据的个数 要加1
} 



//删除 这个任意位置(给的下标)
void SLErase(SL* ps, int pos)//pos是这个任意位置的下标
{
	assert(ps);//或assert(ps!=NULL) 防御式检查，断言好习惯，防止传递到是空指针NULL

    //为什么下标pos可以不等于下标为size，虽然我们这里是删除，下标size是不算的有效数据的，所以不等于。
	//还有一个原因，如果这个顺序表刚好满了，即size=capacity，这个时候如果pos等于下标size，就会导致指针a越界访问
	assert(pos >= 0 && pos < ps->size);//检查这个任意位置的下标 是否 在我们需要操作的 有效数据内
	//并且pos < ps->size 放在断言函数里 同时检查了顺序表为空的情况，为空就不需要执行删除的操作


	int cur = pos;//定义一个变量 存放 下标pos
	while (cur <= ps->size - 1 - 1)//最后一次循环 是下标cur 等于 有效数据的倒数第二个数据的下标
	{
		ps->a[cur] = ps->a[cur + 1];
		cur++;
	}

	ps->size--;//别忘了，删除一个数据，有效数据的个数 要减1
}



//给一个数据x，查找它在有效数组的下标，并返回
//可以和任意位置(给的下标)插入数据的函数 或者 删除这个任意位置(给的下标)的函数 一起使用
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);//或assert(ps!=NULL) 防御式检查，断言好习惯，防止传递到是空指针NULL

	for (int i = 0; i < ps->size; i++)//遍历一遍
	{
		if (ps->a[i] == x)
		return i;//找到了，返回下标
	}

	return -1;//没找到，返回-1
}


//给一个下标，找打这个下对对应的数据，然后用数据x修改( 和SLfind()函数 一起使用 )
void SLModify(SL* ps, int pos, SLDataType x)//pos是要修改的数据下标，并修改成数据x
{
	assert(ps);//或assert(ps!=NULL) 防御式检查，断言好习惯，防止传递到是空指针NULL

	 //为什么下标pos可以不等于下标为size，虽然我们这里是查找有效数据，下标size对应的数据是不算的有效数据的，所以不等于。
	//还有一个原因，如果这个顺序表刚好满了，即size=capacity，这个时候如果pos等于下标size，就会导致指针a越界访问
	assert(pos >= 0 && pos < ps->size);//检查这个任意位置的下标 是否 在我们需要操作的 有效数据内
	//并且pos < ps->size 放在断言函数里 同时检查了顺序表为空的情况，为空就不需要执行查找的操作

	ps->a[pos] = x;//修改
}