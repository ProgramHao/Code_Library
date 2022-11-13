#pragma once

#include<iostream>
using namespace std;

//自己模拟实现类list，我们把它放在自己定义的命名空间jh里，这样可以区别于系统的类list
namespace jh
{
	////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	//这个类模板是为了 链表的 新节点 设计的
	//即这里的类类型list_node<T> 是新节点的类型
	//这里的模板参数 里类类型struct 的模板参数
	template<class T> 
	//结构体类型list_node，用来定义新节点的结构体类型，在c++里：结构体和类等价
	//这里struct和class等价，因为是c++里，所以结构体类型可以不用加 关键字struct
	struct list_node
	{
		//该类的成员变量，都是内置类型，
		//所以不写拷贝构造，编译器会默然生成 拷贝构造函数
		T _data;//节点里的数据
		list_node<T>* _next;//节点里指向下一个节点的指针
		list_node<T>* _prev;//节点里指向上一个节点的指针

		//在类list_node里，定义一个构造函数
		//用来创建新节点
		//因为new一个类类型list_node<T>大小的空间，是会调用它的构造函数的
		list_node(const T& x = T()) //给一个缺省值，防止没有实参传递
			:_data(x) //初始化列表
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};



	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	// 这里的类类型_list_iterator是为了 链表里的迭代器 设计的
	// 即这里的类类型__list_iterator<T, Ref, Ptr>是迭代器的类型
	// 这里的模板参数T、Ref、Ptr是类类型__list_iterator 里的模板参数
	//三个模板参数，Ref(引用的意思)可以表示为 T&、const T& ；
	//Ptr(指针的意思)可以表示为 T*、const T* 
	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		//我们这里可以类型名重定义一下，类类型list_node<T>太长了，定义为 Node
		//注意最前面的类类型list_node<T>，即节点类型，在代码第10行
		typedef list_node<T> Node;

		//类类型__list_iterator<T, Ref, Ptr>名字太长，重定义类型名为iterator
		typedef __list_iterator<T, Ref, Ptr> iterator;

		//因为用了函数find(),就必须加上下面这些，会检查，
		//下面这些是一个规范的迭代器需要的东西，现在不用管
		//55-59行代码
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef Ptr pointer;
		typedef Ref reference;
		typedef ptrdiff_t difference_type;


		//这个类里的成员变量，是一个节点类型Node的指针变量，
		//类类型Node,即类类型list_node<T> 类型名重定义来的
		//因为我们说过迭代器就是一个指针，指向对应的数据空间的
		//因为这里是链表，所以指向的数据空间就是 节点
		Node* _node;


		//该类类型的拷贝构造
		//这里是迭代器类型__list_iterator<T, Ref, Ptr>(因为重定义了，所以是iterator) 
		//这个类类型的构造函数，如果用类类型__list_iterator<T, Ref, Ptr>定义了一个该对象，
		//那么就会用调用这个类的构造函数
		__list_iterator(Node* node)
			:_node(node)//这个类型是类类型Node，要去类类型Node里调用它的拷贝构造函数，
						//类类型Node 是 类类型list_node<int> 类型名重定义来的，
						//去这个类里调用 拷贝构造函数
		{}

		//判断迭代器指向的数据空间是否是同一块，即指向的节点是否是同一块
		//直接比较迭代器(指针)的值，即指向的节点 的地址即可
		bool operator!=(const iterator& it) const
		{
			//判断两个迭代器是否不相等,this->_node!=it._node
			return _node != it._node;
		}

		//判断迭代器指向的数据空间是否是同一块，即指向的节点是否是同一块
		//直接比较迭代器(指针)的值，即指向的节点 的地址即可
		bool operator==(const iterator& it) const
		{
			////判断两个迭代器是否不相等，即this->_node==it._node
			return _node == it._node;
		}



		// *it  it.operator*()
		// const T& operator*()
		// T& operator*()
		//这里为什么用模板参数Ref，是因为如果用 重载解引用 的迭代器被const修饰，
		// 那么这个迭代器指向的那个节点的空间里的东西就不能被修改，即具有常属性，
		//比如这里的数据_data具有常属性，那么返回的时候，就必须带有const修饰，
		// 因为这里是传引用返回，所以防止出现引用权限提高的错误出现，
		//所以这里没有用T&，因为T& operator*()、const T& operator*() 都有可能，
		// 用模板参数Ref(引用),就不需要写两份，那么需要什么，就用什么就行
		Ref operator*() //解引用迭代器
		{
			//解引用迭代器，是想得到这个迭代器 指向的那个节点 里存放的数据_data
			//所以直接返回数据_data
			return _node->_data;
		}


