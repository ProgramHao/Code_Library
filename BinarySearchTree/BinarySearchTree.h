#pragma once

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//重新定义一个命名空间，在里面实现搜索二叉树的相关功能
namespace Key
{
	//定义这个类BSTreeNode，是为了二叉树的节点
	template<class K>
	struct BSTreeNode
	{
		//节点里的左指针指向左节点，右指针指向右节点
		//以及存放的数据内容
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;

		//构造函数
		BSTreeNode(const K& key)
			:_left(nullptr) //初始化列表
			, _right(nullptr)
			, _key(key)
		{}
	};



	//定义这个类BSTree，就是为了搜索二叉树
	//class BinarySearchTree
	template<class K>
	class BSTree
	{
		//类类型BSTreeNode<K>，即节点的类型的名字太长，重定义下
		typedef BSTreeNode<K> Node;
	public:

		//插入一个数据，并返回是否成功插入
		bool Insert(const K& key)
		{
			//指向搜索二叉树的根节点的指针是空，说明是一个空间，
			//所以创建一个指向 通过该数据创建的节点 的指针即可
			if (_root == nullptr)
			{
				//这里的Node(key)是匿名对象，所以会去调用类Node的构造函数，注意分别，
				//然后通过new出来的该节点空间，将地址赋给_root
				_root = new Node(key);
				//直接返回正确即可
				return true;
			}

			//这个parent指针是为了找到插入的位置后，可以链接上二叉树
			//因为最后找到的位置后，需要将该位置与该位置的父节点链接上
			Node* parent = nullptr;
			Node* cur = _root;//从根节点往下走，_root是指向根节点的指针
			//该循环就是为了找到要插入位置的 指向父节点的指针parent
			while (cur)//走到nullptr就结束循环
			{
				//因为搜索二叉树的特性，
				//节点里的数据比要插入的数据key小，就往右下走；
				//节点里的数据比要插入的数据key大，就往左下走；
				if (cur->_key < key)
				{
					//每次往下走，都记录一下该节点，因为是下一个节点的父节点
					//用指针parent指向该节点
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					//每次往下走，都记录一下该节点，因为是下一个节点的父节点
					//用指针parent指向该节点
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					//因为搜索二叉树的特性，没有相等的数据在里面，
					//直接返回false
					return false;
				}
			}

			//通过parent链接上找到的那个位置，这样才能将找到位置的节点链接上二叉树
			//通过插入的数据key，用匿名对象创建一个节点，并用指针cur指向这个节点
			cur = new Node(key);
			//下面是是通过parent链接该节点
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			//最后返回ture
			return true;
		}


