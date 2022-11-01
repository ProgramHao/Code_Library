#include<iostream>
using namespace std;
//
//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//
//	// 1.malloc/calloc/realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof (int));
//	int* p3 = (int*)realloc(p2, sizeof(int)* 10);
//
//	// 这里需要free(p2)吗？
//	free(p3);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}



//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//
//	int* p2 = new int;
//	// 申请5个int的数组
//	int* p3 = new int[5];
//
//	// 申请1个int对象，初始化为5
//	int* p4 = new int(5);
//
//	//C++11支持new[] 用{}初始化  C++98不支持
//	int* p5 = new int[5]{1,2,3};
//
//	free(p1);
//
//	delete p2;
//	delete[] p3;
//	delete p4;
//	delete[] p5;
//
//	// 针对内置类型，new/delete跟malloc/free没有本质的区别，只有用法的区别
//	// new/delete 用法简化了
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}

//
//class A
//{
//public:
//	//构造函数
//	A(int a = 0)
//		: _a(a)//初始化列表
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

//int main()
//{
//	// 1、堆上申请空间
//	A* p1 = (A*)malloc(sizeof(A));
//	if (p1 == NULL)
//	{
//		perror("malloc fail");
//		return 0;
//	}
//
//	// 1、释放空间
//	free(p1);
//
//	// 1、先堆上申请空间   2、再调用构造函数初始化
//	//A* p2 = new A; 调用构造函数
//	A* p2 = new A(10); //当然一样的可以自己传参给构造函数
//
//	// 1、先调用析构函数清理对象中资源  2、再释放空间
//	delete p2;
//
//	cout << endl << endl;
//
//	A* p3 = new A[2];
//	delete[] p3;
// 
//	/* C++11支持
//	 A* p3 = new A[2]{1,2};
//	 A* p3 = new A[2]{ A(1), A(2) };*/
//
//	// 结论：new/delete 是为自定义类型准备的。
//	// 不仅在对申请出来，还会调用构造和析构初始化和清理
//
//	return 0;
//}


//class A
//{
//public:
//	//构造函数
//	A(int a = 0)
//		: _a(a)//初始化列表
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
//	// 失败返回NULL
//	char* p1 = (char*)malloc(1024u*1024u*1024u*2 - 1);
//	//cout << p1 << endl;
//	printf("%p\n", p1);
//
//	// new失败,不需要检查返回值，他失败是抛异常
//	try
//	{
//		//char* p2 = new char[1024u * 1024u * 1024u * 2 - 1];
//		//printf("%p\n", p2);
//		size_t n = 0;
//		while (1)
//		{
//		char* p2 = new char[1024];
//		++n;
//
//		printf("%p->[%d]\n", p2, n);
//		}
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}



//// 重载operator delete，在申请空间时：打印在哪个文件、哪个函数、第多少行，申请了多少个字节
//void* operator new(size_t size, const char* fileName, const char* funcName, size_t lineNo)
//{
//	void* p = ::operator new(size);
//	cout << "new:" << fileName << "||" << funcName << "||" << lineNo << "||" << p << "||" << size << endl;
//	return p;
//}
//
//// 重载operator delete，在释放空间时：打印再那个文件、哪个函数、第多少行释放
//void operator delete(void* p, const char* fileName, const char* funcName, size_t lineNo)
//{
//	cout << "delete:" << fileName << "||" << funcName << "||" << lineNo << "||" << p << endl;
//	::operator delete(p);
//}

////#ifdef _DEBUG
//#define new new(__FILE__, __FUNCTION__, __LINE__)
//#define delete(p) operator delete(p, __FILE__, __FUNCTION__, __LINE__)
////#endif
//
//int main()
//{
//	A* p1 = new A;
//	delete p1;
//
//	//delete(p1);
//
//	//delete(p1);
//
//	A* p2 = new A[4];
//	//delete[] p2;
//
//	A* p3 = new A;
//	delete p3;
//
//	A* p4 = new A;
//	//delete p4;
//
//	A* p5 = new A;
//	delete p5;
//}



class A
{
public:
	//构造函数
	A(int a = 0)
		: _a(a)//初始化列表
	{
		cout << "A():" << this << endl;
	}

	~A()
	{
		cout << "~A():" << this << endl;
	}

private:
	int _a;
};

// new -> operator new + 构造函数
// 默认情况下operator new使用全局库里面
// 每个类可以去实现自己专属operator new  new这个类对象，他就会调自己实现这个operator new

// 实现一个类专属的operator new  -- 了解一下
struct ListNode
{
	int _val;
	ListNode* _next;

	// 内存池
	static allocator<ListNode> alloc;

	void* operator new(size_t n)
	{
		cout << "operator new -> STL内存池allocator申请" << endl;
		void* obj = alloc.allocate(1);
		return obj;
	}

	void operator delete(void* ptr)
	{
		cout << "operator delete -> STL内存池allocator申请" << endl;

		alloc.deallocate((ListNode*)ptr, 1);
	}

	struct ListNode(int val)
		:_val(val)
		, _next(nullptr)
	{}
};

// allocator以后会讲，现在先会用即可
allocator<ListNode> ListNode::alloc;

int main()
{
	// 频繁申请ListNode. 想提高效率 -- 申请ListNode时，不去malloc，而是自己定制内存池
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);

	delete node1;
	//delete node2;
	delete node3;

	A* p1 = new A;

	return 0;
}



class Time
{
public:
	//这里不是默认构造函数，是自定义构造函数
	Time(int hour)
	{
		_hour = hour;
	}

private:
	int _hour;
};

class Date
{
public:
	//这里不是默认构造函数，是自定义构造函数
	Date(int year, int hour, int x)
		:_t(hour)   //初始化列表
		,_N(10)
		,_ref(x)
	{
		_year = year;
	}

private:
	int _year;
	Time _t; //自定义类型
	const int _N;//const修饰的成员变量
	int& _ref;  //引用成员变量
};

int main()
{
	int y = 0;
	Date d(2022, 1, y);
	return 0;
}


class A
{
public:
	A(int a)
		:_a1(a)
		, _a2(_a1);
	{

	}

	void Print()
	{
		cout << _a1 << _a2 << end;
	}

private:
	int _a2;
	int _a1;
};

int main()
{
	A aa(1);
	aa.Print();
	return 0;
}


class Date
{
public:
	//构造函数
	Date(int year)
		:_year(year) //初始化列表
	{

	}

private:
	int _year;
};

int main()
{
	Date d1(2022);//直接调用构造
	Date d2 = 2020;//隐式类型转换，讲int类型直接转换成类类型Date

	return 0;
}