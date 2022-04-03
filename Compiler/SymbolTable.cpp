#include "SymbolTable.h"

/*
 *��ʼ��������ͷ�ڵ�
 */
void Init_Table(SymbolTable* T) {
	(*T) = (SymbolTable)malloc(sizeof(TNode));
	(*T)->next = NULL;
}

/*
 *������ű���
 */
int TableLength(SymbolTable T) {
	if (T == NULL || T->next == NULL) {
		return 0;
	}
	int len = 0;
	SymbolTable p;
	p = T->next;
	while (p != NULL) {
		len++;
		p = p->next;
	}
	return len;
}

/*
 *���������ҵ�(��ʶ��)��Ŀ�ڷ��ű��е�λ��(��1��ʼ)
 */
int LocateItem(SymbolTable T, char w_name[20]) {
	if (T == NULL || T->next == NULL) {
		return 0;
	}

	int i = 1;
	SymbolTable p = T->next;

	while (p != NULL) {
		if ((p->data.w_kind == 1 || p->data.w_kind == 3)&& strcmp(p->data.w_name,w_name) == 0)
		{
			break;
		}
		i++;
		p = p->next;
	}

	if (p != NULL) {
		return i;
	}
	else {
		return 0;
	}
}

/**
  * ������ֵ�ҵ�(����)��Ŀ�ڷ��ű��е�λ��(��1��ʼ)
  */
int LocateItem(SymbolTable T, int val) {
	if (T == NULL || T->next == NULL)
	{
		return 0;
	}

	int i = 1;
	SymbolTable p = T->next;
	while (p != NULL) {
		if (p->data.w_kind == 2 && p->data.w_val == val)
		{
			break;
		}
		i++;
		p = p->next;
	}

	if (p != NULL) {
		return i;
	}
	else {
		return 0;
	}
}

/*
 * ����:����ű�ĵ�i��λ�ò���һ��
 */
int  TableInsert(SymbolTable T, int i, symbolItem item) {
	SymbolTable p, s;
	int j;
	if (T == NULL) {
		return 0;
	}

	p = T;
	j = 0;
	//Ѱ�ҵ�i-1�����
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}

	//��������ͷ����i��ֵ�����Ϲ涨(i<1)
	if (p == NULL || j > i - 1) {
		return 0;
	}

	//�����½��
	s = (SymbolTable)malloc(sizeof(TNode));
	if (s == NULL) {
		exit(-2);
	}
	s->data = item;
	s->next = p->next;
	p->next = s;

	return 1;
}

//��ӱ���������ڷ��ű��е�λ�� 
int add(SymbolTable T, symbolItem item) {
	int res = TableInsert(T, TableLength(T) + 1, item);
	if (res == 1) {
		return TableLength(T);
	}
	return 0;
}

void setSymbolItem(SymbolTable T, int index, int type, int addr)
{
	if (T == NULL) {
		return;
	}

	SymbolTable p;
	p = T;
	int j = 0;
	//Ѱ�ҵ�i-1�����
	while (p != NULL && j < index - 1) {
		p = p->next;
		j++;
	}

	//��������ͷ����i��ֵ�����Ϲ涨(i<1)
	if (p == NULL || j > index - 1) {
		return ;
	}

	p->next->data.w_type = type;
	p->next->data.w_addr = addr;
}

/*
 *����:��visit�������ʷ��ű�
 */
void TableTraverse(SymbolTable T, void(Visit)(symbolItem)) {
	SymbolTable p;

	if (T == NULL || T->next == NULL) {
		return;
	}

	p = T->next;

	while (p != NULL) {
		Visit(p->data);
		p = p->next;
	}
}

int newtemp(SymbolTable T)
{
	char names[][20] = { "t1","t2","t3","t4","t5","t6","t7","t8","t9",
	"s1","s2","s3","s4","s5","s6","s7","s8","s9" };
	char name[20];
	for (int i = 0; i < 18; i++)
	{
		strcpy_s(name, names[i]);
		if (LocateItem(T,name) == 0)
		{
			break;
		}
	}
	symbolItem item;
	strcpy_s(item.w_name, 20, name);
	item.w_kind = 3;//�м����
	item.w_type = -1;
	item.w_val = -1;
	item.w_addr = -1;
	return add(T, item);
}

symbolItem searchItem(SymbolTable T, int i)
{
	if (T == NULL) {
		return {-1};
	}

	SymbolTable p, s;
	p = T;
	int j = 0;
	//Ѱ�ҵ�i�����
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}

	//��������ͷ����i��ֵ�����Ϲ涨(i<1)
	if (p == NULL || j > i) {
		return {-1};
	}

	return p->data;
}
