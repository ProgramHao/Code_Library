#define _CRT_SECURE_NO_WARNINGS 1


////https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/submissions/
//#include<stdio.h>
//
//int removeDuplicates(int* nums, int numsSize) {
//    if (numsSize == 0)//����������Ԫ�أ���ֱ�ӷ��أ���������
//    {
//        return 0;
//    }
//
//    int tmp = numsSize;
//    int j = 1;//j�����±꣬��1��ʼ��
//    for (int i = 0; i < numsSize - 1; i++)
//    {
//        if (nums[i] == nums[i + 1])//��Ⱦ�����Ԫ�ظ�����1
//        {
//            tmp--;
//        }
//        else //����Ⱦͽ����ȵ��Ǹ�ֵ�Ž������ǰ��
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
//        //����������ʱ�������в���
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


//// ѡ������ֱ֮������ʱ�临�Ӷ�O(N*N)
//// �ܲ��Ϊ������Ҳ��O(N*N)
//// N
//// N-2
//// N-4
//// ...
////��һ���������յ���������Ԫ�ص�ַ���ڶ����������յ�������Ԫ�ظ���
//void SelectSort(int* a, int n) //ѡ������ֱ֮������
//{
//	int begin = 0, end = n - 1;//��� ��һ���±� �� ���һ���±�
//
//	while (begin < end)//ѭ���ظ����¹���
//	{
//		int mini = begin, maxi = begin;//�ȶ��� ��Сֵ���±� �� ���ֵ���±� ����begin
//
//		for (int i = begin; i <= end; ++i)//������ѭ������һ�Σ�ѡ�����ֵ���±�
//										   //����Сֵ���±�
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
//		Swap(&a[begin], &a[mini]);//����Сֵ���ڵ�һ��λ����
//
//		// ���begin��maxi�ص�����Ҫ����һ��maxi��λ��
//		if (begin == maxi)
//		{
//			maxi = mini;
//		}
//
//		Swap(&a[maxi], &a[end]);//�����ֵ�������һ��λ����
//
//		++begin;//��ǰ��һλ
//		--end;//�����һλ
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

//�������� ֮ ð������
// ʱ�临�Ӷȣ�O��N*N��
// ������:O(N)
// N-1
// N-2
// ...
// �� �������� ֮ ֱ�Ӳ������� ��ȣ�˭���� -�� ֱ�Ӳ������� ����
void BubbleSort(int* a, int n)
{
	//����10������ֻ��Ҫð������9�Σ���Ϊ����9��,���һ�����Ͳ���ð���ˣ����Ѿ�����С��(������)
	for (int i = 0; i < n - 1; i++)//����������(�Ž���)				   
	{
		int exchange = 0;//��������ǿ���û�н���ð��������ı��������ֵ�����û�иı�
						 //˵����һ�˱�����û��Ԫ�صĽ�����˵���Ѿ��ź���

        //���ﻹҪ��1����Ϊ��һ����ֻ��Ҫ�ͺ󼸸����ȽϽ�������i����Ϊ�ź�һ����������Ͳ��ò�����
		for (int j = 0; j < n - i - 1; j++)//��������ѡ�������򣬽������С����
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				exchange = 1;//��Ԫ�صĽ�����˵����û���źã����û�н���if�ڲ�
							 //˵��û��Ԫ�ؽ��������Ѿ��ź�
			}
		}

		if (exchange == 0)//���û��Ԫ�ؽ�������ôexchange�Ͳ���ı䣬˵���Ѿ��ź�
						  //�Ͳ��ü������ˣ�ֱ��break����ѭ��
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


//ѡ������ ֮ ֱ������ , �������� ֮ ð������