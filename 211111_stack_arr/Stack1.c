#include<stdio.h>
#include<stdlib.h>
#include"Stack1.h"
#define MAX_CAPACITY 100
char stack[MAX_CAPACITY];
int top = -1;//index of top element

char Push(char ch){
	if (IsFull())/*스택이 가득차면 더 이상 push할 수 없다*/
		return -1;
	top++;
	stack[top] = ch;
	/*지금의 경우는 top=-1로 초기화되었으므로 아래의 코드로 한 번에 가능 */
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
	/*pop하기전에먼저 emety검사*/
	if (IsEmpty())
		return NULL;
	/*반환할 값을 변수에 저장하고 top을 하나 내린다*/
	char tmp = stack[top];
	top--;
	return tmp;
}
char Peek()
{
	/*스택이 비어있는지 검사*/
	if (IsEmpty())
		return NULL;
	return stack[top];
}
int main(void)
{
	while (1) {
		int menu,ch;
		int save_ch;
		printf("현재 데이터 수:%d / %d\n", top+1, MAX_CAPACITY);
		printf("(1)Push(2)Pop(3)Peek(4)종료:");
		scanf_s("%d", &menu);
		rewind(stdin);
		if (menu == 4)	break;
		switch (menu) {
		case 1:
			printf("데이터로 어떤 문자?:");
			ch = getc(stdin);
			rewind(stdin);
			if (Push(ch) == -1)
				puts("Push오류");/*엔터를 치는 순간 \n을 \0으로 치환*/
			break;
		case 2:
			save_ch = Pop();
			if (save_ch== NULL)
				puts("Pop오류");
			else
				printf("Pop데이터 :%c\n", save_ch);
			break;
		case 3:
			save_ch = Peek();
			if (save_ch == NULL)
				puts("Peek오류");
			else
				printf("top의 데이터:%c\n", save_ch);
			break;
		default:
			printf("잘못된 메뉴번호입니다\n");
			break;
		}
	}
	return 0;
}