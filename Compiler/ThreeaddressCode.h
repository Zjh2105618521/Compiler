#pragma once
#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>

/*����ַ��ṹ��*/
typedef struct {
	int type;   //���ͣ�1:����x = y op z 2:��ֵ:x = y 
					//3:������ת��: goto L4.����ת��: if x relop y goto L
	int x, y, z; //�����x,y,z��ŵĶ��Ƿ��ű�ĵ�ַ
	int op; //op/relop,���token_id
	int L; //���Ҫ��ת������ַ�������
}ThrAddrCode;

/*����ַ������*/
typedef struct {
	ThrAddrCode* base;
	int len;
	int size;
}ThrAddrCodes;

/*��ʼ��*/
void InitCodes(ThrAddrCodes* codes);

/*�������ַ��*/
void AddCode(ThrAddrCodes* codes, ThrAddrCode code);

/*��ȡĳһ������ַ��*/
ThrAddrCode getCode(ThrAddrCodes codes, int i);

/*����ĳһ������ַ��*/
void setCode(ThrAddrCodes* codes, int i, ThrAddrCode code);

/*�޸�ĳһ������ַ���L����*/
void setCodeL(ThrAddrCodes* codes, int i, int L);

/*��ȡ��һ��Ҫ���ɵ�����ַ������±�*/
int getNextInstr(ThrAddrCodes codes);

/*�������*/
void TraverseAddrCodes(ThrAddrCodes codes, void(Visit)(ThrAddrCode));