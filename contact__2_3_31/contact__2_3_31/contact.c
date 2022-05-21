#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


void LoadContact(Contact* pc)
{
	FILE* pf = fopen("text.txt", "r");
	if (pf == NULL)
	{
		perror("the mistake is");
		return;
	}
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))//fread��ȡ���ݺ������᷵�ض�ȡ����Ԫ�سɹ��ĸ�������������һ��һ��Ԫ�ض���
		                                       //�����ȡ�ɹ�����ô����ֵΪ1����ȡ���ɹ�������ֵΪ0����ʱȫ�����ļ���ȡ�꣬����ѭ��
	{
		//�����Ƿ���������
		CheckCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;
}

//��̬�İ汾
void InitContact(Contact* pc)
{
	assert(pc);//���ԣ���ֹ��ָ��
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;//��ǰͨѶ¼���������
	pc->data = (PeoInfo*)malloc(pc->capacity * sizeof(PeoInfo));//��̬����һ��ռ䣬date�൱����������ÿ��Ԫ���ǽṹ������ 
	//pc->data = (PeoInfo*)calloc(pc->capacity, sizeof(PeoInfo));����ֱ����calloc����Դ���malloc��memset����
	if (pc->data == NULL)//��̬����ռ�ʧ�ܣ�����malloc�᷵�ؿ�ָ��
	{
		perror("InitContact::malloc");
		return;
	}
	memset(pc->data, 0, pc->capacity * sizeof(PeoInfo));//���ֽڣ�ͨѶ¼�������*��Ÿ�����Ϣ�ṹ�����͵���ռ�ռ䣬����date�����ֽ���0�滻
                                                        //����������ݳ�ʼ��

	//�����ļ����ݵ�ͨѶ¼
	LoadContact(pc);

}                                                       

void SaveContact(Contact* pc)//����ͨѶ¼���ļ�
{
	int i = 0;
	FILE* pf = fopen("text.txt", "w");
	if (pf == NULL)
	{
		perror("the mistake is");
		return;
	}

	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}

void DestroyContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
	printf("����ͨѶ�ʳɹ�\n");
}


void CheckCapacity(Contact* pc)
{
	//���ݵĴ���
	if (pc->sz == pc->capacity)
	{
		PeoInfo* tmp = (PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInfo));//�����ṹ��PeoInfo���͵Ŀռ������
		if (tmp != NULL)//�ж��Ƿ񿪱ٳɹ�
		{
			pc->data = tmp;
		}
		else
		{
			perror("CheckCapacity::realloc");
			return;
		}
		pc->capacity += 2;
		printf("���ݳɹ�\n");
	}
}

void AddContact(Contact* pc)
{
	assert(pc);

	//��̬�İ汾
	CheckCapacity(pc);

	//¼����Ϣ
	printf("����������:>");             //date���������������������Ԫ�ص�ַ���������Ԫ���ǽṹ��PeoInfo����
	scanf("%s", pc->data[pc->sz].name); //ָ��p  p[0]===*(p+0) �൱�ڰ�ָ�뵱��������
	printf("����������:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("��ӳɹ�\n");
}


void PrintContact(const Contact* pc)
{
	assert(pc);

	int i = 0;
	printf("%-20s %-5s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");

	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[i].name, 
			pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}

//�ҵ��˷����±�
//�Ҳ�������-1
int FindByName(const Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}

	return -1;
}

void DelContact(Contact* pc,FILE* pf)
{
	assert(pc);

	if (pc->sz == 0)
	{
		printf("ͨѶ¼�ѿգ��޷�ɾ��\n");
		return;
	}
	//ɾ��
	//1. �ҵ�
	char name[NAME_MAX] = { 0 };
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//2. ɾ��
	int j = 0;
	for (j = pos; j < pc->sz - 1; j++)
	{
		pc->data[j] = pc->data[j + 1];
	}
	fscanf(pf, "%s %d %s %s %s", pc->data[pc->sz].name, &(pc->data[pc->sz].age), pc->data[pc->sz].sex, pc->data[pc->sz].tele, pc->data[pc->sz].addr);
	pc->sz--;
	printf("ɾ���ɹ�\n");
}

void SearchContact(const Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	printf("%-20s %-5s %-5s %-12s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[pos].name, 
		pc->data[pos].age, pc->data[pos].sex,
		pc->data[pos].tele, pc->data[pos].addr);
}
