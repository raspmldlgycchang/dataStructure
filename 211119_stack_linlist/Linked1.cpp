#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

namespace Num_class {
	enum class Num_class {
		ROCK,
		SCISSORS,
		PAPER
	};
}
typedef unsigned int HANDLE;
typedef struct node* p_node;
struct node {
	Num_class::Num_class enumObj[3];//사용자별 3번까지 경기진행하기위해서
	p_node p_next;
};
typedef struct node NODE;
typedef struct Stack {
	node Node;
}Stack, *p_Stack;
void SetEnum(void* const p, char flag, int input) {//p라는 위치에 저장할 것이고 void포인터형을 이용하려면은 
//기본적으로 사용법(flag로 어느 자료형을 쓸건지 지정)
//(사용할 메모리크기 지정(포인터변수))
	for (unsigned int i = 0; i < 3; i++) {
		if (flag) {
			*(int*)(((&((Stack*)p)->Node)->enumObj)[i]) = input;
			//매개변수를 p_gyc p;로 받았다면 ((p_gyc)p)->enumObj = Num_class::Num_class::ROCK;이 됨
		}
	}
}
//사용자추가하는 것을 AddNode에서 구현하고
//사용자1명에 대한 말을 추가하는 것은 다른 함수들에서 구현한다
void AddNode(NODE** pp_head)
{
	NODE* p;
	if ((*pp_head) != NULL) {
		while (p->p_next != NULL)
			p = p->p_next;
		p->p_next = (NODE*)malloc(sizeof(NODE));
	}
	else {//(*pp_head)==NULL
		p = *pp_head = (NODE*)malloc(sizeof(NODE));
	}

	p->p_next = NULL;
}
void DeleteNode(NODE** pp_head)
{
	NODE* p = *pp_head, * p_save_next;
	while (NULL != p) {
		p_save_next = p->p_next;
		free(p);
		p = p_save_next;
	}
}
int main()
{
	//원하는 만큼 사용자수를 만들고 원하는 만큼 사용자에 대한 말을 추가하기위해서
	// 초기화를 따로 하지 않고 아래처럼 구조체 변수 선언만 한다
	//Stack구조체변수 선언및 char형 변수를 사용자 입력에 따라 다른 정수값으로 CharToInt로
	Stack stackObj;
	char str[8] = { 0, };//SCISSORS에 최대길이 맞추기 8바이트
	Num_class::Num_class num_class;
	while (1) {
		//Stack구조체에 사용자에 해당하는 사용자 노드 할당
		//Stack구조체의 요소 Node구조체에 대해서 pp_head를 보내준다
		NODE* p_head = &(stackObj.Node);
		AddNode(&p_head);
		puts("ROCK, SCISSORS, PAPER 어떤 것을 선택하시겠어요?:(for exit: press CTRL+C)");
		//소켓 코드로 바꾸기(read, send 등)
		//Ctrl+C처리부분
		if (NULL != fgets(str, 8, stdin)) {
			//버퍼에서바로읽어오기는 안되고 메모리주소인 변수명을 주어야 한다
			num_class = (Num_class::Num_class)getchar();
			rewind(stdin);
			switch ((int)num_class) {
			case 1:
				SetEnum(&stackObj, 1,(int)num_class);
				break;
			case 2:
				SetEnum(&stackObj, 1, (int)num_class);
				break;
			case 3:
				SetEnum(&stackObj, 1, (int)num_class);
				break;
			default:
				puts("잘못 입력하셨습니다\n");
				break;
			}
			
		}
	}
	
	
	
	exit(0);
}