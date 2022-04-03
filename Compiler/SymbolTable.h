#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�������� 
typedef struct symbolItem {
    char w_name[20];  	//����NAME
    int w_kind;			//����KIND
    int w_type;			//����TYPE 
    int w_val;			//��ֵVAL 
    int w_addr;			//��ַADDR
}symbolItem;

//���ű��� 
typedef struct TNode {
    symbolItem data;
    struct TNode* next;
}TNode;

//���ű�
typedef TNode* SymbolTable;

/*
 * ��ʼ��
 */
void Init_Table(SymbolTable* T);

/*
 * ��������ȡ���ű�ĳ���
 */
int TableLength(SymbolTable T);

/*
 *����:����w_name���ҷ�����(��ʶ��)�����ظ����ڷ��ű��е�λ��
 */
int LocateItem(SymbolTable T, char w_name[20]);

/*
 *����:������ֵ��С���ҷ�����(����)�����ظ����ڷ��ű��е�λ��
 */
int LocateItem(SymbolTable T,int val);

/*
 * ����:����ű����һ��
 */
int TableInsert(SymbolTable T, int i, symbolItem item);

/**
 *�ڱ������������
 */
int add(SymbolTable T, symbolItem item);

/*���·��ű��е�index�������*/
void setSymbolItem(SymbolTable T, int index, int type, int addr);

/*
 *����:��visit�������ʷ��ű�
 */
void TableTraverse(SymbolTable T, void(Visit)(symbolItem));

/*�����м�����������ڷ��ű���λ��*/
int newtemp(SymbolTable T);

/*���ҷ�����*/
symbolItem searchItem(SymbolTable T, int i);