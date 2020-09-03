#include <iostream>

using namespace std;

char rev[][7]={ "����","�����","��ν�","������","��ο�",
				"����","������","������","������","������",
				"ȫ����","���Ͽ�","������","������","������",
				"������","����ȣ","������","������","��ȣ��",
				"�ӹ̰�","��Ҹ�","�����","������","������",
				"��Ȳ��","�ִٿ�","������","���ؼ�" };

struct Tree
{
	char *name;
	Tree *left;
	Tree *right;
};

Tree *head, *tail;

void init_list()
{
	head = new Tree;
	tail = new Tree;

	head->right = tail;
	head->left = NULL;
	tail->right = tail;
	tail->left= tail;
}
void init_insert_list()
{
	for (int i=0; i<sizeof(rev)/sizeof(rev[0]); i++)
	{
		Tree *nw = new Tree;
		nw->name = strdup(rev[i]);

		nw->right = head->right;
		nw->left = tail;
		head->right = nw;
	}
}
void sort_list()
{
	char *min;
	Tree *h;

	for (Tree *p=head->right; p->!=tail; p=p->left)
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
}*//*
void search_node(Tree *p)
{
	for (Tree *left)
}/*
void print_list()
{
	for (Tree *p=head->next; p!=tail; p=p->next) { cout << p->name << endl; }
}*/

int main()
{
	init_list();
	init_insert_list();
	sort_list();
//	print_list();

	return 0;
}