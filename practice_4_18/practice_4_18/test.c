#define _CRT_SECURE_NO_WARNINGS 1


////https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/submissions/
//#include<stdio.h>
//
//int removeDuplicates(int* nums, int numsSize) {
//    if (numsSize == 0)//给的数组无元素，则直接返回，结束函数
//    {
//        return 0;
//    }
//
//    int tmp = numsSize;
//    int j = 1;//j从是下标，从1开始放
//    for (int i = 0; i < numsSize - 1; i++)
//    {
//        if (nums[i] == nums[i + 1])//相等就数组元素个数减1
//        {
//            tmp--;
//        }
//        else //不相等就将不等的那个值放进数组的前面
//        {
//            nums[j] = nums[i + 1];
//            j++;
//        }
//    }
//    return tmp;
//}
//
//int main()
//{
//    int arr[] = { 0,1,1,2,3,4,4,5,5,6,7 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int ret = removeDuplicates(arr, sz);
//    printf("%d\n", ret);
//
//    for (int i = 0; i < ret; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}



////https://leetcode-cn.com/problems/implement-strstr/submissions/
//int strStr(char* haystack, char* needle) {
//    if (*needle == '\0')
//        return 0;
//
//    char* s1 = NULL;
//    char* s2 = NULL;
//    //char* cp=haystack;
//    int i = 0;
//
//    while (*haystack)
//    {
//        //创建两个临时变量进行操作
//        s1 = haystack;  //s1=cp
//        s2 = needle;
//        while (*s1 && *s2 && (*s1 == *s2))
//        {
//            s1++;
//            s2++;
//        }
//        if (*s2 == '\0')
//        {
//            return i;
//        }
//        haystack++;  //cp++
//        i++;
//    }
//
//    return -1;
//}






#include<stdio.h>
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//// 选择排序之直接排序，时间复杂度O(N*N)
//// 很差，因为最好情况也是O(N*N)
//// N
//// N-2
//// N-4
//// ...
////第一个参数接收的是数组首元素地址，第二个参数接收的是数组元素个数
//void SelectSort(int* a, int n) //选择排序之直接排序
//{
//	int begin = 0, end = n - 1;//存放 第一个下标 和 最后一个下标
//
//	while (begin < end)//循环重复以下过程
//	{
//		int mini = begin, maxi = begin;//先定义 最小值的下标 和 最大值的下标 都是begin
//
//		for (int i = begin; i <= end; ++i)//将数组循环遍历一次，选出最大值的下标
//										   //和最小值的下标
//		{
//			if (a[i] <= a[mini])
//			{
//				mini = i;
//			}
//
//			if (a[i] >= a[maxi])
//			{
//				maxi = i;
//			}
//		}
//
//		Swap(&a[begin], &a[mini]);//将最小值放在第一个位置上
//
//		// 如果begin跟maxi重叠，需要修正一下maxi的位置
//		if (begin == maxi)
//		{
//			maxi = mini;
//		}
//
//		Swap(&a[maxi], &a[end]);//将最大值放在最后一个位置上
//
//		++begin;//向前走一位
//		--end;//向后退一位
//	}
//}
//
//int main()
//{
//	int arr[] = { 3,6,1,8,4,0,2,5 };
//	SelectSort(arr, 8);
//	for (int i = 0; i < 8; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}





#include<stdio.h>

//交换排序 之 冒泡排序
// 时间复杂度：O（N*N）
// 最好情况:O(N)
// N-1
// N-2
// ...
// 跟 插入排序 之 直接插入排序 相比？谁更好 -》 直接插入排序 更好
void BubbleSort(int* a, int n)
{
	//比如10个数，只需要冒泡排序9次，因为经过9次,最后一个数就不用冒泡了，它已经是最小的(排升序)
	for (int i = 0; i < n - 1; i++)//或者是最大的(排降序)				   
	{
		int exchange = 0;//定义这个是看有没有进入冒泡排序里改变它本身的值，如果没有改变
						 //说明这一趟遍历并没有元素的交换，说明已经排好了

        //这里还要减1是因为第一个数只需要和后几个数比较交换，减i是因为排好一个，这个数就不用参与了
		for (int j = 0; j < n - i - 1; j++)//这里我们选择排升序，降序就是小于嘛
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				exchange = 1;//有元素的交换，说明还没有排好；如果没有进入if内部
							 //说明没有元素交换，即已经排号
			}
		}

		if (exchange == 0)//如果没有元素交换，那么exchange就不会改变，说明已经排好
						  //就不用继续排了，直接break跳出循环
		{
			break;
		}
	}
}

int main()
{
	int arr[] = { 3,6,1,8,4,0,2,5 };
	BubbleSort(arr, 8);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


//选择排序 之 直接排序 , 交换排序 之 冒泡排序