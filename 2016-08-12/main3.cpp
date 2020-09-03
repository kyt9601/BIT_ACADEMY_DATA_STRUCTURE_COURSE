#include <iostream>

using namespace std;

char rev[][7]={ "����","�����","��ν�","������","��ο�",
				"����","������","������","������","������",
				"ȫ����","���Ͽ�","������","������","������",
				"������","����ȣ","������","������","��ȣ��",
				"�ӹ̰�","��Ҹ�","�����","������","������",
				"��Ȳ��","�ִٿ�","������","���ؼ�" };

struct List
{
	char *name;
	List *next;
};

List *head, *tail;

void init_list()
{
	head = new List;
	tail = new List;

	head->next = tail;
	tail->next = tail;
}
void init_insert_list()
{
	for (int i=0; i<sizeof(rev)/sizeof(rev[0]); i++)
	{
		List *nw = new List;
		nw->name = strdup(rev[i]);

		nw->next = head->next;
		head->next = nw;
	}
}
void init_sort_list()
{
	char *min;
	List *h;

	for (List *p=head->next; p->next!=tail; p=p->next)
	{
//		min = new char[strlen(p->name)+1];
//		strcpy(min,p->name);
		min = strdup(p->name);

		h = NULL;
		
		for (List *t=p->next; t!=tail; t=t->next)
		{
			if (strcmp(min,t->name) > 0)
			{
				delete min;
//				min = new char[strlen(t->name)+1];
//				strcpy(min,t->name);
				min = strdup(t->name);

				h = t;
			}
		}

		if (h != NULL)
		{
			swap(p->name,h->name);
		}
	}
}
List *search_list(char *name)
{
	List *p;

	for (p=head->next; (p!=tail && strcmp(p->name,name)!=0); p=p->next) {}

	if (p != tail) { return p; }
	else { return NULL; }
}
void add_list()
{
	char add[7];
	cout << "�߰��� �̸� : ";
	cin >> add;

	List *p = search_list(add);

	if (p != NULL)
	{
		cout << "�̸��� �����մϴ�" << endl;
	}
	else
	{
		List *nw = new List;
		nw->name = strdup(add);

		nw->next = head->next;
		head->next = nw;
		init_sort_list();
	}
}
void delete_list()
{
	char del[7];
	cout << "������ �̸� : ";
	cin >> del;

	List *p = search_list(del);

	if (p != NULL)
	{
		List *h;

		for (h=head; h->next!=p; h=h->next) {}

		h->next = p->next;
		delete p;
	}
}
void print_list()
{
	int i = 1;
	for (List *p=head->next; p!=tail; p=p->next,i++) { cout << p->name << endl; }
	cout << endl;
}

int main()
{
	init_list();
	init_insert_list();
	init_sort_list();

	int num;

	do
	{
		system("cls");
		print_list();

		cout << "[1] ����" << endl;
		cout << "[0] ����" << endl;
		cout << "���� : ";
		cin >> num;

		switch (num)
		{
		case 1 : delete_list(); break;
		case 0 : break;
		}
	}
	while (num != 0);

	return 0;
}