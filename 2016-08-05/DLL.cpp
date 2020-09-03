/*#include <iostream>

using namespace std;

typedef struct Double_Linked_List
{
	double key;
	Double_Linked_List *prev, *next;
} List;

List *head, *tail;

void init_list()
{
	head = new List;
	tail = new List;

	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;
}
void add_list(double data)
{
	List* nw = new List;

	nw->key = data;
	nw->next = head->next;
	nw->prev = head->next->prev;
	head->next = nw;
	head->next->prev = nw;
}
void ordered_list(double data)
{
	List *p;

	for (p=head->next; (p->key<=data && p!=tail); p=p->next) {}

	List *nw = new List;
	nw->key = data;

	if (p != tail)
	{
		nw->next = p->next;
		nw->prev = p->next->prev;
		p->next = nw;
		p->next->prev = nw;
	}
	else
	{
		nw->next = tail->prev->next;
		nw->prev = tail->prev;
		tail->prev->next = nw;
		tail->prev = nw;
	}
}
void print_list()
{
	for (List *p=head->next; p!=tail; p=p->next) { cout << p->key << endl; }
	cout << endl;
}
List *find_list(double data)
{
	List *p;

	for (p=head->next; (p->key!=data && p!=tail); p=p->next) {}

	if (p != tail) { return p; }
	else { return NULL; }
}
void delete_list(double del_data)
{
	List *p = find_list(del_data);

	if (p != NULL)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
	}
}

void main()
{
	init_list();
	for (int i=1; i<=5; i++) { add_list(i); }
	
	ordered_list(4.5);
	ordered_list(5.5);
	print_list();

	delete_list(4.5);
	print_list();
}*/