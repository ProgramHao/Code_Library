#include <iostream>
#include<vector>
#include<list>
using namespace std;

#include"Stack.h"
#include"Queue.h"

//����ģ��ʵ�ֵ�stack
void test_stack()
{
	//�õ�ģ��ʵ��stack��������һ��������
	//�ײ�����������vector����list���ǿ��Ե�
	jh::stack<int,vector<int>> st;
	jh::stack<int, list<int>> st2;
	jh::stack<int> st3;//�����������������Ĭ�ϵ�����deque

	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
}


//����ģ��ʵ�ֵ�queue
void test_queue()
{
	//�õ�ģ��ʵ��queue��������һ��������
	//�ײ�����list�ǿ��Ե�,��������vector��֧�֣���Ϊvectorû��pop_front��
	//��Ϊvector��pop_frontЧ��̫���ˣ�����û���������ӿ�
	jh::queue<int, list<int>> q;
	jh::queue<int> q1;//�����������������Ĭ�ϵ�����deque

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
}

#include <iostream>
#include<vector>
//�º���less��greater��ͷ�ļ���functional
#include <functional>
using namespace std;

#include"PriorityQueue.h"

//����ģ��ʵ�ֵ�priority_queue
void test_priority_queue()
{
	// Ĭ�ϴ�����ȼ���
	jh::priority_queue<int> pq;

	pq.push(3);
	pq.push(1);
	pq.push(2);
	pq.push(5);
	pq.push(0);
	pq.push(1);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	int a[] = { 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
	//priority_queue�ײ�������vector����vector����ʹ�ö��㷨ʹvector�е�Ԫ��
	//����ɶѵĽṹ������priority_queue����һ���ѣ�Ĭ���Ǵ�ѣ�
	//��������������priority_queue�Ķ���heap������������һ�����
	//�ڶ���ģ����������û���Ļ�����Ĭ�ϵ�����vector
	//������ģ�����Compare(���бȽϵķº���)û���Ļ�����Ĭ�ϵķº���less�������
	jh::priority_queue<int> heap(a, a+sizeof(a)/sizeof(int));

	//��������ģ�����Compare(���бȽϵķº���)���ɷº���greater<int>��������С���ˣ�
	//��������������priority_queue�Ķ���heap1������������һ��С��
	jh::priority_queue<int, vector<int>, greater<int>> heap1(a, a + sizeof(a) / sizeof(int));
	
	while (!heap.empty())
	{
		cout << heap.top() << " ";
		heap.pop();
	}
	cout << endl;
}

int main()
{
	//test_stack();
	//test_queue();
	test_priority_queue();

	return 0;
}










// //�º����Ǻ�������  -- ���º���Ҳ��һ���࣬����ͨ������operator()��ʵ�ֹ��ܵ�
// //ͨ������operator()������������������������������ �º�������� ��������һ��ȥʹ��
////��������ͨ��ģʵ�������һ��
//namespace jh
//{
//	//������less�����Էº�������һ����
//	template<class T>
//	class less
//	{
//	public:
//		//��const����
//		bool operator()(const T& l, const T& r) const
//		{
//			return l < r;
//		}
//	};
//
//
//	//������greater�����Էº�������һ����
//	template<class T>
//	class greater
//	{
//	public:
//		bool operator()(const T& l, const T& r) const
//		{
//			return l > r;
//		}
//	};
//}
//
//int main()
//{
//	//������������less�Ķ���
//	jh::less<int> lsFunc;
//
//	cout << lsFunc(1, 2) << endl;
//	// �ȼ������棬��ⲻ�˵�ʱ����������صĲ�����()
//	//cout << lsFunc.operator()(1, 2) << endl;
//
//
//	//������������greater�Ķ���
//	jh::greater<int> gtFunc;
//
//	cout << gtFunc(1, 2) << endl;
//	// �ȼ������棬��ⲻ�˵�ʱ����������صĲ�����()
//	//cout << gtFunc.operator()(1, 2) << endl;
//
//	return 0;
//}