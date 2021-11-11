#include<stdio.h>
#include<stdlib.h>
#include"Stack1.h"
#define MAX_CAPACITY 100
char stack[MAX_CAPACITY];
int top = -1;//index of top element

char Push(char ch){
	if (IsFull())/*������ �������� �� �̻� push�� �� ����*/
		return -1;
	top++;
	stack[top] = ch;
	/*������ ���� top=-1�� �ʱ�ȭ�Ǿ����Ƿ� �Ʒ��� �ڵ�� �� ���� ���� */
	//stack[top++] = ch;
}
int IsEmpty()
{
	return top == -1;
}
int IsFull()
{
	return top == MAX_CAPACITY - 1;
}
char Pop()
{
	/*pop�ϱ��������� emety�˻�*/
	if (IsEmpty())
		return NULL;
	/*��ȯ�� ���� ������ �����ϰ� top�� �ϳ� ������*/
	char tmp = stack[top];
	top--;
	return tmp;
}
char Peek()
{
	/*������ ����ִ��� �˻�*/
	if (IsEmpty())
		return NULL;
	return stack[top];
}
int main(void)
{
	while (1) {
		int menu,ch;
		int save_ch;
		printf("���� ������ ��:%d / %d\n", top+1, MAX_CAPACITY);
		printf("(1)Push(2)Pop(3)Peek(4)����:");
		scanf_s("%d", &menu);
		rewind(stdin);
		if (menu == 4)	break;
		switch (menu) {
		case 1:
			printf("�����ͷ� � ����?:");
			ch = getc(stdin);
			rewind(stdin);
			if (Push(ch) == -1)
				puts("Push����");/*���͸� ġ�� ���� \n�� \0���� ġȯ*/
			break;
		case 2:
			save_ch = Pop();
			if (save_ch== NULL)
				puts("Pop����");
			else
				printf("Pop������ :%c\n", save_ch);
			break;
		case 3:
			save_ch = Peek();
			if (save_ch == NULL)
				puts("Peek����");
			else
				printf("top�� ������:%c\n", save_ch);
			break;
		default:
			printf("�߸��� �޴���ȣ�Դϴ�\n");
			break;
		}
	}
	return 0;
}