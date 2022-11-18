
//struct Date
//{
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	bool operator>(const Date& d) const
//	{
//		if ((_year > d._year)
//			|| (_year == d._year && _month > d._month)
//			|| (_year == d._year && _month == d._month && _day > d._day))
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool operator<(const Date& d) const
//	{
//		if ((_year < d._year)
//			|| (_year == d._year && _month < d._month)
//			|| (_year == d._year && _month == d._month && _day < d._day))
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	int _year;
//	int _month;
//	int _day;
//};


//// ��ģ��
//namespace hhh
//{
//	template<class T>
//	struct less
//	{
//		bool operator()(const T& x1, const T& x2) const
//		{
//			return x1 < x2;
//		}
//	};
//
	////��ģ�岿���ػ�
	//template<class T>
	//struct less<T*>
	//{
	//	bool operator()(Date* x1, Date* x2) const
	//	{
	//		return *x1 < *x2;
	//	}
	//};
//}
//
//int main()
//{
//
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//
//
//
//	//�����������Date,����ģ��less��ʱ�򣬵�Ȼ����
//	hhh::less<Date> lessFunc1;
//	cout << lessFunc1(d1, d2) << endl;
//
//	//�����������Date*��Ҳ��ָ��,�����������ģ��less��ʱ��
//	//����ָ������Date*�� �޷�����ģ��������ʱ��Ҫ����less ������ģ���ػ�
//	hhh::less<Date*> lessFunc2;
//	cout << lessFunc2(p1, p2) << endl;
//
//
//
//	//�����������Date,����ģ��less��ʱ�򣬵�Ȼ����
//	std::priority_queue<Date, vector<Date>, hhh::less<Date>> dq1;
//	dq1.push(Date(2022, 9, 27));
//	dq1.push(Date(2022, 9, 25));
//	dq1.push(Date(2022, 9, 28));
//	dq1.push(Date(2022, 9, 29));
//
//
//	while (!dq1.empty())
//	{
//		Date top = dq1.top();
//		cout << top._year << "/" << top._month << "/" << top._day << endl;
//		dq1.pop();
//	}
//	cout << endl;
//
//	std::priority_queue<Date*, vector<Date*>, hhh::less<Date*>> dq2;
//	dq2.push(new Date(2022, 9, 27));//��Ϊ����Ҫ��Date*��������new
//	dq2.push(new Date(2022, 9, 25));
//	dq2.push(new Date(2022, 9, 28));
//	dq2.push(new Date(2022, 9, 29));
//
//	while (!dq2.empty())
//	{
//		Date* top = dq2.top();
//		cout << top->_year << "/" << top->_month << "/" << top->_day << endl;
//		dq2.pop();
//	}
//
//	return 0;
//}



//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
// ȫ�ػ�
//template<> //ģ������Ͳ�Ҫд��
//class Data<int, char> //ȫ��ģ����� �����廯
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//	�ػ���ʱ�������Ա�������Բ�д
//	/*int _d1;
//	char _d2;*/
//};
//
// ƫ�ػ�
//template <class T1> //д��û�о��廯�� ģ�����
//class Data<T1, int> //ֻ��һ����ģ����� ���廯��
//{
//public:
//	Data() { cout << "Data<T1, int>" << endl; }
//private:
//	/*T1 _d1;
//	int _d2;*/
//};
//
//
//ƫ�ػ�����������ָ�ػ����ֲ�����
//�������ģ���������һ����������������Ƴ�����һ���ػ��汾��
//template<class T1, class T2> //ģ�����û�о��廯��������ʽ���ˣ�����������
//class Data<T1*,T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//};
//
//ƫ�ػ�����������ָ�ػ����ֲ�����
//�������ģ���������һ����������������Ƴ�����һ���ػ��汾��
//template<class T1, class T2>//ģ�����û�о��廯��������ʽ���ˣ�����������
//class Data<T1&, T2&>
//{
//public:
//	Data() { cout << "Data<T1&, T2&>" << endl; }
//};
//
//ƫ�ػ�����������ָ�ػ����ֲ�����
//�������ģ���������һ����������������Ƴ�����һ���ػ��汾��
//template<class T1, class T2>//ģ�����û�о��廯��������ʽ���ˣ�����������
//class Data<T1&, T2*>
//{
//public:
//	Data() { cout << "Data<T1&, T2*>" << endl; }
//};
//
//
//int main()
//{
//	Data<int, int> d0;
//	Data<double, int> d1;
//	
//	Data<int, char> d2;
//	
//	Data<double, double> d3;
//	Data<double*, double*> d4;
//	Data<int*, char*> d5;
//	Data<int*, char> d6;
//	
//	Data<int&, char&> d7;
//	Data<int&, double&> d8;
//	Data<int&, double*> d9;
//	
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // ����
//	int _age = 18;  // ����
//	....
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};
//
//int main()
//{
//	Student s;
//	s._name = "����";
//	s._age = 18;
//	s.Print();
//
//	Teacher t;
//	t._name = "����ʦ";
//	t._age = 40;
//	t.Print();
//
//	return 0;
//}



