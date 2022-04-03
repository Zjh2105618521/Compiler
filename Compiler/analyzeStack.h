#pragma once

#include<stdio.h>
#include<stdlib.h>
#include "ThreeaddressCode.h"

#define STACK_INIT_SIZE  50
#define STACK_INCREMENT 10

typedef struct {
	int l[20];
	int num;
}list;

typedef struct {
	int status; //״̬
	int symbol; //����
	int type,width;//������������S����
	int instr;     //��ת��˳�������ʹ�õ��ı�������ַ��λ�õ�����
	list truelist, falselist, nextlist;//Bool���ʽ����������
	int addr;	//��ʾ��Ӧ���ű��λ�õ�����,�����õ�������lexname�ͳ�����val
}stackItem;

//����ջ
typedef struct {
	stackItem* base;
	stackItem* top;
	int stackSize;
}AnStack;

/*��ʼ��*/
void InitStack(AnStack* S);

/*��ջ*/
void Push(AnStack* S, stackItem e);

/*��ջ*/
void Pop(AnStack* S, stackItem* e);

/*��ȡջ��״ֵ̬*/
int getTopSta(AnStack S);

/*��ȡջ������*/
stackItem getTop(AnStack S);

/*����*/
void Traverse(AnStack S, void(Visit)(stackItem));

/*��ʼ��list*/
void makelist(list* list1, int instr);

/*����2��list*/
list merge(list list1, list list2);

/*����:��instr���list1�и�����ַ���L����*/
void backpatch(ThrAddrCodes *codes,list list1, int instr);