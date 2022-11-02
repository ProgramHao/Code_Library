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
//	static int _scount;//声明
//};
//
////静态成员函数 在类外定义初始化,
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
//	//d1 << cout;->d1.operator<<(&d1,cout);不符合常规调用
//	//因为成员函数第一个参数一定是隐藏的this，所以d1必须放在<<的左侧
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
//	friend ostream& operator<<(ostream& _cout，const Date& d);
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
//	friend class Date;//声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
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
//	void SetTimeOfDate(int hour, int minute，int second)
//	{
//		// 直接访问时间类私有的成员变量
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
//	//new(p2)A; 格式1
//	new(p2)A(10); //格式2
//
//	return 0;
//}


 //泛型编程 -- 模板
 //模板参数(模板类型) -- 类似函数参数(参数对象)
 //typename后面类型名字T是随便取，Ty、K、V，一般是大写字母或者单词首字母大写
 //T 代表是一个模板类型(虚拟类型)
//template<typename T>  //或者用关键字class，没有区别 template<class T>
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



////查c++库的网站
//// https://cplusplus.com/reference/
//// https://en.cppreference.com/w/  官方
//
//// c++库里面,已经写好了swap函数，可以直接用
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
//	// Add(1.1, 2); // 推演实例化矛盾，报错
//
//	//// 编译器自动推演，隐式实例化
//	//cout << Add(1, 2) << endl;
//	//cout << Add((int)1.1, 2) << endl;
//	//cout << Add(1.1, (double)2) << endl;
//
//	//// 显示实例化
//	//cout << Add<int>(1.1, 2) << endl;
//	//cout << Add<double>(1.1, 2) << endl;
//
//	// 必须显示实例化才能调用
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
	//构造函数
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

// 模板不支持分离编译。 比如声明放在.h  定义放在.cpp是不行的 -- 原因：模板进阶再讲解
// 模板在同一个文件中，是可以声明和定义分离的

template<class T>
void Stack<T>::Push(const T& x)
{
	if (_top == _capacity)
	{
		size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
		// 1、开新空间
		// 2、拷贝数据
		// 3、释放旧空间
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
	//类模板都是显示实例化
	//虽然他们都是用了一个模板，但是Stack<int>，Stack<char> 是两个类型
	Stack<char> st1; // char
	Stack<int> st2; // int

	return 0;
}