//#include <iostream>
//#include <string>
//using namespace std;

////����
//class Person 
//{
//protected:
//	string _name; // ����
//	string _sex;  // �Ա�
//	int	_age;	 // ����
//};
//
////����
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//
//int main()
//{
//	//�������
//	Student sobj;
//
//	// 1.���������Ը�ֵ���������/ָ��/����
//	// ������Ȼ�ǲ�ͬ���ͣ����ǲ�����ʽ����ת��
//	// ��������һ������֧�֣��﷨��Ȼ֧�ֵ�
//	Person pobj = sobj;
//	Person* pp = &sobj;
//
//	//���������֪��������ʽ����ת������Ϊ��ʽ����ת����������ʱ������
//	//����ʱ������ͷ�����ԣ������������ǰ��Ӧ��Ҫ��const��
//	//��Ȼ���þͳ���Ȩ����ߵĴ���
//	// ���������룬��������붼������ʽ����ת����
//	//�������������һ������֧�֣��﷨��Ȼ֧�ֵ�
//	Person& rp = sobj;
//
//
//	//���������ʽ����ת����������Ϊ���ܳ����������õ�Ȩ����ߣ�
//	//����Ҫ��const
//	int i = 0;
//	const double& d = i;
//
//	//sobj = (Student)pobj;
//
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
////����
//class Person
//{
//public:
//	//���������Լ�д�Ĺ��캯��
//	//ע��Ĭ�Ϲ��캯��ֻ��3�֣��� ��һ��ȫȱʡ���캯�����ڶ���û�в����Ĺ��캯����
//	//���������ǲ�д���캯����ע��������ɶ��ûд��������Ĭ�����ɵĹ��캯��
//	// ֻ�������ֽ�Ĭ�Ϲ��캯���������Ķ��������Լ�д�Ĺ��캯��
//	Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	//��������
//	Person(const Person& p)
//	{
//		_name = p._name;
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	//��ֵ����������
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	//��������
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//protected:
//	string _name; // ����
//};
//
////����
//class Student : public Person
//{
//public:
//	//���������Լ�д�Ĺ��캯��
//	//ע��Ĭ�Ϲ��캯��ֻ��3�֣��� ��һ��ȫȱʡ���캯�����ڶ���û�в����Ĺ��캯����
//	//���������ǲ�д���캯����ע��������ɶ��ûд��������Ĭ�����ɵĹ��캯��
//	// ֻ�������ֽ�Ĭ�Ϲ��캯���������Ķ��������Լ�д�Ĺ��캯��
//	Student(const char* name , int num )
//		//�������û��Ĭ�Ϲ��죬����������๹�캯���ĳ�ʼ���б���ʾ���ã�
//		//ע��Ĭ�Ϲ��캯��ֻ��3�֣��� ��һ��ȫȱʡ���캯�����ڶ���û�в����Ĺ��캯����
//		//���������ǲ�д���캯����ע��������ɶ��ûд��������Ĭ�����ɵĹ��캯��
//		// ֻ�������ֽ�Ĭ�Ϲ��캯���������Ķ��������Լ�д�Ĺ��캯��
//		//�������������󣬵��ø���Ĺ��캯��
//		:Person(name) //�����﷨Ҫ�󣬱����ʼ��д���б��������ֻ������д��
//		, _num(num) //��������Լ��ĳ�Ա��д����������ڲ�Ҳ�ǿ��Եģ�
//		            //���������������������ѧ�������Լ��ĳ�Ա�����д�ڳ�ʼ���б����
//		
//	{
//		cout << "Student()" << endl;
//	}
//
//	//��������
//	Student(const Student& s)
//	    //����Ҳ����������������õ�����Ƭ���и��ԭ���ڻ�������������ֵת���
//		//���������͵Ķ���ֱ�ӿ���������������͵Ķ���
//		// Ȼ����Ƭԭ��ֻ�ǽ������и���ĳ�Ա����������˸��࣬
//		//����ͻ���ø���Ŀ�������
//		:Person(s) //������õĸ��࿽���������Ҫд����������﷨�涨
//	{
//		_num = s._num;
//	}
//
//
//	//���Ʋ���������
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			//ȥ���ø���ĸ�ֵ���������أ�
//			//����Ҳ���������󣬲���������Ƭ��ԭ��
//			//��Ϊ������������ĺ����ڲ������������˸���ĸ�ֵ���������أ�
//			//����Ҫ���������޶���::���������ֵ���������������ĸ�����ģ������Ǹ���.
//			//��������Ĺ��캯���Ϳ������� ȥ���� ����Ĺ��캯���Ϳ��������ʱ��
//			//�����ڳ�ʼ���б�����õģ��﷨�涨�����ڳ�ʼ���б�
//			//����ʼ���б� ����Ҫ ���������޶���::������Щ�����õĸ�����
//			Person::operator=(s);
//
//			_num = s._num;
//		}
//
//		cout << "Student& operator=(const Student& s)" << endl;
//
//		return *this;
//	}
//
//
//	//��������
//	// ����������ĺ������������������������ء�
//	// ���ں����̬����Ҫ�������������ֻ�ͳһ�����destructor()
//	~Student()
//	{
//		//�������������⣬����Ҫ��ʾ���ø���������������ҲΪ�˱�֤���������࣬����������
//		// ����Ҫ��ʾ���ø���������������Ϊ���������Լ����������ʾ���ø��������������ͻ��ظ����á�
//		// ÿ�����������������棬���Զ����ø��������������������ܱ�֤���������࣬����������
//		//Person::~Person();
//
//		// ...���������Լ���
//		cout << "~Student()" << endl;
//	}
//
//
//	//ȡ��ַ���������أ���ʵ����Ҫ�Լ�д���ñ������ľ͹���
//	Student* operator&()
//	{
//		return this;
//	}
//	//ȡ��ַ���������أ���ʵ����Ҫ�Լ�д���ñ������ľ͹���
//	const Student* operator&()const
//	{
//		return this;
//	}
//
//protected:
//	int _num;
//};
//
//
//int main()
//{
//	//�������s
//	Student s1("����", 1);//����
//
//
//	Student s2(s1);//��������
//	//Student s2 = s1;Ҳ�ǿ�������
//
//	Student s3("����", 2);
//	s3 = s1;//��ֵ
//
//	return 0;
//}





