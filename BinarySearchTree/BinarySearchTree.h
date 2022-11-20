#pragma once

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//���¶���һ�������ռ䣬������ʵ����������������ع���
namespace Key
{
	//���������BSTreeNode����Ϊ�˶������Ľڵ�
	template<class K>
	struct BSTreeNode
	{
		//�ڵ������ָ��ָ����ڵ㣬��ָ��ָ���ҽڵ�
		//�Լ���ŵ���������
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;

		//���캯��
		BSTreeNode(const K& key)
			:_left(nullptr) //��ʼ���б�
			, _right(nullptr)
			, _key(key)
		{}
	};



	//���������BSTree������Ϊ������������
	//class BinarySearchTree
	template<class K>
	class BSTree
	{
		//������BSTreeNode<K>�����ڵ�����͵�����̫�����ض�����
		typedef BSTreeNode<K> Node;
	public:

		//����һ�����ݣ��������Ƿ�ɹ�����
		bool Insert(const K& key)
		{
			//ָ�������������ĸ��ڵ��ָ���ǿգ�˵����һ���ռ䣬
			//���Դ���һ��ָ�� ͨ�������ݴ����Ľڵ� ��ָ�뼴��
			if (_root == nullptr)
			{
				//�����Node(key)�������������Ի�ȥ������Node�Ĺ��캯����ע��ֱ�
				//Ȼ��ͨ��new�����ĸýڵ�ռ䣬����ַ����_root
				_root = new Node(key);
				//ֱ�ӷ�����ȷ����
				return true;
			}

			//���parentָ����Ϊ���ҵ������λ�ú󣬿��������϶�����
			//��Ϊ����ҵ���λ�ú���Ҫ����λ�����λ�õĸ��ڵ�������
			Node* parent = nullptr;
			Node* cur = _root;//�Ӹ��ڵ������ߣ�_root��ָ����ڵ��ָ��
			//��ѭ������Ϊ���ҵ�Ҫ����λ�õ� ָ�򸸽ڵ��ָ��parent
			while (cur)//�ߵ�nullptr�ͽ���ѭ��
			{
				//��Ϊ���������������ԣ�
				//�ڵ�������ݱ�Ҫ���������keyС�����������ߣ�
				//�ڵ�������ݱ�Ҫ���������key�󣬾��������ߣ�
				if (cur->_key < key)
				{
					//ÿ�������ߣ�����¼һ�¸ýڵ㣬��Ϊ����һ���ڵ�ĸ��ڵ�
					//��ָ��parentָ��ýڵ�
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					//ÿ�������ߣ�����¼һ�¸ýڵ㣬��Ϊ����һ���ڵ�ĸ��ڵ�
					//��ָ��parentָ��ýڵ�
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					//��Ϊ���������������ԣ�û����ȵ����������棬
					//ֱ�ӷ���false
					return false;
				}
			}

			//ͨ��parent�������ҵ����Ǹ�λ�ã��������ܽ��ҵ�λ�õĽڵ������϶�����
			//ͨ�����������key�����������󴴽�һ���ڵ㣬����ָ��curָ������ڵ�
			cur = new Node(key);
			//��������ͨ��parent���Ӹýڵ�
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			//��󷵻�ture
			return true;
		}


