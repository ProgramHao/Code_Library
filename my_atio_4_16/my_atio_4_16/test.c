#define _CRT_SECURE_NO_WARNINGS 1


//ģ��ʵ��atoi


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

//��ָ��
//���ַ���
//�������ַ�
//ǰ���пհ��ַ�
//ǰ����+-
//���

//#include<stdio.h>
//#include <assert.h>
//#include <ctype.h> //�Ǻ���isspace()�ͺ���isdigit()��ͷ�ļ�
//#include <limits.h> //INT_MIN��INT_MAX ��ͷ�ļ�
//       //������� ���͵���Сֵ ���͵����ֵ
//
//enum Status
//{
//	VALID,
//	INVALID
//}status = INVALID;//�Ƿ�
////����һ��ö�����͵ı���status
//
//int my_atoi(const char* str)
//{
//	int flag = 1;
//	//��ָ��
//	assert(str);
//
//	//�ַ���Ϊ��
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	//�հ��ַ�
//	while(isspace(*str))//����isspace()���ж��Ƿ��пո�
//	{ 
//		str++;
//	}
//	//������
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
//	long long n = 0;//��Ϊn���ܻ�Խ�磬������8���ֽڵ�long long�����ȴ洢
//	                //����� INT_MIN �� INT_MAX ���Ƚ�
//	while (*str != '\0')
//	{
//		if (isdigit((int)(*str)))//����isdigit()�ж�һ���ַ��Ƿ�Ϊ�����ַ�
//		{
//			n = n * 10 + flag * (*str - '0');//���ַ���Ϊ"1234"  1  12   123  1234
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
//		else //�ַ����������ַ�����ֱ������ѭ����������ַ��Ͳ��ټ���ת��
//		{
//			break;
//		}
//		str++;
//	}
//	 
//	//���һ���ַ��� �� ת�����ַ����� ������־ �ַ�'\0'����ô���� ��ȫת����������Ϊ�� ����ת��
//	//���һ���ַ��� ���� ת�����ַ����� ������־ �ַ�'\0'����ô���� ����ȫת����������Ϊ�� �Ƿ�ת��
//	if (*str == '\0')
//	{
//		status = VALID;
//	}
//
//	return (int)n;//��Ϊ����ĺ������ص�������int��������ķ���ֵ��������long long������ǿ������ת��(int)
//}
//
////�⺯��atio()�������ַ���"1234"ת��Ϊ���֣�1234��"123a45"----123; "-123wde556"--- -123; "  -  123se 45"-----  0; ""--- 0  
//                                                //"12 3a5"---12;   "    12"-----12;     "    12 345"----12
//int main()
//{
//	char arr[100] = "    12 345";
//	int ret = my_atoi(arr);
//	if(status == VALID)
//		printf("����ת����%d\n", ret);
//	else
//		printf("�Ƿ�ת����%d\n", ret);
//	return 0;
//}



// ��������
// ʱ�临�Ӷ��Ƕ��٣�O(N^2)
// ʲô������������  1+2+3+...+n-1
// ʲô�������ã�˳������  O(N)
void InsertSort(int* a, int n)
{
	// [0, end]����  end+1λ�õ�ֵ����[0, end]����[0, end+1]����
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



// ֱ�Ӳ�������Ļ����ϵ��Ż�
// 1���Ƚ���Ԥ����������ӽ�����
// 2��ֱ�Ӳ�������
// ʱ�临�Ӷȣ�O(logN*N) ���� O(log3N*N)
// ƽ����ʱ�临�Ӷ���O(N^1.3)
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		//gap = gap / 2;  // logN
		gap = gap / 3 + 1; // log3N ��3Ϊ�����Ķ���
		// gap > 1ʱ����Ԥ����  �ӽ�����
		// gap == 1ʱ����ֱ�Ӳ������� ����

		// gap�ܴ�ʱ������Ԥ����ʱ�临�Ӷ�O(N)
		// gap��Сʱ�������Ѿ��ܽӽ������ˣ���ʱ���Ҳ��(N)

		// �Ѽ��Ϊgap�Ķ�������ͬʱ��
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

