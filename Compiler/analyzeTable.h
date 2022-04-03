#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int i;		//״̬i
	int x;	//����x������Ϊ�ս������ս��
	int j;		//״̬j
}Go;

typedef struct {
	Go* elem;
	int len;
	int size;
}GoList;

typedef struct {
	int i;				//״̬i
	int a;				//�ս����a
	int status;	//����1����Լ2������3������4
	int j;				//������״̬����Լʹ�õĲ���ʽ��š�����ʹ�õĹ�Լ����ʽ���
}Action;

typedef struct {
	Action* base;
	int len;
	int size;
}ActionList;

//��ʼ��Go����
void InitGoList(GoList* l);

//��ѯgoto�������ҵ��򷵻�j��ֵ�����򷵻�-1
int gotoJ(GoList l, int i, int x);

//���Go��
void addGo(GoList* l, Go g);

/*��ʼ��Action����*/
void InitActionList(ActionList* T);

/*����:����i,x,status����*/
int actionIsExist(ActionList T, Action item);

/*���Action��*/
void addAction(ActionList* T, Action item);

/*����i��a��ѯAction*/
Action queryActionList(ActionList T, int i, int a);
