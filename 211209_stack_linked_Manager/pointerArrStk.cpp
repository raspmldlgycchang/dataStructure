#define _CRT_SECURE_NO_WARNINGS
#define MAX_CAPACITY 100
#include "../silseup10_fork/CharStack.h"
#include"../LinkedList/nodestruct.h"
#include<iostream>
typedef char* (*func_type)(char*);
func_type p_func[2] = { &push, &peek};

#define MAX_CAPACITY 100
#define MALLOC(p,s)\
	if(!((p)=malloc(s))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}
#include "../silseup10_fork/CharStack.h"

class StackManager {
private:
	element** mp_stacks;
	unsigned int m_max_user_cnt, m_max_count;
	/*������ �Լ��� ȣ���ؾ��ϴ� �Լ������͹迭*/
	char* (*mp_stkfunc[2])(char*) = { p_func[0], p_func[1] };
public:
	StackManager(unsigned int a_max_user_cnt, unsigned int a_max_count);
	~StackManager();
	void SetStack(char* ap_string) {
		char* result[2];
		for (int i = 0; i < 2; i++) {
			result[i] = (*mp_stkfunc[i])(ap_string);
		}
	}
};


StackManager::StackManager(unsigned int a_max_user_cnt=8, unsigned int a_max_count=8)
{
	m_max_user_cnt = a_max_user_cnt, m_max_count = a_max_count;
	mp_stacks = new element * [m_max_user_cnt];
	for (unsigned int j = 0; j < m_max_user_cnt; j++)
		*(mp_stacks + j) = new element[m_max_count];
	//memset
	for (unsigned int j = 0; j < m_max_user_cnt; j++) {
		memset(mp_stacks[j], 0, sizeof(element)*m_max_count);
	}
}
StackManager::~StackManager()
{
	element* p_stk=NULL, *p_save_next = NULL;
	for (unsigned int j = 0; j < m_max_user_cnt; j++)
	{
		p_stk = &mp_stacks[j][0];
		for (unsigned int i = 0; i < m_max_count; i++)
		{
			while (NULL != p_stk) {
				p_save_next = p_stk->p_next;
				delete[] p_stk->mp_string;
				p_stk++;
			}
		}
		delete[] mp_stacks[j];
		p_stk = p_save_next;
		
	}
	delete[] mp_stacks;
}
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
	if (is_empty())
		return NULL;
	char* result = top->str_data;
	top = top->p_next;
	NODE* p = NULL;
	p = top;
	free(p);
	return result;
}
char* peek(char* p_string)
{
	if (is_empty())
		return NULL;
	return top->str_data;
}
int main(void)
{
	/*Ŭ������ �ۼ��Ѱ�*/
	StackManager stkMan(5,8);
	char arr[] = "�ȳ��ϼ���";
	char* ap_string = arr;
	stkMan.SetStack(ap_string);
	/*���� ����ü ������ �迭����*/
	const int m_max_user_cnt = 5;
	element* stk[m_max_user_cnt];
	return 0;
}
void error_handling(const char* msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}