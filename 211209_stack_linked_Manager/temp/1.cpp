#define _CRT_SECURE_NO_WARNINGS
#define MAX_CAPACITY 100
#include "CharStack.h"
#include"../LinkedList/nodestruct.h"
#include<iostream>
typedef char*(*func_type)(char*);
func_type p_func[2] = { &push, &peek};
#define MALLOC(p,s)\
	if(!((p)=malloc(s))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

class StackManager {
private:
	element** mp_stacks;
	char** pp;//����ں� ���� �ϴ� ���� ������ memcpy�� mp_stacks�� ����
	/*������ �Լ��� ȣ���ؾ��ϴ� �Լ������͹迭*/
	//void* tmp_func;
	char*(*mp_stkfunc[2])(char*) = { p_func[0], p_func[1]};
public:
	StackManager(unsigned int a_max_user_cnt, unsigned int a_max_count);
	~StackManager();

};

/*�������� ���� ����ü ������*/
element* stack;
//�Լ��ȿ� �ֱ�//MALLOC(stack, sizeof(*stack));
//�迭�� ������ �� ���� �ڵ�
//int capacity = -1;
//int top = -1;
NODE* top = NULL;

//�迭�� ������ ������ ��쿡 �ʿ��� �κ�
//int is_full() {
//	return top == MAX_CAPACITY - 1;
//}
int is_empty() {
	//�迭�� ������ ��
	//return top ==-1;
	return top == NULL;
}
char* push(char* ap_string)
{
	/*if (is_full()) {
		return;
	}*///�迭�� ������ ������ ��쿡 �ʿ��� �κ�
	int len = strlen(ap_string) + 1;
	NODE* p = (NODE*)malloc(sizeof(NODE));
	void* p_tmp = ap_string;
	char* p_str_tmp = (char*)(&((element*)p_tmp)->mp_string);
	memcpy(p_str_tmp, ap_string, len);
	std::cout << p_str_tmp << ": p_str_tmp" << std::endl;
	p->p_next = top;
	top = p;
	return (char*)0;/*���������� �˷���*/
}
char* pop()
{
	int result = is_empty();
	if (result)
		return NULL;
	char* result = top->str_data;
	top = top->p_next;
	NODE* p = NULL;
	p = top;
	free(p);
	return result;
}char* search(char* ret_str)
{

}
int main(void)
{
	/*���� ����ü ������ �迭����*/
	element* stk = NULL;

	return 0;
}
void error_handling(const char* msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}