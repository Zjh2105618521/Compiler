#pragma once
#include<stdio.h>
#include<stdlib.h>

//�ķ�����ʽ(��)�ṹ��
typedef struct {
	int left;   //����ʽ��
	int num;   //�Ҳ���������
	int right[12]; //����ʽ�Ҳ�
	int point;//���С��㡯������λ�ã�point �� [0,num]
	int a; //չ����,LR(1)�ķ���չ����,��ʾ��Լ��ֻ������չ�������ܹ�Լ
}production;

//��հ��ṹ��
typedef struct {
	production* I;
	int len;
	int size;
}Colletion;

//���
typedef struct {
	Colletion* cluster;
	int len;
	int size;
}Clusters;

//�жϲ���ʽ�Ƿ�Ϊ�ղ���ʽ
int ProIsNul(production p);

//��ѯ����ʽ���
int queryProNum(production* s, int num, production p);

//��ʼ����հ�
void InitColletion(Colletion *col);

//��հ�col�����Ƿ������p
int ProIsExist(Colletion col, production p);

//����հ��������
void addPro(Colletion* col, production p);

//��ʼ�����
void InitCluters(Clusters* clu);

//��ѯ����е���հ�
int queryCol(Clusters clu, Colletion col);

//��Cluters�����Colletion,�����±�
int addCol(Clusters* clu, Colletion col);