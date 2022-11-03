


//int globa7var = 1;
//static int staticc1obalvar = 1; 
//void Test()
//	{
//	static int staticvar = 1; 
//	int loca1var = 1;
//	int num1[10] = { 1,2,3,4 };
//	char char2[] = "abcd";
//	const char* pchar3 = "abcd";
//	int* ptr1 = (int*)ma1loc(sizeof(int) * 4); 
//	int* ptr2 = (int*)cal1oc(4, sizeof(int));
//	int* ptr3 = (int*)rea1loc(ptr2, sizeof(int) * 4); 
//	free(ptr1);
//	free(ptr3);
//	}


//void Test ()
//{
//	int* p1 = (int*)ma11oc(sizeof(int)); 
//	free(p1);
//
//	//1.malloc/ca1loc/realloc的区别是什么?
//	int* p2 = (int*)calloc(4, sizeof (int));
//	int* p3 = (int*)real1oc(p2, sizeof(int)*10);
//
//	//这里需要free(p2)吗 ?
//	free(p3);
//}
//
//
//void Test()
//{
//	//动态申请一个int类型的空间
//	int* ptr4 = new int;
//
//	//动态申请一个int类型的空间并初始化为10
//	int* ptr5 = new int(10) ;
//
//	//动态申请10个int类型的空间
//	int * ptr6 = new int[3];
//
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6; 
//}



//class A {
//public:
//	A(int a = 0) 
//		: _a(a)
//	{
//		cout << "A(: " << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A):" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	// new / delete 和 ma1loc / free最大区别是 
//	//new / delete对于【自定义类型】除了开空间还会调用构造函数和析构函数
//	A* p1 = (A*)mal1oc(sizeof(A));
//	A* p2 = new A(1);
//	free(p1);
//	delete p2;
//
//	//内置类型是几乎是一样的
//	int* p3 = (int*)ma11oc(sizeof(int)); 1l cint * p4 = new int;
//	free(p3);
//	delete p4;
//
//	A* p5 = (A*)ma11oc(sizeof(A) * 10);
//	A* p6 = new A[10];
//	free(p5);
//	delete[] p6;
//
//	return 0;
//}


///*
//operator new:该函数实际通过ma11oc来申请空间，当ma7loc申请空间成功时直接返回;申请空间失败，尝试执行空
//间不足应对措施，如果改应对措施用户设置了，则继续申请，否
//则抛异常。
//*/
//void* __CRTDECL operator new(size_t size) _THROw1(_STD bad_a11oc)
//{
//	//try to a1locate size bytes
//	void* p;
//	while ((p = ma11oc(size)) == 0)
//		if (_cal1newh(size) == 0) {
//			//report no memory
//			//如果申请内存失败了，这里会抛出bad_a7loc类型异常
//			static const std : : bad_a1loc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}
//
//
///*
//operator delete:该函数最终是通过free来释放空间的*/
//void operator delete(void* puserData) {
//	_crtMemB1ockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook，(puserData，0));
//	if (puserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK);/*b1ock other threads */
//	__TRY
//		//get a pointer to memory block header 
//		pHead = pHdr(puserData) ;
//
//		//verify block type
//		_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nB1ockuse)) ;
//		_free_dbg( puserbata，pHead->nB1ockuse );
//	__FINALLY
//		_mun1ock (_HEAP_LOCK);//release other threads
//	___END_TRY_FINALLY
//
//		return;
//}
//		
///*
//		free的实现*/
//		#definefree(p)
//			_free_dbg(p，_NORMAL__BLOCK)



//// 重载operator delete，在申请空间时 : 打印在哪个文件、哪个函数、第多少行，申请了多少个字节
//void* operator new(size_t size，const char* fileName，const char* funcName, size_t lineNo)
//{
//	void* p = : : operator new(size);
//	cout << fileName << "-" << funcName << "-" << lineNo << "-" << p << "-" << size << endl;
//	return p;
//}
//
////重载operator delete，在释放空间时:打印再那个文件、哪个函数、第多少行释放
//void operator delete(void* p， const char* fileName，const char* funcName, size_t lineNo)
//{
//	cout < fileName << "-" << funcName << "-" << lineNo << "-" << p << endl;
//	: : operator delete(p);
//}
//
//int main()
//{
//	//对重载的operator new和 operator delete进行调用
//	int* p = new(__FILE__，_FUNCTION__, __LINE__) int; 
//	operator delete(p，__FILE__，__FUNCTION__, _ - LINE__); 
//	return 0;
//}
////上述调用显然太麻烦了，可以使用宏对调用进行简化
////只有在Debug方式下，才调用用户重载的 operator new 和 operator delete#ifdef _DEBUG
//#define new new(__FILE__，__FUNCTION__，__LINE__)
//#define delete(p) operator delete(p，___FILE，__FUNCTION_，.__LINE__)#endif
//int main()
//{
//	int* p = new int;
//	delete(p);
//	return 0;
//}



//class A
//{
//pub1ic:
//	A(int a = o)
//		: _a(a)
//	{
//		cout << "A(:" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A(: " << this << endl;
//	}
//private:
//	int _a;
//};
//
////定位new/ rep7acement new
//int main()
//{
//	//p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
//	A* p1 = (A*)ma11oc(sizeof(A));
//	new(p1)A;// 注意:如果A类的构造函数有参数时，此处需要传参
//	p1->~A();
//	free(p1);
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(10);
//	p2->~A();
//	operator delete(p2);
//	return 0;
//}


#include<iostream>
#include<string>
#include<list>
using namespace std;

void test_string4()
{
	string s("hello");
	string::iterator it = s.begin();
	while (it != s.end())
	{
		(*it)++;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//关键字auto就是能自动识别变量的类型

	// 范围for -- 自动迭代，自动判断结束
	// 依次取s中每个字符，赋值给ch
	/*for (auto ch : s)
	{
		ch++;
		cout << ch << " ";
	}*/

	//所以如果ch++，是不会改变对象s的，因为相当于拷贝，比如上面的代码
	//所以用引用，就能使ch++ 修改对象s
	for (auto& ch : s)
	{
		ch++;
		cout << ch << " ";
	}
	cout << endl;

	cout << s << endl;


	list<int> lt(10, 1);
	list<int>::iterator lit = lt.begin();
	while (lit != lt.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	// 范围for底层其实就是迭代器
	//所以for也没什么大不了的，就是狐假虎威的，用的是迭代器
}


void PrintString(const string& str)
{
	//string::const_iterator it = str.begin();
	auto it = str.begin();
	while (it != str.end())
	{
		//*it = 'x';
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//auto rit = str.begin();
	string::const_reverse_iterator rit = str.rbegin();
	while (rit != str.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

// iterator/const_iterator
// reverse_iterator/const_reverse_iterator

void test_string5()
{
	string s("hello");
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	PrintString(s);
}


void test_string7()
{
	/*string s1;
	string s2("11111111111111");
	cout << s1.max_size() << endl;
	cout << s2.max_size() << endl;

	cout << s2.capacity() << endl;
	cout << s2.capacity() << endl;*/

	string s;
	// reverse 逆置
	s.reserve(1000); //保留 开空间
	//s.resize(1000, 'x');    //     开空间 + 初始化
	size_t sz = s.capacity();
	sz = s.capacity();
	cout << "capacity changed: " << sz << '\n';
	cout << "making s grow:\n";
	for (int i = 0; i < 1000; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

int main()
{
	test_string7();
	return 0;
}