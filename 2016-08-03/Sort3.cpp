/*#include <iostream>

using namespace std;

"정희석","조경빈","김민식","정윤기","김민우",
"김상원","조성윤","김형섭","나승학","허진석",
"홍종완","이하연","조유진","박종현","박종후",
"신지윤","윤승호","윤정문","이현지","이호준",
"임미경","김소림","김원명","김유미","김정원",
"조황석","최다운","최진의","허준성"

#define swap(x,y) do{int t; t=x, y=x, y=t;}while(0);

int partition(int arr[], int s, int e) 
{ 
	int i, j, pivot;

	i = s; 
	j = e + 1; 

	pivot = arr[i];

	while(i < j)
	{ 
		while(arr[++i] <= pivot);
		while(arr[--j] > pivot);

		if (i < j) { swap(arr[i],arr[j]); } 
	} 

	swap(arr[s],arr[j]);

	return j; 
} 
void Myqsort(int arr[], int s, int e) 
{ 
	int mid; 

	if (s < e)
	{ 
		mid = partition(arr,s,e); 
		Myqsort(arr,s,mid-1); 
		Myqsort(arr,mid+1,e); 
	} 
}

void main()
{
	int a[]={3,4,1,5,2};

	Myqsort(a,0,4);

	for (int i=0; i<sizeof(a)/sizeof(int); i++) { cout << a[i] << endl; }
}

void main()
{
	int arr[5] = {3,4,1,5,2};

	int i, j, k, l;

	while (1)
	{
		for (i=1; arr[0]>=arr[i]; i++);
		for (j=4; arr[0]<arr[j]; j--);

		if (i != j-1) { swap(arr[i],arr[j]); }
		else { swap(arr[0],arr[i]); break;}
	}

	while (1)
	{
		for (j=1; arr[0]>=arr[j]; j++);
		for (k=i-1; arr[0]<arr[k]; k--);

		if (j != k-1) { swap(arr[j],arr[k]); }
		else { swap(arr[0],arr[j]); break;}
	}

	while (1)
	{
		for (k=i+2; arr[i+1]>=arr[k]; k++);
		for (l=4; arr[i+1]<arr[l]; l--);

		if (k != l-1) { swap(arr[k],arr[l]); }
		else { swap(arr[i+1],arr[k]); break;}
	}

	for (int k=0; k<5; k++) { cout << arr[k] << endl; }
}

typedef struct LIST
{
	int key;
	LIST *next;
} List;

List *head, *tail;

void init_List()
{
	head = new List;
	tail = new List;

	head->next = tail;
	tail->next = tail;
}
void add_List(int data)
{
	List *p;
	p = new List;

	p->key = data;
	p->next = head->next;
	head->next = p;
}
void print_list()
{
	List *p;

	for (p=head->next; p!=tail; p=p->next)
	{
		cout << p->key << endl;
	}
}

void main()
{
	init_List();
	
	add_List(10);
	add_List(20);
	add_List(30);
	add_List(40);

	print_list();
}*/