#pragma once

#include<deque>//容器deque的头文件

namespace jh
{
	//queue的模板容器给的默认 是容器deque，所以它是queue的底层容器，
    //如果模板容器没有具体的容器时(比如容器list等)，就用的默认容器，
	//注意：容器适配器queue 不支持容器vector
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		//队尾入
		void push(const T& x)
		{
			_con.push_back(x);
		}

		//对头删
		void pop()
		{
			_con.pop_front();
		}

		//队尾数据
		T& back()
		{
			return _con.back();
		}

		//对头数据
		T& front()
		{
			return _con.front();
		}

		//返回队尾的数据
		//传入的容器的对象(比如类list的对象)被const修饰
		const T& back() const
		{
			return _con.back();
		}

		//返回队头的数据
		//传入的容器的对象(比如类list的对象)被const修饰
		const T& front() const
		{
			return _con.front();
		}

		//栈是否为空，这里最好加一个const，
		//不管传入的容器的对象(比如类list的对象)是否被const修饰，都可以用
		bool empty()  const
		{
			return _con.empty();
		}

		//返回队列里的数据个数
		size_t size() const
		{
			return _con.size();
		}
	private:
		//这里模拟实现栈，我们可以封装一个链表queue，更方便实现模拟
		//所以就可以直接调用queue的接口，用来实现上面的功能(删除插入数据等)
		//这里就相当于queue的底层用了list这样的容器，
		//但是这里的queue并不是适配器，这里的queue只能算封装的一个vector，
		//因为我们说stack和queue是一个容器适配器，那么如何让它们是适配器了？
		//那么底层的容器就不能写死，比如这里用了容器list，那么就只能用list的相关接口
		// 来实现上面的功能，比如删除插入数据等
		//list<T> _con;


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