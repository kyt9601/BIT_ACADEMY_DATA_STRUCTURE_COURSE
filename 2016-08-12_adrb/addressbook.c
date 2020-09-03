#include "addressbook.h"

extern Phone_Node *head;  // sll�� ù ���
extern Phone_Node *tail;  // sll�� ������ ���

void init_phone(void)
{
	head = (Phone_Node*)malloc(sizeof(Phone_Node));
	tail = (Phone_Node*)malloc(sizeof(Phone_Node));
	head->next = tail;
	tail->next = tail;
}
void input_atfirst(Phone_Node *t)
{
	//  sll�� �� �տ� t ��带 �����ϴ� ������ �����ϼ���.
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
	printf(" �̸� �Է�: ");
	gets(t->name);

	printf(" ����ȣ �Է�: ");
	gets(t->phone); 

	printf(" �׷� �Է�: ");
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
	puts("     �̸�            �޴���         �׷�");
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
		printf("���� %s �� ������ �ʾҽ��ϴ�.\n",FILE_NAME);
		return;
	}

	while (1)
	{
		t = (Phone_Node*)malloc(sizeof(Phone_Node));
		if (!fread(t, REC_SIZE, 1, fp)) {
			free(t); break;
		}
		//  sll�� ���� ��� ���� 
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
		printf("���� %s �� ������ �ʾҽ��ϴ�.\n",FILE_NAME);
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
	Phone_Node *t = NULL;  // ������ ��带 �����ϴ� ����
	Phone_Node *p = NULL;  // ������ ����� ���� ��带 �����ϴ� ����

	//  s ������ ����� �̸� ��带 ã�� �����ϴ� �κ��� �ۼ��ϼ���.  
	//  ������ ��� ã�⿡ ���ؼ��� search_phone �Լ��� ����ϵ��� �մϴ�.
	//  return ���� ���� �� ��� 1, �������� ���� ��� 0�� ��ȯ�մϴ�.

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
	//  �̸��� s�� ��带 �˻��ϴ� �ڵ带 �ۼ��ϼ���.
	//  p�� �������, t�� �˻������ �����ϴ� �����̸�, ���ڿ� �񱳴� strcmp�� �����

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