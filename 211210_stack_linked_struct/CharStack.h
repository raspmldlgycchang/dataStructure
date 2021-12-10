#pragma once
#ifndef __CharStack
#define __CharStack
#include"nodestruct.h"
typedef struct element* p_element;
struct element {
	node* stk;//노드구조체 연결리스트의 헤드포인터
	int top;//top
};
typedef struct element element;

void* push(element *s, void* ap_string);
void* peek(element*s,void* ret_str);
void* pop(element *s, void* arg);
int is_empty(element *s);
void deleteStack(element* s);
#endif