		//T* operator->() 
		//我们知道 指向结构体对象 的指针 会用操作符-> 来访问这个结构体对象里的 结构成员变量的，
		//c++的 结构体 和 类 等效，即struct于class一样，都包含 成员变量 和 成员函数。
		//为了防止出现下面的测试用例2 test_list2()会发生的情况
		//这里类类型iterator里 重载操作符->
		//注意：因为是在类类型iterator里 重载操作符->，所以只能是类类型iterator的对象才能使用
		//这里用模板参数Ptr(指针)，和上面的重载解引用原因一样，就不用写两份
		//T* operator->()、const T* operator->()都能可能
		Ptr operator->()  
		{
			//operator*()即返回了 迭代器指向的 某个节点 里的成员变量
			//然后对该成员变量取地址，相当于作为一个指针返回，因为指针的值就是地址
			return &(operator*());
		}


		//++迭代器，就是指向节点 的指针前置++，指向下一个节点
		//因为迭代器类型是类类型iterator，所以返回值也用这个
		//可以传引用返回，是因为使用前置++的该迭代器不会出这个函数后不会被销毁
		iterator& operator++()
		{
			//会改变该迭代器本身，因为是前置++
			_node = _node->_next;
			//这里的解引用不是迭代器重置的解引用，因为这个this不是迭代器
			//迭代器的类型是类类型iterator，而这个this是指向这个迭代器的指针，
			//即这个指针this的类型iterator*，相当于是一个二级指针，
			//所以这里的解引用是系统的指针解引用，即这个指针this解引用后，
			//才是使用前置++的该迭代器本身
			return *this;
		}

		

		//迭代器++，就是指向节点 的指针后置++，指向下一个节点
		//因为迭代器类型是类类型iterator，所以返回值也用这个
		//这里是传值返回，是因为使用后置++的该迭代器会在函数内部定义一个临时变量
		//因为后置++是用了再加，所以我们要使得使用后置++的该迭代器不能改变，
		//所以函数内部定义一个临时变量，然后返回的是这个临时变量
		//临时变量出函数会被销毁，所以要用传值返回
		iterator operator++(int)
		{
			//*this就是使用后置++的该迭代器
			//然后拷贝构造这个迭代器 给tmp，迭代器类型是 类类型iterator 
			//去调用这个类类型的拷贝构造
			iterator tmp(*this);
			_node = _node->_next;
			return tmp;
		}


		// --it，迭代器前置--，和前置++原理一样
		iterator& operator--()
		{
			_node = _node->_prev;
			return *this;
		}


		// it--，迭代器后置--，和后置++原理一样
		iterator operator--(int)
		{
			iterator tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
	};




	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	//这里的类类型list，是为了 模拟实现链表
	//模拟实现类list，这里我们实现带头双向循环链表
	//这里的模板参数T 是类类型list 的模板参数
	template<class T> //模板参数T
	class list
	{
		//我们这里可以类型名重定义一下，类类型list_node<T>太长了，定义为 Node
		//注意最前面的类类型list_node<T>，即节点类型，在代码第10行
		typedef list_node<T> Node;

	public:
		//设计三个模板参数，需要哪个模板就自动用哪个模板参数
		//这样 类类型__list_iterator 这样的迭代器指向的节点里 的成员变量，需要这个变量的什么类型形式
		//T，T&(引用)，T*(指针)
		typedef __list_iterator<T, T&, T*> iterator;
		//设计三个模板参数，需要哪个模板就会自动用哪个模板参数
		typedef __list_iterator<T, const T&, const T*> const_iterator;


		//const修饰的迭代器，为了防止出现测试用例test_list3()的情况
		//const修饰的迭代器 本质就是让迭代器指向的那个节点里的内容不能被改变，即这块空间里的东西不能被修改
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}


		//const修饰的迭代器，为了防止出现测试用例test_list3()的情况
		//const修饰的迭代器 本质就是让迭代器指向的那个节点里的内容不能被改变，即这块空间里的东西不能被修改
		const_iterator end() const
		{
			return const_iterator(_head);
		}


		//指向第一个节点的迭代器
		iterator begin()
		{
			//第一个节点 是 哨兵位节点的下一个节点
			return iterator(_head->_next);//这里是匿名对象 比如int(1)：就是一个初始化为1的int类型的对象
											//也是调用了类类型iterator的拷贝构造
		}


		//指向 最后一个节点的 下一个节点 的迭代器，
		//因为这里是带头双向循环链表，所以迭代器end()就是指向的哨兵位节点
		iterator end()
		{
			return iterator(_head);
		}



