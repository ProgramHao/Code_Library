#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"


//���Ե����� �������ÿ���ڵ㣬���������Ϊ�����������ӵ�
void TestSList1()
{
	//�ö�Ӧ�Ľṹ��ָ��������ռ䣬�Ϳ���ͨ��ָ�� ���з��� ���� �����޸�
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));//mallocһ���ṹ������SLTNoded�Ĵ�С��������һ����������Ľڵ�
	assert(n1);//��������Ƿ񿪱ٳɹ���Ҳ������if���������

	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));//mallocһ���ṹ������SLTNoded�Ĵ�С��������һ����������Ľڵ�
	assert(n2);//��������Ƿ񿪱ٳɹ���Ҳ������if���������

	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));//mallocһ���ṹ������SLTNoded�Ĵ�С��������һ����������Ľڵ�
	assert(n3);//��������Ƿ񿪱ٳɹ���Ҳ������if���������

	SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTNode));//mallocһ���ṹ������SLTNoded�Ĵ�С��������һ����������Ľڵ�
	assert(n4);//��������Ƿ񿪱ٳɹ���Ҳ������if���������

	n1->data = 1;//��ÿ���ڵ������data��ʼ������
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;

	n1->next = n2;//��ÿ���ڵ�����ָ��next��ʼ�������ҳ�ʼ��Ϊָ����һ���ڵ�Ŀռ䣬���Ը�ֵ����дһ���ڵ�ĵ�ַ
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;//����ڵ�n4�����һ���ڵ㣬��Ϊ�ǵ��������Խڵ�n4���ָ��next��ʼ����ָ��NULL

	SListPrint(n1);//��ӡ����
}

void TestSList2()//����β��
{
	SLTNode* plist = NULL;//���� �������һ���ڵ㣬ֱ�ӿ�ָ�룬��˼��һ��ʼ���������һ���ڵ㶼û��
	SListPushBack(&plist, 1);//ʵ���ǵ�һ���ڵ� ����ĵ�ַ����һ��ָ�� ����ĵ�ַ��ע����һ��ָ�뱾��ĵ�ַ���Ǳ���ģ������ö���ָ�����
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);

	SListPrint(plist);//��ӡ��������ֵ���ݼ��ɣ���Ϊ����ı�ʵ�Σ�������ı��һ���ڵ�
}

void TestSList3()//����β��
{
	SLTNode* plist = NULL;//���� �������һ���ڵ㣬ֱ�ӿ�ָ�룬��˼��һ��ʼ���������һ���ڵ㶼û��
	SListPushFront(&plist, 11);//ʵ���ǵ�һ���ڵ� ����ĵ�ַ����һ��ָ�� ����ĵ�ַ��ע����һ��ָ�뱾��ĵ�ַ���Ǳ���ģ������ö���ָ�����
	SListPushFront(&plist, 22);
	SListPushFront(&plist, 33);
	SListPushFront(&plist, 44);
	SListPushFront(&plist, 55);

	SListPrint(plist);//��ӡ��������ֵ���ݼ��ɣ���Ϊ����ı�ʵ�Σ�������ı��һ���ڵ�
}

void TestSList4()//����βɾ
{
	SLTNode* plist = NULL;//���� �������һ���ڵ㣬ֱ�ӿ�ָ�룬��˼��һ��ʼ���������һ���ڵ㶼û��
	SListPushBack(&plist, 11);//ʵ���ǵ�һ���ڵ� ����ĵ�ַ����һ��ָ�� ����ĵ�ַ��ע����һ��ָ�뱾��ĵ�ַ���Ǳ���ģ������ö���ָ�����
	SListPushBack(&plist, 22);
	SListPushBack(&plist, 33);
	SListPushBack(&plist, 44);
	SListPushBack(&plist, 55);
	SListPrint(plist);//��ӡ��������ֵ���ݼ��ɣ���Ϊ����ı�ʵ�Σ�������ı��һ���ڵ�

	SListPopBack(&plist);//βɾ
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	
	SListPrint(plist);//��ӡ��������ֵ���ݼ��ɣ���Ϊ����ı�ʵ�Σ�������ı��һ���ڵ�
}

void TestSList5()//����ͷɾ
{
	SLTNode* plist = NULL;//���� �������һ���ڵ㣬ֱ�ӿ�ָ�룬��˼��һ��ʼ���������һ���ڵ㶼û��
	SListPushBack(&plist, 1);//ʵ���ǵ�һ���ڵ� ����ĵ�ַ����һ��ָ�� ����ĵ�ַ��ע����һ��ָ�뱾��ĵ�ַ���Ǳ���ģ������ö���ָ�����
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);//��ӡ��������ֵ���ݼ��ɣ���Ϊ����ı�ʵ�Σ�������ı��һ���ڵ�

	SListPopFront(&plist);//ͷɾ
	SListPopFront(&plist);
	SListPrint(plist);//��ӡ��������ֵ���ݼ��ɣ���Ϊ����ı�ʵ�Σ�������ı��һ���ڵ�
}