		//��һ�����ݣ����Ҳ����ظýڵ�ĵ�ַ
		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				//�������������������ԣ�
				//�ڵ�������ݱ�Ҫ���ҵ�����keyС�����������ߣ�
				//�ڵ�������ݱ�Ҫ���ҵ�����key�󣬾��������ߣ�
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					//�ҵ��ˣ��ͷ���ָ��ýڵ��ָ��
					return cur;
				}
			}

			//ѭ��������û�з��أ���ô��û�иýڵ㣬����nullptr
			return nullptr;
		}



		//ɾ��ĳ���ڵ�
		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				//�������������������ԣ�
				//�ڵ�������ݱ�Ҫɾ��������keyС�����������ߣ�
				//�ڵ�������ݱ�Ҫɾ��������key�󣬾��������ߣ�
				if (cur->_key < key)
				{
					//����һ�ڵ��ʱ����parent��¼�¸ýڵ�
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					//����һ�ڵ��ʱ����parent��¼�¸ýڵ�
					parent = cur;
					cur = cur->_left;
				}
				else //���
				{
					// ��ʼɾ����ɾ��������ڵ���3�������
					// 1��ɾ��������ڵ� ��Ϊ��
					// 2��ɾ��������ڵ� ��Ϊ��
					// 3��ɾ��������ڵ� ���Ҷ���Ϊ��

					//////1��ɾ��������ڵ� ��Ϊ��
					if (cur->_left == nullptr)
					{
						//���������������������ɾ��������ڵ� ��Ϊ�յ�ǰ���£�
						//ɾ���Ľڵ��Ǹ��ڵ㣬��ôֻ��Ҫ����һ��ָ����ڵ��ָ�뼴��
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else //�ų���������������
						{
							if (cur == parent->_left) //ɾ���Ľڵ��Ǹ��ڵ����ڵ�
							{
								//��ɾ���ڵ�ĸ��ڵ���ɾ���ڵ���ҽڵ���������
								parent->_left = cur->_right;
							}
							else  //ɾ���Ľڵ��Ǹ��ڵ���ҽڵ�
							{
								//��ɾ���ڵ�ĸ��ڵ���ɾ���ڵ���ҽڵ���������
								parent->_right = cur->_right;
							}
						}

						//���Ӻú󣬽���Ҫɾ���Ľڵ�ɾ��
						delete cur;
						cur = nullptr;//�ڵ�ɾ���󣬽�ָ��ýڵ��ָ���ÿ��Ǻ�ϰ��
					}

					/////// 2��ɾ��������ڵ� ��Ϊ��
					else if (cur->_right == nullptr)
					{
						//���������������������ɾ��������ڵ� ��Ϊ�յ�ǰ���£�
						//ɾ���Ľڵ��Ǹ��ڵ㣬��ôֻ��Ҫ����һ��ָ����ڵ��ָ�뼴��
						if (_root == cur)
						{
							_root = cur->_left;
						}
						else  //�ų���������������
						{
							if (cur == parent->_left) //ɾ���Ľڵ��Ǹ��ڵ����ڵ�
							{
								//��ɾ���ڵ�ĸ��ڵ���ɾ���ڵ���ҽڵ���������
								parent->_left = cur->_left;
							}
							else  //ɾ���Ľڵ��Ǹ��ڵ���ҽڵ�
							{
								//��ɾ���ڵ�ĸ��ڵ���ɾ���ڵ���ҽڵ���������
								parent->_right = cur->_left;
							}
						}

						//���Ӻú󣬽���Ҫɾ���Ľڵ�ɾ��
						delete cur;
						cur = nullptr;//�ڵ�ɾ���󣬽�ָ��ýڵ��ָ���ÿ��Ǻ�ϰ��
					}

					////////3��ɾ��������ڵ� ���Ҷ���Ϊ�ա������滻��(�滻��ֻ�ǽڵ��������)
					        //�������滻����һ�������������ڵ�����滻,�������������ҽڵ�
							//��һ������������С�ڵ�����滻,��������������ڵ�			
					else
					{
						// �����õ�һ���ҵ���������С�ڵ�����滻,
						//��������С�ڵ� ���� ������������ڵ�

						//����С�ڵ㣬ͬʱҲҪ��¼��С�ڵ�ĸ��ڵ㣬
						//�������ɾ����С�ڵ�� ��������
						Node* minParent = cur;
						Node* min = cur->_right;
						//һֱ������ߵĽڵ㣬ֱ��û����ڵ�
						while (min->_left)
						{
							//ÿ���Ҷ�Ҫ��������С�ڵ�ĸ��ڵ�
							minParent = min;
							min = min->_left;
						}

						//����Ҫɾ���ڵ���滻�ڵ��������
						swap(cur->_key, min->_key);
						//�������������
						if (minParent->_left == min) //����һ�����
							minParent->_left = min->_right;
						else
							//�����������������ɾ��������ڵ� ���Ҷ���Ϊ�� ��ǰ���£�
							//ɾ���Ľڵ��Ǹ��ڵ�
							minParent->_right = min->_right;

						//ɾ�����滻�ڵ�
						delete min;
						min = nullptr;//�ڵ�ɾ���󣬽�ָ��ýڵ��ָ���ÿ��Ǻ�ϰ��
					}

					return true;
				}
			}

			return false;
		}




		//����������û���޸Ľڵ�Ľӿڣ���Ϊ�޸ĺ�Ͳ���������������



		//��ֵ���������� =
		// t2 = t1
		BSTree<K>& operator=(BSTree<K> t)
		{
			//ֱ�ӽ��� ָ����������ڵ��ָ�뼴��
			swap(_root, t._root);
			return *this;
		}



