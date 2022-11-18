
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


//// 类模板
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
	////类模板部分特化
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
//	//这里的数据是Date,用类模板less的时候，当然可以
//	hhh::less<Date> lessFunc1;
//	cout << lessFunc1(d1, d2) << endl;
//
//	//这里的数据是Date*，也是指针,所以如果用类模板less的时候，
//	//对于指针类型Date*是 无法处理的，所以这个时候要对类less 进行类模板特化
//	hhh::less<Date*> lessFunc2;
//	cout << lessFunc2(p1, p2) << endl;
//
//
//
//	//这里的数据是Date,用类模板less的时候，当然可以
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
//	dq2.push(new Date(2022, 9, 27));//因为这里要传Date*，所以用new
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
// 全特化
//template<> //模板参数就不要写了
//class Data<int, char> //全部模板参数 都具体化
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//	特化的时候，这个成员变量可以不写
//	/*int _d1;
//	char _d2;*/
//};
//
// 偏特化
//template <class T1> //写上没有具体化的 模板参数
//class Data<T1, int> //只有一部分模板参数 具体化了
//{
//public:
//	Data() { cout << "Data<T1, int>" << endl; }
//private:
//	/*T1 _d1;
//	int _d2;*/
//};
//
//
//偏特化并不仅仅是指特化部分参数，
//而是针对模板参数更进一步的条件限制所设计出来的一个特化版本。
//template<class T1, class T2> //模板参数没有具体化，但是形式变了，即条件限制
//class Data<T1*,T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//};
//
//偏特化并不仅仅是指特化部分参数，
//而是针对模板参数更进一步的条件限制所设计出来的一个特化版本。
//template<class T1, class T2>//模板参数没有具体化，但是形式变了，即条件限制
//class Data<T1&, T2&>
//{
//public:
//	Data() { cout << "Data<T1&, T2&>" << endl; }
//};
//
//偏特化并不仅仅是指特化部分参数，
//而是针对模板参数更进一步的条件限制所设计出来的一个特化版本。
//template<class T1, class T2>//模板参数没有具体化，但是形式变了，即条件限制
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
//	string _name = "peter"; // 姓名
//	int _age = 18;  // 年龄
//	....
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//
//int main()
//{
//	Student s;
//	s._name = "李四";
//	s._age = 18;
//	s.Print();
//
//	Teacher t;
//	t._name = "吴老师";
//	t._age = 40;
//	t.Print();
//
//	return 0;
//}



//#include <iostream>
//#include <string>
//using namespace std;

