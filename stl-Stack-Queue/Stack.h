#pragma once
#include<deque>//容器deque的头文件

namespace jh
{
	//stack的模板容器给的默认 是容器deque，所以它是satck的底层容器，
	//如果模板容器没有具体的容器时(比如容器vector、list等)，就用的默认容器
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		//入栈
		void push(const T& x)
		{
			_con.push_back(x);
		}

		//出栈
		void pop()
		{
			_con.pop_back();
		}

		//返回栈顶元素
		T& top()
		{
			return _con.back();
		}

		//传入的容器的对象(比如类vector的对象)被const修饰
		const T& top() const
		{
			return _con.back();
		}

		//栈是否为空，这里最好加一个const，
		//不管传入的容器的对象(比如类vector的对象)是否被const修饰，都可以用
		bool empty()  const
		{
			return _con.empty();
		}

		//返回栈里的数据个数
		size_t size() const
		{
			return _con.size();
		}



	private:
		//这里模拟实现栈，我们可以封装一个顺序表vector，更方便实现模拟
		//所以就可以直接调用vector的接口，用来实现上面的功能(尾插尾删等)
		//这里就相当于stack的底层用了vector这样的容器，
		//但是这里的stack并不是适配器，这里的stack只能算封装的一个vector，
		//因为我们说stack和queue是一个容器适配器，那么如何让它们是适配器了？
		//那么底层的容器就不能写死，比如这里用了容器vector，那么就只能用vector的相关接口
		// 来实现上面的功能，比如尾插尾删等
		//vector<T> _con;

		
		// 什么是适配器了？就比如一个接口，充电就是功能，
		// 如果它既可以给手机充电，又可以给电脑耳机等等充电；
		// 那么这个接口的另一端，不同的电压就是容器，
		// 不管是插在220v的电压上，还是车载电压上等等，都可以实现这个功能；
		// 那么这个接口就是适配器！！
		//这里就给容器一个模板参数，此时的stack就是一个容器适配器了，
		//因为这里的容器是多变的
		Container _con;
	};


}