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
	char** pp;//사용자별 말을 일단 담은 다음에 memcpy로 mp_stacks에 복사
	/*스택의 함수를 호출해야하는 함수포인터배열*/
	//void* tmp_func;
	char*(*mp_stkfunc[2])(char*) = { p_func[0], p_func[1]};
public:
	StackManager(unsigned int a_max_user_cnt, unsigned int a_max_count);
	~StackManager();

};

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
	/*스택 구조체 포인터 배열선언*/
	element* stk = NULL;

	return 0;
}
void error_handling(const char* msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}