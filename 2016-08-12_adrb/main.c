// input_atfirst �Լ�
// delete_phone �Լ�
// search_phone �Լ�
// 3���� �Լ��� �ϼ� �Ͻÿ�

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
			printf("�˻��̸� : ");
			gets(name);
			t = search_phone(&p, name);
			if (t == NULL) {
				printf("�̸��� ã���� �����ϴ�.");
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
			printf("�����̸�: ");
			gets(name);
			if (!delete_phone(name))
				printf("������ �����͸� ã���� �����ϴ�.");
		break;
		}/*switch*/
	}/*while*/

	printf("�����մϴ�\n");
}
int getMenu(void){

	int select;

	puts("===============");
	puts("  Phone Book");
	puts("===============");
	puts(" 1. �Է�");
	puts(" 2. ���");
	puts(" 3. �˻�");
	puts(" 4. ����");
	puts(" 5. ����");
	puts(" 6. ����");
	puts(" 0. ����");
	puts("===============");

	do
	{
		printf("��ȣ�� �Է��ϼ���: ");
		scanf("%d", &select);
		fflush(stdin);
	}
	while (select < 0 || select > 6);

	return select;
}