#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct node {
	char* str_data;
	struct node* p_next;
}NODE;
void AddNode(NODE** pp_head, char* ap_str_data)
{
	NODE* p;
	if (NULL != (*pp_head)) {
		p = *pp_head;
		while (NULL != p->p_next)
			p = p->p_next;
		p->p_next = (NODE*)malloc(sizeof(NODE));
		p = p->p_next;
	}
	else {
		p = *pp_head = (NODE*)malloc(sizeof(NODE));
	}
	p->str_data = ap_str_data;
	p->p_next = NULL;
}
void DeleteNode(NODE** pp_head)
{
	NODE* p_tmp = NULL;
	while (*pp_head != NULL) {
		p_tmp = (*pp_head)->p_next;
		free(*pp_head);
		*pp_head = p_tmp;
	}
}