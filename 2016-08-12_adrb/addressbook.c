#include "addressbook.h"

extern Phone_Node *head;  // sll의 첫 노드
extern Phone_Node *tail;  // sll의 마지막 노드

void init_phone(void)
{
	head = (Phone_Node*)malloc(sizeof(Phone_Node));
	tail = (Phone_Node*)malloc(sizeof(Phone_Node));
	head->next = tail;
	tail->next = tail;
}
void input_atfirst(Phone_Node *t)
{
	//  sll의 맨 앞에 t 노드를 삽입하는 로직을 구현하세요.
	Phone_Node *nw = (Phone_Node*)malloc(sizeof(Phone_Node));

	strcpy(nw->name,t->name);
	strcpy(nw->phone,t->phone);
	strcpy(nw->group,t->group);

	nw->next = head->next;
	head->next = nw;
}
void input_phone(void)
{
	Phone_Node *t;
	t = (Phone_Node*)malloc(sizeof(Phone_Node));
	puts("*****************");
	puts("** Phone Input **"); 
	puts("*****************");
	printf(" 이름 입력: ");
	gets(t->name);

	printf(" 폰번호 입력: ");
	gets(t->phone); 

	printf(" 그룹 입력: ");
	gets(t->group);
	/* insert at first */
	input_atfirst(t);
}

void display_phone(Phone_Node *t)
{
	printf("  %-14s %-17s %-10s\n", t->name, t->phone, t->group);
}
void display_outline(void)
{ 
	puts("************** ***************** **********");
	puts("     이름            휴대폰         그룹");
	puts("************** ***************** **********");
}
void open_phone()
{
	FILE *fp=NULL;
	Phone_Node *t=NULL;
	Phone_Node *p=NULL;
	Phone_Node *s=NULL;

	if ((fp = fopen(FILE_NAME, "rt")) == NULL)
	{
		printf("파일 %s 가 열리지 않았습니다.\n",FILE_NAME);
		return;
	}

	while (1)
	{
		t = (Phone_Node*)malloc(sizeof(Phone_Node));
		if (!fread(t, REC_SIZE, 1, fp)) {
			free(t); break;
		}
		//  sll에 없는 경우 삽입 
		s = search_phone(&p, t->name);
		if (s == NULL) 
			input_atfirst(t);
	}

	fclose(fp);
}
void save_phone()
{
	FILE *fp;
	Phone_Node *t;

	if ((fp = fopen(FILE_NAME, "wt")) == NULL){
		printf("파일 %s 가 열리지 않았습니다.\n",FILE_NAME);
		return;
	}

	t = head->next;
	while (t != tail)
	{
		fwrite(t, REC_SIZE, 1, fp);
		t = t->next;
	}
	fclose(fp);
}
int delete_phone(char *s)
{
	Phone_Node *t = NULL;  // 삭제할 노드를 저장하는 변수
	Phone_Node *p = NULL;  // 삭제할 노드의 이전 노드를 저장하는 변수

	//  s 변수에 저장된 이름 노드를 찾아 삭제하는 부분을 작성하세요.  
	//  삭제할 노드 찾기에 대해서는 search_phone 함수를 사용하도록 합니다.
	//  return 값은 삭제 한 경우 1, 삭제하지 못한 경우 0을 반환합니다.

	t = search_phone(&p,s);

	if (t != NULL)
	{
		p->next = t->next;
		free(t);

		return 1;
	}
	else
	{
		return 0;
	}
}
Phone_Node *search_phone(Phone_Node **p, char *s)
{
	Phone_Node *t;
	//  이름이 s인 노드를 검색하는 코드를 작성하세요.
	//  p는 이전노드, t는 검색결과를 저장하는 변수이며, 문자열 비교는 strcmp를 사용함

	for (t=head->next; t!=tail; t=t->next)
	{
		if (strcmp(t->name,s) == 0) { break; }
	}

	if (t != tail)
	{
		for ((*p)=head; (*p)->next!=t; (*p)=(*p)->next) {}
	}

	return (t == tail) ? NULL : t;
}