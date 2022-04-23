#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"
//测试初始化
void TestSeqList1()
{
	SL sl ;//定义一个结构体类型的变量
	SLInit(&sl);//地址传递，才能改变实参
}



//测试尾插
void TestSeqList2()
{
	SL sl;//定义一个结构体类型的变量
	SLInit(&sl);//初始化，地址传递，才能改变实参
	SLPushBack(&sl, 1);//尾插几个数
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);

	SLPrintArray(&sl);//打印数组元素

	SLDestroy(&sl);//销毁顺序表
}

//测试头插
void TestSeqList3()
{
	SL sl;//定义一个结构体类型的变量
	SLInit(&sl);//初始化，地址传递，才能改变实参
	SLPushFront(&sl, 1);//头插几个数
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);

	SLPrintArray(&sl);//打印数组元素

	SLDestroy(&sl);//销毁顺序表
}


//测试尾删
void TestSeqList4()
{
	SL sl;//定义一个结构体类型的变量
	SLInit(&sl);//初始化，地址传递，才能改变实参
	SLPushBack(&sl, 1);//尾插几个数
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrintArray(&sl);//打印数组元素

	SLPopBack(&sl);//尾删
	SLPopBack(&sl);
	SLPrintArray(&sl);//打印数组元素

	SLDestroy(&sl);//销毁顺序表
}


//测试头删
void TestSeqList5()
{
	SL sl;//定义一个结构体类型的变量
	SLInit(&sl);//初始化，地址传递，才能改变实参
	SLPushBack(&sl, 5);//尾插几个数
	SLPushBack(&sl, 6);
	SLPushBack(&sl, 7);
	SLPushBack(&sl, 8);
	SLPrintArray(&sl);//打印数组元素

	SLPopFront(&sl);//头删几个
	SLPopFront(&sl);
	SLPrintArray(&sl);//打印数组元素

	SLDestroy(&sl);//销毁顺序表
}


//测试任意位置(给的下标) 插入 数据
void TestSeqList6()
{
	SL sl;//定义一个结构体类型的变量
	SLInit(&sl);//初始化，地址传递，才能改变实参
	SLPushBack(&sl, 11);//尾插几个数
	SLPushBack(&sl, 22);
	SLPushBack(&sl, 33);
	SLPushBack(&sl, 44);
	SLPrintArray(&sl);//打印数组元素

	SLInsert(&sl, 3, 55);//任意位置(给的下标) 插入 数据
	SLPrintArray(&sl);//打印数组元素

	SLInsert(&sl, 0, 66);//任意位置(给的下标) 插入 数据
	SLPrintArray(&sl);//打印数组元素

	SLDestroy(&sl);//销毁顺序表
}


//测试删除 这个任意位置(给的下标)
void TestSeqList7()
{
	SL sl;//定义一个结构体类型的变量
	SLInit(&sl);//初始化，地址传递，才能改变实参
	SLPushBack(&sl, 111);//尾插几个数
	SLPushBack(&sl, 222);
	SLPushBack(&sl, 333);
	SLPushBack(&sl, 444);
	SLPushBack(&sl, 555);
	SLPrintArray(&sl);//打印数组元素

	//删除 这个任意位置(给的下标)
	SLErase(&sl, 2);//pos是这个任意位置的下标
	SLPrintArray(&sl);//打印数组元素

	//删除 这个任意位置(给的下标)
	SLErase(&sl, 2);//pos是这个任意位置的下标
	SLPrintArray(&sl);//打印数组元素

	SLDestroy(&sl);//销毁顺序表
}


//测试给一个数据，查找它在有效数组的下标，并返回(和任意位置(给的下标)插入数据的函数 一起使用的情况 )
void TestSeqList8()
{
	SL sl;//定义一个结构体类型的变量
	SLInit(&sl);//初始化，地址传递，才能改变实参
	SLPushBack(&sl, 111);//尾插几个数
	SLPushBack(&sl, 222);
	SLPushBack(&sl, 333);
	SLPushBack(&sl, 444);
	SLPushBack(&sl, 555);
	SLPrintArray(&sl);//打印数组元素

	int x = 0;
	scanf("%d", &x);
	int pos = SLFind(&sl, x);//查找一个数x 返回其下标
	if (pos != -1)//判断是否找到这个数的下标
	{
		SLInsert(&sl, pos, 666);//在这个下标pos的位置，插入一个数据
	}
	SLPrintArray(&sl);//打印数组元素

	SLDestroy(&sl);//销毁顺序表
}


