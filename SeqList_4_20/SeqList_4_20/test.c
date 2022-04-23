#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"
//���Գ�ʼ��
void TestSeqList1()
{
	SL sl ;//����һ���ṹ�����͵ı���
	SLInit(&sl);//��ַ���ݣ����ܸı�ʵ��
}



//����β��
void TestSeqList2()
{
	SL sl;//����һ���ṹ�����͵ı���
	SLInit(&sl);//��ʼ������ַ���ݣ����ܸı�ʵ��
	SLPushBack(&sl, 1);//β�弸����
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);

	SLPrintArray(&sl);//��ӡ����Ԫ��

	SLDestroy(&sl);//����˳���
}

//����ͷ��
void TestSeqList3()
{
	SL sl;//����һ���ṹ�����͵ı���
	SLInit(&sl);//��ʼ������ַ���ݣ����ܸı�ʵ��
	SLPushFront(&sl, 1);//ͷ�弸����
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);

	SLPrintArray(&sl);//��ӡ����Ԫ��

	SLDestroy(&sl);//����˳���
}


//����βɾ
void TestSeqList4()
{
	SL sl;//����һ���ṹ�����͵ı���
	SLInit(&sl);//��ʼ������ַ���ݣ����ܸı�ʵ��
	SLPushBack(&sl, 1);//β�弸����
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrintArray(&sl);//��ӡ����Ԫ��

	SLPopBack(&sl);//βɾ
	SLPopBack(&sl);
	SLPrintArray(&sl);//��ӡ����Ԫ��

	SLDestroy(&sl);//����˳���
}


//����ͷɾ
void TestSeqList5()
{
	SL sl;//����һ���ṹ�����͵ı���
	SLInit(&sl);//��ʼ������ַ���ݣ����ܸı�ʵ��
	SLPushBack(&sl, 5);//β�弸����
	SLPushBack(&sl, 6);
	SLPushBack(&sl, 7);
	SLPushBack(&sl, 8);
	SLPrintArray(&sl);//��ӡ����Ԫ��

	SLPopFront(&sl);//ͷɾ����
	SLPopFront(&sl);
	SLPrintArray(&sl);//��ӡ����Ԫ��

	SLDestroy(&sl);//����˳���
}


//��������λ��(�����±�) ���� ����
void TestSeqList6()
{
	SL sl;//����һ���ṹ�����͵ı���
	SLInit(&sl);//��ʼ������ַ���ݣ����ܸı�ʵ��
	SLPushBack(&sl, 11);//β�弸����
	SLPushBack(&sl, 22);
	SLPushBack(&sl, 33);
	SLPushBack(&sl, 44);
	SLPrintArray(&sl);//��ӡ����Ԫ��

	SLInsert(&sl, 3, 55);//����λ��(�����±�) ���� ����
	SLPrintArray(&sl);//��ӡ����Ԫ��

	SLInsert(&sl, 0, 66);//����λ��(�����±�) ���� ����
	SLPrintArray(&sl);//��ӡ����Ԫ��

	SLDestroy(&sl);//����˳���
}


//����ɾ�� �������λ��(�����±�)
void TestSeqList7()
{
	SL sl;//����һ���ṹ�����͵ı���
	SLInit(&sl);//��ʼ������ַ���ݣ����ܸı�ʵ��
	SLPushBack(&sl, 111);//β�弸����
	SLPushBack(&sl, 222);
	SLPushBack(&sl, 333);
	SLPushBack(&sl, 444);
	SLPushBack(&sl, 555);
	SLPrintArray(&sl);//��ӡ����Ԫ��

	//ɾ�� �������λ��(�����±�)
	SLErase(&sl, 2);//pos���������λ�õ��±�
	SLPrintArray(&sl);//��ӡ����Ԫ��

	//ɾ�� �������λ��(�����±�)
	SLErase(&sl, 2);//pos���������λ�õ��±�
	SLPrintArray(&sl);//��ӡ����Ԫ��

	SLDestroy(&sl);//����˳���
}


//���Ը�һ�����ݣ�����������Ч������±꣬������(������λ��(�����±�)�������ݵĺ��� һ��ʹ�õ���� )
void TestSeqList8()
{
	SL sl;//����һ���ṹ�����͵ı���
	SLInit(&sl);//��ʼ������ַ���ݣ����ܸı�ʵ��
	SLPushBack(&sl, 111);//β�弸����
	SLPushBack(&sl, 222);
	SLPushBack(&sl, 333);
	SLPushBack(&sl, 444);
	SLPushBack(&sl, 555);
	SLPrintArray(&sl);//��ӡ����Ԫ��

	int x = 0;
	scanf("%d", &x);
	int pos = SLFind(&sl, x);//����һ����x �������±�
	if (pos != -1)//�ж��Ƿ��ҵ���������±�
	{
		SLInsert(&sl, pos, 666);//������±�pos��λ�ã�����һ������
	}
	SLPrintArray(&sl);//��ӡ����Ԫ��

	SLDestroy(&sl);//����˳���
}