void TestSList6()//���Բ��Һ� �޸�(����)
{
	SLTNode* plist = NULL;//���� �������һ���ڵ㣬ֱ�ӿ�ָ�룬��˼��һ��ʼ���������һ���ڵ㶼û��
	SListPushBack(&plist, 11);//ʵ���ǵ�һ���ڵ� ����ĵ�ַ����һ��ָ�� ����ĵ�ַ��ע����һ��ָ�뱾��ĵ�ַ���Ǳ���ģ������ö���ָ�����
	SListPushBack(&plist, 22);
	SListPushBack(&plist, 33);
	SListPushBack(&plist, 44);
	SListPushBack(&plist, 55);
	SListPrint(plist);//��ӡ��������ֵ���ݼ��ɣ���Ϊ����ı�ʵ�Σ�������ı��һ���ڵ�

	SLTNode* ret = SListFind(plist, 55);//����ֻ�ǲ��ң�������ı��һ���ڵ㣬�ʹ�ӡһ��������ֱ��ֵ���ݾ��У����β���һ��ָ�뼴��
	if (ret != NULL)
	{
		printf("�ҵ��˶�Ӧ�Ľڵ�\n");
		ret->data = 666;//���ҳ����󣬻����Ը����� �޸ģ���ȫ���õ����޸ģ���Ȼ��Ҳ���Ե���дһ��
		SListPrint(plist);//��ӡ��������ֵ���ݼ��ɣ���Ϊ����ı�ʵ�Σ�������ı��һ���ڵ�
	}
	else
	{
		printf("û�ҵ���Ӧ�Ľڵ�\n");
	}
}

void TestSList7()//���������(�Ͳ��Һ������ʹ��)
{
	SLTNode* plist = NULL;//���� �������һ���ڵ㣬ֱ�ӿ�ָ�룬��˼��һ��ʼ���������һ���ڵ㶼û��
	SListPushBack(&plist, 111);//ʵ���ǵ�һ���ڵ� ����ĵ�ַ����һ��ָ�� ����ĵ�ַ��ע����һ��ָ�뱾��ĵ�ַ���Ǳ���ģ������ö���ָ�����
	SListPushBack(&plist, 222);
	SListPushBack(&plist, 333);
	SListPushBack(&plist, 444);
	SListPushBack(&plist, 555);
	SListPrint(plist);//��ӡ��������ֵ���ݼ��ɣ���Ϊ����ı�ʵ�Σ�������ı��һ���ڵ�

	SLTNode* ret = SListFind(plist, 111);//����ֻ�ǲ��ң�������ı��һ���ڵ㣬�ʹ�ӡһ��������ֱ��ֵ���ݾ��У����β���һ��ָ�뼴��
	if (ret != NULL)
	{
		printf("�ҵ��˶�Ӧ�Ľڵ�\n");
		SListInsert(&plist, ret, 1234);//��һ���ڵ���ܻ�ı䣬����ʵ����һ��ָ��(��һ���ڵ�)����ĵ�ַ���ö���ָ����գ��� ��ַ����
		SListPrint(plist);//��ӡ��������ֵ���ݼ��ɣ���Ϊ����ı�ʵ�Σ�������ı��һ���ڵ�
	}
	else
	{
		printf("û�ҵ���Ӧ�Ľڵ�\n");
	}

}

void TestSList8()//�������ɾ(�Ͳ��Һ������ʹ��)
{
	SLTNode* plist = NULL;//���� �������һ���ڵ㣬ֱ�ӿ�ָ�룬��˼��һ��ʼ���������һ���ڵ㶼û��
	SListPushBack(&plist, 1111);//ʵ���ǵ�һ���ڵ� ����ĵ�ַ����һ��ָ�� ����ĵ�ַ��ע����һ��ָ�뱾��ĵ�ַ���Ǳ���ģ������ö���ָ�����
	SListPushBack(&plist, 2222);
	SListPushBack(&plist, 3333);
	SListPushBack(&plist, 4444);
	SListPushBack(&plist, 5555);
	SListPrint(plist);//��ӡ��������ֵ���ݼ��ɣ���Ϊ����ı�ʵ�Σ�������ı��һ���ڵ�

	SLTNode* ret = SListFind(plist, 1111);//����ֻ�ǲ��ң�������ı��һ���ڵ㣬�ʹ�ӡһ��������ֱ��ֵ���ݾ��У����β���һ��ָ�뼴��
	if (ret != NULL)
	{
		printf("�ҵ��˶�Ӧ�Ľڵ�\n");
		SListErase(&plist, ret);//��һ���ڵ���ܻ�ı䣬����ʵ����һ��ָ��(��һ���ڵ�)����ĵ�ַ���ö���ָ����գ��� ��ַ����
		SListPrint(plist);//��ӡ��������ֵ���ݼ��ɣ���Ϊ����ı�ʵ�Σ�������ı��һ���ڵ�
	}
	else
	{
		printf("û�ҵ���Ӧ�Ľڵ�\n");
	}

}

int main()
{
	//TestSList1();//���Ե����� �������ÿ���ڵ㣬���������Ϊ�����������ӵ�
	//TestSList2();//����β��
	//TestSList3();//����ͷ��
	//TestSList4();//����βɾ
	//TestSList5();//����ͷɾ
	//TestSList6();//���Բ��Һ� �޸�(����)
	//TestSList7();//���������(�Ͳ��Һ������ʹ��)
	TestSList8();//�������ɾ(�Ͳ��Һ������ʹ��)
	return 0;
}