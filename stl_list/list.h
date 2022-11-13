#pragma once

#include<iostream>
using namespace std;

//�Լ�ģ��ʵ����list�����ǰ��������Լ�����������ռ�jh���������������ϵͳ����list
namespace jh
{
	////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	//�����ģ����Ϊ�� ����� �½ڵ� ��Ƶ�
	//�������������list_node<T> ���½ڵ������
	//�����ģ����� ��������struct ��ģ�����
	template<class T> 
	//�ṹ������list_node�����������½ڵ�Ľṹ�����ͣ���c++��ṹ�����ȼ�
	//����struct��class�ȼۣ���Ϊ��c++����Խṹ�����Ϳ��Բ��ü� �ؼ���struct
	struct list_node
	{
		//����ĳ�Ա�����������������ͣ�
		//���Բ�д�������죬��������ĬȻ���� �������캯��
		T _data;//�ڵ��������
		list_node<T>* _next;//�ڵ���ָ����һ���ڵ��ָ��
		list_node<T>* _prev;//�ڵ���ָ����һ���ڵ��ָ��

		//����list_node�����һ�����캯��
		//���������½ڵ�
		//��Ϊnewһ��������list_node<T>��С�Ŀռ䣬�ǻ�������Ĺ��캯����
		list_node(const T& x = T()) //��һ��ȱʡֵ����ֹû��ʵ�δ���
			:_data(x) //��ʼ���б�
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};



	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	// �����������_list_iterator��Ϊ�� ������ĵ����� ��Ƶ�
	// �������������__list_iterator<T, Ref, Ptr>�ǵ�����������
	// �����ģ�����T��Ref��Ptr��������__list_iterator ���ģ�����
	//����ģ�������Ref(���õ���˼)���Ա�ʾΪ T&��const T& ��
	//Ptr(ָ�����˼)���Ա�ʾΪ T*��const T* 
	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		//������������������ض���һ�£�������list_node<T>̫���ˣ�����Ϊ Node
		//ע����ǰ���������list_node<T>�����ڵ����ͣ��ڴ����10��
		typedef list_node<T> Node;

		//������__list_iterator<T, Ref, Ptr>����̫�����ض���������Ϊiterator
		typedef __list_iterator<T, Ref, Ptr> iterator;

		//��Ϊ���˺���find(),�ͱ������������Щ�����飬
		//������Щ��һ���淶�ĵ�������Ҫ�Ķ��������ڲ��ù�
		//55-59�д���
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef Ptr pointer;
		typedef Ref reference;
		typedef ptrdiff_t difference_type;


		//�������ĳ�Ա��������һ���ڵ�����Node��ָ�������
		//������Node,��������list_node<T> �������ض�������
		//��Ϊ����˵������������һ��ָ�룬ָ���Ӧ�����ݿռ��
		//��Ϊ��������������ָ������ݿռ���� �ڵ�
		Node* _node;


		//�������͵Ŀ�������
		//�����ǵ���������__list_iterator<T, Ref, Ptr>(��Ϊ�ض����ˣ�������iterator) 
		//��������͵Ĺ��캯���������������__list_iterator<T, Ref, Ptr>������һ���ö���
		//��ô�ͻ��õ��������Ĺ��캯��
		__list_iterator(Node* node)
			:_node(node)//���������������Node��Ҫȥ������Node��������Ŀ������캯����
						//������Node �� ������list_node<int> �������ض������ģ�
						//ȥ���������� �������캯��
		{}

		//�жϵ�����ָ������ݿռ��Ƿ���ͬһ�飬��ָ��Ľڵ��Ƿ���ͬһ��
		//ֱ�ӱȽϵ�����(ָ��)��ֵ����ָ��Ľڵ� �ĵ�ַ����
		bool operator!=(const iterator& it) const
		{
			//�ж������������Ƿ����,this->_node!=it._node
			return _node != it._node;
		}

		//�жϵ�����ָ������ݿռ��Ƿ���ͬһ�飬��ָ��Ľڵ��Ƿ���ͬһ��
		//ֱ�ӱȽϵ�����(ָ��)��ֵ����ָ��Ľڵ� �ĵ�ַ����
		bool operator==(const iterator& it) const
		{
			////�ж������������Ƿ���ȣ���this->_node==it._node
			return _node == it._node;
		}



