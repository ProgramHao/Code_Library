#include <iostream>
#include <vector>
#include <string>

//这个标准模板库:algorithm(算法)，里面有很多算法接口函数
//https://legacy.cplusplus.com/reference/algorithm/?kw=algorithm
#include <algorithm>

//头文件
#include <functional>
using namespace std;

//vector和string一样，都是一种类
//而且十分的相似
//vector其实就是顺序表，所以也是用的数组，所以和类string很相似
//成员变量和成员函数 基本一样
//和类string一样，类vector也是看文档
//https://cplusplus.com/reference/vector/vector/

//用了和系统的命名空间std一样的名字，是为了与后面的模拟实现vector区分
//名字可以一样，因为在编译链接的时候，相同名字的命名空间会合并
namespace std
{
	void test_vector1()
	{
		//模板类型T设为int
		//无参构造
		vector<int> v1;
		//构造10个整型1
		vector<int> v2(10, 1);
		//拷贝构造
		vector<int> v3(v2);
	}

	void test_vector2()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		// 下标+[]
		for (size_t i = 0; i < v1.size(); ++i)
		{
			v1[i]++;
		}
		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		// 迭代器
		//这里具体的迭代器begin( ),是指向第一个数据的类似指针的东西
		//返回的是指向第一个数据空间的迭代器，迭代器类型为iterator
		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			(*it)--;

			cout << *it << " ";
			++it;
		}
		cout << endl;

		//将类vector对象v1的数据依次给变量e
		//auto是存储器，还有自动识别数据类型的功能
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}


	//测试类vector的扩容机制
	void TestVectorExpand()
	{
		size_t sz;
		vector<int> v;
		//v.resize(100);
		v.reserve(100);

		sz = v.capacity();
		cout << "making v grow:\n";
		for (int i = 0; i < 100; ++i)
		{
			v.push_back(i);
			if (sz != v.capacity())
			{
				sz = v.capacity();
				cout << "capacity changed: " << sz << '\n';
			}
		}
	}

	void test_vector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		//求该数据的类型可以的最大值，这里是整型，所以是42亿多
		//但是结果是10亿多，是因为这里要除以sizeof(int)
		//但是这个成员函数没有意义，用不到
		cout << v1.max_size() << endl;

		//测试类vector的扩容机制
		//运行后的结果：成员变量 容量_capacity是大概1.5倍增长
		//但是这是在vs2013编译器下的扩容机制
		//如果是在g++编译器下，是以2倍的方式增长
		TestVectorExpand();
	}


	void test_vector4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		//在 标准模板库:algorithm(算法)里，find( )
		//所以类vector里，没有设计成员函数find()
		//找数据的位置，如果没找到，会返回迭代器end( )
		//迭代器end()是指向最后一个数据空间 类似指针的 东西
		vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
		if (pos != v1.end())//判断是否找到
		{
			//插入函数
			v1.insert(pos, 30);
		}

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;


		pos = find(v1.begin(), v1.end(), 300);
		if (pos != v1.end())//判断是否找到
		{
			//删除函数 
			v1.erase(pos);
		}

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}


	void test_vector5()
	{
		vector<int> v1;
		v1.push_back(10);
		v1.push_back(2);
		v1.push_back(32);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(1);
		v1.push_back(9);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;


		//函数排序sort(),系统定义在命名空间std里
		//这里的函数sort()默认排升序，自己去c++网站查就明白了
		sort(v1.begin(), v1.end());

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;


		//这两个函数都在头文件functional(函数对象)里
		// 先会用，后面会讲解
		////less<int> ls; 类模板函数，这是升序函数
		////greater<int> gt; 类模板函数，这是降序函数
		
		//sort(v1.begin(), v1.end(), ls); 传对象ls还是排升序

		//排降序，不能直接传对象gt，会出错，传匿名对象greater<int>()
		sort(v1.begin(), v1.end(), greater<int>());
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;


		string s("hello313131244");
		//sort(s.begin(), s.end());
		sort(s.begin(), s.end(), greater<char>());//排降序
		cout << s << endl;


		//vector<char> v; 顺序表，存字符(因为给的模板类型是char)
		//string str;  字符串 
		//区别：最大的是数据结尾\0 
		// string有：+=、find、比较大小、to_string、<< 、>>等等，vector没有
		// 因为上面的区别，所以 vector<char> 无法替代string


		//类vector：void push_back (const value_type& val);
		vector<string> strV;
		string str1("张三");

		strV.push_back(str1);
		strV.push_back(string("李四"));//传匿名对象，匿名对象和临时变量一样，具有常性

		//直接传字符串，这里是隐式类型转换
		strV.push_back("王六");
		strV.push_back("赵七");

		//因为是类vector的对象strV存的数据是类string
		//所以依次将数据给str会设计深拷贝，为了避免这种情况
		//所以str设置为引用，这样就不会深拷贝了，效率大大提高
		for (const auto& str : strV)
		{
			cout << str << endl;
		}
	}

}

	int main()
	{
		std::test_vector1();

		return 0;
	}
