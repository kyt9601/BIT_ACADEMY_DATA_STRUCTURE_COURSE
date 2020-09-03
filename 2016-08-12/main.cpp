/*#include <iostream>

using namespace std;

void search(char list[][9], char *key, int *size, int *mid_index)
{
	if (strcmp(list[*mid_index],key) == 0)
	{
		cout << "Pablo";
	}
	else if (strcmp(list[*mid_index],key) < 0)
	{
		(*mid_index) = ((*mid_index)+((*size)-1)) / 2;
	}
	else
	{
		(*mid_index) /= 2;
	}

	cout << list[*mid_index] << endl;
}

int main()
{
	char list[][9] = {"Alice", "Bill", "Carol", "David", "Elvis",
					"Fred", "Gabriel", "Helen", "Isabel", "Jane", "Kuper",
					"Louic", "Mathilda", "Nadia", "Olive", "Pablo", "Queen",
					"Rambo", "Scarlet", "Trisha", "Umberto", "Vincent", "Wily",
					"Xxx", "Yuki", "Zorro" };

	int size = sizeof(list)/sizeof(list[0]);
	int mid_index = (size-1) / 2;
	char *key = "Pablo";

	search(list,key,&size,&mid_index);
	search(list,key,&size,&mid_index);
	search(list,key,&size,&mid_index);
	search(list,key,&size,&mid_index);
	search(list,key,&size,&mid_index);
	search(list,key,&size,&mid_index);
	search(list,key,&size,&mid_index);
}*/