		// *it  it.operator*()
		// const T& operator*()
		// T& operator*()
		//����Ϊʲô��ģ�����Ref������Ϊ����� ���ؽ����� �ĵ�������const���Σ�
		// ��ô���������ָ����Ǹ��ڵ�Ŀռ���Ķ����Ͳ��ܱ��޸ģ������г����ԣ�
		//�������������_data���г����ԣ���ô���ص�ʱ�򣬾ͱ������const���Σ�
		// ��Ϊ�����Ǵ����÷��أ����Է�ֹ��������Ȩ����ߵĴ�����֣�
		//��������û����T&����ΪT& operator*()��const T& operator*() ���п��ܣ�
		// ��ģ�����Ref(����),�Ͳ���Ҫд���ݣ���ô��Ҫʲô������ʲô����
		Ref operator*() //�����õ�����
		{
			//�����õ�����������õ���������� ָ����Ǹ��ڵ� ���ŵ�����_data
			//����ֱ�ӷ�������_data
			return _node->_data;
		}


		//T* operator->() 
		//����֪�� ָ��ṹ����� ��ָ�� ���ò�����-> ����������ṹ�������� �ṹ��Ա�����ģ�
		//c++�� �ṹ�� �� �� ��Ч����struct��classһ���������� ��Ա���� �� ��Ա������
		//Ϊ�˷�ֹ��������Ĳ�������2 test_list2()�ᷢ�������
		//����������iterator�� ���ز�����->
		//ע�⣺��Ϊ����������iterator�� ���ز�����->������ֻ����������iterator�Ķ������ʹ��
		//������ģ�����Ptr(ָ��)������������ؽ�����ԭ��һ�����Ͳ���д����
		//T* operator->()��const T* operator->()���ܿ���
		Ptr operator->()  
		{
			//operator*()�������� ������ָ��� ĳ���ڵ� ��ĳ�Ա����
			//Ȼ��Ըó�Ա����ȡ��ַ���൱����Ϊһ��ָ�뷵�أ���Ϊָ���ֵ���ǵ�ַ
			return &(operator*());
		}


		//++������������ָ��ڵ� ��ָ��ǰ��++��ָ����һ���ڵ�
		//��Ϊ������������������iterator�����Է���ֵҲ�����
		//���Դ����÷��أ�����Ϊʹ��ǰ��++�ĸõ������������������󲻻ᱻ����
		iterator& operator++()
		{
			//��ı�õ�����������Ϊ��ǰ��++
			_node = _node->_next;
			//����Ľ����ò��ǵ��������õĽ����ã���Ϊ���this���ǵ�����
			//��������������������iterator�������this��ָ�������������ָ�룬
			//�����ָ��this������iterator*���൱����һ������ָ�룬
			//��������Ľ�������ϵͳ��ָ������ã������ָ��this�����ú�
			//����ʹ��ǰ��++�ĸõ���������
			return *this;
		}

		

		//������++������ָ��ڵ� ��ָ�����++��ָ����һ���ڵ�
		//��Ϊ������������������iterator�����Է���ֵҲ�����
		//�����Ǵ�ֵ���أ�����Ϊʹ�ú���++�ĸõ��������ں����ڲ�����һ����ʱ����
		//��Ϊ����++�������ټӣ���������Ҫʹ��ʹ�ú���++�ĸõ��������ܸı䣬
		//���Ժ����ڲ�����һ����ʱ������Ȼ�󷵻ص��������ʱ����
		//��ʱ�����������ᱻ���٣�����Ҫ�ô�ֵ����
		iterator operator++(int)
		{
			//*this����ʹ�ú���++�ĸõ�����
			//Ȼ�󿽱�������������� ��tmp�������������� ������iterator 
			//ȥ������������͵Ŀ�������
			iterator tmp(*this);
			_node = _node->_next;
			return tmp;
		}


		// --it��������ǰ��--����ǰ��++ԭ��һ��
		iterator& operator--()
		{
			_node = _node->_prev;
			return *this;
		}


