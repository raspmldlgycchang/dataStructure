#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node* p_node;
struct node {
	char* mp_string;
	node* p_next;
};
typedef struct node NODE;
