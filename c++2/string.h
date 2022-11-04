#pragma once

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<iostream>
using namespace std;

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
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		string(const string& s);
		string& operator=(const string& s);


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

		void push_back(char ch);
		void append(const char* str);
		string& operator+=(char ch);
		string& operator+=(const char* str);


	private:
		size_t _capacity;
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