		// it--������������--���ͺ���++ԭ��һ��
		iterator operator--(int)
		{
			iterator tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
	};




	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	//�����������list����Ϊ�� ģ��ʵ������
	//ģ��ʵ����list����������ʵ�ִ�ͷ˫��ѭ������
	//�����ģ�����T ��������list ��ģ�����
	template<class T> //ģ�����T
	class list
	{
		//������������������ض���һ�£�������list_node<T>̫���ˣ�����Ϊ Node
		//ע����ǰ���������list_node<T>�����ڵ����ͣ��ڴ����10��
		typedef list_node<T> Node;

	public:
		//�������ģ���������Ҫ�ĸ�ģ����Զ����ĸ�ģ�����
		//���� ������__list_iterator �����ĵ�����ָ��Ľڵ��� �ĳ�Ա��������Ҫ���������ʲô������ʽ
		//T��T&(����)��T*(ָ��)
		typedef __list_iterator<T, T&, T*> iterator;
		//�������ģ���������Ҫ�ĸ�ģ��ͻ��Զ����ĸ�ģ�����
		typedef __list_iterator<T, const T&, const T*> const_iterator;


		//const���εĵ�������Ϊ�˷�ֹ���ֲ�������test_list3()�����
		//const���εĵ����� ���ʾ����õ�����ָ����Ǹ��ڵ�������ݲ��ܱ��ı䣬�����ռ���Ķ������ܱ��޸�
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}


		//const���εĵ�������Ϊ�˷�ֹ���ֲ�������test_list3()�����
		//const���εĵ����� ���ʾ����õ�����ָ����Ǹ��ڵ�������ݲ��ܱ��ı䣬�����ռ���Ķ������ܱ��޸�
		const_iterator end() const
		{
			return const_iterator(_head);
		}


		//ָ���һ���ڵ�ĵ�����
		iterator begin()
		{
			//��һ���ڵ� �� �ڱ�λ�ڵ����һ���ڵ�
			return iterator(_head->_next);//�������������� ����int(1)������һ����ʼ��Ϊ1��int���͵Ķ���
											//Ҳ�ǵ�����������iterator�Ŀ�������
		}


		//ָ�� ���һ���ڵ�� ��һ���ڵ� �ĵ�������
		//��Ϊ�����Ǵ�ͷ˫��ѭ���������Ե�����end()����ָ����ڱ�λ�ڵ�
		iterator end()
		{
			return iterator(_head);
		}



		// ����ָ���ڱ�λͷ����ָ�� �� ��ʼ������ڱ�λ�ڵ�
		//��������ȫ��void empty_init(list<T>* const this);
		void empty_init()
		{
			// ����ָ���ڱ�λͷ����ָ��
			_head = new Node;
			//��ʼ������ڱ�λ�ڵ�ʱ������ڵ��������ָ��_next��_prev����ָ���Լ�
			_head->_next = _head;
			_head->_prev = _head;
		}
		//�������캯��
		//�������һ��������ģ�������
		//��������������Ϳ��Բ���list�ģ�Ҳ����ʱvector�� �ȵ�
		template <class InputIterator>
		list(InputIterator first, InputIterator last)//����һ������������
		{
			//��ȻҪ�������죬��Ȼ���������������һ������
			//Ҳ��Ҫһ���ڱ�λ��ͷ�ڵ㣬�����ڿ������캯���
			//����ָ���ڱ�λͷ����ָ�� �� ��ʼ������ڱ�λ�ڵ�
			empty_init();

			while (first != last)
			{
				//��������ȫ��thid->push_back(this,*first);
				push_back(*first);
				++first;
			}
		}



		//���캯�����������Ǹ����캯��һ��һ����
		//ֻ�����ｫ����� ���캯�� ��Ĵ��� ��ȡ����������һ��empty_init()����
		list()
		{
			//����ָ���ڱ�λͷ����ָ�� �� ��ʼ������ڱ�λ�ڵ�
			empty_init();
		}




