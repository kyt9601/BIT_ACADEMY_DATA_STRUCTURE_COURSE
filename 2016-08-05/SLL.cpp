#include <iostream>

using namespace std;

typedef struct Single_Linked_List
{	
	char *name;
	int price;
	int count;
	Single_Linked_List *next;
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
void sort();

void print_init()
{
	cout << "=====  M E N U  =====" << endl;
	cout << " 1. ������Ȳ ���" << endl;
	cout << " 2. ������Ȳ ��������" << endl;
	cout << " 3. ��ǰ ã��" << endl;
	cout << " 4. ��ǰ ����" << endl;
	cout << " 5. ������Ȳ �迭" << endl;
	cout << " 6. ����" << endl;
	cout << " 7. ����" << endl;
	cout << "=====================" << endl;
	cout << "�޴��� �����Ͻÿ� : ";
}
void init_list()
{
	head = new List;
	tail = new List;

	head->next = tail;
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

	for (p=head->next; (p!=tail && strcmp(p->name,data)!=0); p=p->next) {}

	if (p != tail) { return p; }
	else { return NULL; }
}
void print_item()
{
	int n = 1, sum = 0;

	cout << "============================================" << endl;
	cout << "\t" << "�Ｚ���� �¶���  ���� ��Ȳ" << endl;
	cout << "============================================" << endl;
	cout << "\t" << "��ǰ��" << "\t" << "�ܰ�" << "\t" << "����" << "\t" << "�ݾ�" << endl;
	cout << "--------------------------------------------" << endl;

	for (List *p=head->next; p!=tail; p=p->next,n++)
	{
		if (strcmp(p->name,"DVD")==0 || strcmp(p->name,"LEDTV")==0 || strcmp(p->name,"����")==0 || strcmp(p->name,"��Ʈ��5")==0)
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
	cout << "\t" << "���� �հ�" << "\t" << sum << endl;
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

	cout << "���Ϸγ������� �ϼ�" << endl;
}
void find_item()
{
	char data[100];
	cout << "�˻���ǰ �Է� : ";
	cin >> data;

	List *f = find_list(data);

	if (f != NULL)
	{
		cout << "============================================" << endl;
		cout << "��ǰ��\t�ܰ�\t����\t�ݾ�" << endl;
		cout << "--------------------------------------------" << endl;
		cout << f->name << "\t" << f->price << "\t" << f->count << "\t" << (f->price)*(f->count) << endl;
		cout << "============================================" << endl;
	}
	else
	{
		cout << "ã�� �����Ͱ� �����ϴ�." << endl;
	}
}
void delete_item()
{
	char data[100];
	cout << "������ǰ �Է�  : ";
	cin >> data;

	List *f = find_list(data);

	if (f != NULL)
	{
		for (List *t=f; t->next!=tail; t=t->next)
		{
			delete t->name;

			t->name = strdup(t->next->name);
			t->price = t->next->price;
			t->count = t->next->count;

			if (t->next->next == tail)
			{
				t->next = tail;
				delete t->next;
			}
		}
	}
	else
	{
		cout << "ã�� �����Ͱ� �����ϴ�." << endl;
	}
}
void sort_item()
{
	int num1, num2;

	cout << "���Ĺ���� �����Ͻÿ�" << endl;
	cout << "(��ǰ��=0, �ݾ�=1, �Ǹŷ�=2, �Ǹűݾ�=3) :";
	cin >> num1;

	cout << endl << "���Ĺ���� �����Ͻÿ�" << endl;
	cout << "(��������=0, ��������=1) :";
	cin >> num2;

	sort();
}

void sort()
{
	List *p, *h;
	int min;

	for (p=head->next; p->next!=tail; p=p->next)
	{
		min = p->price;

		for (List *t=p->next; t!=tail; t=t->next)
		{
			if (t->price < min)
			{
				min = t->price;
				h = t;
			}
		}

		swap(p->name,h->name);
		swap(p->price,h->price);
		swap(p->count,h->count);
	}
}

void main()
{	
	init_list();

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

	int num = 0;
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
		case 5 : continue; break;
		case 6 : sort_item(); break;
		case 7 : break;
		}

		system("pause");
		system("cls");
	}
}