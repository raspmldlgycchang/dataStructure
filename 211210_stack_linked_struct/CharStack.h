#pragma once
#ifndef __CharStack
#define __CharStack
#include"nodestruct.h"
typedef struct element* p_element;
struct element {
	node* stk;//��屸��ü ���Ḯ��Ʈ�� ���������
	int top;//top
};
typedef struct element element;

void* push(element *s, void* ap_string);
void* peek(element*s,void* ret_str);
void* pop(element *s, void* arg);
int is_empty(element *s);
void deleteStack(element* s);
#endif