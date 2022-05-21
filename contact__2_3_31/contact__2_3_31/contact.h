#pragma once
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//���͵�����

#define MAX 1000  //���峣����������ò�Ҫ�ӷֺ�

#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30

//ͨѶ¼��ʼ״̬��������С
#define DEFAULT_SZ 3

enum Option  //ע�⣬ö�����Ƕ��ţ���Ϊ�൱�ڳ���
{
	EXIT,//0,ö��Ĭ�ϴ�Ϊ0�������μ�1
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SORT,//5
	PRINT//6
};

typedef struct PeoInfo
{
	char name[NAME_MAX];//�ṹ�������Ƿֺţ�����Ϊ�����Ǳ������൱�����
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
} PeoInfo;


//��̬�İ汾
typedef struct Contact  //�൱��һ���ڵ㣬ֻ������˳�������ṹ�������ģ�����Ҫͨ��ָ������ÿһ���ڵ�
{
	PeoInfo* data;//���Դ��1000���˵���Ϣ
	int sz;//��¼ͨѶ���Ѿ��������Ϣ����
	int capacity;//��¼ͨѶ¼��ǰ���������
}Contact;



//����������

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//����ͨѶ¼
void DestroyContact(Contact* pc);

//������ϵ�˵���Ϣ
void AddContact(Contact* pc);

//��ӡͨѶ¼�е���Ϣ
void PrintContact(const Contact* pc);

//ɾ��ָ����ϵ��
void DelContact(Contact* pc);

//����ָ����ϵ��
void SearchContact(const Contact* pc);

//����ͨѶ¼���ļ�
void SaveContact(Contact* pc);

//�Ƿ���������
void CheckCapacity(Contact* pc);

//�����ļ����ݵ�ͨѶ¼
void LoadContact(Contact* pc);