		//������Ҫע�⣬��������������棬д��������Ͷ����ʱ��
		//��������Ϳ��Բ��ü�ģ�������Ҳ���Լӣ�
		//�����������棬д��������͵Ķ����ʱ����������ͱ���� �����ģ�������
		//�����������������list�list<T>& x �� list& x �����ԣ�
		//��������������list�����ʱ�򣬾ͱ���д�� list<int>& x,
		//������Ҫ��ģ������ǣ�������������ģ�������
		//����ֹ���������Ƕ�д�ϣ������Ͳ����׼ǻ���
		void swap(list<T>& x)
			//void swap(list& x)
		{
			//�������ռ�std��˵�������õ�swap��ϵͳ�⺯�����
			std::swap(_head, x._head);
		}
		//�������캯��
		// lt2(lt1)
		list(const list<T>& lt)
		{
			
			//��������ʼ��ָ���ڱ�λͷ����ָ�룬��������ȫ��this->empty_init(this);
			//���Ǹ�lt2 ������ָ���ڱ�λͷ����ָ�� �� ��ʼ������ڱ�λ�ڵ㣬
			empty_init();
			//�õ������ ������������ �Ŀ������캯����
			//��һ����ʱ������������
			list<T> tmp(lt.begin(), lt.end());
			//��������ȫ��this->swap(this,tmp);
			//���Ǹ���ʱ����tmp��lt2�� ָ���ڱ�λ�ڵ��ָ�� ����
			swap(tmp);
			//����������������list�ı���tmp�ᱻ��������Ϊ������ʱ����
		}



		//��ֵ����������
		// lt1 = lt3
		list<T>& operator=(list<T> lt)
		{
			//��������ȫ��this->swap(this,lt);
			//ֱ�ӽ���lt1 �� lt3�� ָ���ڱ�λ�ڵ��ָ�� ���ɣ���Ϊ�Ǹ�ֵ��
			swap(lt);
			//Ȼ�󽻻��󣬷����ڱ�λ�ڵ㼴�ɣ����Ƿ��ص�ָ���ڱ�λ�ڵ��ָ��
			//�Ƿ����ڱ�λ�ڵ㱾����Ϊthis��ָ������������list�Ķ���lt1�������þ���lt1
			return *this;
		}


