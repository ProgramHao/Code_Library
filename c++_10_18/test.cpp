

#include <iostream>
#include <string>
using namespace std;

//class Time
//{
//public:
//
//	//这里 不是 默认构造函数，因为这里的构造函数要传递参数
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
//	// 要初始化_t 对象，必须通过初始化列表
//	Date(int year, int hour, int& x)
//		:_t(hour)
//		, _N(10)
//		, _ref(x)
//	{
//		// 函数体内初始化
//		_year = year;
//		_ref++;
//	}
//private:
//	int _year;
//	Time _t;
//	const int _N;//const必须在定义的地方初始化，只有一次机会
//	int& _ref;//引用在定义的时候也要初始化
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
//	// 要初始化_t 对象，可以再函数体内赋值，但是还是会走初始化列表调用Time的默认构造
//	//Date(int year, int hour)
//	//{
//	//	// 函数体内初始化
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
//		// 函数体内初始化
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
//// 结论：自定义类型成员，推荐用初始化列表初始化
//// 初始化列表可以认为是成员变量定义的地方
//
//int main()
//{
//	int y = 0;
//	Date d(2022, 1, y);
//	//const int N; // const必须在定义的地方初始化，只有一次机会
//
//	return 0;
//}


// 结论：自定义类型成员，推荐用初始化列表初始化
//// 初始化列表可以认为是成员变量定义的地方
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
//	//自定义的构造函数
//	Date(int year, int hour, int& x)
//		:_t(hour)
//		,_N(10)
//		, _ref(x)
//	{
//		// 函数体内初始化
//		//_year = year;
//		_ref++;
//	}
//private:
//	// 声明
//	int _year = 0;  // C++11  缺省值-- 初始化时没有显示给值就会用这个缺省值
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
//		:_a((int*)malloc(sizeof(int)*N))//初始话列表 是可以使用函数的
//		, _N(N)
//	{
//		//函数体内
//		if (_a == NULL)
//		{
//			perror("malloc fail");
//		}
//		memset(_a, 0, sizeof(int)*N);
//	}*/
//
//	// 有些初始化工作还是必须在函数体内完成
//	A(int N)
//		:_N(N)
//	{
//		//函数体内
//		_a = (int*)malloc(sizeof(int)*N);
//		if (_a == NULL)
//		{
//			perror("malloc fail");
//		}
//		memset(_a, 0, sizeof(int)*N);
//	}
//private:
//	// 声明
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


//// explicit关键字 + 匿名对象
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
//	Date d1(2022);  // 直接调用构造
//	Date d2 = 2022; // 隐式类型转换：构造 + 拷贝构造 + 编译器优化 -> 直接调用构造 
//	const Date& d3 = 2022;
//
//	int i = 10;
//	double a = 20;
//	const double& d = i;
//
//	return 0;
//}



//// explicit关键字 + 匿名对象
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
//	Date d1(2022);  // 直接调用构造
//	Date d2 = 2022; // 隐式类型转换：构造 + 拷贝构造 + 编译器优化 -》直接调用构造 
//	const Date& d3 = 2022;
//
//	int i = 10;
//	const double& d = i;
//
//	// 匿名对象 -- 声明周期只有这一行
//	Date(2000);
//
//	Date d4(2000);
//
//	// 匿名对象 一些使用场景
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
//	static int _scount;  // 声明
//};
//
//// 类外面定义初始化
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
//	 静态成员函数 --  没有this指针
//	static int GetCount()
//	{
//
//		return _scount;
//	}
//
//private:
//	 静态成员变量，属于整个类，生命周期整个程序运行期间，存在静态取
//	static int _scount;  // 声明
//};
//
// 类外面定义初始化
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



////// 设计一个只能在栈上定义对象的类
//class StackOnly
//{
//public:
//	//静态成员函数-----没有this指针
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
//	//StackOnly so1; // 栈
//	//static StackOnly so2; // 静态区
//	StackOnly so3 = StackOnly::CreateObj();
//
//	return 0;
//}



//
///////////////////////////////////////////////////////////////////////////////////////////
// 内部类
//class A
//{
//private:
//	int _h;
//	static int k;
//public:
//	 B定义在A的里面
//	 1、受A的类域限制，访问限定符
//	 2、B天生是A的友元
//	class B
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a._h << endl;//OK -- 友元
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
	//构造函数
	W(int x = 0)
	{
		cout << "W()" << endl;
	}

	//拷贝构造函数
	W(const W& w)
	{
		cout << "W(const W& w)" << endl;
	}

	//运算符重载 =
	W& operator=(const W& w)
	{
		cout << "W& operator=(const W& w)" << endl;
		return *this;
	}

	//析构函数
	~W()
	{
		cout << "~W()" << endl;
	}
};

//传值传参，会引起拷贝构造函数
void f1(W w)
{

}

//传引用传参，不会引起拷贝构造函数
void f2(const W& w)
{

}

//传值返回，会引起拷贝构造
W f3()
{
	W ret;//构造
	return ret;//传值返回，会引起拷贝构造
}

int main()
{
	W w1;
	f1(w1);
	f2(w1);
	cout << endl << endl;

	f1(W()); //W()是匿名对象  本来构造+拷贝构造--编译器的优化--直接构造
	// 结论：连续一个表达式步骤中，连续构造(因为拷贝构造也是构造)一般都会优化 -- 合二为一

	W w2 = 1;//这里也是编译器优化，因为有临时变量，也是来连续的 因为编译器优化---直接构造


	cout << endl << endl;

	f3();
	return 0;
}




// 《深度探索C++对象模型》
//int main()
//{
//	f3(); // 1次构造  1次拷贝
//	cout << endl << endl;
//
//	W w1 = f3(); // 本来：1次构造  2次拷贝 -- 优化：1次构造  1次拷贝
//
//	cout << endl << endl;
//
//	W w2;
//	w2 = f3(); // 本来：1次构造  1次拷贝 1次赋值
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
//	W y = f(f(x)); // 1次构造  7次拷贝  or  1次构造  5次拷贝
//
//	return 0;
//}

//int main()
//{
//	W x;
//	W y = f(x); // 1次构造  4次拷贝
//
//	return 0;
//}