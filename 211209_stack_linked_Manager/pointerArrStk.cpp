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
	/*스택의 함수를 호출해야하는 함수포인터배열*/
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
/*전역변수 스택 구조체 포인터*/
element* stack;
//함수안에 넣기//MALLOC(stack, sizeof(*stack));
//배열로 구현할 때 쓰는 코드
//int capacity = -1;
//int top = -1;
NODE* top = NULL;

//배열로 구현한 스택의 경우에 필요한 부분
//int is_full() {
//	return top == MAX_CAPACITY - 1;
//}
int is_empty() {
	//배열로 구현할 때
	//return top ==-1;
	return top == NULL;
}
char* push(char* ap_string)
{
	/*if (is_full()) {
		return;
	}*///배열로 구현한 스택의 경우에 필요한 부분
	int len = strlen(ap_string) + 1;
	NODE* p = (NODE*)malloc(sizeof(NODE));
	void* p_tmp = ap_string;
	char* p_str_tmp = (char*)(&((element*)p_tmp)->mp_string);
	memcpy(p_str_tmp, ap_string, len);
	std::cout << p_str_tmp << ": p_str_tmp" << std::endl;
	p->p_next = top;
	top = p;
	return (char*)0;/*성공했음을 알려줌*/
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
	/*클래스로 작성한것*/
	StackManager stkMan(5,8);
	char arr[] = "안녕하세요";
	char* ap_string = arr;
	stkMan.SetStack(ap_string);
	/*스택 구조체 포인터 배열선언*/
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