		//给一个数据，查找并返回该节点的地址
		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				//根据搜索二叉树的特性，
				//节点里的数据比要查找的数据key小，就往右下走；
				//节点里的数据比要查找的数据key大，就往左下走；
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
					//找到了，就返回指向该节点的指针
					return cur;
				}
			}

			//循环结束都没有返回，那么就没有该节点，返回nullptr
			return nullptr;
		}



		//删除某个节点
		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				//根据搜索二叉树的特性，
				//节点里的数据比要删除的数据key小，就往右下走；
				//节点里的数据比要删除的数据key大，就往左下走；
				if (cur->_key < key)
				{
					//走下一节点的时候，用parent记录下该节点
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					//走下一节点的时候，用parent记录下该节点
					parent = cur;
					cur = cur->_left;
				}
				else //相等
				{
					// 开始删除，删除的这个节点有3种情况：
					// 1、删除的这个节点 左为空
					// 2、删除的这个节点 右为空
					// 3、删除的这个节点 左右都不为空

					//////1、删除的这个节点 左为空
					if (cur->_left == nullptr)
					{
						//这种是特殊情况，就是在删除的这个节点 左为空的前提下，
						//删除的节点是根节点，那么只需要更新一下指向根节点的指针即可
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else //排除上面的特殊情况后
						{
							if (cur == parent->_left) //删除的节点是父节点的左节点
							{
								//将删除节点的父节点与删除节点的右节点链接起来
								parent->_left = cur->_right;
							}
							else  //删除的节点是父节点的右节点
							{
								//将删除节点的父节点与删除节点的右节点链接起来
								parent->_right = cur->_right;
							}
						}

						//链接好后，将需要删除的节点删除
						delete cur;
						cur = nullptr;//节点删除后，将指向该节点的指针置空是好习惯
					}

					/////// 2、删除的这个节点 右为空
					else if (cur->_right == nullptr)
					{
						//这种是特殊情况，就是在删除的这个节点 右为空的前提下，
						//删除的节点是根节点，那么只需要更新一下指向根节点的指针即可
						if (_root == cur)
						{
							_root = cur->_left;
						}
						else  //排除上面的特殊情况后
						{
							if (cur == parent->_left) //删除的节点是父节点的左节点
							{
								//将删除节点的父节点与删除节点的右节点链接起来
								parent->_left = cur->_left;
							}
							else  //删除的节点是父节点的右节点
							{
								//将删除节点的父节点与删除节点的右节点链接起来
								parent->_right = cur->_left;
							}
						}

						//链接好后，将需要删除的节点删除
						delete cur;
						cur = nullptr;//节点删除后，将指向该节点的指针置空是好习惯
					}

					////////3、删除的这个节点 左右都不为空——用替换法(替换的只是节点里的数据)
					        //有两种替换：第一找左子树的最大节点进行替换,即左子树的最右节点
							//第一找右子树的最小节点进行替换,即右子树的最左节点			
					else
					{
						// 这里用第一种找到右子树最小节点进行替换,
						//右子树最小节点 就是 右子树的最左节点

						//找最小节点，同时也要记录最小节点的父节点，
						//方便后面删除最小节点后 进行链接
						Node* minParent = cur;
						Node* min = cur->_right;
						//一直找最左边的节点，直到没有左节点
						while (min->_left)
						{
							//每次找都要更新下最小节点的父节点
							minParent = min;
							min = min->_left;
						}

						//交换要删除节点和替换节点里的数据
						swap(cur->_key, min->_key);
						//分情况进行链接
						if (minParent->_left == min) //这是一般情况
							minParent->_left = min->_right;
						else
							//这种是特殊情况，在删除的这个节点 左右都不为空 的前提下，
							//删除的节点是根节点
							minParent->_right = min->_right;

						//删除掉替换节点
						delete min;
						min = nullptr;//节点删除后，将指向该节点的指针置空是好习惯
					}

					return true;
				}
			}

			return false;
		}




		//搜索二叉树没有修改节点的接口，因为修改后就不是搜索二叉树了



		//赋值操作符重载 =
		// t2 = t1
		BSTree<K>& operator=(BSTree<K> t)
		{
			//直接交换 指向二叉树根节点的指针即可
			swap(_root, t._root);
			return *this;
		}