		// 创建指向哨兵位头结点的指针 并 初始化这个哨兵位节点
		//编译器补全：void empty_init(list<T>* const this);
		void empty_init()
		{
			// 创建指向哨兵位头结点的指针
			_head = new Node;
			//初始化这个哨兵位节点时，这个节点里的两个指针_next和_prev都先指向自己
			_head->_next = _head;
			_head->_prev = _head;
		}
		//拷贝构造函数
		//这里给了一个迭代器模板参数，
		//这样这个迭代器就可以不是list的，也可以时vector的 等等
		template <class InputIterator>
		list(InputIterator first, InputIterator last)//给了一个迭代器区间
		{
			//既然要拷贝构造，当然拷贝构造出来的另一条链表，
			//也需要一个哨兵位的头节点，所以在拷贝构造函数里，
			//创建指向哨兵位头结点的指针 并 初始化这个哨兵位节点
			empty_init();

			while (first != last)
			{
				//编译器补全：thid->push_back(this,*first);
				push_back(*first);
				++first;
			}
		}



		//构造函数，和下面那个构造函数一摸一样，
		//只是这里将下面的 构造函数 里的代码 提取出来定义了一个empty_init()函数
		list()
		{
			//创建指向哨兵位头结点的指针 并 初始化这个哨兵位节点
			empty_init();
		}




		//这里需要注意，在这个类类型里面，写这个类类型对象的时候，
		//这个类类型可以不用加模板参数，也可以加；
		//但是在类外面，写这个类类型的对象的时候，这个类类型必须带 具体的模板参数，
		//比如在这里的类类型list里，list<T>& x 和 list& x 都可以；
		//但是如果在这个类list外面的时候，就必须写出 list<int>& x,
		//即不仅要有模板参数们，还必须带具体的模板参数。
		//但防止混淆，我们都写上，这样就不容易记混淆
		void swap(list<T>& x)
			//void swap(list& x)
		{
			//用命名空间std，说明这里用的swap是系统库函数里的
			std::swap(_head, x._head);
		}
		//拷贝构造函数
		// lt2(lt1)
		list(const list<T>& lt)
		{
			
			//创建并初始化指向哨兵位头结点的指针，编译器补全：this->empty_init(this);
			//这是给lt2 创建的指向哨兵位头结点的指针 并 初始化这个哨兵位节点，
			empty_init();
			//用到上面的 给迭代器区间 的拷贝构造函数，
			//给一个临时变量拷贝构造
			list<T> tmp(lt.begin(), lt.end());
			//编译器补全：this->swap(this,tmp);
			//将那个临时变量tmp和lt2的 指向哨兵位节点的指针 交换
			swap(tmp);
			//函数结束后，类类型list的变量tmp会被析构，因为它是临时变量
		}



		//赋值操作符重载
		// lt1 = lt3
		list<T>& operator=(list<T> lt)
		{
			//编译器补全：this->swap(this,lt);
			//直接交换lt1 和 lt3的 指向哨兵位节点的指针 即可，因为是赋值嘛
			swap(lt);
			//然后交换后，返回哨兵位节点即可，不是返回的指向哨兵位节点的指针
			//是返回哨兵位节点本身，因为this是指向链表类类型list的对象lt1，解引用就是lt1
			return *this;
		}


