#include <iostream>
#include<vector>
#include<list>
using namespace std;

#include"Stack.h"
#include"Queue.h"

//测试模拟实现的stack
void test_stack()
{
	//用的模拟实现stack，这样的一个适配器
	//底层容器不管是vector还是list都是可以的
	jh::stack<int,vector<int>> st;
	jh::stack<int, list<int>> st2;
	jh::stack<int> st3;//不传具体的容器就用默认的容器deque

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


//测试模拟实现的queue
void test_queue()
{
	//用的模拟实现queue，这样的一个适配器
	//底层容器list是可以的,但是容器vector不支持，因为vector没有pop_front，
	//因为vector的pop_front效率太低了，所以没有设计这个接口
	jh::queue<int, list<int>> q;
	jh::queue<int> q1;//不传具体的容器就用默认的容器deque

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
//仿函数less和greater在头文件是functional
#include <functional>
using namespace std;

#include"PriorityQueue.h"

//测试模拟实现的priority_queue
void test_priority_queue()
{
	// 默认大的优先级高
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
	//priority_queue底层容器是vector，在vector上又使用堆算法使vector中的元素
	//构造成堆的结构，所以priority_queue就是一个堆，默认是大堆，
	//所以这里类类型priority_queue的对象heap创建出来就是一个大堆
	//第二个模板容器参数没给的话，用默认的容器vector
	//第三个模板参数Compare(进行比较的仿函数)没给的话，用默认的仿函数less建立大堆
	jh::priority_queue<int> heap(a, a+sizeof(a)/sizeof(int));

	//将第三个模板参数Compare(进行比较的仿函数)换成仿函数greater<int>，创建成小堆了，
	//所以这里类类型priority_queue的对象heap1创建出来就是一个小堆
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










// //仿函数是函数对象  -- 即仿函数也是一种类，它是通过重载operator()来实现功能的
// //通过重载operator()，重载了括号这个操作符，所以这个 仿函数类对象 可以像函数一样去使用
////下面我们通过模实现来理解一下
//namespace jh
//{
//	//类类型less，所以仿函数就是一种类
//	template<class T>
//	class less
//	{
//	public:
//		//加const更好
//		bool operator()(const T& l, const T& r) const
//		{
//			return l < r;
//		}
//	};
//
//
//	//类类型greater，所以仿函数就是一种类
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
//	//创建了类类型less的对象
//	jh::less<int> lsFunc;
//
//	cout << lsFunc(1, 2) << endl;
//	// 等价于下面，理解不了的时候，想象出重载的操作符()
//	//cout << lsFunc.operator()(1, 2) << endl;
//
//
//	//创建了类类型greater的对象
//	jh::greater<int> gtFunc;
//
//	cout << gtFunc(1, 2) << endl;
//	// 等价于下面，理解不了的时候，想象出重载的操作符()
//	//cout << gtFunc.operator()(1, 2) << endl;
//
//	return 0;
//}