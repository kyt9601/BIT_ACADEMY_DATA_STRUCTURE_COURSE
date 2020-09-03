#ifndef _MYLIST_H_
#define _MYLIST_H_

typedef struct list
{
	int key;
	list *next;
} List;

List *head,*tail;

void init_list();
void insert_at_first(int data);
void ordered_insert(int data);
void print_list();
void find_list(int data);

#endif