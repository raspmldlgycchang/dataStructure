#define _CRT_SECURE_NO_WARNINGS
#define MAX_CAPACITY 100
#define BUF_SIZE 240
#include<malloc.h>
#include "CharStack.h"
typedef void*(*func_type)(element*, void*);
func_type p_func[2] = { &push, &pop };
int is_empty(element *s) {
	if (s->top == NULL) {
		fprintf(stderr, "stack empty error");
		exit(EXIT_FAILURE);
	}
	return 0;
}
void* push(element* s, void* ap_string)
{
	int len = strlen((const char*)ap_string) + 1;
	if (s == NULL) {
		s->top = 0;
		s = (element*)malloc(sizeof(element));
		memcpy((s->stk[s->top]).mp_string,(const char*)ap_string, len);
	}
	else {
		s = (element*)realloc(s, sizeof(element) * (++(s->top)));
		memcpy((s->stk[s->top]).mp_string, ap_string, len);
	}
	(s->stk[s->top]).p_next= &s->stk[s->top];
	//s->stk[s->top] = s->stk[s->top];
	s->top++;
	return (void*)0;
}
void* pop(element *s, void *arg) {
	if (!is_empty(s)) {
		node* tmp = &s->stk[s->top];
		int len = strlen((char*)arg)+1;
		char* p_tmp_array = (char*)malloc(len);
		memcpy(p_tmp_array, (char*)arg, len);
		s->stk = tmp->p_next;//헤드포인터가 어차피 top을 가리키고 있으므로
		//헤드포인터를 top이 가리키고 있는 노드의 p_next가 가리키는 노드인
		//맨 위 다음 노드의 주소를 가리키도록 한다
		tmp = &s->stk[s->top];
		free(s->stk);//pop을 했으므로 이 헤드포인터는 안 쓰는거라서 free
		free(tmp);
		return (void*)p_tmp_array;
	}

}
void* peek(element*s, void* p_string)
{
	if (is_empty(s))
		return NULL;
	return (void*)&(s->stk[s->top]);
}
void deleteStack(element* s)
{
	NODE* p_tmp = NULL;
	while (s->stk != NULL) {
		p_tmp = (s->stk)->p_next;
		free(s->stk);
		s->stk = p_tmp;
	}
}
int main(void)
{
	element s;
	int menu;
	char input[BUF_SIZE];
	printf("(1)푸시 (2)팝 (3)종료: ");
	scanf_s("%d", &menu);
	switch (menu) {
	case 1:
		printf("문자열입력 : ");
		fgets(input, BUF_SIZE, stdin);
		if (p_func[0](&s, input) != 0) {
			puts("\a 푸시 에러");
		}
		break;
	case 2:
		char* result = (char*)p_func[1](&s, (void*)NULL);
		if (result == NULL)
			puts("\a 팝 에러");
		else
			printf("팝 데이터 : %s\n", result);
		break;
	default:
		break;
	}
	return 0;
}
