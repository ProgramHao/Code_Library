#include<iostream>
#include<assert.h>
using namespace std;

//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//
//	A(const A& t)
//	{
//		++_scount;
//	}
//
//private:
//	static int _scount;//����
//};
//
////��̬��Ա���� �����ⶨ���ʼ��,
//int A::_scount = 0;
//
//int main()
//{
//	A a1;
//	A a2;
//
//	return 0;
//}
//
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//
//	}
//
//	//d1 << cout;->d1.operator<<(&d1,cout);�����ϳ������
//	//��Ϊ��Ա������һ������һ�������ص�this������d1�������<<�����
//	ostream& operator<<(ostream& _cout)
//	{
//		_cout << _year << "-" << _month << "-" << _day << endl;
//		return _cout;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Date
//{
//	friend ostream& operator<<(ostream& _cout��const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//private:
//	int _year; 
//	int _month; 
//	int _day;
//};
//
//ostream& operator<<(ostream& _cout, const Date& d) {
//	_cout < d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//	
//istream& operator>>(istream& _cin, Date& d) {
//	cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//
//int main()
//{
//	Date d; 
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}


//class Time 
//{
//	friend class Date;//����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second) {
//	}
//private:
//	int _hour; 
//	int _minute; 
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTimeOfDate(int hour, int minute��int second)
//	{
//		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year; 
//	int _month; 
//	int _day; 
//	Time _t; 
//};




//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p1 = new A;
//
//	A* p2 = (A*)malloc(sizeof(A));
//	if (p2 == nullptr)
//	{
//		perror("malloc fail");
//	}
//	//new(p2)A; ��ʽ1
//	new(p2)A(10); //��ʽ2
//
//	return 0;
//}


 //���ͱ�� -- ģ��
 //ģ�����(ģ������) -- ���ƺ�������(��������)
 //typename������������T�����ȡ��Ty��K��V��һ���Ǵ�д��ĸ���ߵ�������ĸ��д
 //T ������һ��ģ������(��������)
//template<typename T>  //�����ùؼ���class��û������ template<class T>
//void Swap(T& left, T& right)
//{
//	T tmp = left;
//	left = right;
//	right = tmp;
//}

//int main()
//{
//	int i = 1, j = 2;
//	double x = 1.1, y = 2.2;
//	swap(i, j);
//	swap(x, y);
//
//	char m = 'A', n = 'B';
//	swap(m, n);
//
//	//map<string, string>::iterator it = dict.begin();
//	//auto it = dict.begin();
//
//	return 0;
//}



////��c++�����վ
//// https://cplusplus.com/reference/
//// https://en.cppreference.com/w/  �ٷ�
//
//// c++������,�Ѿ�д����swap����������ֱ����
//int main()
//{
//	int i = 1, j = 2;
//	double x = 1.1, y = 2.2;
//	swap(i, j);
//	swap(x, y);
//
//	char m = 'A', n = 'B';
//	swap(m, n);
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//template<class T>
//T* Func(int n)
//{
//	T* a = new T[n];
//	return a;
//}
//
//int main()
//{
//	// Add(1.1, 2); // ����ʵ����ì�ܣ�����
//
//	//// �������Զ����ݣ���ʽʵ����
//	//cout << Add(1, 2) << endl;
//	//cout << Add((int)1.1, 2) << endl;
//	//cout << Add(1.1, (double)2) << endl;
//
//	//// ��ʾʵ����
//	//cout << Add<int>(1.1, 2) << endl;
//	//cout << Add<double>(1.1, 2) << endl;
//
//	// ������ʾʵ�������ܵ���
//	Func<A>(10);
//
//	return 0;
//}




//typedef char STDataType;
//class Stack
//{
//private:
//	STDataType* _a;
//	int top;
//	int capacity;
//};
//
//class Stacki
//{
//private:
//	int* _a;
//	int top;
//	int capacity;
//};
//
//class Stackc
//{
//private:
//	char* _a;
//	int top;
//	int capacity;
//};
//
//int main()
//{
//	Stackc st1; // char
//	Stacki st2; // int
//
//	return 0;
//}

template<typename T>
class Stack
{
public:
	//���캯��
	Stack(size_t capacity = 4)
		:_a(nullptr)
		, _top(0)
		, _capacity(0)
	{
		if (capacity > 0)
		{
		_a = new T[capacity];
		_capacity = capacity;
		_top = 0;
		}
	}


	~Stack()
	{
		delete[] _a;
		_a = nullptr;
		_capacity = _top = 0;
	}


	void Push(const T& x);


	void Pop()
	{
		assert(_top > 0);
		--_top;
	}


	bool Empty()
	{
		return _top == 0;
	}


	const T& Top()
	{
		assert(_top > 0);

		return _a[_top - 1];
	}


private:
	T* _a;
	size_t _top;
	size_t _capacity;
};

// ģ�岻֧�ַ�����롣 ������������.h  �������.cpp�ǲ��е� -- ԭ��ģ������ٽ���
// ģ����ͬһ���ļ��У��ǿ��������Ͷ�������

template<class T>
void Stack<T>::Push(const T& x)
{
	if (_top == _capacity)
	{
		size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
		// 1�����¿ռ�
		// 2����������
		// 3���ͷžɿռ�
		T* tmp = new T[newCapacity];
		if (_a)
		{
			memcpy(tmp, _a, sizeof(T)*_top);
			delete[] _a;
		}

		_a = tmp;
		_capacity = newCapacity;
	}

	_a[_top] = x;
	++_top;
}

int main()
{
	//��ģ�嶼����ʾʵ����
	//��Ȼ���Ƕ�������һ��ģ�壬����Stack<int>��Stack<char> ����������
	Stack<char> st1; // char
	Stack<int> st2; // int

	return 0;
}