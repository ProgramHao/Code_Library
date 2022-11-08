#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<assert.h>
#include<iostream>
using namespace std;

namespace jh
{
	template<class T>
	class vector
	{
	public:
		//系统迭代器也是这样
		//T是类vector对象存放的数据的类型，迭代器是指针。所以用T*
		typedef T* iterator;
		typedef const T* const_iterator;

		//迭代器gebin()
		//上面T*typedef成iterator，类型名重定义
		iterator begin()
		{
			return _start;
		}

		//迭代器end()
		iterator end()
		{
			return _finish;
		}

		//迭代器gebin(),传递的参数类型有const修饰
		//所以返回的迭代器，也必须要有const修饰
		//所以上面T*typedef一个const_iterator
		//注意这个this指针里的const是没有关系的
		//vector* const this,这里的const是指this指针不能修改
		//而函数后面有const这个，是指传递的参数是有const修饰
		//即如const vector<int>& v;
		// const 修饰 对象v空间不能修改
		//而类vector 对象里的成员变量为_start等，那么就不能被修改
		//所以要定义一个const_iterator,防止出现权限放大的错误
		//比如下面类外的 测试函数Func( )
		const_iterator begin() const
		{
			return _start;
		}

		//迭代器end(),传递的参数类型有const修饰
		const_iterator end() const
		{
			return _finish;
		}


		//无参构造
		vector()
			:_start(nullptr)//初始化列表，全部初始化为空指针
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}


