#pragma once

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<iostream>
using namespace std;

//注意：这里是我们自己定义的命名空间bit，在里面模拟实现string类
//而系统设计好的string类，是在系统的命名空间std里，
//所以这里面的所有string类，都用不了系统写好的string类里面的东西
//这样就好模拟实现string类
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		//第一个数据的地址
		iterator begin()
		{
			return _str;
		}

		//最后一个数据的下一个地址（字符'/0'不算数据里面）
		iterator end()
		{
			return _str + _size;
		}


		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		//对比下面的代码，它是可以的
		/*string()
			:_str(new char[1])
			, _size(0)
			, _capacity(0)
		{
			_str[0] = '\0';
		}*/


		//不能这么初始化空对象，因为成员函数 c_str( )
		//不能初始化_str为空指针，因为成员函数 c_str( )
		/*string()
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
			{}*/


		//string(const char* str = "\0")
		//字符串 "" ,这样表示其实在编译器已经是有字符/0了
		//不需要再自己写字符'/0',有点画蛇添足的感觉
		//string(const char* str = "")
		//	:_str(new char[strlen(str)+1])
		//	, _size(strlen(str))
		//	, _capacity(strlen(str))
		//{
		//	strcpy(_str, str);
		//}


		//这样会出错，因为第一次构造的时候，因为
		//而根据初始化列表的顺序，_capacity是随机值，所以会出问题
		//string(const char* str = "")
		//		: _size(strlen(str))
		//		, _str(new char[_capacity + 1])
		//		, _capacity(_size)
		//	{
		//		strcpy(_str, str);
		//	}


		//不推荐用初始化列表，因为会跟顺序相联系，有时候维护会有问题
		//所以直接在函数内部初始化，如下
		string(const char* str = "")//给了一个缺省值：空字符串
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		

		//拷贝构造
		// 传统写法
		 //s2(s1)，看不懂的时候，别忘了省略的this指针
		string(const string& s)
			:_str(new char[s._capacity+1])
			, _size(s._size)
			, _capacity(s._capacity)
		{
			strcpy(_str, s._str);
		}


		//赋值操作符1
		// s1 = s3
		// s1 = s1
		string& operator=(const string& s)
		{
			//防止自己给自己赋值的情况，就没必要下面的操作
			if (this != &s)
			{
				//新开辟一块空间
				//开辟新空间的原因：不知道两个对象的成员指针分别指向的空间的大小
				//所以为了避免空间够不够，直接开辟一块一样的空间，就不用考虑了
				char* tmp = new char[s._capacity + 1];
				//将要拷贝的内容，拷贝到新开辟的空间里
				strcpy(tmp, s._str);

				//因为赋值之前，已经定义了这个对象
				//即已经构造了，所以对象里的成员指针_str会指向一块空间
				//所以如果直接改变指针_str的值，就会导致之前的那块空间找不到了
				//所以为了防止这块空间内存泄漏，所以需要先delete释放这块空间
				delete[] _str;

				//上面已经将之前指针_str指向的空间释放
				//这时候就可以改变指针_str的值，这样就不会内存泄露了
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}

			return *this;
		}





		//拷贝构造——现代写法
		// 现代写法 -- 资本主义/老板思维
        // s2(s1)
		void swap(string& tmp)
		{
			//加::，是因为这里调用的全局的swap，为了区分，才加上
			::swap(_str, tmp._str);
			::swap(_size, tmp._size);
			::swap(_capacity, tmp._capacity);
		}
		//现代写法——拷贝构造
		// s2(s1)
		string(const string& s)
			:_str(nullptr)
			, _size(0)   
			, _capacity(0)
		{
			//这里用初始列列表，因为这里是交换，如果没有，
			//临时对象tmp会是随机值，然后交换后，对象s1
			//里的成员指针指向的那块空间(即tmp里的_str指向的空间)
			//出函数后就会被析构，但是那块空间里是存放的随机的，用不了
			//析构函数，就会报错
			string tmp(s._str);
			//自己模拟的类string的swap
			swap(tmp); //this->swap(tmp);
		}


		//赋值操作符2
		//s1 = s3
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				//string tmp(s._str);和string tmp(s)一样
				string tmp(s);
				swap(tmp); // this->swap(tmp);
				//这里绝对不能用全局的swap，可以去网站看
				//就是::swap(*this,tmp),因为这个函数内部
				//就继续类对象赋值，就会一直循环，会栈溢出
			}
			return *this;
		}
		//上面的赋值操作符2 的简化
		// s1 = s3
		// s顶替tmp做打工人
		string& operator=(string s)
		{
			//编译器补全的：swap(this,s);
			//void swap(string* const this,string& s)
			swap(s);
			return *this;
		}



		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}


		//系统的类string的reserve只扩容不删容，自定义也要这样
		//保留函数，就是数据大于容量的时候
		void reserve(size_t n)
		{
			//数据大于容量，需要扩容
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];//多的一个是给字符'/0'
				//将成员指针_str指向的空间的数据复制过来
				strcpy(tmp, _str);
				//然后释放成员指针_str指向的空间，防止内存泄漏
				delete[] _str;

				//所以这样就可以 直接改变指针_str的值
				_str = tmp;
				_capacity = n;//容量也改变了
			}
		}


		//尾插，插入一个字符
		void push_back(char ch)
		{
			//满了就扩容
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			_str[_size] = ch;
			++_size;
			//_size加加后，要注意放入字符'/0'
			_str[_size] = '\0';

			//定义了插入函数后，就可以直接用插入函数即可
			//上面的代码都不需要了
			//insert(_size, ch);
		}

		
		//也是尾插，不过这里是插入的一个字符串
		void append(const char* str)
		{
			size_t len = strlen(str);

			// 满了就扩容
			// _size + len  8  18  10  
			if (_size + len > _capacity)
			{
				reserve(_size+len);
			}

			strcpy(_str + _size, str);
			//strcat(_str, str); 需要找\0，效率低，用strpcy即可
			_size += len;
			
			//定义了插入函数后，就可以直接用插入函数即可
			//上面的代码都不需要了
			//insert(_size, str);
		}


		//运算操作符+=，这里插入的一个字符
		//+=用于尾插是最好用的，这里可以直接复用函数push_back( )
		string& operator+=(char ch)
		{
			//直接尾插
			push_back(ch);
			return *this;
		}


		string& operator+=(const char* str);


	private:
		size_t _capacity;//能存储有效数据的空间
		size_t _size;
		char* _str;
	};

	void test_string1()
	{
		/*std::string s1("hello world");
		std::string s2;*/
		string s1("hello world");
		string s2;

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		for (size_t i = 0; i < s1.size(); ++i)
		{
			s1[i]++;
		}

		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout << s1[i] << " ";
		}
		cout << endl;
	}

	void test_string2()
	{
		string s1("hello world");
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		it = s1.begin();
		while (it != s1.end())
		{
			*it += 1;
			++it;
		}
		cout << endl;

		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}
}