//测试给一个数据，查找它在有效数组的下标，并返回(删除这个任意位置(给的下标)的函数 一起使用的情况 )
void TestSeqList9()
{
	SL sl;//定义一个结构体类型的变量
	SLInit(&sl);//初始化，地址传递，才能改变实参
	SLPushBack(&sl, 1111);//尾插几个数
	SLPushBack(&sl, 2222);
	SLPushBack(&sl, 3333);
	SLPushBack(&sl, 4444);
	SLPushBack(&sl, 5555);
	SLPrintArray(&sl);//打印数组元素

	int x = 0;
	scanf("%d", &x);
	int pos = SLFind(&sl, x);//查找一个数x 返回其下标
	if (pos != -1)//判断是否找到这个数的下标
	{
		SLErase(&sl, pos);//在这个下标pos的位置，插入一个数据
	}
	SLPrintArray(&sl);//打印数组元素

	SLDestroy(&sl);//销毁顺序表
}


//测试给一个下标，找打这个下对对应的数据，然后用数据x修改( 内部有SLfind()函数 )
void TestSeqList10()
{
	SL sl;//定义一个结构体类型的变量
	SLInit(&sl);//初始化，地址传递，才能改变实参
	SLPushBack(&sl, 1111);//尾插几个数
	SLPushBack(&sl, 2222);
	SLPushBack(&sl, 3333);
	SLPushBack(&sl, 4444);
	SLPushBack(&sl, 5555);
	SLPrintArray(&sl);//打印数组元素

	int y = 0;//要修改的值
	int z = 0;//修改后的值
	printf("请输入你要修改的值和修改后的值：");
	scanf("%d%d", &y, &z);
	int pos = SLFind(&sl, y);//查找一个数y 返回其下标
	if (pos != -1)//判断是否找到这个数的下标
	{
		SLModify(&sl, pos, z);//给一个下标pos，找打这个下标对应的数据，然后用数据x修改
	}
	else
	{
		printf("没找到要修改的值\n");
	}
	SLPrintArray(&sl);//打印数组元素

	SLDestroy(&sl);//销毁顺序表
}

//int main()
//{
//	TestSeqList1();//测试初始化
//	TestSeqList2();//测试尾插
//	TestSeqList3();//测试头插
//	TestSeqList4();//测试尾删
//	TestSeqList5();//测试头删
//	TestSeqList6();//测试任意位置(给的下标) 插入 数据
//	TestSeqList7();//测试删除 这个任意位置(给的下标)
//	TestSeqList8();//测试给一个数据，查找它在有效数组的下标，并返回(和任意位置(给的下标)插入数据的函数 一起使用的情况 )
//	TestSeqList9();//测试给一个数据，查找它在有效数组的下标，并返回(删除这个任意位置(给的下标)的函数 一起使用的情况 )
//	TestSeqList10();//测试给一个下标，找打这个下标对应的数据，然后用数据x修改( 和SLfind()函数 一起使用 )
//	return 0;
//}


void menu()
{
	printf("**************************************************************\n");
	printf("******        1、初始化                2、尾插          ******\n");
	printf("******        3、头插                  4、尾删          ******\n");
	printf("******        5、头删                  6、随机插        ******\n");
	printf("******        7、随机删                8、查找并随机插  ******\n");
	printf("******        9、查找并随机删          10、修改         ******\n");
	printf("******        0、退出                                   ******\n");
	printf("**************************************************************\n");
}

int main()
{
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		getchar();//将缓冲区里的 回车 字符'\n' 接收掉
		switch (input)
		{
		case 1:
			TestSeqList1();//测试初始化
			break;
		case 2:
			TestSeqList2();//测试尾插
			break;
		case 3:
			TestSeqList3();//测试头插
			break;
		case 4:
			TestSeqList4();//测试尾删
			break;
		case 5:
			TestSeqList5();//测试头删
			break;
		case 6:
			TestSeqList6();//测试任意位置(给的下标) 插入 数据
			break;
		case 7:
			TestSeqList7();//测试删除 这个任意位置(给的下标)
			break;
		case 8:
			TestSeqList8();//测试给一个数据，查找它在有效数组的下标，并返回(和任意位置(给的下标)插入数据的函数 一起使用的情况 )
			break;
		case 9:
			TestSeqList9();//测试给一个数据，查找它在有效数组的下标，并返回(删除这个任意位置(给的下标)的函数 一起使用的情况 )
			break;
		case 10:
			TestSeqList10();//测试//给一个下标，找打这个下标对应的数据，然后用数据x修改( 和SLfind()函数 一起使用 )
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}