		//构造——迭代器区间构造
		//为什么这里还有一个类模板InputIterator了
		//因为如果我们直接用iterator，那么就是使用的上面定义好的T*，就写死了
		//上面给的数据类型是什么，迭代器iterator就是什么类型指针
		//但是我们自己定义的一个类模板，就可以构造的对象里面的数据就可以自己决定
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)//必须有初始化列表，不然使用push_back会出现野指针的问题
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			//[first,end) 左闭右开
			while (first != last)
			{
				//看不懂的时候，想编译器补全的样子:this->push_back(this,*first);
				push_back(*first);
				++first;
			}
		}

		//构造函数
		//库里的explicit vector (size_type n, const value_type& val = value_type()
		//上面的value_type是typedef的T，即第一个类模板类型名重定义
		//这是半缺省，这里的缺省值 T()是T这个类型的匿名对象
		//比如这里的T是string或者vector，那么定义这个匿名对象的时候，会调用相应的默认构造
		//如果这里T是内置类型，比如int了，会有默认构造吗？会的！因为c++出现了模板
		//所以可以认为内置类型，也有构造函数
		//int是0，char是'/0',指针是空指针nullptr
		vector(size_t n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			//保留函数，直接扩容
			//看不懂的时候，想编译器补全的样子:this->reserve(this,n);
			reserve(n);

			//再将n个val插入
			for (size_t i = 0; i < n; ++i)
			{
				//看不懂的时候，想编译器补全的样子:this->reserve(this,n);
				push_back(val);
			}
		}



		//拷贝构造——传统写法
		// v2(v1)
		vector(const vector<T>& v)
		{
			_start = new T[v.size()]; // v.capacity()也可以
			//将数据拷贝到新空间里
			memcpy(_start, v._start, sizeof(T)*v.size());
			//这段代码也可以代替上面的memcpy，都可以
			//for (size_t i = 0; i < v.size(); ++i)
			//{
			//	_start[i] = v._start[i];
			//}

			_finish = _start + v.size();
			//如果前面开空间用的v.capacity()，那么这里应该加v.capacity()
			_end_of_storage = _start + v.size();
		}

		
		//拷贝构造——其他写法
		//v2(v1)
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			//用保留函数，直接扩容 
			//看不懂的时候，想编译器补全的样子:this->reserve(v.size());
			reserve(v.size());
			//最好给引用，因为这里的数据类型是T
			//T可能会是vector类型，用引用就不会出现 死递归拷贝构造
			//用了引用，因为传递给函数的参数也是const修饰
			//所以也要加上const,防止出现 引用权限提高的错误
			for (const auto& e : v)
			{
				//看不懂的时候，想编译器补全的样子:this->push_back(e);
				push_back(e);
			}
		}




		//交换函数
		void swap(vector<T>& v)
		{
			//用到系统定义好的swap函数，所以用上了命名空间std
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		//拷贝构造的现代写法
		// v2(v1)
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			//用上面的交换函数swap( )
			//看不懂的时候，想编译器补全的样子:this->swap(this,tmp);
			swap(tmp);
		}



		//赋值符重载——现代写法(推荐)
		// v1 = v2
		vector<T>& operator=(vector<T> v)
		{
			//这样交换后，相当于打工人，v2里的全给了v1
			swap(v);
			return *this;
		}


		//析构函数
		~vector()
		{
			//因为迭代器_start是指向存放数据的第一个数据的空间
			delete[] _start;
			//再置为空指针
			_start = _finish = _end_of_storage = nullptr;
		}

		//求容量的函数
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		//操作符[],传的数据的类型是const修饰
		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

		//操作符[],传的数据的类型 没有 const修饰
		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		//有效数据个数的函数
		size_t size() const
		{
			return _finish - _start;
		}



		//保留函数，扩容
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//有效数据函数size( )计算扩容前的有效数据个数
				//方便后面的使用
				size_t sz = size();
				T* tmp = new T[n];//T就是存放的数据的类型
				if (_start)
				{
					//将之前的数据拷贝过来
					memcpy(tmp, _start, sizeof(T) * sz);
					//释放之前的空间
					delete[] _start;
				}

				//迭代器_start的地址改变成新的空间地址
				_start = tmp;
				//迭代器_finish指向最后一个有效数据的空间 的下一个
				//注意这里不能用size(),看自己定义的size函数，_start已经改变
				_finish = _start + sz;
				//迭代器_end_of_storage指向新容量最后的地址
				_end_of_storage = _start + n;
			}
		}


		//扩容和缩容
		//同样给了一个缺省值T()，是匿名对象
		void resize(size_t n, const T& val = T())
		{
			//需要的扩容到空间n 比 容量 大
			if (n > capacity())
			{
				//复用reserve()直接扩容
				//看不懂的时候，想编译器补全的样子:this->reserve(this,n);
				reserve(n);
			}

			//需要的扩容到空间n 比 有效数据个数 大
			if (n > size())
			{
				// 初始化填值
				while (_finish < _start + n)
				{
					//将多的那一块空间，初始化为val
					*_finish = val;
					++_finish;
				}
			}
			else //空间n 比 有效数据个数 小会等于，需要缩容
			{
				//直接将_finish(end())的位置指向空间到n的位置
				_finish = _start + n;
			}
		}



		//尾插
		//为什么这里要加const，因为可能给的参数是一个隐式类型转换
		//比如vector<string> v;v.push_back("xx");
		//这里的字符串"xx"会先生成临时变量转换为类string类型，而临时变量具有常性
		//而这里用的引用，所以必须加const，不然会发生权限变大的错误
		void push_back(const T& x)
		{
			//扩容，两个迭代器指向的同一个位置
			if (_finish == _end_of_storage)
			{
				//函数capacity()计算容量
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			*_finish = x;//放入数据
			++_finish;//指针指向下一个

			////可以直接复用插入函数insert()代替上面的代码
			//insert(end(), x);
		}


		//尾删
		void pop_back()
		{
			//断言：防止没有数据，就不需要尾删
			assert(_finish > _start);
			--_finish;
		}


		//插入数据的函数
		//在位置pos(迭代器，即指针)处，插入一个数据
		//插入后，包括位置pos及后面的数据往后挪
		void insert(iterator pos, const T& x)
		{
			//断言：位置pos(迭代器)必须正常
			assert(pos >= _start);
			assert(pos <= _finish);

			//空间不够就要扩容
			if (_finish == _end_of_storage)
			{
				//先记录一下相对位置的长度
				//因为扩容需要建立新的空间，迭代器pos指向空间地址会改变
				//这个时候就会发生迭代器失效的问题，就变成野指针了
				//所以需要将迭代器更新一下
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				//找到新的空间，pos相对与_start的相对位置
				//更新迭代器pos的位置
				//注意一点：这里的pos是传值传参，是 拷贝
				//所以外部的pos并没有改变
				//所以插入一个数据后，我们有时候不知道是否扩容
				//所以最好在外部，就不要再继续用外部的pos了
				//因为可能会迭代器失效
				//虽然这里用引用可以解决，但是会让其他的函数受影响
				//而且库里也是传值传参，所以不要用引用
				pos = _start + len;
			}

			// 挪动数据——要挪的数据，从后往前挪
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;

			//插入一个数据后，迭代器_finish要加加一次
			//迭代器_finish指向最后一个有效数据的空间 的下一个
			++_finish;
		}



		//删除位置pos(迭代器)处的数据
		// 方便解决:一边遍历一边删除的迭代器失效问题
		
		//系统的erase()函数，其实内部会有缩容的代码
		//所以会出现迭代器pos失效的问题
		//所以系统会给返回迭代器pos的位置
		iterator erase(iterator pos)
		{
			// 挪动数据进行删除
			iterator begin = pos + 1;
			//将pos位置后的数据往前移动，是从前面的数据开始往前移动
			while (begin != _finish) {
				*(begin - 1) = *begin;
				++begin;
			}

			//删除一个数据后，迭代器_finish要--
			--_finish;

			//这里如果不返回这个pos位置，那么这几段代码会出错
			//即函数定义成void，会出现问题
			//返回一个，可以解决各种各样的意外
			//这里迭代器pos依旧是指向 已经删除数据的 那一块空间
			//但是因为删除数据后，数据会往前挪，所以这个时候这个空间
			//存放的数据是这个删除数据的下一个数据
			return pos;
		}


		//返回第一个数据
		T& front()
		{
			assert(size() > 0);

			return *_start;
		}

		//返回最后一个数据
		T& back()
		{
			assert(size() > 0);

			return *(_finish - 1);
		}


	private:
		//注意：只要是指针，都是内置类型，不管什么类型的指针
		//系统的类vector也是三个私有成员变量
		//迭代器，类似指针一样
		iterator _start;
		//迭代器_finish指向最后一个有效数据的空间 的下一个
		iterator _finish;
		iterator _end_of_storage;


	};

	//下面是类vector外，命名空间jh里

	//测试迭代器用const修饰(const_iterator)的函数
	void Func(const vector<int>& v)
	{
		//这里的v是引用，并用const修饰
		//所以迭代器v.begin()就必须是const修饰的迭代器
		//因为迭代器begin(),是对象v空间存放的成员变量_start
		//即_start不能修改，所以作为迭代器，就必须是const修饰的迭代器
		//因为 引用，防止出现引用 权限变大的错误
		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			//*it = 10;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}


	void test_vector1()
	{
		/*double d = 2.2;
		const int& i = d;

		vector<string> v;
		v.push_back("xxxxx");*/

		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		//注意定义迭代器变量的方式
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		v.pop_back();
		v.pop_back();

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}



	void test_vector7()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(4);


		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v1(v);
		v[0] *= 10;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector8()
	{
		string s("hello world");
		vector<int> vs(s.begin(), s.end());
		for (auto e : vs)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(4);

		vs = v;  // 赋值重载
		vector<int> copy = v; // 等价于copy(v) ，所以还是拷贝构造

		vs[0] *= 10;
		for (auto e : vs)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}



	void test_vector10()
	{
		vector<int> v1;
		v1.resize(10, 0);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		//std::vector<int> v2;
		vector<int> v2;
		v2.reserve(10);
		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);
		v2.push_back(4);
		v2.push_back(5);

		v2.resize(8, 8);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		v2.resize(20, 20);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		v2.resize(3);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
	}


}