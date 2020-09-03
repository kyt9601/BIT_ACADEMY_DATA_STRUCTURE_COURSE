/*
#include <stdio.h>
#include <malloc.h>
#include "List.h"

//	 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//	ㅣ									 ㅣ
//	ㅣ									 ㅣ
//	ㅣ				 Data				 ㅣ
//	ㅣ									 ㅣ
//	ㅣㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅣ
//	ㅣ									 ㅣ
//	ㅣ				 next				 ㅣ
//	 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

List *create_list(int data)
{
	List *nw;
	nw = (List*)malloc(sizeof(List));

	nw->key = data;

	return nw;
}
void init_list()
{
	head = (List*)malloc(sizeof(List));
	tail = (List*)malloc(sizeof(List));

	head->next = tail;
	tail->next = tail;
}
void insert_at_first(List *nw)
{
	nw->next = head->next;
	head->next = nw;
}
void add_list(int data)
{
	List *nw;
	nw = create_list(data);

	insert_at_first(nw);
}
void print_list()
{
	List *view;
//	view = head->next;

	for (view=head->next; view!=tail; view=view->next)
//	while (view != tail)
	{
		printf("%d\n",view->key);
//		view = view->next;
	}
}
void ordered_insert(int data)
{	// 자동으로 크기순 정렬
	List *p, *c;
	List *nw;

	p = head;
//	c = head->next;
	c = (*head).next;

//	while (c->key<=data && c!=tail)
	while ((*c).key<=data && c!=tail)
	{
//		p = p->next;
		p = (*p).next;
//		c = c->next;
		c = (*c).next;
	}

	nw = create_list(data);

//	p->next = nw;
	(*p).next = nw;
//	nw->next = c;
	(*nw).next = c;

}

void main()
{
	init_list();

//	add_list(3);
//	add_list(4);
//	add_list(1);
//	add_list(5);
//	add_list(2);

	ordered_insert(3);
	ordered_insert(4);
	ordered_insert(1);
	ordered_insert(5);
	ordered_insert(2);

	print_list();
}
*/