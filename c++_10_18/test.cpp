

#include <iostream>
#include <string>
using namespace std;

//class Time
//{
//public:
//
//	//���� ���� Ĭ�Ϲ��캯������Ϊ����Ĺ��캯��Ҫ���ݲ���
//	Time(int hour)
//	{
//		_hour = hour;
//	}
//
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	// Ҫ��ʼ��_t ���󣬱���ͨ����ʼ���б�
//	Date(int year, int hour, int& x)
//		:_t(hour)
//		, _N(10)
//		, _ref(x)
//	{
//		// �������ڳ�ʼ��
//		_year = year;
//		_ref++;
//	}
//private:
//	int _year;
//	Time _t;
//	const int _N;//const�����ڶ���ĵط���ʼ����ֻ��һ�λ���
//	int& _ref;//�����ڶ����ʱ��ҲҪ��ʼ��
//};
//
//int main()
//{
//	int y = 0;
//	Date d(2022, 1, y);
//
//	return 0;
//}



//class Time
//{
//public:
//	Time(int hour = 0)
//	{
//		_hour = hour;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	// Ҫ��ʼ��_t ���󣬿����ٺ������ڸ�ֵ�����ǻ��ǻ��߳�ʼ���б����Time��Ĭ�Ϲ���
//	//Date(int year, int hour)
//	//{
//	//	// �������ڳ�ʼ��
//	//	_year = year;
//	//	Time t(hour);
//	//	_t = t;
//	//}
//
//
//	Date(int year, int hour, int& x)
//		:_t(hour)
//		, _N(10)
//		, _ref(x)
//	{
//		// �������ڳ�ʼ��
//		_year = year;
//		_ref++;
//	}
//private:
//	int _year;
//	Time _t;
//	const int _N;
//	int& _ref;
//};
//
//// ���ۣ��Զ������ͳ�Ա���Ƽ��ó�ʼ���б��ʼ��
//// ��ʼ���б������Ϊ�ǳ�Ա��������ĵط�
//
//int main()
//{
//	int y = 0;
//	Date d(2022, 1, y);
//	//const int N; // const�����ڶ���ĵط���ʼ����ֻ��һ�λ���
//
//	return 0;
//}


// ���ۣ��Զ������ͳ�Ա���Ƽ��ó�ʼ���б��ʼ��
//// ��ʼ���б������Ϊ�ǳ�Ա��������ĵط�
//class Time
//{
//public:
//	Time(int hour = 0)
//	{
//		_hour = hour;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//
//	//�Զ���Ĺ��캯��
//	Date(int year, int hour, int& x)
//		:_t(hour)
//		,_N(10)
//		, _ref(x)
//	{
//		// �������ڳ�ʼ��
//		//_year = year;
//		_ref++;
//	}
//private:
//	// ����
//	int _year = 0;  // C++11  ȱʡֵ-- ��ʼ��ʱû����ʾ��ֵ�ͻ������ȱʡֵ
//	Time _t;
//	const int _N;
//	int& _ref;
//};
//
//int main()
//{
//	int y = 0;
//	Date d(2022, 1, y);
//
//	return 0;
//}


//class A
//{
//public:
//	/*A(int N)
//		:_a((int*)malloc(sizeof(int)*N))//��ʼ���б� �ǿ���ʹ�ú�����
//		, _N(N)
//	{
//		//��������
//		if (_a == NULL)
//		{
//			perror("malloc fail");
//		}
//		memset(_a, 0, sizeof(int)*N);
//	}*/
//
//	// ��Щ��ʼ���������Ǳ����ں����������
//	A(int N)
//		:_N(N)
//	{
//		//��������
//		_a = (int*)malloc(sizeof(int)*N);
//		if (_a == NULL)
//		{
//			perror("malloc fail");
//		}
//		memset(_a, 0, sizeof(int)*N);
//	}
//private:
//	// ����
//	int* _a;
//	int _N;
//};
//
//int main()
//{
//	A aa(10);
//
//	return 0;
//}


//// explicit�ؼ��� + ��������
//class Date
//{
//public:
//	explicit Date(int year)
//		:_year(year)
//	{
//		cout << "	Date(int year)" << endl;
//	}
//
//private:
//	int _year;
//};
//
//
//int main()
//{
//	Date d1(2022);  // ֱ�ӵ��ù���
//	Date d2 = 2022; // ��ʽ����ת�������� + �������� + �������Ż� -> ֱ�ӵ��ù��� 
//	const Date& d3 = 2022;
//
//	int i = 10;
//	double a = 20;
//	const double& d = i;
//
//	return 0;
//}



