#include <iostream>
#include <time.h>

#include "MyList.h"

using namespace std;

void init_list()
{
	head = new List;
	tail = new List;

	head->next = tail;
	tail->next = tail;
}
void insert_at_first(int data)
{
	List *nw = new List;

	nw->key = data;

//	List *c = head->next;
//	head->next = nw;
//	nw->next = c;
	nw->next = head->next;
	head->next = nw;
// 순서가 반대지만, 변수가 1개 줄어든다
}
void ordered_insert(int data)
{
	List *p, *c;
	
	p = head;
	c = head->next;

	while (c->key<=data && c!=tail)
	{
		p = p->next;
		c = c->next;
	}

	// p 와 c 사이에
	// nw 를 끼워 넣는다
	List *nw = new List;
	nw->key = data;
	p->next = nw;
	nw->next = c;
}
void print_list()
{
	List *p;

	for (p=head->next; p!=tail; p=p->next)
	{
		cout << p->key << endl;
	}
}
void find_list(int data)
{
	List *p;
	bool Find = false;

	for (p=head->next; p!=tail; p=p->next)
	{
		if (p->key == data)
		{
			Find = true;
		}
	}

	if (Find == true)
	{
		cout << "데이터를 찾았습니다" << endl;
	}
	else
	{
		cout << "데이터를 찾지 못했습니다" << endl;
	}
}
void delete_list(int data)
{
	List *p;
	
	for (p=head->next; (p->key!=data && p!=tail); p=p->next);
	{
		if (p->key == data)
		{
			p = p->next;
		}
	}
}

void delay(int dy)
{
	time_t t;
	t = clock();
	while (clock()-t<dy);
}

void main()
{
	init_list();

	insert_at_first(30);
	insert_at_first(10);
	insert_at_first(20);

	ordered_insert(4);
	ordered_insert(1);
	ordered_insert(5);
	ordered_insert(2);
	ordered_insert(3);

	print_list();

	find_list(10);
	find_list(100);
	
	delete_list(10);

	print_list();

	delay(2000);	// 2초 딜레이
}