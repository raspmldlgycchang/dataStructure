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
	Num_class::Num_class enumObj[3];//����ں� 3������ ��������ϱ����ؼ�
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
	if (i < max_len) {//SCISSORS : 8���� ->8����Ʈ
		printf("%s : buffer\n", buffer);
		return 1;
	}
	buffer[i] = 0;
	rewind(stdin);
	return 0;
}
void SetEnum(void* const p, char flag, int input) {//p��� ��ġ�� ������ ���̰� void���������� �̿��Ϸ����� 
//�⺻������ ����(flag�� ��� �ڷ����� ������ ����)
//(����� �޸�ũ�� ����(�����ͺ���))
	for (unsigned int i = 0; i < 3; i++) {
		if (flag) {
			(((&((Stack*)p)->Node)->enumObj)[i]) = (Num_class::Num_class)input;
			printf("%p == %p : (&((Stack*)p)->Node)->enumObj�� �ּ� �� ((&((Stack*)p)->Node)->enumObj)[0]�� �ּ�\n", &((&((Stack*)p)->Node)->enumObj), &(((&((Stack*)p)->Node)->enumObj)[0]));
			printf("%d : enumObj\n", (((&((Stack*)p)->Node)->enumObj)[i]));
			//�Ű������� p_gyc p;�� �޾Ҵٸ� ((p_gyc)p)->enumObj = Num_class::Num_class::ROCK;�� ��
		}
	}
}
//������߰��ϴ� ���� AddNode���� �����ϰ�
//�����1�� ���� ���� �߰��ϴ� ���� �ٸ� �Լ��鿡�� �����Ѵ�
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
	//���ϴ� ��ŭ ����ڼ��� ����� ���ϴ� ��ŭ ����ڿ� ���� ���� �߰��ϱ����ؼ�
	// �ʱ�ȭ�� ���� ���� �ʰ� �Ʒ�ó�� ����ü ���� ���� �Ѵ�
	//Stack����ü���� ����� char�� ������ ����� �Է¿� ���� �ٸ� ���������� CharToInt��
	Stack stackObj;
	char str[2] = { 0, };//SCISSORS�� �ִ���� ���߱� 8����Ʈ
	Num_class::Num_class num_class;
	NODE* p_head = &(stackObj.Node);
	p_head = NULL;
	while (1) {
		//Stack����ü�� ����ڿ� �ش��ϴ� ����� ��� �Ҵ�
		//Stack����ü�� ��� Node����ü�� ���ؼ� pp_head�� �����ش�
		AddNode(&p_head);
		puts("ROCK, SCISSORS, PAPER � ���� �����Ͻðھ��?:(for exit: press CTRL+C)");
		//���� �ڵ�� �ٲٱ�(read, send ��)
		//Ctrl+Có���κ�
		char buffer[8] = { 0, };
		//scanf�� �о�� ���� �ϳ��� ���ڰ� �ƴϰ� ������ ���� scanf�� ���и� ��ȯ�� ��
		//if (scanf_s("%c", &num_class) == 0) {
		//	rewind(stdin);
		//	printf("[Enter] Capital Letter of ROCK, SCISSORS, PAPER: ");
		//}
		/*
		//�̰� ù��° ������� ROCK, SCISSORS, PAPER�� ���� str���ڿ��� ��� �о�ͼ� strcmp�� ���ϴ� ����̴�
		unsigned int i = 0;
		for (; i < 8 - 1; i++) {
			num_class = (Num_class::Num_class)getchar();
			buffer[i] = (char)num_class;
			if (buffer[i] == '\n') {
				buffer[i] = 0;
				break;
			}
		}
		if (i < 7)	printf("%s : ����ڰ� ��⿡�� �� ��\n", buffer);
		else {
			buffer[i] = 0;
			rewind(stdin);
			printf("����ڰ� 7���� �̻��� ���ڸ� �Է��ؼ� ���ڰ� �߷��� ����˴ϴ�\n");
		}
		if (strcmp(str, "ROCK")) {
			SetEnum(&stackObj, 1, 0);//��� ����ü enumObj�� ���������� ����� 0,1,2�� �����Ϸ��� int������ ROCK, SCISSORS, PAPER�� 0,1,2�� ���ְ� �����༭ 
									//SetEnum�Լ����� �� ������ �ٷ� enumObj�� �־��ֵ��� ���־�� �Ѵ�
		}
		else if (strcmp(str, "SCISSORS")) {
			SetEnum(&stackObj, 1, 1);
		}
		else if (strcmp(str, "PAPER")) {
			SetEnum(&stackObj, 1, 2);
		}
		else {
			puts("�߸� �Է��ϼ̽��ϴ�");
		}
		*/
		//�ٸ����: ROCK, SCISSORS, PAPER�� �� ������ �ƽ�Ű�ڵ� 82,83,80���� ������ �����ϹǷ� �ձ��ڸ� getchar()���� �� ����Ʈ�� �о������ ��⿡�� ������ ���� �˼��ִ�
		if (NULL != fgets(str, 1, stdin)) {//���ۿ����ٷ��о����� �ȵǰ� �޸��ּ��� �������� �־�� �Ѵ�
			//Ȥ�� ROCK, SCISSORS, PAPER�� �� ������ �ƽ�Ű�ڵ� 82,83,80���� ������ �����ϹǷ�
			//�ձ��ڸ� getchar()���� �� ����Ʈ�� �о������ ��⿡�� ������ ���� �˼��ִ�
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
				puts("�߸� �Է��ϼ̽��ϴ�\n");
				rewind(stdin);
				break;
			}
		}
		
	}
	DeleteNode(&p_head);
	
	
	
	exit(0);
}