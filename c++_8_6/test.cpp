#include<iostream>
using namespace std;
//
//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//
//	// 1.malloc/calloc/realloc��������ʲô��
//	int* p2 = (int*)calloc(4, sizeof (int));
//	int* p3 = (int*)realloc(p2, sizeof(int)* 10);
//
//	// ������Ҫfree(p2)��
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
//	// ����5��int������
//	int* p3 = new int[5];
//
//	// ����1��int���󣬳�ʼ��Ϊ5
//	int* p4 = new int(5);
//
//	//C++11֧��new[] ��{}��ʼ��  C++98��֧��
//	int* p5 = new int[5]{1,2,3};
//
//	free(p1);
//
//	delete p2;
//	delete[] p3;
//	delete p4;
//	delete[] p5;
//
//	// ����������ͣ�new/delete��malloc/freeû�б��ʵ�����ֻ���÷�������
//	// new/delete �÷�����
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
//	//���캯��
//	A(int a = 0)
//		: _a(a)//��ʼ���б�
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
//	// 1����������ռ�
//	A* p1 = (A*)malloc(sizeof(A));
//	if (p1 == NULL)
//	{
//		perror("malloc fail");
//		return 0;
//	}
//
//	// 1���ͷſռ�
//	free(p1);
//
//	// 1���ȶ�������ռ�   2���ٵ��ù��캯����ʼ��
//	//A* p2 = new A; ���ù��캯��
//	A* p2 = new A(10); //��Ȼһ���Ŀ����Լ����θ����캯��
//
//	// 1���ȵ����������������������Դ  2�����ͷſռ�
//	delete p2;
//
//	cout << endl << endl;
//
//	A* p3 = new A[2];
//	delete[] p3;
// 
//	/* C++11֧��
//	 A* p3 = new A[2]{1,2};
//	 A* p3 = new A[2]{ A(1), A(2) };*/
//
//	// ���ۣ�new/delete ��Ϊ�Զ�������׼���ġ�
//	// �����ڶ����������������ù����������ʼ��������
//
//	return 0;
//}


//class A
//{
//public:
//	//���캯��
//	A(int a = 0)
//		: _a(a)//��ʼ���б�
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
//	// ʧ�ܷ���NULL
//	char* p1 = (char*)malloc(1024u*1024u*1024u*2 - 1);
//	//cout << p1 << endl;
//	printf("%p\n", p1);
//
//	// newʧ��,����Ҫ��鷵��ֵ����ʧ�������쳣
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



//// ����operator delete��������ռ�ʱ����ӡ���ĸ��ļ����ĸ��������ڶ����У������˶��ٸ��ֽ�
//void* operator new(size_t size, const char* fileName, const char* funcName, size_t lineNo)
//{
//	void* p = ::operator new(size);
//	cout << "new:" << fileName << "||" << funcName << "||" << lineNo << "||" << p << "||" << size << endl;
//	return p;
//}
//
//// ����operator delete�����ͷſռ�ʱ����ӡ���Ǹ��ļ����ĸ��������ڶ������ͷ�
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
	//���캯��
	A(int a = 0)
		: _a(a)//��ʼ���б�
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

// new -> operator new + ���캯��
// Ĭ�������operator newʹ��ȫ�ֿ�����
// ÿ�������ȥʵ���Լ�ר��operator new  new�����������ͻ���Լ�ʵ�����operator new

// ʵ��һ����ר����operator new  -- �˽�һ��
struct ListNode
{
	int _val;
	ListNode* _next;

	// �ڴ��
	static allocator<ListNode> alloc;

	void* operator new(size_t n)
	{
		cout << "operator new -> STL�ڴ��allocator����" << endl;
		void* obj = alloc.allocate(1);
		return obj;
	}

	void operator delete(void* ptr)
	{
		cout << "operator delete -> STL�ڴ��allocator����" << endl;

		alloc.deallocate((ListNode*)ptr, 1);
	}

	struct ListNode(int val)
		:_val(val)
		, _next(nullptr)
	{}
};

// allocator�Ժ�ὲ�������Ȼ��ü���
allocator<ListNode> ListNode::alloc;

int main()
{
	// Ƶ������ListNode. �����Ч�� -- ����ListNodeʱ����ȥmalloc�������Լ������ڴ��
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
	//���ﲻ��Ĭ�Ϲ��캯�������Զ��幹�캯��
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
	//���ﲻ��Ĭ�Ϲ��캯�������Զ��幹�캯��
	Date(int year, int hour, int x)
		:_t(hour)   //��ʼ���б�
		,_N(10)
		,_ref(x)
	{
		_year = year;
	}

private:
	int _year;
	Time _t; //�Զ�������
	const int _N;//const���εĳ�Ա����
	int& _ref;  //���ó�Ա����
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
	//���캯��
	Date(int year)
		:_year(year) //��ʼ���б�
	{

	}

private:
	int _year;
};

int main()
{
	Date d1(2022);//ֱ�ӵ��ù���
	Date d2 = 2020;//��ʽ����ת������int����ֱ��ת����������Date

	return 0;
}