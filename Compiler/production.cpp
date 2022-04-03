#include "production.h"


//�жϲ���ʽ�Ƿ�Ϊ�ղ���ʽ
int ProIsNul(production p) {
	if (p.num == 1 && p.right[0] == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//��ѯ����ʽ���
int queryProNum(production* s, int num, production p)
{
	for (int i = 0; i < num; i++)
	{
		if (s[i].left == p.left && s[i].num == p.num)
		{
			int flag = 1;
			for (int j = 0; j < s[i].num; j++)
			{
				if (s[i].right[j] != p.right[j])
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				return i;
			}
		}
	}
	return -1;
}

//��ʼ����հ�
void InitColletion(Colletion* col) {
	(*col).I = (production*)malloc(5 * sizeof(production));
	(*col).len = 0;
	(*col).size = 5;
}

//�ж���հ����Ƿ������p
int ProIsExist(Colletion col, production p) {
	for (int i = 0; i < col.len; i++)
	{
		production q = col.I[i];
		if (q.left == p.left && q.num == p.num && p.point == q.point && p.a == q.a)
		{
			int flag = 1;
			for (int j = 0; j < q.num; j++)
			{
				if (q.right[j] != p.right[j])
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				return 1;
			}
		}
	}
	return 0;
}

//����հ��������
void addPro(Colletion* col, production p) {
	if (col == NULL || (*col).I == NULL)
	{
		return;
	}

	if (ProIsExist(*col,p) == 1) //ȥ�ش���
	{
		return;
	}

	if ((*col).len >= (*col).size)
	{
		production* x;
		x = (production*)realloc((*col).I, ((*col).size + 5) * sizeof(production));
		(*col).I = x;
		(*col).size += 5;
	}

	int len = (*col).len;
	(*col).I[len] = p;
	(*col).len++;
}

//��ʼ�����
void InitCluters(Clusters* clu) {
	(*clu).cluster = (Colletion*)malloc(5 * sizeof(Colletion));
	(*clu).len = 0;
	(*clu).size = 5;
}

//������հ�,����λ��
int queryCol(Clusters clu, Colletion col) {
	for (int i = 0; i < clu.len; i++)
	{
		Colletion c = clu.cluster[i];
		if (c.len == col.len) //����Ŀһ��
		{
			int flag = 1;
			//�ж�ÿһ��
			for (int j = 0; j < col.len; j++)
			{
				production p = col.I[j];
				if (ProIsExist(c, p) == 0) //��һ�ͬ
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				return i;
			}
		}
	}
	return -1;
}

//������������հ�
int addCol(Clusters* clu, Colletion col) {
	if (clu == NULL || (*clu).cluster == NULL)
	{
		return -1;
	}

	if (queryCol(*clu,col) != -1)
	{
		return -1;
	}

	if ((*clu).len >= (*clu).size)
	{
		Colletion* x;
		x = (Colletion*)realloc((*clu).cluster, ((*clu).size + 5) * sizeof(Colletion));
		(*clu).cluster = x;
		(*clu).size += 5;
	}

	int len = (*clu).len;
	(*clu).cluster[len] = col;
	(*clu).len++;

	return len;
}