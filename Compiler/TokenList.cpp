#include "TokenList.h"

/*
 *��ʼ��
 */
void InitList(TokenList* L) {
	(*L).token = (Token*)malloc(LIST_INIT_SIZE * sizeof(Token));
	if ((*L).token == NULL) {
		exit(-2); //�ڴ����ʧ�� 
	}

	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
}

/*
 *����
 */
int ListLength(TokenList L) {
	return L.length;
}

/*
 *���Token
 */
int Append(TokenList* L, Token t) {
	Token* newbase;
	//ȷ��˳������
	if (L == NULL || (*L).token == NULL) {
		return 0;
	}

	//���洢�ռ������������¿ռ�
	if ((*L).length >= (*L).listsize) {
		newbase = (Token*)realloc((*L).token, ((*L).listsize + LIST_INCREMENT) * sizeof(Token));
		if (newbase == NULL) {
			exit(-2); //�ڴ����·���ʧ�� 
		}

		(*L).token = newbase;
		(*L).listsize += LIST_INCREMENT;
	}
	int len = (*L).length;

	(*L).token[len] = t;
	(*L).length++;

	return 1;
}

/*
 *����
 */
void ListTraverse(TokenList L, void(Visit)(Token)) {
	int i;

	for (i = 0; i < L.length; i++) {
		Visit(L.token[i]);
	}
}