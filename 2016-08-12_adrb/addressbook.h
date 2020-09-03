#ifndef __ADDRESSBOOK_H__
#define __ADDRESSBOOK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "PhoneBook.txt"
#define NAME_SIZE 15
#define PON_SIZE 20
#define GRP_SIZE 10
#define REC_SIZE (NAME_SIZE + PON_SIZE + GRP_SIZE)
typedef struct _phone {
	char name[NAME_SIZE];
	char phone[PON_SIZE]; 
	char group[GRP_SIZE];
	struct _phone *next;
}Phone_Node;
void input_atfirst(Phone_Node *t);
void init_phone(void);
void input_phone(void);
void display_phone(Phone_Node *t);
void display_outline(void);
void open_phone();
void save_phone();
int delete_phone(char *s);
Phone_Node *search_phone(Phone_Node **p, char *s);

#endif