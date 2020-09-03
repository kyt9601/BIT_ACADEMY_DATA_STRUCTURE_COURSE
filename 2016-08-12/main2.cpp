/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CntName 26

char key[CntName][10] = {"Alice", "Bill", "Carol", "David", "Elvis", "Fred", "Gabriel",
"Helen", "Isabel", "Jane", "Kuper", "Louic", "Mathilda", "Nadia", "Olive",
"Pablo", "Queen", "Rambo", "Scarlet", "Trisha", "Umberto", "Vincent", 
"Wily", "Xxx", "Yuki", "Zorro"};

// ���� Ž�� (�Ϲ� �Լ�)
int BiSearch_F(char *find)
{
	int low, high, mid;
	low = 0;
	high = CntName-1;

	while(low <= high)
	{
		mid = (low + high) / 2;				// �߰� ���� ���   

		if(strcmp(key[mid], find) > 0)		// find < key[mid]
		{
			high = mid -1;
			continue;
		}

		if(strcmp(key[mid], find) == 0)     // find == key[mid]
			return mid;

		if(strcmp(key[mid], find) < 0)      // find > key[mid]
			low = mid +1;
	}

	return -1;
}

// ���� Ž�� (��� �Լ�)
int BiSearch_R(char *find, int low, int high)
{
	int mid; 

	if(low > high)      
		return -1;

	mid = (low + high) / 2;

	if(strcmp(key[mid], find) > 0)
	{
		high = mid -1;
		return BiSearch_R(find, low, high);
	}

	if(strcmp(key[mid], find) == 0)
		return mid;

	if(strcmp(key[mid], find) < 0)
	{
		low=  mid +1;
		return BiSearch_R(find, low, high);
	}

	return 0;
}

int str_cmp(const void * fir, const void *sec)
{
	return -1;
}

void main()
{
	char name[10];
	int result;
	char (*save)[10] = key;
	char (*location)[sizeof(key[0])];

	printf("ã���� �ϴ� �̸��� : ");
	scanf_s("%s",name);

	result = BiSearch_F(name);

	printf("\n======�Ϲ� �Լ�=======");

	if(result <0)
		printf("\nã�� �̸��� �������� �ʴ´�.\n");
	else
		printf("\n %s�� �迭 %d��° ��ġ�Ѵ�.\n", name, result+1);

	printf("\n======��� �Լ�======="); 

	result = BiSearch_R(name, 0, CntName);

	if(result <0)
		printf("\nã�� �̸��� �������� �ʴ´�.\n");
	else
		printf("\n %s�� �迭 %d��° ��ġ�Ѵ�.\n", name, result+1);

	printf("\n======���̺귯��  �Լ�======="); 

	//location = bsearch(name,key, sizeof(key)/sizeof(key[0]), sizeof(key[0]), str_cmp());

//	if(location == 0)
		printf("\nã�� �̸��� �������� �ʴ´�.\n");
}*/