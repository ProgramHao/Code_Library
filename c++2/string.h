#pragma once

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<iostream>
using namespace std;

//ע�⣺�����������Լ�����������ռ�bit��������ģ��ʵ��string��
//��ϵͳ��ƺõ�string�࣬����ϵͳ�������ռ�std�
//���������������string�࣬���ò���ϵͳд�õ�string������Ķ���
//�����ͺ�ģ��ʵ��string��
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		//��һ�����ݵĵ�ַ
		iterator begin()
		{
			return _str;
		}

		//���һ�����ݵ���һ����ַ���ַ�'/0'�����������棩
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

		//�Ա�����Ĵ��룬���ǿ��Ե�
		/*string()
			:_str(new char[1])
			, _size(0)
			, _capacity(0)
		{
			_str[0] = '\0';
		}*/


		//������ô��ʼ���ն�����Ϊ��Ա���� c_str( )
		//���ܳ�ʼ��_strΪ��ָ�룬��Ϊ��Ա���� c_str( )
		/*string()
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
			{}*/


		//string(const char* str = "\0")
		//�ַ��� "" ,������ʾ��ʵ�ڱ������Ѿ������ַ�/0��
		//����Ҫ���Լ�д�ַ�'/0',�е㻭������ĸо�
		//string(const char* str = "")
		//	:_str(new char[strlen(str)+1])
		//	, _size(strlen(str))
		//	, _capacity(strlen(str))
		//{
		//	strcpy(_str, str);
		//}


		//�����������Ϊ��һ�ι����ʱ����Ϊ
		//�����ݳ�ʼ���б��˳��_capacity�����ֵ�����Ի������
		//string(const char* str = "")
		//		: _size(strlen(str))
		//		, _str(new char[_capacity + 1])
		//		, _capacity(_size)
		//	{
		//		strcpy(_str, str);
		//	}


		//���Ƽ��ó�ʼ���б���Ϊ���˳������ϵ����ʱ��ά����������
		//����ֱ���ں����ڲ���ʼ��������
		string(const char* str = "")//����һ��ȱʡֵ�����ַ���
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		

		//��������
		// ��ͳд��
		 //s2(s1)����������ʱ�򣬱�����ʡ�Ե�thisָ��
		string(const string& s)
			:_str(new char[s._capacity+1])
			, _size(s._size)
			, _capacity(s._capacity)
		{
			strcpy(_str, s._str);
		}


		//��ֵ������1
		// s1 = s3
		// s1 = s1
		string& operator=(const string& s)
		{
			//��ֹ�Լ����Լ���ֵ���������û��Ҫ����Ĳ���
			if (this != &s)
			{
				//�¿���һ��ռ�
				//�����¿ռ��ԭ�򣺲�֪����������ĳ�Աָ��ֱ�ָ��Ŀռ�Ĵ�С
				//����Ϊ�˱���ռ乻������ֱ�ӿ���һ��һ���Ŀռ䣬�Ͳ��ÿ�����
				char* tmp = new char[s._capacity + 1];
				//��Ҫ���������ݣ��������¿��ٵĿռ���
				strcpy(tmp, s._str);

				//��Ϊ��ֵ֮ǰ���Ѿ��������������
				//���Ѿ������ˣ����Զ�����ĳ�Աָ��_str��ָ��һ��ռ�
				//�������ֱ�Ӹı�ָ��_str��ֵ���ͻᵼ��֮ǰ���ǿ�ռ��Ҳ�����
				//����Ϊ�˷�ֹ���ռ��ڴ�й©��������Ҫ��delete�ͷ����ռ�
				delete[] _str;

				//�����Ѿ���֮ǰָ��_strָ��Ŀռ��ͷ�
				//��ʱ��Ϳ��Ըı�ָ��_str��ֵ�������Ͳ����ڴ�й¶��
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}

			return *this;
		}





		//�������졪���ִ�д��
		// �ִ�д�� -- �ʱ�����/�ϰ�˼ά
        // s2(s1)
		void swap(string& tmp)
		{
			//��::������Ϊ������õ�ȫ�ֵ�swap��Ϊ�����֣��ż���
			::swap(_str, tmp._str);
			::swap(_size, tmp._size);
			::swap(_capacity, tmp._capacity);
		}
		//�ִ�д��������������
		// s2(s1)
		string(const string& s)
			:_str(nullptr)
			, _size(0)   
			, _capacity(0)
		{
			//�����ó�ʼ���б���Ϊ�����ǽ��������û�У�
			//��ʱ����tmp�������ֵ��Ȼ�󽻻��󣬶���s1
			//��ĳ�Աָ��ָ����ǿ�ռ�(��tmp���_strָ��Ŀռ�)
			//��������ͻᱻ�����������ǿ�ռ����Ǵ�ŵ�����ģ��ò���
			//�����������ͻᱨ��
			string tmp(s._str);
			//�Լ�ģ�����string��swap
			swap(tmp); //this->swap(tmp);
		}


		//��ֵ������2
		//s1 = s3
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				//string tmp(s._str);��string tmp(s)һ��
				string tmp(s);
				swap(tmp); // this->swap(tmp);
				//������Բ�����ȫ�ֵ�swap������ȥ��վ��
				//����::swap(*this,tmp),��Ϊ��������ڲ�
				//�ͼ��������ֵ���ͻ�һֱѭ������ջ���
			}
			return *this;
		}
		//����ĸ�ֵ������2 �ļ�
		// s1 = s3
		// s����tmp������
		string& operator=(string s)
		{
			//��������ȫ�ģ�swap(this,s);
			//void swap(string* const this,string& s)
			swap(s);
			return *this;
		}



		//��������
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


		//ϵͳ����string��reserveֻ���ݲ�ɾ�ݣ��Զ���ҲҪ����
		//�����������������ݴ���������ʱ��
		void reserve(size_t n)
		{
			//���ݴ�����������Ҫ����
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];//���һ���Ǹ��ַ�'/0'
				//����Աָ��_strָ��Ŀռ�����ݸ��ƹ���
				strcpy(tmp, _str);
				//Ȼ���ͷų�Աָ��_strָ��Ŀռ䣬��ֹ�ڴ�й©
				delete[] _str;

				//���������Ϳ��� ֱ�Ӹı�ָ��_str��ֵ
				_str = tmp;
				_capacity = n;//����Ҳ�ı���
			}
		}


		//β�壬����һ���ַ�
		void push_back(char ch)
		{
			//���˾�����
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			_str[_size] = ch;
			++_size;
			//_size�ӼӺ�Ҫע������ַ�'/0'
			_str[_size] = '\0';

			//�����˲��뺯���󣬾Ϳ���ֱ���ò��뺯������
			//����Ĵ��붼����Ҫ��
			//insert(_size, ch);
		}

		
		//Ҳ��β�壬���������ǲ����һ���ַ���
		void append(const char* str)
		{
			size_t len = strlen(str);

			// ���˾�����
			// _size + len  8  18  10  
			if (_size + len > _capacity)
			{
				reserve(_size+len);
			}

			strcpy(_str + _size, str);
			//strcat(_str, str); ��Ҫ��\0��Ч�ʵͣ���strpcy����
			_size += len;
			
			//�����˲��뺯���󣬾Ϳ���ֱ���ò��뺯������
			//����Ĵ��붼����Ҫ��
			//insert(_size, str);
		}


		//���������+=����������һ���ַ�
		//+=����β��������õģ��������ֱ�Ӹ��ú���push_back( )
		string& operator+=(char ch)
		{
			//ֱ��β��
			push_back(ch);
			return *this;
		}


		string& operator+=(const char* str);


	private:
		size_t _capacity;//�ܴ洢��Ч���ݵĿռ�
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