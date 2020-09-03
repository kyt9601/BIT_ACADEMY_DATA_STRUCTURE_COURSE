#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 256

struct nlist
{
	int key;	//
	char *name; 
	char *phone;
	struct nlist *next;
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval=0; *s!='\0'; s++) 
	{
		hashval *= 31;
		hashval += *s;
	}

	return hashval % HASHSIZE; 
}

struct nlist* lookup(char *s)
{
	struct nlist *np;

	for(np=hashtab[hash(s)]; np!=NULL; np=np->next)
	{
		if (strcmp(s,np->name) == 0) { return np; }
	}

	return NULL; 
}

char *str_mcopy(char *s)
{
	char *p = (char*)malloc(strlen(s)+1);

	if (p != NULL) { strcpy(p,s); }

	return p;
}

struct nlist* install(char *name, char *phone)
{
	struct nlist *np;
	unsigned hashval;

	if ((np=lookup(name)) == NULL)
	{
		np = (struct nlist*)malloc(sizeof(*np));

		if (np==NULL || (np->name=str_mcopy(name))==NULL)
		{
			return NULL;
		}

		np->key  = hash(name);
		hashval = hash(name);
		np->next = hashtab[hashval]; 
		hashtab[hashval] = np;
	}
	else
	{
//		free ((void*)np->phone);
		np = (struct nlist*)malloc(sizeof(*np));

		if (np==NULL || (np->name=str_mcopy(name))==NULL)
		{
			return NULL;
		}

		np->key  = hash(name);
		hashval = hash(name)-1;
		np->next = hashtab[hashval]; 
		hashtab[hashval] = np;
	}

	if ((np->phone=str_mcopy(phone)) == NULL) 
	{
		return NULL;
	}

	return np;
}
void print(char *s)
{
	int i;
	struct nlist *head, *ptr;

	for (i=0; i<HASHSIZE; i++)
	{
		head = hashtab[i];

		for (ptr=head; ptr!=NULL; ptr=ptr->next)
		{
			if (strcmp(ptr->name,s) == 0)
				{ printf("found : %s, %s\n",ptr->name,ptr->phone); }
		}
	}
}

int main()
{
	char *name[] = {"손나은","김태희","한지민",
		"문채원","전지현","문채원"};
	char *phone[] = {"731-1234", "567-8976", "521-5030", 
		"521-9600", "418-4165", "520-3307", "425-1024"};
	int i, n = sizeof(name) / sizeof(name[0]);
	struct nlist *head, *ptr;

	for (i=0; i<n; i++)
	{
		printf("%d : %s\n",hash(name[i]),name[i]);
		install(name[i],phone[i]);
	}

	printf ("\nHash Table List\n");

	for (i=0; i<HASHSIZE; i++)
	{
		head = hashtab[i];

		for (ptr=head; ptr!=NULL; ptr=ptr->next)
		{
			printf("%d : %s, %s\n",ptr->key,ptr->name,ptr->phone);
		}
	}

	printf("\nHash Table Search \n");

//	ptr = lookup("문채원");
//	printf("found : %s, %s\n",ptr->name,ptr->phone);

	print("문채원");

	printf("\nPress any key to end...");
	getchar();
	return 0;
}