		//析构函数
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}


		//清理掉所有的数据
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				//传入erase的迭代器在删除指向的节点后会失效，因为链表地址空间不连续，
				//所以将返回的新的迭代器接收
				it = erase(it);
			}
		}



		//构造函数，无参构造
		//构造 类类型list的对象 的函数
		list()
		{
			//因为我们模拟的是带头双向循环链表，所以要创建哨兵位节点
			_head = new Node; // 操作符new ：int* ptr = new int 动态申请一个int类型的空间
			//两个指针，最开始都指向哨兵位节点
			_head->_next = _head;//指向下一个节点的指针
			_head->_prev = _head;//指向上一个节点的指针
		}


		//尾插
		void push_back(const T& x)
		{
			//先找尾节点
			Node* tail = _head->_prev;
			//创建新节点
			//操作符new ：int* ptr = new int(10) 动态申请一个int类型的空间 并初始化为10
			Node* newnode = new Node(x);//Node是 节点的类型，代码118行

			// _head          tail  newnode
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;

			//insert(end(), x);
		}


		//头插
		void push_front(const T& x)
		{
			insert(begin(), x);
		}



		//在迭代器pos(指针)指向的节点处插入一个节点
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			Node* newnode = new Node(x);

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}


		//尾删
		void pop_back()
		{
			erase(--end());
		}


		//头删
		void pop_front()
		{
			erase(begin());
		}


		//删除迭代器pos指向的节点
		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;

			//因为删除迭代器pos指向的节点pos后，迭代器pos就失效了，
			// 因为这是链表，地址空间是不连续的，
			//所以要返回一个新的迭代器
			return iterator(next);
		}

	private:
		//类类型list，只有指向 哨兵位节点的 指针_head，这一个私有成员变量
		//因为类类型list就是一个链表，知道指向 哨兵位节点的 指针_head
		//后面的节点后会知道了
		//就可以想象，已经有一个链表，我们知道指向 哨兵位节点的 指针_head，
		//然后通过哨兵位节点里的两个指针，指向上一个节点和指向下一个节点的指针，
		//后面的节点都知道了
		Node* _head;
	};



	//测试迭代器的函数
	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		it = lt.begin();
		while (it != lt.end())
		{
			*it *= 2;
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}





	struct Pos
	{
		int _a1;
		int _a2;

		Pos(int a1 = 0, int a2 = 0)
			:_a1(a1)
			, _a2(a2)
		{}
	};
	//测试访问用 指向结构体对象 的指针 用操作符-> 去访问结构体对象里的成员变量
	void test_list2()
	{
		int x = 10;
		int* p1 = &x;

		cout << *p1 << endl;

		Pos aa;
		Pos* p2 = &aa;
		p2->_a1;
		p2->_a2;

		list<Pos> lt;
		lt.push_back(Pos(10, 20));
		lt.push_back(Pos(10, 21));

		list<Pos>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._a1 << ":" << (*it)._a2 << endl;
			cout << it->_a1 << ":" << it->_a2 << endl;
			//其实应该的写法是it->->_a1 it->->_a2
			//前面的it-> 就是调用了类类型iterator 的操作符->重载函数，即it.operator->(),
			//返回的 就是迭代器指向的那一个节点里 的Pos类类型对象的地址，即返回的是Pos类类型对象的地址
			//也可以说是一个指针，因为指针的值就是地址嘛
			//后面的第二个操作符->就是系统里的，指向 结构体类型Pos对象 的指针 通过-> 
			//访问到结构体类型Pos 对象里的成员变量 _a1和_a2。
			//但是这里为什么只有一个->，是因为编译器语法的可读性，省略掉了一个->

			++it;
		}
		cout << endl;
	}





	void Func(const list<int>& l)
	{
		//const修饰的类类型list的对象l,那么对象l的空间里的东西不能被改变
		//假如this指针 指向对象l这个节点，那么this指针就应该被const修饰
		// 即const list<int>* const this;第二个const是系统自带的，
		// 第一个const指的是this指针指向的那块空间不能被改变，
		// 第二个const指的是this指针不能被改变。
		//const修饰的类类型list的对象l，这里又是引用
		//所以就一定要关心 引用是否会出现权限变大的错误
		//如果还是用类类型iterator的成员函数iterator begin()；
		//那么补全l.begin() 就是 l.begin(list<int>* const this)
		//这个时候就出现了权限放大的错误，因为this指针指向的那块空间可读可写
		//所以这个时候用类类型iterator的成员函数const_iterator begin()const;
		//这样补全l.begin() 就是 l.begin(const list<int>* const this)
		//这样this指针指向的那块空间只能读，不能写，既不能被修改
		list<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			//*it = 10;就不可写了

			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	//测试当类类型list的对象被const修饰的时候，就需要const修饰的迭代器
	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		Func(lt);
	}




	//验证函数push_front、pop_back、insert
	void test_list4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		it = lt.begin();
		while (it != lt.end())
		{
			*it *= 2;
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.push_front(10);
		lt.push_front(20);
		lt.push_front(30);
		lt.push_front(40);

		lt.pop_back();
		lt.pop_back();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		auto pos = find(lt.begin(), lt.end(), 4);
		if (pos != lt.end())
		{
			// pos是否会失效？不会
			lt.insert(pos, 40);
			//lt.insert(pos, 30);
			*pos *= 100;
		}

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}




	void test_list5()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int> copy = lt;
		//这里就是浅拷贝，会出现浅拷贝的两个错误，所以不能这样拷贝
		//我们上面写的拷贝构造函数就是深拷贝
		for (auto& e : lt)
		{
			e *= 2;
		}
		cout << endl;

		for (auto e : copy)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		//lt.clear();

		list<int> lt1;
		lt1.push_back(10);
		lt1.push_back(20);
		lt1.push_back(30);

		copy = lt1;
		for (auto e : copy)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;
	}


}
