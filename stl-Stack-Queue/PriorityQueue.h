#pragma once

#include<iostream>
#include<vector>
using namespace std;

namespace jh
{
	// 模板参数Compare(进行比较的仿函数) 默认是less->大堆
	// Compare是进行比较的仿函数的模板参数 仿函数less->大堆
	// Compare是进行比较的仿函数的模板参数 仿函数greater->小堆
	//因为less和greater都是一种类，这里用的是系统的类less和类greater；所以要加上命名空间std
	template<class T, class Container = vector<T>, class Compare = std::less<T>>
	class priority_queue
	{
	public:
		//无参默认构造函数
		priority_queue()
		{}


		//用迭代器区间的构造函数
		//这里的迭代器是模板参数，即可以用不同容器的迭代器
		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			// 建立堆，因为priority_queue就是一个堆，这里是模拟实现
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
			{
				adjust_down(i);
			}
		}


		// 向上调整算法，时间复杂度O(logN)
		void adjust_up(size_t child)
		{
			//定义一个第三个模板参数Compare(进行比较的仿函数) 的对象，方便后面使用
			Compare com;
			//父亲的下标
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				//这是模拟实现的时候，没有加第三个模板参数Compare(进行比较的仿函数)，
				//就可以这样建立大堆或小堆
				//建立大堆
				//if (_con[child] > _con[parent])
				// 建立小堆
				//if (_con[parent] < _con[child])


				//这是设置了第三个模板参数Compare(进行比较的仿函数)的时候，
				//并且给了默认的参数仿函数less排大堆
				if (com(_con[parent], _con[child]))
				{
					std::swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}


		//在队尾插入数据后，要重新形成新的大堆要用向上调整算法
		//注意这里只能用向上调整算法
		void push(const T& x)
		{
			_con.push_back(x);
			//这里传的是插入数据后，队尾数据的下标
			adjust_up(_con.size() - 1);
		}


		// 向下调整算法，时间复杂度O(logN)
		void adjust_down(size_t parent)
		{
			//定义一个第三个模板参数Compare(进行比较的仿函数) 的对象，方便后面使用
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				//这是模拟实现的时候，没有加第三个模板参数Compare(进行比较的仿函数)，
				//就可以这样建立大堆或小堆
				// 建立大堆，选出左右孩子中大的那一个
				//if (child+1 < _con.size() && _con[child+1] > _con[child])
				// 建立小堆，选出左右孩子中小的那一个
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])
				
				
			    //这是设置了第三个模板参数Compare(进行比较的仿函数)的时候，
				//并且给了默认的参数仿函数less排大堆
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}

				//这是模拟实现的时候，没有加第三个模板参数Compare(进行比较的仿函数)，
				//就可以这样建立大堆或小堆
				//if (_con[child] > _con[parent])
				//if (_con[parent] < _con[child])

				//这是设置了第三个模板参数Compare(进行比较的仿函数)的时候，
				//并且给了默认的参数仿函数less排大堆
				if (com(_con[parent], _con[child]))
				{
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}


		//删除队列队头数据后，要形成新的大堆要用向下调整算法
		//注意这里只能用向下调整算法
		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			adjust_down(0);
		}

		//返回对头的数据
		const T& top()
		{
			return _con[0];
		}

		//栈是否为空，这里最好加一个const，
		//不管传入的容器的对象(比如类vector的对象)是否被const修饰，都可以用
		bool empty()  const
		{
			return _con.empty();
		}


		//返回栈里的数据个数，
		//不管传入的容器的对象(比如类vector的对象)是否被const修饰，都可以用
		size_t size() const
		{
			return _con.size();
		}

	private:
		//用模板参数容器，可以用任意的容器
		Container _con;
	};
}