//#include <iostream>
//#include <string>
//using namespace std;
//
////��Ϊ������Person��������Student������Student�Ķ�������������д������Person����ĺ��棬
////�������Ҫ�õĻ���Ҫ���͸ı���˳��Ҫ���ͼ��������Student������,�����������ˡ�
//class Student;
//
////����
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//
////����
//class Student : public Person
//{
//	//friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}





//#include <iostream>
//#include <string>
//using namespace std;
//
//����
//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // ����
//public:
//	��̬��Ա����������̬�����Ƿ��ھ�̬����
//	static int _count; // ͳ���˵ĸ�����
//};
//int Person::_count = 0;
//
//����
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//
//int main()
//{
//	�������
//	Person p;
//	�������
//	Student s;
//
//	�����ͨ�ĳ�Ա����_name
//	��ʹ����Ӹ���̳��˳�Ա����_name��
//	�ı丸�����ĳ�Ա����_name ������ı��������ĳ�Ա����_name��
//	���ǲ���ͬһ��
//	p._name = "����";
//	cout << s._name << endl;
//
//	
//	cout << Student::_count << endl;
//	�ı丸��ľ�̬��Ա����
//	++Person::_count;
//	�������дӸ���̳еľ�̬��Ա����Ҳ�ᷢ���仯����Ϊ��ͬһ��
//	cout << Student::_count << endl;
//
//	�Ӹ���̳еĳ�Ա������ͬһ������Ϊ��̬�����Ƿ��ھ�̬����
//	��������Է��֣������Ǹ��໹�����࣬��̬�����ĵ�ַ��һ����
//	��ͬһ��
//	cout << &Person::_count << endl;
//	cout << &Student::_count << endl;
//
//	return 0;
//}




