#pragma once
#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>

//First��FOLLOW���ṹ��
typedef struct {
	int* elem; //�����ַ  
	int len;  
	int size;
}Vts;

//��ʼ��
void InitVts(Vts* t);

//�Ƿ������,���򷵻ش�1��ʼ���±꣬���򷵻�0
int includeNul(Vts t);

//�Ƿ����$,���򷵻ش�1��ʼ���±꣬���򷵻�0
int includeEof(Vts t);

//���Ԫ�أ���ĩβ���
void addVt(Vts *t,int i);

//�󲢼���s = s �� t
void UnionVts(Vts *s, Vts t);

//ȥ��,t = t - {0}������Ԫ��ǰ��һ����λ
void SubNul(Vts* t);

//�ӿ�,t = t �� {0}
void AddNul(Vts* t);