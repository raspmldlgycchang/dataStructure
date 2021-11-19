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
int GetMyString(char buffer[], int max_len)
{
	unsigned int i = 0;
	for (; i < max_len - 1; i++) {
		buffer[i] = getchar();
		if (buffer[i] == '\n') {
			buffer[i] = '\0';
			break;
		}
	}
	if (i < max_len) {//SCISSORS : 8글자 ->8바이트
		printf("%s : buffer\n", buffer);
		return 1;
	}
	buffer[i] = 0;
	rewind(stdin);
	return 0;
}
void SetEnum(void* const p, char flag, int input) {//p라는 위치에 저장할 것이고 void포인터형을 이용하려면은 
//기본적으로 사용법(flag로 어느 자료형을 쓸건지 지정)
//(사용할 메모리크기 지정(포인터변수))
	for (unsigned int i = 0; i < 3; i++) {
		if (flag) {
			(((&((Stack*)p)->Node)->enumObj)[i]) = (Num_class::Num_class)input;
			printf("%p == %p : (&((Stack*)p)->Node)->enumObj의 주소 와 ((&((Stack*)p)->Node)->enumObj)[0]의 주소\n", &((&((Stack*)p)->Node)->enumObj), &(((&((Stack*)p)->Node)->enumObj)[0]));
			printf("%d : enumObj\n", (((&((Stack*)p)->Node)->enumObj)[i]));
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
		p = *pp_head;
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
	char str[2] = { 0, };//SCISSORS에 최대길이 맞추기 8바이트
	Num_class::Num_class num_class;
	NODE* p_head = &(stackObj.Node);
	p_head = NULL;
	while (1) {
		//Stack구조체에 사용자에 해당하는 사용자 노드 할당
		//Stack구조체의 요소 Node구조체에 대해서 pp_head를 보내준다
		AddNode(&p_head);
		puts("ROCK, SCISSORS, PAPER 어떤 것을 선택하시겠어요?:(for exit: press CTRL+C)");
		//소켓 코드로 바꾸기(read, send 등)
		//Ctrl+C처리부분
		char buffer[8] = { 0, };
		//scanf로 읽어온 것이 하나의 문자가 아니고 숫자일 때나 scanf가 실패를 반환할 때
		//if (scanf_s("%c", &num_class) == 0) {
		//	rewind(stdin);
		//	printf("[Enter] Capital Letter of ROCK, SCISSORS, PAPER: ");
		//}
		/*
		//이건 첫번째 방법으로 ROCK, SCISSORS, PAPER로 적힌 str문자열을 모두 읽어와서 strcmp로 비교하는 방법이다
		unsigned int i = 0;
		for (; i < 8 - 1; i++) {
			num_class = (Num_class::Num_class)getchar();
			buffer[i] = (char)num_class;
			if (buffer[i] == '\n') {
				buffer[i] = 0;
				break;
			}
		}
		if (i < 7)	printf("%s : 사용자가 경기에서 낸 것\n", buffer);
		else {
			buffer[i] = 0;
			rewind(stdin);
			printf("사용자가 7글자 이상의 문자를 입력해서 글자가 잘려서 저장됩니다\n");
		}
		if (strcmp(str, "ROCK")) {
			SetEnum(&stackObj, 1, 0);//노드 구조체 enumObj에 정수형으로 저장된 0,1,2를 저장하려면 int형으로 ROCK, SCISSORS, PAPER를 0,1,2로 해주고 보내줘서 
									//SetEnum함수에서 그 정수를 바로 enumObj에 넣어주도록 해주어야 한다
		}
		else if (strcmp(str, "SCISSORS")) {
			SetEnum(&stackObj, 1, 1);
		}
		else if (strcmp(str, "PAPER")) {
			SetEnum(&stackObj, 1, 2);
		}
		else {
			puts("잘못 입력하셨습니다");
		}
		*/
		//다른방법: ROCK, SCISSORS, PAPER는 앞 글자의 아스키코드 82,83,80으로 구별이 가능하므로 앞글자만 getchar()으로 한 바이트만 읽어오더라도 경기에서 무엇을 낸지 알수있다
		if (NULL != fgets(str, 1, stdin)) {//버퍼에서바로읽어오기는 안되고 메모리주소인 변수명을 주어야 한다
			//혹은 ROCK, SCISSORS, PAPER는 앞 글자의 아스키코드 82,83,80으로 구별이 가능하므로
			//앞글자만 getchar()으로 한 바이트만 읽어오더라도 경기에서 무엇을 낸지 알수있다
			num_class = (Num_class::Num_class)getchar();
			switch ((int)num_class) {
			case 82:
				SetEnum(&stackObj, 1, 0);
				break;
			case 83:
				SetEnum(&stackObj, 1, 1);
				break;
			case 80:
				SetEnum(&stackObj, 1, 2);
				break;
			default:
				puts("잘못 입력하셨습니다\n");
				rewind(stdin);
				break;
			}
		}
		
	}
	DeleteNode(&p_head);
	
	
	
	exit(0);
}