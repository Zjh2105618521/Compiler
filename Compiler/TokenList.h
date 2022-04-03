#pragma once
#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 30 
#define LIST_INCREMENT 10

typedef struct Token {
    int token_id;
    int table_id;//���λ�ڷ��ű��λ�ã���1��ʼ 
}Token;

typedef struct TokenList {
    Token* token; //˳���洢�ռ�Ļ�ַ
    int length;
    int listsize;
}TokenList;

/*
 *��ʼ��
 */
void InitList(TokenList* L);

/*
 *����
 */
int ListLength(TokenList L);

/*
 *���Token
 */
int Append(TokenList* L, Token t);

/*
 *����
 */
void ListTraverse(TokenList L, void(Visit)(Token));