////父类
//class Person 
//{
//protected:
//	string _name; // 姓名
//	string _sex;  // 性别
//	int	_age;	 // 年龄
//};
//
////子类
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//int main()
//{
//	//子类对象
//	Student sobj;
//
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	// 这里虽然是不同类型，但是不是隐式类型转换
//	// 这里算是一个特殊支持，语法天然支持的
//	Person pobj = sobj;
//	Person* pp = &sobj;
//
//	//这句代码就能知道不是隐式类型转换，因为隐式类型转换会生成临时变量，
//	//而临时变量巨头常属性，所以这个引用前面应该要加const，
//	//不然引用就出现权限提高的错误，
//	// 所以这句代码，上两句代码都不是隐式类型转换。
//	//这三句代码算是一个特殊支持，语法天然支持的
//	Person& rp = sobj;
//
//
//	//这里就是隐式类型转换，并且因为不能出现引用引用的权限提高，
//	//所以要加const
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
////父类
//class Person
//{
//public:
//	//这是我们自己写的构造函数
//	//注意默认构造函数只有3种！！ 第一：全缺省构造函数；第二：没有参数的构造函数；
//	//第三：我们不写构造函数，注意我们是啥都没写，编译器默认生成的构造函数
//	// 只有这三种叫默认构造函数，其他的都是我们自己写的构造函数
//	Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	//拷贝构造
//	Person(const Person& p)
//	{
//		_name = p._name;
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	//赋值操作符重载
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	//析构函数
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//protected:
//	string _name; // 姓名
//};
//
////子类
//class Student : public Person
//{
//public:
//	//这是我们自己写的构造函数
//	//注意默认构造函数只有3种！！ 第一：全缺省构造函数；第二：没有参数的构造函数；
//	//第三：我们不写构造函数，注意我们是啥都没写，编译器默认生成的构造函数
//	// 只有这三种叫默认构造函数，其他的都是我们自己写的构造函数
//	Student(const char* name , int num )
//		//如果父类没有默认构造，则必须在子类构造函数的初始化列表显示调用！
//		//注意默认构造函数只有3种！！ 第一：全缺省构造函数；第二：没有参数的构造函数；
//		//第三：我们不写构造函数，注意我们是啥都没写，编译器默认生成的构造函数
//		// 只有这三种叫默认构造函数，其他的都是我们自己写的构造函数
//		//这里用匿名对象，调用父类的构造函数
//		:Person(name) //这是语法要求，必须初始化写在列表这里，而且只能这样写。
//		, _num(num) //这个子类自己的成员，写在这个函数内部也是可以的，
//		            //不过我们在类与对象那里学过，类自己的成员，最好写在初始化列表这里。
//		
//	{
//		cout << "Student()" << endl;
//	}
//
//	//拷贝构造
//	Student(const Student& s)
//	    //这里也是匿名对象，这里就用到了切片或切割的原理，在基类和派生类对象赋值转换里，
//		//将子类类型的对象，直接拷贝构造给父类类型的对象，
//		// 然后切片原理只是将子类中父类的成员拷贝构造给了父类，
//		//这里就会调用父类的拷贝构造
//		:Person(s) //这里调用的父类拷贝构造必须要写在这里，这是语法规定
//	{
//		_num = s._num;
//	}
//
//
//	//复制操作符重载
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			//去调用父类的赋值操作符重载，
//			//这里也是匿名对象，并且用了切片的原理
//			//因为这里是在子类的函数内部，这里又用了父类的赋值操作符重载，
//			//所以要用域作用限定符::表明这个赋值操作符重载是在哪个类里的，这里是父类.
//			//上面子类的构造函数和拷贝构造 去调用 父类的构造函数和拷贝构造的时候，
//			//都是在初始化列表里调用的，语法规定必须在初始化列表，
//			//而初始化列表 不需要 用域作用限定符::表明这些函数用的父类里
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
//	//析构函数
//	// 子类的析构的函数跟父类析构函数构成隐藏。
//	// 由于后面多态的需要，析构函数名字会统一处理成destructor()
//	~Student()
//	{
//		//析构函数很特殊，不需要显示调用父类析构函数，这也为了保证先析构子类，再析构父类
//		// 不需要显示调用父类析构函数，因为编译器会自己做，如果显示调用父类析构函数，就会重复调用。
//		// 每个子类析构函数后面，会自动调用父类析构函数，这样才能保证先析构子类，再析构父类
//		//Person::~Person();
//
//		// ...处理子类自己的
//		cout << "~Student()" << endl;
//	}
//
//
//	//取地址操作符重载，其实不需要自己写，用编译器的就够了
//	Student* operator&()
//	{
//		return this;
//	}
//	//取地址操作符重载，其实不需要自己写，用编译器的就够了
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
//	//子类对象s
//	Student s1("张三", 1);//构造
//
//
//	Student s2(s1);//拷贝构造
//	//Student s2 = s1;也是拷贝构造
//
//	Student s3("李四", 2);
//	s3 = s1;//赋值
//
//	return 0;
//}