//// explicit�ؼ��� + ��������
//class Date
//{
//public:
//	//explicit Date(int year)
//	Date(int year)
//		:_year(year)
//	{
//		cout << "	Date(int year)" << endl;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//};
//
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		// ...
//		return 0;
//	}
//};
//
//int main()
//{
//	Date d1(2022);  // ֱ�ӵ��ù���
//	Date d2 = 2022; // ��ʽ����ת�������� + �������� + �������Ż� -��ֱ�ӵ��ù��� 
//	const Date& d3 = 2022;
//
//	int i = 10;
//	const double& d = i;
//
//	// �������� -- ��������ֻ����һ��
//	Date(2000);
//
//	Date d4(2000);
//
//	// �������� һЩʹ�ó���
//	Solution slt;
//	slt.Sum_Solution(10);
//	Solution().Sum_Solution(10);
//
//	return 0;
//}



//class A
//{
//public:
//	A() 
//	{ ++_scount; }
//
//	A(const A& t) { ++_scount; }
//
//
////private:
//	static int _scount;  // ����
//};
//
//// �����涨���ʼ��
//int A::_scount = 0;
//
//int main()
//{
//	A a1;
//	A a2;
// 
//	cout << a1._scount << endl;
//	cout << a2._scount << endl;
//	cout << A::_scount << endl;
//
//	return 0;
//}
//
//

//class A
//{
//public:
//	A() 
//	{ ++_scount; }
//
//	A(const A& t) { ++_scount; }
//
//	 ��̬��Ա���� --  û��thisָ��
//	static int GetCount()
//	{
//
//		return _scount;
//	}
//
//private:
//	 ��̬��Ա���������������࣬���������������������ڼ䣬���ھ�̬ȡ
//	static int _scount;  // ����
//};
//
// �����涨���ʼ��
//int A::_scount = 0;
//
//int main()
//{
//	A a1;
//	A a2;
//
//	cout <<A::GetCount() << endl;
//
//	return 0;
//}



////// ���һ��ֻ����ջ�϶���������
//class StackOnly
//{
//public:
//	//��̬��Ա����-----û��thisָ��
//	static StackOnly CreateObj()
//	{
//		StackOnly so;
//		return so;
//	}
//
//private:
//	StackOnly(int x = 0, int y = 0)
//		:_x(x)
//		, _y(0)
//	{}
//private:
//	int _x = 0;
//	int _y = 0;
//};
//
//int main()
//{
//	//StackOnly so1; // ջ
//	//static StackOnly so2; // ��̬��
//	StackOnly so3 = StackOnly::CreateObj();
//
//	return 0;
//}



//
///////////////////////////////////////////////////////////////////////////////////////////
// �ڲ���
//class A
//{
//private:
//	int _h;
//	static int k;
//public:
//	 B������A������
//	 1����A���������ƣ������޶���
//	 2��B������A����Ԫ
//	class B
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a._h << endl;//OK -- ��Ԫ
//		}
//	private:
//		int _b;
//	};
//};
//int A::k = 1;
//
//int main()
//{
//	cout << sizeof(A) << endl; // 4
//	A a;
//	A::B b;
//
//	return 0;
//}




class W
{
public:
	//���캯��
	W(int x = 0)
	{
		cout << "W()" << endl;
	}

	//�������캯��
	W(const W& w)
	{
		cout << "W(const W& w)" << endl;
	}

	//��������� =
	W& operator=(const W& w)
	{
		cout << "W& operator=(const W& w)" << endl;
		return *this;
	}

	//��������
	~W()
	{
		cout << "~W()" << endl;
	}
};

//��ֵ���Σ������𿽱����캯��
void f1(W w)
{

}

//�����ô��Σ��������𿽱����캯��
void f2(const W& w)
{

}

//��ֵ���أ������𿽱�����
W f3()
{
	W ret;//����
	return ret;//��ֵ���أ������𿽱�����
}

int main()
{
	W w1;
	f1(w1);
	f2(w1);
	cout << endl << endl;

	f1(W()); //W()����������  ��������+��������--���������Ż�--ֱ�ӹ���
	// ���ۣ�����һ�����ʽ�����У���������(��Ϊ��������Ҳ�ǹ���)һ�㶼���Ż� -- �϶�Ϊһ

	W w2 = 1;//����Ҳ�Ǳ������Ż�����Ϊ����ʱ������Ҳ���������� ��Ϊ�������Ż�---ֱ�ӹ���


	cout << endl << endl;

	f3();
	return 0;
}




// �����̽��C++����ģ�͡�
//int main()
//{
//	f3(); // 1�ι���  1�ο���
//	cout << endl << endl;
//
//	W w1 = f3(); // ������1�ι���  2�ο��� -- �Ż���1�ι���  1�ο���
//
//	cout << endl << endl;
//
//	W w2;
//	w2 = f3(); // ������1�ι���  1�ο��� 1�θ�ֵ
//
//	return 0;
//}

//W f(W u)
//{
//	//cout << "--------" << endl;
//	W v(u);
//	W w = v;
//	//cout << "--------" << endl;
//	return w;
//}
//
//int main()
//{
//	W x;
//	W y = f(f(x)); // 1�ι���  7�ο���  or  1�ι���  5�ο���
//
//	return 0;
//}

//int main()
//{
//	W x;
//	W y = f(x); // 1�ι���  4�ο���
//
//	return 0;
//}