//���Ը�һ�����ݣ�����������Ч������±꣬������(ɾ���������λ��(�����±�)�ĺ��� һ��ʹ�õ���� )
void TestSeqList9()
{
	SL sl;//����һ���ṹ�����͵ı���
	SLInit(&sl);//��ʼ������ַ���ݣ����ܸı�ʵ��
	SLPushBack(&sl, 1111);//β�弸����
	SLPushBack(&sl, 2222);
	SLPushBack(&sl, 3333);
	SLPushBack(&sl, 4444);
	SLPushBack(&sl, 5555);
	SLPrintArray(&sl);//��ӡ����Ԫ��

	int x = 0;
	scanf("%d", &x);
	int pos = SLFind(&sl, x);//����һ����x �������±�
	if (pos != -1)//�ж��Ƿ��ҵ���������±�
	{
		SLErase(&sl, pos);//������±�pos��λ�ã�����һ������
	}
	SLPrintArray(&sl);//��ӡ����Ԫ��

	SLDestroy(&sl);//����˳���
}


//���Ը�һ���±꣬�Ҵ�����¶Զ�Ӧ�����ݣ�Ȼ��������x�޸�( �ڲ���SLfind()���� )
void TestSeqList10()
{
	SL sl;//����һ���ṹ�����͵ı���
	SLInit(&sl);//��ʼ������ַ���ݣ����ܸı�ʵ��
	SLPushBack(&sl, 1111);//β�弸����
	SLPushBack(&sl, 2222);
	SLPushBack(&sl, 3333);
	SLPushBack(&sl, 4444);
	SLPushBack(&sl, 5555);
	SLPrintArray(&sl);//��ӡ����Ԫ��

	int y = 0;//Ҫ�޸ĵ�ֵ
	int z = 0;//�޸ĺ��ֵ
	printf("��������Ҫ�޸ĵ�ֵ���޸ĺ��ֵ��");
	scanf("%d%d", &y, &z);
	int pos = SLFind(&sl, y);//����һ����y �������±�
	if (pos != -1)//�ж��Ƿ��ҵ���������±�
	{
		SLModify(&sl, pos, z);//��һ���±�pos���Ҵ�����±��Ӧ�����ݣ�Ȼ��������x�޸�
	}
	else
	{
		printf("û�ҵ�Ҫ�޸ĵ�ֵ\n");
	}
	SLPrintArray(&sl);//��ӡ����Ԫ��

	SLDestroy(&sl);//����˳���
}

//int main()
//{
//	TestSeqList1();//���Գ�ʼ��
//	TestSeqList2();//����β��
//	TestSeqList3();//����ͷ��
//	TestSeqList4();//����βɾ
//	TestSeqList5();//����ͷɾ
//	TestSeqList6();//��������λ��(�����±�) ���� ����
//	TestSeqList7();//����ɾ�� �������λ��(�����±�)
//	TestSeqList8();//���Ը�һ�����ݣ�����������Ч������±꣬������(������λ��(�����±�)�������ݵĺ��� һ��ʹ�õ���� )
//	TestSeqList9();//���Ը�һ�����ݣ�����������Ч������±꣬������(ɾ���������λ��(�����±�)�ĺ��� һ��ʹ�õ���� )
//	TestSeqList10();//���Ը�һ���±꣬�Ҵ�����±��Ӧ�����ݣ�Ȼ��������x�޸�( ��SLfind()���� һ��ʹ�� )
//	return 0;
//}


void menu()
{
	printf("**************************************************************\n");
	printf("******        1����ʼ��                2��β��          ******\n");
	printf("******        3��ͷ��                  4��βɾ          ******\n");
	printf("******        5��ͷɾ                  6�������        ******\n");
	printf("******        7�����ɾ                8�����Ҳ������  ******\n");
	printf("******        9�����Ҳ����ɾ          10���޸�         ******\n");
	printf("******        0���˳�                                   ******\n");
	printf("**************************************************************\n");
}

int main()
{
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		getchar();//����������� �س� �ַ�'\n' ���յ�
		switch (input)
		{
		case 1:
			TestSeqList1();//���Գ�ʼ��
			break;
		case 2:
			TestSeqList2();//����β��
			break;
		case 3:
			TestSeqList3();//����ͷ��
			break;
		case 4:
			TestSeqList4();//����βɾ
			break;
		case 5:
			TestSeqList5();//����ͷɾ
			break;
		case 6:
			TestSeqList6();//��������λ��(�����±�) ���� ����
			break;
		case 7:
			TestSeqList7();//����ɾ�� �������λ��(�����±�)
			break;
		case 8:
			TestSeqList8();//���Ը�һ�����ݣ�����������Ч������±꣬������(������λ��(�����±�)�������ݵĺ��� һ��ʹ�õ���� )
			break;
		case 9:
			TestSeqList9();//���Ը�һ�����ݣ�����������Ч������±꣬������(ɾ���������λ��(�����±�)�ĺ��� һ��ʹ�õ���� )
			break;
		case 10:
			TestSeqList10();//����//��һ���±꣬�Ҵ�����±��Ӧ�����ݣ�Ȼ��������x�޸�( ��SLfind()���� һ��ʹ�� )
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}