////////////////////上面的插入、删除、查找都是循环的方式写的/////////////////////////
////////////////////下面的插入、删除、查找来用递归的方式写的////////////////////////
//其实如果不是功能的思想一定要递归，最好还是用循环，因为递归深度太深，会出现栈溢出的情况



	//这里用了多对public和private没有任何其他意思，只是为了方便看，应该是要合并在一起的
	public:
		//因为我们自己写了拷贝构造函数，拷贝构造函数也是构造函数，
		//那六个类的默认成员函数，如果我们自己不写，编译器会自动生成，
		//但是我们这里写了，所以不会生成，所以我们自己要写一个构造函数
		/*BSTree()
		{}*/

		//这里用这个c++11的用法，强制生成也是
		// C++11的用法：强制编译器生成默认的构造
		BSTree() = default;

		/////////////////////拷贝构造函数//////////////////////////
		//这里是封装了私有成员函数_Copy() 封装成公有成员函数BSTree()
		//这里类外对象就可以访问，而且可以用this指针
		BSTree(const BSTree<K>&t)
		{
			_root = _Copy(t._root);
		}
		private:
			//拷贝函数
			//递归不能用this指针，所以需要将成员函数_Copy()封装一下
			Node* _Copy(Node* root)
			{
				if (root == nullptr)
				{
					return nullptr;
				}

				//用的前序的思想就行节点数据的拷贝
				Node* copyRoot = new Node(root->_key);
				copyRoot->_left = _Copy(root->_left);
				copyRoot->_right = _Copy(root->_right);
				return copyRoot;
			}


	//这里用了多对public和private没有任何其他意思，只是为了方便看，应该是要合并在一起的
	public:
		///////////////////析构函数//////////////////////////
		//这里是封装了私有成员函数_Destory() 封装成公有成员函数~BSTree()
		//这里类外对象就可以访问，而且可以用this指针
		~BSTree()
		{
			_Destory(_root);
		}
	private:
		//插入
		//递归不能用this指针，所以需要将成员函数_Destory()封装一下
		//这里的指针必须用引用，因为如果不加，指针root就是形参，但是我们在内部，
		//会改变形参root的值，因为我们想改变传值给root的外部指针变量发生改变，
		//但是形参的改变不会影响实参，所以这里必须用引用，这个时候参数root
		//就是外部指针的别名，这样就能改变外部实参指针的值了
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





	//这里用了多对public和private没有任何其他意思，只是为了方便看，应该是要合并在一起的
	public:
		//删除
		//这里是封装了私有成员函数_InsertR() 封装成公有成员函数InsertR()
		//这里类外对象就可以访问，而且可以用this指针
		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}
	private:
		//删除
		//递归不能用this指针，所以需要将成员函数_InsertR()封装一下
		//这里的指针必须用引用，因为如果不加，指针root就是形参，但是我们在内部，
		//会改变形参root的值，因为在相等的情况下，
		// 我们想对外部的实参进行操作，因为相等的时候，就是要删除该节点，
		// 那么只有引用，才可以将传入函数内部的 外部实参进行操作，
		//但是形参的改变不会影响实参，所以这里必须用引用，这个时候形参root
		//就是外部指针的别名，这样就能改变外部实参指针的值了
		bool _EraseR(Node*& root, const K& key)
		{
			//递归到最后也没找到要删除的节点，就返回false；
			//或者是空树的情况，也返回false
			if (root == nullptr)
				return false;

			if (root->_key < key)
				return _EraseR(root->_right, key);
			else if (root->_key > key)
				return _EraseR(root->_left, key);
			else  //相等，因为是引用，所以可以对外部的实参进行操作，就可以删除，依旧3种情况
			{
				// 1、删除的这个节点 左为空
				// 2、删除的这个节点 右为空
				// 3、删除的这个节点 左右都不为空

				//因为是引用，既然已经判断相等，那么就可以直接对函数的形参root进行操作，
				//这样就能改变外部实参，这就是引用的好处
				Node* del = root;
				// 1、删除的这个节点 左为空
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				// 2、删除的这个节点 右为空
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				// 3、删除的这个节点 左右都不为空
				else
				{
					//依旧用替换法，依旧用第一种找到右子树最小节点进行替换,
					Node* min = root->_right;
					while (min->_left)
					{
						min = min->_left;
					}
					//将要删除的节点与替换节点里的数据进行替换
					swap(root->_key, min->_key);
					//return EraseR(key);  错的,这样会无限递归
					
					//画个图就明白了
					return _EraseR(root->_right, key);
				}


				//这里就可以直接将指针del指向的节点删除，因为它的值为root，
				//形参root是外部实参的别名。
				delete del;
				//del = nullptr;这个是将指针置空的好习惯，其实也可以不写，
				//因为del是函数内部的局部变量，出了函数就自动销毁了，所以可以不写
				
				//删除成功后，返回true
				return true;
			}
		}






	//这里用了多对public和private没有任何其他意思，只是为了方便看，应该是要合并在一起的
	public:
		//插入
		//这里是封装了私有成员函数_InsertR() 封装成公有成员函数InsertR()
		//这里类外对象就可以访问，而且可以用this指针
		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}
	private:
		//插入
		//递归不能用this指针，所以需要将成员函数_InsertR()封装一下
		//这里的指针必须用引用，因为如果不加，指针root就是形参，但是我们在内部，
		//会改变形参root的值，因为我们想改变传值给root的外部指针变量发生改变，
		//但是形参的改变不会影响实参，所以这里必须用引用，这个时候参数root
		//就是外部指针的别名，这样就能改变外部实参指针的值了
		bool _InsertR(Node*& root, const K& key)
		{
			//这是空树的情况，也是递归结束的条件
			if (root == nullptr)
			{
				//这里会改变指针root的值，所以函数里要用引用，这样才能改变外部实参指针的值
				//这里就将插入的节点链接上了，因为这里的root是传入这里实参的别名，
				//要不就是上一层的root->left,要不就是root->right,
				//所以这样一赋值，不久将这个创建的节点链接上了嘛
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




		

	//这里用了多对public和private没有任何其他意思，只是为了方便看，应该是要合并在一起的
	public:
		//查找
		//这里是封装了私有成员函数_FindR() 封装成公有成员函数FindR()
		//这里类外对象就可以访问，而且可以用this指针
		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}
	private:
		//查找
		//递归不能用this指针，所以需要将成员函数_FindR()封装一下
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






	//这里用了多对public和private没有任何其他意思，只是为了方便看，应该是要合并在一起的
	public:
		//在公共里，对私有的成员函数_InOrder()进行封装，就可以用中序遍历了
		//成为一个公共的成员函数InOrder(),
		//这样外部用InOrder()这个成员函数的时候，就可以用this指针了
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}
	private:
		//这里定义成私有，是因为中序遍历是一个递归，
		//不能用this指针进行递归，所以在这里定义成私有，
		//然后在公共里，对其进行一个封装，见上面的代码
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
		//该类的成员变量，就一个
		//指向搜索二叉树的根节点的指针
		Node* _root = nullptr;
	};


	//////////////////////////这已经在类外了，在命名空间jh里//////////////////////////////
	//测试插入与删除
	void TestBSTree1()
	{
		BSTree<int> t;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13, 4, 3, 4 };
		for (auto e : a)
		{
			t.Insert(e);
		}

		// 排序+去重
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

		// 排序+去重
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







