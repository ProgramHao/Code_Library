#pragma once

#include<iostream>
#include<vector>
using namespace std;

namespace jh
{
	// ģ�����Compare(���бȽϵķº���) Ĭ����less->���
	// Compare�ǽ��бȽϵķº�����ģ����� �º���less->���
	// Compare�ǽ��бȽϵķº�����ģ����� �º���greater->С��
	//��Ϊless��greater����һ���࣬�����õ���ϵͳ����less����greater������Ҫ���������ռ�std
	template<class T, class Container = vector<T>, class Compare = std::less<T>>
	class priority_queue
	{
	public:
		//�޲�Ĭ�Ϲ��캯��
		priority_queue()
		{}


		//�õ���������Ĺ��캯��
		//����ĵ�������ģ��������������ò�ͬ�����ĵ�����
		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			// �����ѣ���Ϊpriority_queue����һ���ѣ�������ģ��ʵ��
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
			{
				adjust_down(i);
			}
		}


		// ���ϵ����㷨��ʱ�临�Ӷ�O(logN)
		void adjust_up(size_t child)
		{
			//����һ��������ģ�����Compare(���бȽϵķº���) �Ķ��󣬷������ʹ��
			Compare com;
			//���׵��±�
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				//����ģ��ʵ�ֵ�ʱ��û�мӵ�����ģ�����Compare(���бȽϵķº���)��
				//�Ϳ�������������ѻ�С��
				//�������
				//if (_con[child] > _con[parent])
				// ����С��
				//if (_con[parent] < _con[child])


				//���������˵�����ģ�����Compare(���бȽϵķº���)��ʱ��
				//���Ҹ���Ĭ�ϵĲ����º���less�Ŵ��
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


		//�ڶ�β�������ݺ�Ҫ�����γ��µĴ��Ҫ�����ϵ����㷨
		//ע������ֻ�������ϵ����㷨
		void push(const T& x)
		{
			_con.push_back(x);
			//���ﴫ���ǲ������ݺ󣬶�β���ݵ��±�
			adjust_up(_con.size() - 1);
		}


		// ���µ����㷨��ʱ�临�Ӷ�O(logN)
		void adjust_down(size_t parent)
		{
			//����һ��������ģ�����Compare(���бȽϵķº���) �Ķ��󣬷������ʹ��
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				//����ģ��ʵ�ֵ�ʱ��û�мӵ�����ģ�����Compare(���бȽϵķº���)��
				//�Ϳ�������������ѻ�С��
				// ������ѣ�ѡ�����Һ����д����һ��
				//if (child+1 < _con.size() && _con[child+1] > _con[child])
				// ����С�ѣ�ѡ�����Һ�����С����һ��
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])
				
				
			    //���������˵�����ģ�����Compare(���бȽϵķº���)��ʱ��
				//���Ҹ���Ĭ�ϵĲ����º���less�Ŵ��
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}

				//����ģ��ʵ�ֵ�ʱ��û�мӵ�����ģ�����Compare(���бȽϵķº���)��
				//�Ϳ�������������ѻ�С��
				//if (_con[child] > _con[parent])
				//if (_con[parent] < _con[child])

				//���������˵�����ģ�����Compare(���бȽϵķº���)��ʱ��
				//���Ҹ���Ĭ�ϵĲ����º���less�Ŵ��
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


		//ɾ�����ж�ͷ���ݺ�Ҫ�γ��µĴ��Ҫ�����µ����㷨
		//ע������ֻ�������µ����㷨
		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			adjust_down(0);
		}

		//���ض�ͷ������
		const T& top()
		{
			return _con[0];
		}

		//ջ�Ƿ�Ϊ�գ�������ü�һ��const��
		//���ܴ���������Ķ���(������vector�Ķ���)�Ƿ�const���Σ���������
		bool empty()  const
		{
			return _con.empty();
		}


		//����ջ������ݸ�����
		//���ܴ���������Ķ���(������vector�Ķ���)�Ƿ�const���Σ���������
		size_t size() const
		{
			return _con.size();
		}

	private:
		//��ģ��������������������������
		Container _con;
	};
}