//#include <iostream>
//#include <string>
//using namespace std;
//
////因为我们类Person里用了类Student，而类Student的定义在我们这里写在了类Person定义的后面，
////所以如果要用的话，要不就改变下顺序，要不就加上这个类Student的声明,这样就能用了。
//class Student;
//
////父类
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//
////子类
//class Student : public Person
//{
//	//friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
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
//父类
//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	静态成员变量——静态变量是放在静态区的
//	static int _count; // 统计人的个数。
//};
//int Person::_count = 0;
//
//子类
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//int main()
//{
//	父类对象
//	Person p;
//	子类对象
//	Student s;
//
//	这个普通的成员变量_name
//	即使子类从父类继承了成员变量_name，
//	改变父类对象的成员变量_name 并不会改变子类对象的成员变量_name，
//	它们不是同一个
//	p._name = "张三";
//	cout << s._name << endl;
//
//	
//	cout << Student::_count << endl;
//	改变父类的静态成员变量
//	++Person::_count;
//	在子类中从父类继承的静态成员变量也会发生变化，因为是同一个
//	cout << Student::_count << endl;
//
//	从父类继承的成员变量是同一个，因为静态变量是放在静态区的
//	从这里可以发现，不管是父类还是子类，静态变量的地址是一样的
//	即同一个
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
//// 1、父类构造函数私有-- 子类是不可见
//// 2、子类对象实例化，无法调用父类的构造函数，就导致实例化失败
//
//// C++11
//// 增加了关键字 final
//
//int main()
//{
//	B bb;//子类对象实例化就会失败
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
//	string _name; // 姓名
//
//	 int _age;
//	 ...
//};
//
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	Assistant at;
//
//	 菱形继承的二义性问题
//	这里就不知道该访问 继承的哪个类的 成员变量_name
//	at._name = "张山";
//	
//
//	菱形继承的数据冗余问题
//	解决菱形继承的二义性问题：
//	 就是用域访问限定符来指定 访问的成员变量是继承的哪个类的
//	但是这里又有数据冗余，相当于子类at的继承的成员变量_name有两份，
//	导致空间的浪费
//	at.Student::_name = "张三";
//	at.Teacher::_name = "李四";
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
//	string _name; // 姓名
//
//	// int _age;
//	// ...
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	Assistant at;
//
//	// 菱形虚拟继承解决了二义性和数据冗余
//	at._name = "小张";
//	at.Student::_name = "张三";
//	at.Teacher::_name = "李四";
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

////父类
//class Person
//{
//public:
//	//这里的关键字virtual和虚拟继承没有任何关系，是他的另一个功能
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
////子类
//class Student : public Person {
//public:
//	// 构成 虚函数的重写(覆盖)的条件 : 虚函数 + 三同（函数名、参数、返回值）
//	// 不符合重写，就是隐藏关系
//	// 特例1：子类虚函数不加virtual，依旧构成重写 （实际最好加上）
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
////子类
//class Soldier : public Person{
//public:
//	// 构成 虚函数的重写(覆盖)的条件 : 虚函数 + 三同（函数名、参数、返回值）
//	// 不符合重写，就是隐藏关系
//	// 特例1：子类虚函数不加virtual，依旧构成重写 （实际最好加上）
//	virtual void BuyTicket() { cout << "优先买票" << endl; }
//};
//
//// 构成多态两个条件(要同时满足才行)：
//// 1、构成 虚函数重写
//// 2、父类指针或者引用去调用虚函数
//
//
////参数是父类的引用
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
//	//因为继承是is a(是一个)，
//	//所以子类的对象可以理解为是一个基类的对象。
//	//所以这里不是隐式类型转换，完全是因为继承is a
//	Func(ps);
//	Func(st);
//	Func(sd);
//	
//	return 0;
//}



