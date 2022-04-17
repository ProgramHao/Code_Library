#define _CRT_SECURE_NO_WARNINGS 1


//模拟实现atoi


//int my_atoi(const char* str)
//{
//	int n = 0;
//	while (*str)
//	{
//		n = n * 10 + *str-'0';//'3'-'0'==>51-48 = 3
//		str++;
//	}
//	return n;
//}

//空指针
//空字符串
//非数字字符
//前面有空白字符
//前面有+-
//溢出

//#include<stdio.h>
//#include <assert.h>
//#include <ctype.h> //是函数isspace()和函数isdigit()的头文件
//#include <limits.h> //INT_MIN和INT_MAX 的头文件
//       //代表的是 整型的最小值 整型的最大值
//
//enum Status
//{
//	VALID,
//	INVALID
//}status = INVALID;//非法
////定义一个枚举类型的变量status
//
//int my_atoi(const char* str)
//{
//	int flag = 1;
//	//空指针
//	assert(str);
//
//	//字符串为空
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	//空白字符
//	while(isspace(*str))//函数isspace()是判断是否有空格
//	{ 
//		str++;
//	}
//	//正负号
//	if (*str == '+')
//	{
//		flag = 1;
//		str++;
//	}
//	else if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//
//	long long n = 0;//因为n可能会越界，所以用8个字节的long long类型先存储
//	                //方便和 INT_MIN 或 INT_MAX 作比较
//	while (*str != '\0')
//	{
//		if (isdigit((int)(*str)))//函数isdigit()判断一个字符是否为数字字符
//		{
//			n = n * 10 + flag * (*str - '0');//如字符串为"1234"  1  12   123  1234
//			if (n < INT_MIN)
//			{
//				n = INT_MIN;
//				break;
//			}
//			if(n > INT_MAX)
//			{
//				n = INT_MAX;
//				break;
//			}
//		}
//		else //字符不是数字字符，则直接跳出循环，后面的字符就不再继续转换
//		{
//			break;
//		}
//		str++;
//	}
//	 
//	//如果一个字符串 是 转换到字符串的 结束标志 字符'\0'，那么就是 完全转换，可以认为是 正常转化
//	//如果一个字符串 不是 转换到字符串的 结束标志 字符'\0'，那么就是 不完全转换，可以认为是 非法转化
//	if (*str == '\0')
//	{
//		status = VALID;
//	}
//
//	return (int)n;//因为定义的函数返回的类型是int，而这个的返回值的类型是long long，所以强制类型转换(int)
//}
//
////库函数atio()，将如字符串"1234"转换为数字：1234；"123a45"----123; "-123wde556"--- -123; "  -  123se 45"-----  0; ""--- 0  
//                                                //"12 3a5"---12;   "    12"-----12;     "    12 345"----12
//int main()
//{
//	char arr[100] = "    12 345";
//	int ret = my_atoi(arr);
//	if(status == VALID)
//		printf("正常转化：%d\n", ret);
//	else
//		printf("非法转化：%d\n", ret);
//	return 0;
//}



// 插入排序
// 时间复杂度是多少？O(N^2)
// 什么情况下最坏？逆序  1+2+3+...+n-1
// 什么情况下最好？顺序有序  O(N)
void InsertSort(int* a, int n)
{
	// [0, end]有序  end+1位置的值插入[0, end]，让[0, end+1]有序
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}



// 直接插入排序的基础上的优化
// 1、先进行预排序，让数组接近有序
// 2、直接插入排序
// 时间复杂度：O(logN*N) 或者 O(log3N*N)
// 平均的时间复杂度是O(N^1.3)
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		//gap = gap / 2;  // logN
		gap = gap / 3 + 1; // log3N 以3为底数的对数
		// gap > 1时都是预排序  接近有序
		// gap == 1时就是直接插入排序 有序

		// gap很大时，下面预排序时间复杂度O(N)
		// gap很小时，数组已经很接近有序了，这时差不多也是(N)

		// 把间隔为gap的多组数据同时排
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