////////////////////����Ĳ��롢ɾ�������Ҷ���ѭ���ķ�ʽд��/////////////////////////
////////////////////����Ĳ��롢ɾ�����������õݹ�ķ�ʽд��////////////////////////
//��ʵ������ǹ��ܵ�˼��һ��Ҫ�ݹ飬��û�����ѭ������Ϊ�ݹ����̫������ջ��������



	//�������˶��public��privateû���κ�������˼��ֻ��Ϊ�˷��㿴��Ӧ����Ҫ�ϲ���һ���
	public:
		//��Ϊ�����Լ�д�˿������캯�����������캯��Ҳ�ǹ��캯����
		//���������Ĭ�ϳ�Ա��������������Լ���д�����������Զ����ɣ�
		//������������д�ˣ����Բ������ɣ����������Լ�Ҫдһ�����캯��
		/*BSTree()
		{}*/

		//���������c++11���÷���ǿ������Ҳ��
		// C++11���÷���ǿ�Ʊ���������Ĭ�ϵĹ���
		BSTree() = default;

		/////////////////////�������캯��//////////////////////////
		//�����Ƿ�װ��˽�г�Ա����_Copy() ��װ�ɹ��г�Ա����BSTree()
		//�����������Ϳ��Է��ʣ����ҿ�����thisָ��
		BSTree(const BSTree<K>&t)
		{
			_root = _Copy(t._root);
		}
		private:
			//��������
			//�ݹ鲻����thisָ�룬������Ҫ����Ա����_Copy()��װһ��
			Node* _Copy(Node* root)
			{
				if (root == nullptr)
				{
					return nullptr;
				}

				//�õ�ǰ���˼����нڵ����ݵĿ���
				Node* copyRoot = new Node(root->_key);
				copyRoot->_left = _Copy(root->_left);
				copyRoot->_right = _Copy(root->_right);
				return copyRoot;
			}


	//�������˶��public��privateû���κ�������˼��ֻ��Ϊ�˷��㿴��Ӧ����Ҫ�ϲ���һ���
	public:
		///////////////////��������//////////////////////////
		//�����Ƿ�װ��˽�г�Ա����_Destory() ��װ�ɹ��г�Ա����~BSTree()
		//�����������Ϳ��Է��ʣ����ҿ�����thisָ��
		~BSTree()
		{
			_Destory(_root);
		}
	private:
		//����
		//�ݹ鲻����thisָ�룬������Ҫ����Ա����_Destory()��װһ��
		//�����ָ����������ã���Ϊ������ӣ�ָ��root�����βΣ������������ڲ���
		//��ı��β�root��ֵ����Ϊ������ı䴫ֵ��root���ⲿָ����������ı䣬
		//�����βεĸı䲻��Ӱ��ʵ�Σ�����������������ã����ʱ�����root
		//�����ⲿָ��ı������������ܸı��ⲿʵ��ָ���ֵ��
		void _Destory(Node*& root)
		{
			if (root == nullptr)
			{
				return;
			}

			_Destory(root->_left);
			_Destory(root->_right);
			delete root;
			root = nullptr;
		}





	//�������˶��public��privateû���κ�������˼��ֻ��Ϊ�˷��㿴��Ӧ����Ҫ�ϲ���һ���
	public:
		//ɾ��
		//�����Ƿ�װ��˽�г�Ա����_InsertR() ��װ�ɹ��г�Ա����InsertR()
		//�����������Ϳ��Է��ʣ����ҿ�����thisָ��
		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}
	private:
		//ɾ��
		//�ݹ鲻����thisָ�룬������Ҫ����Ա����_InsertR()��װһ��
		//�����ָ����������ã���Ϊ������ӣ�ָ��root�����βΣ������������ڲ���
		//��ı��β�root��ֵ����Ϊ����ȵ�����£�
		// ��������ⲿ��ʵ�ν��в�������Ϊ��ȵ�ʱ�򣬾���Ҫɾ���ýڵ㣬
		// ��ôֻ�����ã��ſ��Խ����뺯���ڲ��� �ⲿʵ�ν��в�����
		//�����βεĸı䲻��Ӱ��ʵ�Σ�����������������ã����ʱ���β�root
		//�����ⲿָ��ı������������ܸı��ⲿʵ��ָ���ֵ��
		bool _EraseR(Node*& root, const K& key)
		{
			//�ݹ鵽���Ҳû�ҵ�Ҫɾ���Ľڵ㣬�ͷ���false��
			//�����ǿ����������Ҳ����false
			if (root == nullptr)
				return false;

			if (root->_key < key)
				return _EraseR(root->_right, key);
			else if (root->_key > key)
				return _EraseR(root->_left, key);
			else  //��ȣ���Ϊ�����ã����Կ��Զ��ⲿ��ʵ�ν��в������Ϳ���ɾ��������3�����
			{
				// 1��ɾ��������ڵ� ��Ϊ��
				// 2��ɾ��������ڵ� ��Ϊ��
				// 3��ɾ��������ڵ� ���Ҷ���Ϊ��

				//��Ϊ�����ã���Ȼ�Ѿ��ж���ȣ���ô�Ϳ���ֱ�ӶԺ������β�root���в�����
				//�������ܸı��ⲿʵ�Σ���������õĺô�
				Node* del = root;
				// 1��ɾ��������ڵ� ��Ϊ��
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				// 2��ɾ��������ڵ� ��Ϊ��
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				// 3��ɾ��������ڵ� ���Ҷ���Ϊ��
				else
				{
					//�������滻���������õ�һ���ҵ���������С�ڵ�����滻,
					Node* min = root->_right;
					while (min->_left)
					{
						min = min->_left;
					}
					//��Ҫɾ���Ľڵ����滻�ڵ�������ݽ����滻
					swap(root->_key, min->_key);
					//return EraseR(key);  ���,���������޵ݹ�
					
					//����ͼ��������
					return _EraseR(root->_right, key);
				}


				//����Ϳ���ֱ�ӽ�ָ��delָ��Ľڵ�ɾ������Ϊ����ֵΪroot��
				//�β�root���ⲿʵ�εı�����
				delete del;
				//del = nullptr;����ǽ�ָ���ÿյĺ�ϰ�ߣ���ʵҲ���Բ�д��
				//��Ϊdel�Ǻ����ڲ��ľֲ����������˺������Զ������ˣ����Կ��Բ�д
				
				//ɾ���ɹ��󣬷���true
				return true;
			}
		}






	//�������˶��public��privateû���κ�������˼��ֻ��Ϊ�˷��㿴��Ӧ����Ҫ�ϲ���һ���
	public:
		//����
		//�����Ƿ�װ��˽�г�Ա����_InsertR() ��װ�ɹ��г�Ա����InsertR()
		//�����������Ϳ��Է��ʣ����ҿ�����thisָ��
		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}
	private:
		//����
		//�ݹ鲻����thisָ�룬������Ҫ����Ա����_InsertR()��װһ��
		//�����ָ����������ã���Ϊ������ӣ�ָ��root�����βΣ������������ڲ���
		//��ı��β�root��ֵ����Ϊ������ı䴫ֵ��root���ⲿָ����������ı䣬
		//�����βεĸı䲻��Ӱ��ʵ�Σ�����������������ã����ʱ�����root
		//�����ⲿָ��ı������������ܸı��ⲿʵ��ָ���ֵ��
		bool _InsertR(Node*& root, const K& key)
		{
			//���ǿ����������Ҳ�ǵݹ����������
			if (root == nullptr)
			{
				//�����ı�ָ��root��ֵ�����Ժ�����Ҫ�����ã��������ܸı��ⲿʵ��ָ���ֵ
				//����ͽ�����Ľڵ��������ˣ���Ϊ�����root�Ǵ�������ʵ�εı�����
				//Ҫ��������һ���root->left,Ҫ������root->right,
				//��������һ��ֵ�����ý���������Ľڵ�����������
				root = new Node(key);
				return true;
			}

			if (root->_key < key)
				return _InsertR(root->_right, key);
			else if (root->_key > key)
				return _InsertR(root->_left, key);
			else
				return false;
		}




		

	//�������˶��public��privateû���κ�������˼��ֻ��Ϊ�˷��㿴��Ӧ����Ҫ�ϲ���һ���
	public:
		//����
		//�����Ƿ�װ��˽�г�Ա����_FindR() ��װ�ɹ��г�Ա����FindR()
		//�����������Ϳ��Է��ʣ����ҿ�����thisָ��
		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}
	private:
		//����
		//�ݹ鲻����thisָ�룬������Ҫ����Ա����_FindR()��װһ��
		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key < key)
				return _FindR(root->_right, key);
			else if (root->_key > key)
				return _FindR(root->_left, key);
			else
				return true;
		}






	//�������˶��public��privateû���κ�������˼��ֻ��Ϊ�˷��㿴��Ӧ����Ҫ�ϲ���һ���
	public:
		//�ڹ������˽�еĳ�Ա����_InOrder()���з�װ���Ϳ��������������
		//��Ϊһ�������ĳ�Ա����InOrder(),
		//�����ⲿ��InOrder()�����Ա������ʱ�򣬾Ϳ�����thisָ����
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}
	private:
		//���ﶨ���˽�У�����Ϊ���������һ���ݹ飬
		//������thisָ����еݹ飬���������ﶨ���˽�У�
		//Ȼ���ڹ�����������һ����װ��������Ĵ���
		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			cout << root->_key; //<< ":" << root->_value << endl;
			_InOrder(root->_right);
		}




	private:
		//����ĳ�Ա��������һ��
		//ָ�������������ĸ��ڵ��ָ��
		Node* _root = nullptr;
	};


	//////////////////////////���Ѿ��������ˣ��������ռ�jh��//////////////////////////////
	//���Բ�����ɾ��
	void TestBSTree1()
	{
		BSTree<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13, 4, 3, 4 };
		for (auto e : a)
		{
			t.Insert(e);
		}

		// ����+ȥ��
		t.InOrder();

		t.Erase(3);
		t.InOrder();

		t.Erase(8);
		t.InOrder();
		for (auto e : a)
		{
			t.Erase(e);
			t.InOrder();
		}
	}



	void TestBSTree2()
	{
		BSTree<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13, 4, 3, 4 };
		for (auto e : a)
		{
			t.InsertR(e);
		}

		// ����+ȥ��
		t.InOrder();

		t.EraseR(14);
		t.InOrder();

		t.EraseR(8);
		t.InOrder();

		for (auto e : a)
		{
			t.Erase(e);
			t.InOrder();
		}
	}



	void TestBSTree3()
	{
		BSTree<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13, 4, 3, 4 };
		for (auto e : a)
		{
			t.InsertR(e);
		}

		BSTree<int> copy = t;
		copy.InOrder();
		t.InOrder();

		BSTree<int> t1;
		t1.Insert(2);
		t1.Insert(1);
		t1.Insert(3);

		copy = t1;
		copy.InOrder();
		t1.InOrder();
	}

}