//////////////////////////////////////////////////////////////////////////////////
// //1、不是父类的指针或者引用调用
////无法在继承中构造多态
//
//class Person
//{
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	// 虚函数重写/覆盖条件 : 虚函数 + 三同（函数名、参数、返回值）
//	// 不符合重写，就是隐藏关系
//	// 特例1：子类虚函数不加virtual，依旧构成重写 （实际最好加上）
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//class Soldier : public Person{
//public:
//	virtual void BuyTicket() { cout << "优先买票" << endl; }
//};
//
//// 多态两个条件：
//// 1、虚函数重写
//// 2、父类指针或者引用去调用虚函数
//
//
////不是父类的指针或者引用调用
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
//// 2、不符合虚函数重写(覆盖) -- virtual函数
//// ps：特例1：子类虚函数不加virtual，依旧构成重写 （实际最好加上）
////
////父类
////class Person
////{
////public:
////	void BuyTicket() { cout << "买票-全价" << endl; }
////};
////
////子类
////class Student : public Person {
////public:
////	 虚函数重写/覆盖条件 : 虚函数 + 三同（函数名、参数、返回值）
////	 不符合重写，就是隐藏关系
////	 特例1：子类虚函数不加virtual，依旧构成重写 （实际最好加上）
////	virtual void BuyTicket() { cout << "买票-半价" << endl; }
////};
////
////子类
////class Soldier : public Person{
////public:
////	virtual void BuyTicket() { cout << "优先买票" << endl; }
////};
////
//// 多态两个条件：
//// 1、虚函数重写
//// 2、父类指针或者引用去调用虚函数
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
//// 2、不符合重写 -- 参数不同
//class Person
//{
//public:
//	//virtual void BuyTicket(char) { cout << "买票-全价" << endl; }
//	virtual void BuyTicket(int) { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	// 虚函数重写/覆盖条件 : 虚函数 + 三同（函数名、参数、返回值）
//	// 不符合重写，就是隐藏关系
//	// 特例1：子类虚函数不加virtual，依旧构成重写 （实际最好加上）
//	virtual void BuyTicket(int) { cout << "买票-半价" << endl; }
//};
//
//class Soldier : public Person{
//public:
//	virtual void BuyTicket() { cout << "优先买票" << endl; }
//};
//
//// 多态两个条件：
//// 1、虚函数重写
//// 2、父类指针或者引用去调用虚函数
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
////特例2：派生类重写基类虚函数时，与基类虚函数返回值类型不同。
////即基类虚函数返回基类对象的指针或者引用，
////派生类虚函数返回派生类对象的指针或者引用时，称为协变
//
//class Person
//{
//public:
//	//特例2：重写的协变。返回值可以不同，要求必须是父子关系的的指针或者引用
//	virtual Person* BuyTicket(int) 
//	{ 
//		cout << "买票-全价" << endl;
//		return this;
//	}
//
//
//};
//
//class Student : public Person {
//public:
//	// 虚函数重写/覆盖条件 : 虚函数 + 三同（函数名、参数、返回值）
//	// 不符合重写，就是隐藏关系
//	// 特例1：子类虚函数不加virtual，依旧构成重写 （实际最好加上）
//	// 特例2：重写的协变。返回值可以不同，要求必须是父子关系的的指针或者引用
//	virtual Student* BuyTicket(int)
//	{
//		cout << "买票-半价" << endl;
//		return this;
//	}
//
//};
//
//// 多态两个条件：
//// 1、虚函数重写
//// 2、父类指针或者引用去调用虚函数
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
////特例2：派生类重写基类虚函数时，与基类虚函数返回值类型不同。
////即基类虚函数返回基类对象的指针或者引用，
////派生类虚函数返回派生类对象的指针或者引用时，称为协变
//class A
//{};
//
//class B : public A
//{};
//
//class Person
//{
//public:
//	//特例2：重写的协变。返回值可以不同，要求必须是父子关系的的指针或者引用
//	virtual A* BuyTicket(int)
//	{
//		cout << "买票-全价" << endl;
//		return new A;
//	}
//};
//
//class Student : public Person {
//public:
//	// 虚函数重写/覆盖条件 : 虚函数 + 三同（函数名、参数、返回值）
//	// 不符合重写，就是隐藏关系
//	// 特例1：子类虚函数不加virtual，依旧构成重写 （实际最好加上）
//	// 特例2：重写的协变。返回值可以不同，要求必须是父子关系的的指针或者引用
//	virtual B* BuyTicket(int)
//	{
//		cout << "买票-半价" << endl;
//		return new B;
//	}
//};
//
//// 多态两个条件：
//// 1、虚函数重写
//// 2、父类指针或者引用去调用虚函数
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

	// 这两种写法本质没区别

	A* p1 = &aa;//无切片
	A* p2 = &bb;//有切片，切片只能是子类切给父类

	A* ptr1 = &aa;//无切片
	A* p1 = ptr1;//无切片

	B* ptr2 = &bb;//无切片
	A* p2 = ptr2;//有切片，切片只能是子类切给父类

	return 0;
}