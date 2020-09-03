#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addressbook.h"

enum MENU { QUIT, INPUT, OUTPUT, SEARCH, OPEN, SAVE, DELETE };
Phone_Node *head, *tail;
int getMenu(void);