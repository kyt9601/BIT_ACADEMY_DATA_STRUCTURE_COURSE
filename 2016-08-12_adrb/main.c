// input_atfirst 함수
// delete_phone 함수
// search_phone 함수
// 3개의 함수를 완성 하시오

#include "main.h"
/* Single Linked List (head, tail, emptynode) */

int main(void)
{
	Phone_Node *t = NULL;
	Phone_Node *p = NULL;
	char name[NAME_SIZE]="";
	int select=0;

	init_phone();

	while ((select = getMenu()) != QUIT)
	{
		switch (select)
		{
		case INPUT: 
			input_phone();
		break;
		case OUTPUT: 
			t = head->next;
			display_outline();
			while (t != tail)
			{
				display_phone(t);
				t = t->next;
			}
		break;
		case SEARCH: 
			printf("검색이름 : ");
			gets(name);
			t = search_phone(&p, name);
			if (t == NULL) {
				printf("이름을 찾을수 없습니다.");
				break;
			}
			display_outline();
			display_phone(t);
		break;
		case OPEN :
			open_phone();
		break;
		case SAVE :
			save_phone();
		break;
		case DELETE : 
			printf("삭제이름: ");
			gets(name);
			if (!delete_phone(name))
				printf("삭제할 데이터를 찾을수 없습니다.");
		break;
		}/*switch*/
	}/*while*/

	printf("종료합니다\n");
}
int getMenu(void){

	int select;

	puts("===============");
	puts("  Phone Book");
	puts("===============");
	puts(" 1. 입력");
	puts(" 2. 출력");
	puts(" 3. 검색");
	puts(" 4. 열기");
	puts(" 5. 저장");
	puts(" 6. 삭제");
	puts(" 0. 종료");
	puts("===============");

	do
	{
		printf("번호를 입력하세요: ");
		scanf("%d", &select);
		fflush(stdin);
	}
	while (select < 0 || select > 6);

	return select;
}