//#include <iostream>
//using namespace std;
//
//class A final
//{
//private:
//	A()
//	{}
//
//protected:
//	int _a;
//};
//
//class B : public A
//{
//
//};
//// C++98
//// 1�����๹�캯��˽��-- �����ǲ��ɼ�
//// 2���������ʵ�������޷����ø���Ĺ��캯�����͵���ʵ����ʧ��
//
//// C++11
//// �����˹ؼ��� final
//
//int main()
//{
//	B bb;//�������ʵ�����ͻ�ʧ��
//
//	return 0;
//}




//#include <iostream>
//using namespace std;
//
//class Base1 { public:  int _b1; };
//class Base2 { public:  int _b2; };
//class Derive : public Base1, public Base2 { public: int _d; };
//
//int main()
//{
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//
//	d._b1 = 1;
//	d._b2 = 2;
//	d._d = 3;
//
//	cout << p1 << endl;
//	cout << p2 << endl;
//	cout << p3 << endl;
//
//	return 0;
//}







//class Person
//{
//public:
//	string _name; // ����
//
//	 int _age;
//	 ...
//};
//
//class Student : public Person
//{
//protected:
//	int _num; //ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int _id; // ְ�����
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
//int main()
//{
//	Assistant at;
//
//	 ���μ̳еĶ���������
//	����Ͳ�֪���÷��� �̳е��ĸ���� ��Ա����_name
//	at._name = "��ɽ";
//	
//
//	���μ̳е�������������
//	������μ̳еĶ��������⣺
//	 ������������޶�����ָ�� ���ʵĳ�Ա�����Ǽ̳е��ĸ����
//	�������������������࣬�൱������at�ļ̳еĳ�Ա����_name�����ݣ�
//	���¿ռ���˷�
//	at.Student::_name = "����";
//	at.Teacher::_name = "����";
// 
//	return 0;
//}





//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//	string _name; // ����
//
//	// int _age;
//	// ...
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
//int main()
//{
//	Assistant at;
//
//	// ��������̳н���˶����Ժ���������
//	at._name = "С��";
//	at.Student::_name = "����";
//	at.Teacher::_name = "����";
//
//	return 0;
//}



//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//	int _a;
//};
//
////class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
////class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	//D d;
//	//d.B::_a = 1;
//	//d.C::_a = 2;
//	//d._a = 0;
//	//d._b = 3;
//	//d._c = 4;
//	//d._d = 5;
//
//	//B b = d;
//	//B* pb = &d;
//
//	//B c = d;
//	//B* pc = &d;
//
//	B bb;
//	
//	bb._a = 1;
//	bb._b = 2;
//
//	return 0;
//}


#include <iostream>
using namespace std;

