#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

//��ʼ��ջ
void StackInit(ST* ps)
{
	assert(ps);//���Ժ�ϰ��

	ps->a = NULL;//��ʼ���ṹ��(ջ)
	ps->capacity = 0;
	ps->top = 0;
}


//����ջ
void StackDestroy(ST* ps)
{
	assert(ps);//���Ժ�ϰ��

	free(ps->a);//�ͷŶ�̬���ٵ��ڴ�
	ps->capacity = 0;
	ps->top = 0;//�����ʼ��topΪ0���������Ϊ������±꣬��Ϊ�±��0��ʼ�����ݣ���һ�����ݣ�������1
	            //����top�ǵ��ڴ�ŵ�Ԫ�ظ����ģ���Ϊ��0��ʼ����һ�����ݣ�����1������top��ջ����һ��Ԫ�ص��±�
}


//��ջ
void StackPush(ST* ps, STDataType x)
{
	assert(ps);//���Ժ�ϰ��

	//�Ƿ�����
	if (ps->top == ps->capacity)
	{
		//�����µ�����
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//��̬�����µĿռ䣬ע��realloc��malloc������
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		//�ж��Ƿ񿪱ٳɹ�
		if (tmp == NULL)
		{
			printf("realloc fail");
			exit(-1);
		}

		//���ٳɹ�
		ps->a = tmp;
		ps->capacity = newcapacity;
	}

	//��������
	ps->a[ps->top] = x;//��Ϊtop��0��ʼ��������Ϊ�����±꣬��һ����������һ������top��ջ������һ��Ԫ�ص��±�
	ps->top++;
}



//��ջ
void StackPop(ST* ps)
{
	assert(ps);//���Ժ�ϰ��

	//�ж�ջ����ЧԪ�ظ����Ƿ�Ϊ0��Ϊ0�Ͳ���Ҫ��ջ
	assert(!StackEmpty(ps));

	//��ջ��top�ǿ��Ա�ʾջ�����ЧԪ�صĸ���������ֱ��top--�����൱�ڷ��ʲ���ջ����Ԫ�ظ���Ч���Ϻͳ�ջһ��
	ps->top--;
}


//ջ���� Ԫ��
STDataType StackTop(ST* ps)
{
	assert(ps);//���Ժ�ϰ��

	//�ж�ջ����ЧԪ�ظ����Ƿ�Ϊ0��Ϊ0��û��ջ��Ԫ��
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];//��Ϊtop��ʾ��ЧԪ�صĸ������ֿ��Ա�ʾΪ�±꣬�����±�top��ǰһ�����ݾ���ջ��������
}


//�ж�ջ��Ϊ��
bool StackEmpty(ST* ps)
{
	assert(ps);//���Ժ�ϰ��

	if (ps->top == 0)//��Ϊtop�������Ǳ�ʾ��ЧԪ�صĸ������ֿ��Ա�ʾ������±꣬��Ϊ���ǳ�ʼ��Ϊ0
	{
		return true;
	}
	else
	{
		return false;
	}
}


//����ջ����ЧԪ�ظ���
int StackSize(ST* ps)
{
	assert(ps);//���Ժ�ϰ��

	return ps->top;//��Ϊtop�������Ǳ�ʾ��ЧԪ�صĸ������ֿ��Ա�ʾ������±꣬��Ϊ���ǳ�ʼ��Ϊ0
}