#include "Vts.h"

//��ʼ��
void InitVts(Vts* t) {
	t->elem = (int*)malloc(5 * sizeof(int));
	t->len = 0;
	t->size = 5;
}

//�Ƿ������
int  includeNul(Vts t) {
	for (int i = 0; i < t.len; i++)
	{
		if (t.elem[i] == 0)
		{
			return i+1;
		}
	}
	return 0;
}

//�Ƿ����������
int includeEof(Vts t) {
	for (int i = 0; i < t.len; i++)
	{
		if (t.elem[i] == -1)
		{
			return i+1;
		}
	}
	return 0;
}

//���Ԫ��
void addVt(Vts *t,int i) {
	if ((*t).len >= (*t).size)
	{
		int* newbase;
		newbase = (int*)realloc((*t).elem, ((*t).size + 5) * sizeof(int));
		(*t).elem = newbase;
		(*t).size += 5;
	}
	
	int len = (*t).len;
	(*t).elem[len] = i;
	(*t).len++;
}

//�󲢼�
void UnionVts(Vts *s, Vts t) {
	int len1, len2;
	len1 = (*s).len;
	len2 = t.len;
	for (int i = 0; i < len2; i++)
	{
		int x = t.elem[i];
		int flag = 0;
		for (int j = 0; j < len1; j++)
		{
			if (x == (*s).elem[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			addVt(s, x);	//���ظ������
		}
	}
}

//ȥ��
void SubNul(Vts* t) {
	int i = includeNul(*t);
	if (i != 0)
	{
		for (int j = i; j < (*t).len; j++)
		{
			(*t).elem[j - 1] = (*t).elem[j];
		}
		(*t).len--;
	}
}

//�ӿ�
void AddNul(Vts* t) {
	if (includeNul(*t) == 0)
	{
		int len = (*t).len;
		(*t).elem[len] = 0;
		(*t).len++;
	}
}