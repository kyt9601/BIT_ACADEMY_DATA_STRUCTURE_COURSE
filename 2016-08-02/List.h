/*
#ifndef _LIST_H_
#define _LIST_H_

// typedef struct list List;
// struct list
// {
//		int key;
//		struct list *next;
// };
typedef struct list
{
	int key;
	struct list *next;
}	List;

List *head, *tail;
// extern List *head, *tail;
// 기본적으로 붙어있다

List *create_list(int data);
void init_list();
void insert_at_first(List *nw);
void add_list(int data);
void print_list();
void oredered_insert(int data);

#endif
*/