////����
//class Person
//{
//public:
//	//����Ĺؼ���virtual������̳�û���κι�ϵ����������һ������
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
////����
//class Student : public Person {
//public:
//	// ���� �麯������д(����)������ : �麯�� + ��ͬ��������������������ֵ��
//	// ��������д���������ع�ϵ
//	// ����1�������麯������virtual�����ɹ�����д ��ʵ����ü��ϣ�
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//
////����
//class Soldier : public Person{
//public:
//	// ���� �麯������д(����)������ : �麯�� + ��ͬ��������������������ֵ��
//	// ��������д���������ع�ϵ
//	// ����1�������麯������virtual�����ɹ�����д ��ʵ����ü��ϣ�
//	virtual void BuyTicket() { cout << "������Ʊ" << endl; }
//};
//
//// ���ɶ�̬��������(Ҫͬʱ�������)��
//// 1������ �麯����д
//// 2������ָ���������ȥ�����麯��
//
//
////�����Ǹ��������
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//	Soldier sd;
//
//	//��Ϊ�̳���is a(��һ��)��
//	//��������Ķ���������Ϊ��һ������Ķ���
//	//�������ﲻ����ʽ����ת������ȫ����Ϊ�̳�is a
//	Func(ps);
//	Func(st);
//	Func(sd);
//	
//	return 0;
//}



//////////////////////////////////////////////////////////////////////////////////
// //1�����Ǹ����ָ��������õ���
////�޷��ڼ̳��й����̬
//
//class Person
//{
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//	// �麯����д/�������� : �麯�� + ��ͬ��������������������ֵ��
//	// ��������д���������ع�ϵ
//	// ����1�������麯������virtual�����ɹ�����д ��ʵ����ü��ϣ�
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//
//class Soldier : public Person{
//public:
//	virtual void BuyTicket() { cout << "������Ʊ" << endl; }
//};
//
//// ��̬����������
//// 1���麯����д
//// 2������ָ���������ȥ�����麯��
//
//
////���Ǹ����ָ��������õ���
//void Func(Person p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//	Soldier sd;
//
//	Func(ps);
//	Func(st);
//	Func(sd);
//
//	return 0;
//}




////////////////////////////////////////////////////////////////////////////////
//// 2���������麯����д(����) -- virtual����
//// ps������1�������麯������virtual�����ɹ�����д ��ʵ����ü��ϣ�
////
////����
////class Person
////{
////public:
////	void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
////};
////
////����
////class Student : public Person {
////public:
////	 �麯����д/�������� : �麯�� + ��ͬ��������������������ֵ��
////	 ��������д���������ع�ϵ
////	 ����1�������麯������virtual�����ɹ�����д ��ʵ����ü��ϣ�
////	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
////};
////
////����
////class Soldier : public Person{
////public:
////	virtual void BuyTicket() { cout << "������Ʊ" << endl; }
////};
////
//// ��̬����������
//// 1���麯����д
//// 2������ָ���������ȥ�����麯��
////
////void Func(Person& p)
////{
////	p.BuyTicket();
////}
////
////int main()
////{
////	Person ps;
////	Student st;
////	Soldier sd;
////
////	Func(ps);
////	Func(st);
////	Func(sd);
////
////	return 0;
////}


//////////////////////////////////////////////////////////////////////////////
//// 2����������д -- ������ͬ
//class Person
//{
//public:
//	//virtual void BuyTicket(char) { cout << "��Ʊ-ȫ��" << endl; }
//	virtual void BuyTicket(int) { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//	// �麯����д/�������� : �麯�� + ��ͬ��������������������ֵ��
//	// ��������д���������ع�ϵ
//	// ����1�������麯������virtual�����ɹ�����д ��ʵ����ü��ϣ�
//	virtual void BuyTicket(int) { cout << "��Ʊ-���" << endl; }
//};
//
//class Soldier : public Person{
//public:
//	virtual void BuyTicket() { cout << "������Ʊ" << endl; }
//};
//
//// ��̬����������
//// 1���麯����д
//// 2������ָ���������ȥ�����麯��
//
//
//void Func(Person& p)
//{
//	p.BuyTicket(1);
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//	Soldier sd;
//
//	Func(ps);
//	Func(st);
//	Func(sd);
//
//	return 0;
//}



