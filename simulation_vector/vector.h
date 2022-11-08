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
		//ϵͳ������Ҳ������
		//T����vector�����ŵ����ݵ����ͣ���������ָ�롣������T*
		typedef T* iterator;
		typedef const T* const_iterator;

		//������gebin()
		//����T*typedef��iterator���������ض���
		iterator begin()
		{
			return _start;
		}

		//������end()
		iterator end()
		{
			return _finish;
		}

		//������gebin(),���ݵĲ���������const����
		//���Է��صĵ�������Ҳ����Ҫ��const����
		//��������T*typedefһ��const_iterator
		//ע�����thisָ�����const��û�й�ϵ��
		//vector* const this,�����const��ָthisָ�벻���޸�
		//������������const�������ָ���ݵĲ�������const����
		//����const vector<int>& v;
		// const ���� ����v�ռ䲻���޸�
		//����vector ������ĳ�Ա����Ϊ_start�ȣ���ô�Ͳ��ܱ��޸�
		//����Ҫ����һ��const_iterator,��ֹ����Ȩ�޷Ŵ�Ĵ���
		//������������� ���Ժ���Func( )
		const_iterator begin() const
		{
			return _start;
		}

		//������end(),���ݵĲ���������const����
		const_iterator end() const
		{
			return _finish;
		}


		//�޲ι���
		vector()
			:_start(nullptr)//��ʼ���б�ȫ����ʼ��Ϊ��ָ��
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}


		//���졪�����������乹��
		//Ϊʲô���ﻹ��һ����ģ��InputIterator��
		//��Ϊ�������ֱ����iterator����ô����ʹ�õ����涨��õ�T*����д����
		//�����������������ʲô��������iterator����ʲô����ָ��
		//���������Լ������һ����ģ�壬�Ϳ��Թ���Ķ�����������ݾͿ����Լ�����
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)//�����г�ʼ���б���Ȼʹ��push_back�����Ұָ�������
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			//[first,end) ����ҿ�
			while (first != last)
			{
				//��������ʱ�����������ȫ������:this->push_back(this,*first);
				push_back(*first);
				++first;
			}
		}

		//���캯��
		//�����explicit vector (size_type n, const value_type& val = value_type()
		//�����value_type��typedef��T������һ����ģ���������ض���
		//���ǰ�ȱʡ�������ȱʡֵ T()��T������͵���������
		//���������T��string����vector����ô����������������ʱ�򣬻������Ӧ��Ĭ�Ϲ���
		//�������T���������ͣ�����int�ˣ�����Ĭ�Ϲ����𣿻�ģ���Ϊc++������ģ��
		//���Կ�����Ϊ�������ͣ�Ҳ�й��캯��
		//int��0��char��'/0',ָ���ǿ�ָ��nullptr
		vector(size_t n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			//����������ֱ������
			//��������ʱ�����������ȫ������:this->reserve(this,n);
			reserve(n);

			//�ٽ�n��val����
			for (size_t i = 0; i < n; ++i)
			{
				//��������ʱ�����������ȫ������:this->reserve(this,n);
				push_back(val);
			}
		}



		//�������졪����ͳд��
		// v2(v1)
		vector(const vector<T>& v)
		{
			_start = new T[v.size()]; // v.capacity()Ҳ����
			//�����ݿ������¿ռ���
			memcpy(_start, v._start, sizeof(T)*v.size());
			//��δ���Ҳ���Դ��������memcpy��������
			//for (size_t i = 0; i < v.size(); ++i)
			//{
			//	_start[i] = v._start[i];
			//}

			_finish = _start + v.size();
			//���ǰ�濪�ռ��õ�v.capacity()����ô����Ӧ�ü�v.capacity()
			_end_of_storage = _start + v.size();
		}

		
		//�������졪������д��
		//v2(v1)
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			//�ñ���������ֱ������ 
			//��������ʱ�����������ȫ������:this->reserve(v.size());
			reserve(v.size());
			//��ø����ã���Ϊ���������������T
			//T���ܻ���vector���ͣ������þͲ������ ���ݹ鿽������
			//�������ã���Ϊ���ݸ������Ĳ���Ҳ��const����
			//����ҲҪ����const,��ֹ���� ����Ȩ����ߵĴ���
			for (const auto& e : v)
			{
				//��������ʱ�����������ȫ������:this->push_back(e);
				push_back(e);
			}
		}




		//��������
		void swap(vector<T>& v)
		{
			//�õ�ϵͳ����õ�swap���������������������ռ�std
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		//����������ִ�д��
		// v2(v1)
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			//������Ľ�������swap( )
			//��������ʱ�����������ȫ������:this->swap(this,tmp);
			swap(tmp);
		}



		//��ֵ�����ء����ִ�д��(�Ƽ�)
		// v1 = v2
		vector<T>& operator=(vector<T> v)
		{
			//�����������൱�ڴ��ˣ�v2���ȫ����v1
			swap(v);
			return *this;
		}


		//��������
		~vector()
		{
			//��Ϊ������_start��ָ�������ݵĵ�һ�����ݵĿռ�
			delete[] _start;
			//����Ϊ��ָ��
			_start = _finish = _end_of_storage = nullptr;
		}

		//�������ĺ���
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		//������[],�������ݵ�������const����
		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

		//������[],�������ݵ����� û�� const����
		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		//��Ч���ݸ����ĺ���
		size_t size() const
		{
			return _finish - _start;
		}



		//��������������
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//��Ч���ݺ���size( )��������ǰ����Ч���ݸ���
				//��������ʹ��
				size_t sz = size();
				T* tmp = new T[n];//T���Ǵ�ŵ����ݵ�����
				if (_start)
				{
					//��֮ǰ�����ݿ�������
					memcpy(tmp, _start, sizeof(T) * sz);
					//�ͷ�֮ǰ�Ŀռ�
					delete[] _start;
				}

				//������_start�ĵ�ַ�ı���µĿռ��ַ
				_start = tmp;
				//������_finishָ�����һ����Ч���ݵĿռ� ����һ��
				//ע�����ﲻ����size(),���Լ������size������_start�Ѿ��ı�
				_finish = _start + sz;
				//������_end_of_storageָ�����������ĵ�ַ
				_end_of_storage = _start + n;
			}
		}


		//���ݺ�����
		//ͬ������һ��ȱʡֵT()������������
		void resize(size_t n, const T& val = T())
		{
			//��Ҫ�����ݵ��ռ�n �� ���� ��
			if (n > capacity())
			{
				//����reserve()ֱ������
				//��������ʱ�����������ȫ������:this->reserve(this,n);
				reserve(n);
			}

			//��Ҫ�����ݵ��ռ�n �� ��Ч���ݸ��� ��
			if (n > size())
			{
				// ��ʼ����ֵ
				while (_finish < _start + n)
				{
					//�������һ��ռ䣬��ʼ��Ϊval
					*_finish = val;
					++_finish;
				}
			}
			else //�ռ�n �� ��Ч���ݸ��� С����ڣ���Ҫ����
			{
				//ֱ�ӽ�_finish(end())��λ��ָ��ռ䵽n��λ��
				_finish = _start + n;
			}
		}



		//β��
		//Ϊʲô����Ҫ��const����Ϊ���ܸ��Ĳ�����һ����ʽ����ת��
		//����vector<string> v;v.push_back("xx");
		//������ַ���"xx"����������ʱ����ת��Ϊ��string���ͣ�����ʱ�������г���
		//�������õ����ã����Ա����const����Ȼ�ᷢ��Ȩ�ޱ��Ĵ���
		void push_back(const T& x)
		{
			//���ݣ�����������ָ���ͬһ��λ��
			if (_finish == _end_of_storage)
			{
				//����capacity()��������
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			*_finish = x;//��������
			++_finish;//ָ��ָ����һ��

			////����ֱ�Ӹ��ò��뺯��insert()��������Ĵ���
			//insert(end(), x);
		}


		//βɾ
		void pop_back()
		{
			//���ԣ���ֹû�����ݣ��Ͳ���Ҫβɾ
			assert(_finish > _start);
			--_finish;
		}


		//�������ݵĺ���
		//��λ��pos(����������ָ��)��������һ������
		//����󣬰���λ��pos���������������Ų
		void insert(iterator pos, const T& x)
		{
			//���ԣ�λ��pos(������)��������
			assert(pos >= _start);
			assert(pos <= _finish);

			//�ռ䲻����Ҫ����
			if (_finish == _end_of_storage)
			{
				//�ȼ�¼һ�����λ�õĳ���
				//��Ϊ������Ҫ�����µĿռ䣬������posָ��ռ��ַ��ı�
				//���ʱ��ͻᷢ��������ʧЧ�����⣬�ͱ��Ұָ����
				//������Ҫ������������һ��
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				//�ҵ��µĿռ䣬pos�����_start�����λ��
				//���µ�����pos��λ��
				//ע��һ�㣺�����pos�Ǵ�ֵ���Σ��� ����
				//�����ⲿ��pos��û�иı�
				//���Բ���һ�����ݺ�������ʱ��֪���Ƿ�����
				//����������ⲿ���Ͳ�Ҫ�ټ������ⲿ��pos��
				//��Ϊ���ܻ������ʧЧ
				//��Ȼ���������ÿ��Խ�������ǻ��������ĺ�����Ӱ��
				//���ҿ���Ҳ�Ǵ�ֵ���Σ����Բ�Ҫ������
				pos = _start + len;
			}

			// Ų�����ݡ���ҪŲ�����ݣ��Ӻ���ǰŲ
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;

			//����һ�����ݺ󣬵�����_finishҪ�Ӽ�һ��
			//������_finishָ�����һ����Ч���ݵĿռ� ����һ��
			++_finish;
		}



		//ɾ��λ��pos(������)��������
		// ������:һ�߱���һ��ɾ���ĵ�����ʧЧ����
		
		//ϵͳ��erase()��������ʵ�ڲ��������ݵĴ���
		//���Ի���ֵ�����posʧЧ������
		//����ϵͳ������ص�����pos��λ��
		iterator erase(iterator pos)
		{
			// Ų�����ݽ���ɾ��
			iterator begin = pos + 1;
			//��posλ�ú��������ǰ�ƶ����Ǵ�ǰ������ݿ�ʼ��ǰ�ƶ�
			while (begin != _finish) {
				*(begin - 1) = *begin;
				++begin;
			}

			//ɾ��һ�����ݺ󣬵�����_finishҪ--
			--_finish;

			//����������������posλ�ã���ô�⼸�δ�������
			//�����������void�����������
			//����һ�������Խ�����ָ���������
			//���������pos������ָ�� �Ѿ�ɾ�����ݵ� ��һ��ռ�
			//������Ϊɾ�����ݺ����ݻ���ǰŲ���������ʱ������ռ�
			//��ŵ����������ɾ�����ݵ���һ������
			return pos;
		}


		//���ص�һ������
		T& front()
		{
			assert(size() > 0);

			return *_start;
		}

		//�������һ������
		T& back()
		{
			assert(size() > 0);

			return *(_finish - 1);
		}


	private:
		//ע�⣺ֻҪ��ָ�룬�����������ͣ�����ʲô���͵�ָ��
		//ϵͳ����vectorҲ������˽�г�Ա����
		//������������ָ��һ��
		iterator _start;
		//������_finishָ�����һ����Ч���ݵĿռ� ����һ��
		iterator _finish;
		iterator _end_of_storage;


	};

	//��������vector�⣬�����ռ�jh��

	//���Ե�������const����(const_iterator)�ĺ���
	void Func(const vector<int>& v)
	{
		//�����v�����ã�����const����
		//���Ե�����v.begin()�ͱ�����const���εĵ�����
		//��Ϊ������begin(),�Ƕ���v�ռ��ŵĳ�Ա����_start
		//��_start�����޸ģ�������Ϊ���������ͱ�����const���εĵ�����
		//��Ϊ ���ã���ֹ�������� Ȩ�ޱ��Ĵ���
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

		//ע�ⶨ������������ķ�ʽ
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

		vs = v;  // ��ֵ����
		vector<int> copy = v; // �ȼ���copy(v) �����Ի��ǿ�������

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