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
void SetEnum(void* const p, char flag, int input) {//p��� ��ġ�� ������ ���̰� void���������� �̿��Ϸ����� 
//�⺻������ ����(flag�� ��� �ڷ����� ������ ����)
//(����� �޸�ũ�� ����(�����ͺ���))
	for (unsigned int i = 0; i < 3; i++) {
		if (flag) {
			*(int*)(((&((Stack*)p)->Node)->enumObj)[i]) = input;
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
	char str[8] = { 0, };//SCISSORS�� �ִ���� ���߱� 8����Ʈ
	Num_class::Num_class num_class;
	while (1) {
		//Stack����ü�� ����ڿ� �ش��ϴ� ����� ��� �Ҵ�
		//Stack����ü�� ��� Node����ü�� ���ؼ� pp_head�� �����ش�
		NODE* p_head = &(stackObj.Node);
		AddNode(&p_head);
		puts("ROCK, SCISSORS, PAPER � ���� �����Ͻðھ��?:(for exit: press CTRL+C)");
		//���� �ڵ�� �ٲٱ�(read, send ��)
		//Ctrl+Có���κ�
		if (NULL != fgets(str, 8, stdin)) {
			//���ۿ����ٷ��о����� �ȵǰ� �޸��ּ��� �������� �־�� �Ѵ�
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
				puts("�߸� �Է��ϼ̽��ϴ�\n");
				break;
			}
			
		}
	}
	
	
	
	exit(0);
}