//�������������ΪKV�ṹ
//���¶����һ��KeyValue�������ռ�
namespace KeyValue
{
	//����������ģ�����K��V
	template<class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		K _key; //������������͵����ݣ���Ƚ���Kģ��
		V _value;

		BSTreeNode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
	};

	//ͬ���ģ�����������ģ�����K��V
	//���������������ǰ���K�����ݽ������򣬺�V�޹�
	template<class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K, V> Node;
	public:
		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key, value);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			return true;
		}

		//����ֻ������_key�йأ�������_value�޹�
		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}

			return nullptr;
		}

		//ɾ��ֻ������_key�йأ�������_value�޹�
		bool Erase(const K& key)
		{
			//...

			return true;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}
	private:

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			cout << root->_key << ":" << root->_value << endl;
			_InOrder(root->_right);
		}
	private:
		Node* _root = nullptr;
	};




	//�ø������������ΪKV�ṹ��ʵ��һ���򵥵���Ӣ�Ļ���
	void TestBSTree1()
	{
		BSTree<string, string> dict;
		dict.Insert("sort", "����");
		dict.Insert("left", "���");
		dict.Insert("right", "�ұ�");
		dict.Insert("string", "�ַ���");
		dict.Insert("insert", "����");
		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = dict.Find(str);
			if (ret)
			{
				cout << "��Ӧ������:" << ret->_value << endl;
			}
			else
			{
				cout << "��Ӧ������->�޴˵���" << endl;
			}
		}
	}


	//�ø������������ΪKV�ṹ��ʵ��ͳ��ˮ�����ֵĴ���
	void TestBSTree2()
	{
		string arr[] = { "�㽶", "ƻ��", "�㽶", "��ݮ", "�㽶", "ƻ��", "ƻ��", "ƻ��" };

		BSTree<string, int> countTree;
		for (auto& str : arr)
		{
			//BSTreeNode<string, int>* ret = countTree.Find(str);
			auto ret = countTree.Find(str);
			if (ret)
			{
				ret->_value++;
			}
			else
			{
				countTree.Insert(str, 1);
			}
		}

		countTree.InOrder();
	}
}