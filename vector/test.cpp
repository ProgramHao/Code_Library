#include <iostream>
#include <vector>
#include <string>

//�����׼ģ���:algorithm(�㷨)�������кܶ��㷨�ӿں���
//https://legacy.cplusplus.com/reference/algorithm/?kw=algorithm
#include <algorithm>

//ͷ�ļ�
#include <functional>
using namespace std;

//vector��stringһ��������һ����
//����ʮ�ֵ�����
//vector��ʵ����˳�������Ҳ���õ����飬���Ժ���string������
//��Ա�����ͳ�Ա���� ����һ��
//����stringһ������vectorҲ�ǿ��ĵ�
//https://cplusplus.com/reference/vector/vector/

//���˺�ϵͳ�������ռ�stdһ�������֣���Ϊ��������ģ��ʵ��vector����
//���ֿ���һ������Ϊ�ڱ������ӵ�ʱ����ͬ���ֵ������ռ��ϲ�
namespace std
{
	void test_vector1()
	{
		//ģ������T��Ϊint
		//�޲ι���
		vector<int> v1;
		//����10������1
		vector<int> v2(10, 1);
		//��������
		vector<int> v3(v2);
	}

	void test_vector2()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		// �±�+[]
		for (size_t i = 0; i < v1.size(); ++i)
		{
			v1[i]++;
		}
		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		// ������
		//�������ĵ�����begin( ),��ָ���һ�����ݵ�����ָ��Ķ���
		//���ص���ָ���һ�����ݿռ�ĵ�����������������Ϊiterator
		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			(*it)--;

			cout << *it << " ";
			++it;
		}
		cout << endl;

		//����vector����v1���������θ�����e
		//auto�Ǵ洢���������Զ�ʶ���������͵Ĺ���
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}


	//������vector�����ݻ���
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

		//������ݵ����Ϳ��Ե����ֵ�����������ͣ�������42�ڶ�
		//���ǽ����10�ڶ࣬����Ϊ����Ҫ����sizeof(int)
		//���������Ա����û�����壬�ò���
		cout << v1.max_size() << endl;

		//������vector�����ݻ���
		//���к�Ľ������Ա���� ����_capacity�Ǵ��1.5������
		//����������vs2013�������µ����ݻ���
		//�������g++�������£�����2���ķ�ʽ����
		TestVectorExpand();
	}


	void test_vector4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		//�� ��׼ģ���:algorithm(�㷨)�find( )
		//������vector�û����Ƴ�Ա����find()
		//�����ݵ�λ�ã����û�ҵ����᷵�ص�����end( )
		//������end()��ָ�����һ�����ݿռ� ����ָ��� ����
		vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
		if (pos != v1.end())//�ж��Ƿ��ҵ�
		{
			//���뺯��
			v1.insert(pos, 30);
		}

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;


		pos = find(v1.begin(), v1.end(), 300);
		if (pos != v1.end())//�ж��Ƿ��ҵ�
		{
			//ɾ������ 
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


		//��������sort(),ϵͳ�����������ռ�std��
		//����ĺ���sort()Ĭ���������Լ�ȥc++��վ���������
		sort(v1.begin(), v1.end());

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;


		//��������������ͷ�ļ�functional(��������)��
		// �Ȼ��ã�����ὲ��
		////less<int> ls; ��ģ�庯��������������
		////greater<int> gt; ��ģ�庯�������ǽ�����
		
		//sort(v1.begin(), v1.end(), ls); ������ls����������

		//�Ž��򣬲���ֱ�Ӵ�����gt�����������������greater<int>()
		sort(v1.begin(), v1.end(), greater<int>());
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;


		string s("hello313131244");
		//sort(s.begin(), s.end());
		sort(s.begin(), s.end(), greater<char>());//�Ž���
		cout << s << endl;


		//vector<char> v; ˳������ַ�(��Ϊ����ģ��������char)
		//string str;  �ַ��� 
		//�������������ݽ�β\0 
		// string�У�+=��find���Ƚϴ�С��to_string��<< ��>>�ȵȣ�vectorû��
		// ��Ϊ������������� vector<char> �޷����string


		//��vector��void push_back (const value_type& val);
		vector<string> strV;
		string str1("����");

		strV.push_back(str1);
		strV.push_back(string("����"));//���������������������ʱ����һ�������г���

		//ֱ�Ӵ��ַ�������������ʽ����ת��
		strV.push_back("����");
		strV.push_back("����");

		//��Ϊ����vector�Ķ���strV�����������string
		//�������ν����ݸ�str����������Ϊ�˱����������
		//����str����Ϊ���ã������Ͳ�������ˣ�Ч�ʴ�����
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
