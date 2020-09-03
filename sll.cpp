#include <iostream>
#include <time.h>

using namespace std;

typedef struct Doubly_Linked_List
{	
	char *name;
	int price;
	int count;
	Doubly_Linked_List *next;
	Doubly_Linked_List *prev;
} List;

List *head, *tail;

void print_init();
void init_list();
List *find_list(char *data);
void add_list(char *name_data, int price_data, int count_data);
void print_item();
void fout_item();
void find_item();
void delete_item();
void print_init();
void sort_item();
void sort_list(int sel1, int sel2);

void print_init()
{
	cout << "=====  M E N U  =====" << endl;
	cout << " 1. 매출현황 출력" << endl;
	cout << " 2. 매출현황 내보내기" << endl;
	cout << " 3. 상품 찾기" << endl;
	cout << " 4. 상품 삭제" << endl;
	cout << " 5. 매출현황 배열" << endl;
	cout << " 6. 정렬" << endl;
	cout << " 7. 종료" << endl;
	cout << "=====================" << endl;
	cout << "메뉴를 선택하시오 : ";
}
void init_list()
{
	head = new List;
	tail = new List;

	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;
}
void add_list(char *name_data, int price_data, int count_data)
{
	List *f;

	if (count_data == -1)
	{
		List *nw = new List;

		nw->name = strdup(name_data);
		nw->price = price_data;

		nw->next = head->next;
		nw->prev = head->next->prev;
		head->next->prev = nw;
		head->next = nw;
	}
	else
	{
		for (List *p=head->next; p!=tail; p=p->next)
		{
			f = find_list(name_data);
			f->count = count_data;
		}
	}
}
List *find_list(char *data)
{
	List *p;
	time_t t = clock();

	if (t%2 == 0)
	{
		for (p=head->next; (p!=tail && strcmp(p->name,data)!=0); p=p->next) {}
	}
	else
	{
		for (p=tail->prev; (p!=head && strcmp(p->name,data)!=0); p=p->prev) {}
	}

	if (p!=head && p!=tail) { return p; }
	else { return NULL; }
}
void print_item()
{
	int n = 1, sum = 0;

	cout << "============================================" << endl;
	cout << "\t" << "삼성전자 온라인  매출 현황" << endl;
	cout << "============================================" << endl;
	cout << "\t" << "상품명" << "\t" << "단가" << "\t" << "개수" << "\t" << "금액" << endl;
	cout << "--------------------------------------------" << endl;

	for (List *p=head->next; p!=tail; p=p->next,n++)
	{
		if (strcmp(p->name,"DVD")==0 || strcmp(p->name,"LEDTV")==0 || strcmp(p->name,"지펠")==0 || strcmp(p->name,"노트북5")==0)
		{
			cout << n << "\t" << p->name << "\t\t" << p->price << "\t" << p->count << "\t" << (p->price)*(p->count) << endl;
			sum += (p->price)*(p->count);
		}
		else
		{
			cout << n << "\t" << p->name << "\t" << p->price << "\t" << p->count << "\t" << (p->price)*(p->count) << endl;
			sum += (p->price)*(p->count);
		}
	}

	cout << "--------------------------------------------" << endl;
	cout << "\t" << "매출 합계" << "\t" << sum << endl;
	cout << "============================================" << endl;
}
void fout_item()
{
	FILE *item_out = fopen("C:\\List\\item_out.txt","w");
	FILE *sales_out = fopen("C:\\List\\sales_out.txt","w");

	for (List *p=head->next; p!=tail; p=p->next)
	{
		fprintf(item_out,"%s %d\n",p->name,p->price);
		fprintf(sales_out,"%s %d\n",p->name,p->count);
	}

	cout << "파일로 내보내기 완료" << endl;
}
void find_item()
{
	char data[100];
	cout << "검색상품 입력 : ";
	cin >> data;

	List *f = find_list(data);

	if (f != NULL)
	{
		cout << "============================================" << endl;
		cout << "상품명\t단가\t개수\t금액" << endl;
		cout << "--------------------------------------------" << endl;
		cout << f->name << "\t" << f->price << "\t" << f->count << "\t" << (f->price)*(f->count) << endl;
		cout << "============================================" << endl;
	}
	else
	{
		cout << "찾는 데이터가 없습니다." << endl;
	}
}
void delete_item()
{
	char data[100];
	cout << "삭제상품 입력  : ";
	cin >> data;

	List *f = find_list(data);

	if (f == NULL)
	{
		cout << "찾는 데이터가 없습니다." << endl;
	}
	else
	{
		f->prev->next = f->next;
		f->next->prev = f->prev;
		delete f;
	}
/*	else if (f->next==tail || f->prev==head)
	{
		f->prev->next = f->next;
		f->next->prev = f->prev;
		delete f;
	}
	else
	{
		for (List *t=f; t->next!=tail; t=t->next)
		{
			delete t->name;

			t->name = strdup(t->next->name);
			t->price = t->next->price;
			t->count = t->next->count;

			if (t->next->next == tail)
			{
				const List *p = t->next;

				t->next = t->next->next;
				delete p;
				
				break;
			}
		}
	}*/
}
void status_item()
{
	char char_temp[100];
	int int_temp;

	FILE *item = fopen("C:\\List\\item.txt","r");
	FILE *sales = fopen("C:\\List\\sales.txt","r");

	for (int i=0; fscanf(item,"%s %d",char_temp,&int_temp)!=EOF; i++)
	{
		add_list(char_temp,int_temp,-1);
	}

	for (int i=0; fscanf(sales,"%s %d",char_temp,&int_temp)!=EOF; i++)
	{
		add_list(char_temp,-1,int_temp);
	}

	cout << "불러오기 완료" << endl;
}
void sort_item()
{
	int num1, num2;

	cout << "정렬방법을 선택하시오" << endl;
	cout << "(상품명=0, 금액=1, 판매량=2, 판매금액=3) :";
	cin >> num1;

	cout << endl << "정렬방법을 선택하시오" << endl;
	cout << "(오름차순=0, 내림차순=1) :";
	cin >> num2;

	sort_list(num1,num2);
}
void sort_list(int sel1, int sel2)
{
	List *p, *h;
	int temp;
	int int_min;
	char *char_min;

	if (sel2 == 0)
	{
		for (p=head->next; p->next!=tail; p=p->next)
		{		
			h = NULL;
		
			if (sel1 == 0) { char_min = strdup(p->name); }
			else if (sel1 == 1) { int_min = p->price; }
			else if (sel1 == 2) { int_min = p->count; }
			else { int_min = (p->price) * (p->count); }

	//		min = p->price;

			for (List *t=p->next; t!=tail; t=t->next)
			{
				if (sel1 == 1) { temp = t->price; }
				else if (sel1 == 2) { temp = t->count; }
				else if (sel1 == 3) { temp = (t->price) * (t->count); }

				if (sel1!=0 && temp<int_min)
				{
					int_min = temp;

					h = t;
				}
				else if (sel1==0 && 0<strcmp(char_min,t->name))
				{
					delete char_min;
					char_min = strdup(t->name);

					h = t;
				}
			}

			if (h != NULL)
			{
				swap(p->name,h->name);
				swap(p->price,h->price);
				swap(p->count,h->count);
			}
		}
	}
	else
	{
		for (p=tail->prev; p->prev!=head; p=p->prev)
		{		
			h = NULL;
		
			if (sel1 == 0) { char_min = strdup(p->name); }
			else if (sel1 == 1) { int_min = p->price; }
			else if (sel1 == 2) { int_min = p->count; }
			else { int_min = (p->price) * (p->count); }

	//		min = p->price;

			for (List *t=p->prev; t!=head; t=t->prev)
			{
				if (sel1 == 1) { temp = t->price; }
				else if (sel1 == 2) { temp = t->count; }
				else if (sel1 == 3) { temp = (t->price) * (t->count); }

				if (sel1!=0 && temp<int_min)
				{
					int_min = temp;

					h = t;
				}
				else if (sel1==0 && 0<strcmp(char_min,t->name))
				{
					delete char_min;
					char_min = strdup(t->name);

					h = t;
				}
			}

			if (h != NULL)
			{
				swap(p->name,h->name);
				swap(p->price,h->price);
				swap(p->count,h->count);
			}
		}
	}
}	
/*
}
void sort_char()
{
	List *p, *h;
	char *min;

	for (p=head->next; p->next!=tail; p=p->next)
	{
		h = NULL;
		min = strdup(p->name);

		for (List *t=p->next; t!=tail; t=t->next)
		{
			if (0 < strcmp(min,t->name))
			{
				delete min;
				min = strdup(t->name);

				h = t;
			}
		}

		if (h != NULL)
		{
			swap(p->name,h->name);
			swap(p->price,h->price);
			swap(p->count,h->count);
		}
	}
}
*/
void main()
{	
	int num = 0;

	init_list();

	while (num != 7)
	{
		print_init();
		cin >> num;
		system("cls");

		switch (num)
		{
		case 1 : print_item(); break;
		case 2 : fout_item(); break;
		case 3 : find_item(); break;
		case 4 : delete_item(); break;
		case 5 : status_item(); break;
		case 6 : sort_item(); break;
		case 7 : break;
		}

		system("pause");
		system("cls");
	}
}