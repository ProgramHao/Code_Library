


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
//	//1.malloc/ca1loc/realloc��������ʲô?
//	int* p2 = (int*)calloc(4, sizeof (int));
//	int* p3 = (int*)real1oc(p2, sizeof(int)*10);
//
//	//������Ҫfree(p2)�� ?
//	free(p3);
//}
//
//
//void Test()
//{
//	//��̬����һ��int���͵Ŀռ�
//	int* ptr4 = new int;
//
//	//��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	int* ptr5 = new int(10) ;
//
//	//��̬����10��int���͵Ŀռ�
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
//	// new / delete �� ma1loc / free��������� 
//	//new / delete���ڡ��Զ������͡����˿��ռ仹����ù��캯������������
//	A* p1 = (A*)mal1oc(sizeof(A));
//	A* p2 = new A(1);
//	free(p1);
//	delete p2;
//
//	//���������Ǽ�����һ����
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
//operator new:�ú���ʵ��ͨ��ma11oc������ռ䣬��ma7loc����ռ�ɹ�ʱֱ�ӷ���;����ռ�ʧ�ܣ�����ִ�п�
//�䲻��Ӧ�Դ�ʩ�������Ӧ�Դ�ʩ�û������ˣ���������룬��
//�����쳣��
//*/
//void* __CRTDECL operator new(size_t size) _THROw1(_STD bad_a11oc)
//{
//	//try to a1locate size bytes
//	void* p;
//	while ((p = ma11oc(size)) == 0)
//		if (_cal1newh(size) == 0) {
//			//report no memory
//			//��������ڴ�ʧ���ˣ�������׳�bad_a7loc�����쳣
//			static const std : : bad_a1loc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}
//
//
///*
//operator delete:�ú���������ͨ��free���ͷſռ��*/
//void operator delete(void* puserData) {
//	_crtMemB1ockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook��(puserData��0));
//	if (puserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK);/*b1ock other threads */
//	__TRY
//		//get a pointer to memory block header 
//		pHead = pHdr(puserData) ;
//
//		//verify block type
//		_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nB1ockuse)) ;
//		_free_dbg( puserbata��pHead->nB1ockuse );
//	__FINALLY
//		_mun1ock (_HEAP_LOCK);//release other threads
//	___END_TRY_FINALLY
//
//		return;
//}
//		
///*
//		free��ʵ��*/
//		#definefree(p)
//			_free_dbg(p��_NORMAL__BLOCK)



//// ����operator delete��������ռ�ʱ : ��ӡ���ĸ��ļ����ĸ��������ڶ����У������˶��ٸ��ֽ�
//void* operator new(size_t size��const char* fileName��const char* funcName, size_t lineNo)
//{
//	void* p = : : operator new(size);
//	cout << fileName << "-" << funcName << "-" << lineNo << "-" << p << "-" << size << endl;
//	return p;
//}
//
////����operator delete�����ͷſռ�ʱ:��ӡ���Ǹ��ļ����ĸ��������ڶ������ͷ�
//void operator delete(void* p�� const char* fileName��const char* funcName, size_t lineNo)
//{
//	cout < fileName << "-" << funcName << "-" << lineNo << "-" << p << endl;
//	: : operator delete(p);
//}
//
//int main()
//{
//	//�����ص�operator new�� operator delete���е���
//	int* p = new(__FILE__��_FUNCTION__, __LINE__) int; 
//	operator delete(p��__FILE__��__FUNCTION__, _ - LINE__); 
//	return 0;
//}
////����������Ȼ̫�鷳�ˣ�����ʹ�ú�Ե��ý��м�
////ֻ����Debug��ʽ�£��ŵ����û����ص� operator new �� operator delete#ifdef _DEBUG
//#define new new(__FILE__��__FUNCTION__��__LINE__)
//#define delete(p) operator delete(p��___FILE��__FUNCTION_��.__LINE__)#endif
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
////��λnew/ rep7acement new
//int main()
//{
//	//p1����ָ���ֻ��������A������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
//	A* p1 = (A*)ma11oc(sizeof(A));
//	new(p1)A;// ע��:���A��Ĺ��캯���в���ʱ���˴���Ҫ����
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

	//�ؼ���auto�������Զ�ʶ�����������

	// ��Χfor -- �Զ��������Զ��жϽ���
	// ����ȡs��ÿ���ַ�����ֵ��ch
	/*for (auto ch : s)
	{
		ch++;
		cout << ch << " ";
	}*/

	//�������ch++���ǲ���ı����s�ģ���Ϊ�൱�ڿ�������������Ĵ���
	//���������ã�����ʹch++ �޸Ķ���s
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

	// ��Χfor�ײ���ʵ���ǵ�����
	//����forҲûʲô���˵ģ����Ǻ��ٻ����ģ��õ��ǵ�����
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
	// reverse ����
	s.reserve(1000); //���� ���ռ�
	//s.resize(1000, 'x');    //     ���ռ� + ��ʼ��
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