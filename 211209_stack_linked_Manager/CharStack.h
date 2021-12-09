#pragma once
#ifndef ___CharStack
#define ___CharStack
typedef struct element* p_element;
struct element{
	char* mp_string;
	p_element p_next;
};
typedef struct element element;

char* push(char* ap_string);
char* peek(char* mp_string);
char* pop();
//int is_full();
int is_empty();
#endif