////////////////////
////����2����������д�����麯��ʱ��������麯������ֵ���Ͳ�ͬ��
////�������麯�����ػ�������ָ��������ã�
////�������麯����������������ָ���������ʱ����ΪЭ��
//
//class Person
//{
//public:
//	//����2����д��Э�䡣����ֵ���Բ�ͬ��Ҫ������Ǹ��ӹ�ϵ�ĵ�ָ���������
//	virtual Person* BuyTicket(int) 
//	{ 
//		cout << "��Ʊ-ȫ��" << endl;
//		return this;
//	}
//
//
//};
//
//class Student : public Person {
//public:
//	// �麯����д/�������� : �麯�� + ��ͬ��������������������ֵ��
//	// ��������д���������ع�ϵ
//	// ����1�������麯������virtual�����ɹ�����д ��ʵ����ü��ϣ�
//	// ����2����д��Э�䡣����ֵ���Բ�ͬ��Ҫ������Ǹ��ӹ�ϵ�ĵ�ָ���������
//	virtual Student* BuyTicket(int)
//	{
//		cout << "��Ʊ-���" << endl;
//		return this;
//	}
//
//};
//
//// ��̬����������
//// 1���麯����д
//// 2������ָ���������ȥ�����麯��
//
//void Func(Person& p)
//{
//	p.BuyTicket(1);
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//
//	return 0;
//}





////////////////////
////����2����������д�����麯��ʱ��������麯������ֵ���Ͳ�ͬ��
////�������麯�����ػ�������ָ��������ã�
////�������麯����������������ָ���������ʱ����ΪЭ��
//class A
//{};
//
//class B : public A
//{};
//
//class Person
//{
//public:
//	//����2����д��Э�䡣����ֵ���Բ�ͬ��Ҫ������Ǹ��ӹ�ϵ�ĵ�ָ���������
//	virtual A* BuyTicket(int)
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//		return new A;
//	}
//};
//
//class Student : public Person {
//public:
//	// �麯����д/�������� : �麯�� + ��ͬ��������������������ֵ��
//	// ��������д���������ع�ϵ
//	// ����1�������麯������virtual�����ɹ�����д ��ʵ����ü��ϣ�
//	// ����2����д��Э�䡣����ֵ���Բ�ͬ��Ҫ������Ǹ��ӹ�ϵ�ĵ�ָ���������
//	virtual B* BuyTicket(int)
//	{
//		cout << "��Ʊ-���" << endl;
//		return new B;
//	}
//};
//
//// ��̬����������
//// 1���麯����д
//// 2������ָ���������ȥ�����麯��
//
//void Func(Person& p)
//{
//	p.BuyTicket(1);
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//
//	return 0;
//}




////
//class A
//{
//public:
//	virtual void func(int val = 1){ std::cout << "A->" << val << std::endl; }
//	virtual void test(){ func(); }
//};
//
//class B : public A
//{
//public:
//	//void func(int val = 0){ std::cout << "B->" << val << std::endl; }
//	void func(int val){ std::cout << "B->" << val << std::endl; }
//};
//
//int main(int argc, char* argv[])
//{
//	A*p = new A;
//	p->test();
//	return 0;
//}


class A{};
class B:public A{};

int main(int argc, char* argv[])
{
	A aa;
	B bb;

	// ������д������û����

	A* p1 = &aa;//����Ƭ
	A* p2 = &bb;//����Ƭ����Ƭֻ���������и�����

	A* ptr1 = &aa;//����Ƭ
	A* p1 = ptr1;//����Ƭ

	B* ptr2 = &bb;//����Ƭ
	A* p2 = ptr2;//����Ƭ����Ƭֻ���������и�����

	return 0;
}