//改造二叉搜索树为KV结构
//重新定义的一个KeyValue的命名空间
namespace KeyValue
{
	//定义两个类模板参数K、V
	template<class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		K _key; //存放了两个类型的数据，相比较与K模型
		V _value;

		BSTreeNode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
	};

	//同样的，定义两个类模板参数K、V
	//搜索二叉树依旧是按照K的数据进行排序，和V无关
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

		//查找只和数据_key有关，与数据_value无关
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

		//删除只和数据_key有关，与数据_value无关
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




	//用改造二叉搜索树为KV结构来实现一个简单的中英文互译
	void TestBSTree1()
	{
		BSTree<string, string> dict;
		dict.Insert("sort", "排序");
		dict.Insert("left", "左边");
		dict.Insert("right", "右边");
		dict.Insert("string", "字符串");
		dict.Insert("insert", "插入");
		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = dict.Find(str);
			if (ret)
			{
				cout << "对应的中文:" << ret->_value << endl;
			}
			else
			{
				cout << "对应的中文->无此单词" << endl;
			}
		}
	}


	//用改造二叉搜索树为KV结构来实现统计水果出现的次数
	void TestBSTree2()
	{
		string arr[] = { "香蕉", "苹果", "香蕉", "草莓", "香蕉", "苹果", "苹果", "苹果" };

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