		//��������
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}


		//��������е�����
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				//����erase�ĵ�������ɾ��ָ��Ľڵ���ʧЧ����Ϊ�����ַ�ռ䲻������
				//���Խ����ص��µĵ���������
				it = erase(it);
			}
		}



		//���캯�����޲ι���
		//���� ������list�Ķ��� �ĺ���
		list()
		{
			//��Ϊ����ģ����Ǵ�ͷ˫��ѭ����������Ҫ�����ڱ�λ�ڵ�
			_head = new Node; // ������new ��int* ptr = new int ��̬����һ��int���͵Ŀռ�
			//����ָ�룬�ʼ��ָ���ڱ�λ�ڵ�
			_head->_next = _head;//ָ����һ���ڵ��ָ��
			_head->_prev = _head;//ָ����һ���ڵ��ָ��
		}


		//β��
		void push_back(const T& x)
		{
			//����β�ڵ�
			Node* tail = _head->_prev;
			//�����½ڵ�
			//������new ��int* ptr = new int(10) ��̬����һ��int���͵Ŀռ� ����ʼ��Ϊ10
			Node* newnode = new Node(x);//Node�� �ڵ�����ͣ�����118��

			// _head          tail  newnode
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;

			//insert(end(), x);
		}


		//ͷ��
		void push_front(const T& x)
		{
			insert(begin(), x);
		}



		//�ڵ�����pos(ָ��)ָ��Ľڵ㴦����һ���ڵ�
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			Node* newnode = new Node(x);

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}


		//βɾ
		void pop_back()
		{
			erase(--end());
		}


		//ͷɾ
		void pop_front()
		{
			erase(begin());
		}


		//ɾ��������posָ��Ľڵ�
		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;

			//��Ϊɾ��������posָ��Ľڵ�pos�󣬵�����pos��ʧЧ�ˣ�
			// ��Ϊ����������ַ�ռ��ǲ������ģ�
			//����Ҫ����һ���µĵ�����
			return iterator(next);
		}

	private:
		//������list��ֻ��ָ�� �ڱ�λ�ڵ�� ָ��_head����һ��˽�г�Ա����
		//��Ϊ������list����һ������֪��ָ�� �ڱ�λ�ڵ�� ָ��_head
		//����Ľڵ���֪����
		//�Ϳ��������Ѿ���һ����������֪��ָ�� �ڱ�λ�ڵ�� ָ��_head��
		//Ȼ��ͨ���ڱ�λ�ڵ��������ָ�룬ָ����һ���ڵ��ָ����һ���ڵ��ָ�룬
		//����Ľڵ㶼֪����
		Node* _head;
	};



	//���Ե������ĺ���
	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		it = lt.begin();
		while (it != lt.end())
		{
			*it *= 2;
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}





	struct Pos
	{
		int _a1;
		int _a2;

		Pos(int a1 = 0, int a2 = 0)
			:_a1(a1)
			, _a2(a2)
		{}
	};
	//���Է����� ָ��ṹ����� ��ָ�� �ò�����-> ȥ���ʽṹ�������ĳ�Ա����
	void test_list2()
	{
		int x = 10;
		int* p1 = &x;

		cout << *p1 << endl;

		Pos aa;
		Pos* p2 = &aa;
		p2->_a1;
		p2->_a2;

		list<Pos> lt;
		lt.push_back(Pos(10, 20));
		lt.push_back(Pos(10, 21));

		list<Pos>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._a1 << ":" << (*it)._a2 << endl;
			cout << it->_a1 << ":" << it->_a2 << endl;
			//��ʵӦ�õ�д����it->->_a1 it->->_a2
			//ǰ���it-> ���ǵ�����������iterator �Ĳ�����->���غ�������it.operator->(),
			//���ص� ���ǵ�����ָ�����һ���ڵ��� ��Pos�����Ͷ���ĵ�ַ�������ص���Pos�����Ͷ���ĵ�ַ
			//Ҳ����˵��һ��ָ�룬��Ϊָ���ֵ���ǵ�ַ��
			//����ĵڶ���������->����ϵͳ��ģ�ָ�� �ṹ������Pos���� ��ָ�� ͨ��-> 
			//���ʵ��ṹ������Pos ������ĳ�Ա���� _a1��_a2��
			//��������Ϊʲôֻ��һ��->������Ϊ�������﷨�Ŀɶ��ԣ�ʡ�Ե���һ��->

			++it;
		}
		cout << endl;
	}





	void Func(const list<int>& l)
	{
		//const���ε�������list�Ķ���l,��ô����l�Ŀռ���Ķ������ܱ��ı�
		//����thisָ�� ָ�����l����ڵ㣬��ôthisָ���Ӧ�ñ�const����
		// ��const list<int>* const this;�ڶ���const��ϵͳ�Դ��ģ�
		// ��һ��constָ����thisָ��ָ����ǿ�ռ䲻�ܱ��ı䣬
		// �ڶ���constָ����thisָ�벻�ܱ��ı䡣
		//const���ε�������list�Ķ���l��������������
		//���Ծ�һ��Ҫ���� �����Ƿ�����Ȩ�ޱ��Ĵ���
		//���������������iterator�ĳ�Ա����iterator begin()��
		//��ô��ȫl.begin() ���� l.begin(list<int>* const this)
		//���ʱ��ͳ�����Ȩ�޷Ŵ�Ĵ�����Ϊthisָ��ָ����ǿ�ռ�ɶ���д
		//�������ʱ����������iterator�ĳ�Ա����const_iterator begin()const;
		//������ȫl.begin() ���� l.begin(const list<int>* const this)
		//����thisָ��ָ����ǿ�ռ�ֻ�ܶ�������д���Ȳ��ܱ��޸�
		list<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			//*it = 10;�Ͳ���д��

			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	//���Ե�������list�Ķ���const���ε�ʱ�򣬾���Ҫconst���εĵ�����
	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		Func(lt);
	}




	//��֤����push_front��pop_back��insert
	void test_list4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		it = lt.begin();
		while (it != lt.end())
		{
			*it *= 2;
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.push_front(10);
		lt.push_front(20);
		lt.push_front(30);
		lt.push_front(40);

		lt.pop_back();
		lt.pop_back();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		auto pos = find(lt.begin(), lt.end(), 4);
		if (pos != lt.end())
		{
			// pos�Ƿ��ʧЧ������
			lt.insert(pos, 40);
			//lt.insert(pos, 30);
			*pos *= 100;
		}

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}




	void test_list5()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int> copy = lt;
		//�������ǳ�����������ǳ�����������������Բ�����������
		//��������д�Ŀ������캯���������
		for (auto& e : lt)
		{
			e *= 2;
		}
		cout << endl;

		for (auto e : copy)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		//lt.clear();

		list<int> lt1;
		lt1.push_back(10);
		lt1.push_back(20);
		lt1.push_back(30);

		copy = lt1;
		for (auto e : copy)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;
	}


}
