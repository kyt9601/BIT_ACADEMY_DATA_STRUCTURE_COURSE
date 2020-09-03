/*#include <iostream>

using namespace std;

void main1()
{
//	if ( (a&64) != 0 ) {}	64는 2의 6승, 6번째 비트가 0인지

	int a = 0xa5;

	if (a&(1<<6)) { puts("true"); }
	else puts("false");

	// a = a | 0xa;
	a |= ((1<<3)+(1<<1));
	printf("%x\n",a);

	// a = a & ~(0x6);
	a &= ~((a<<1)+(1<<1));
	printf("%x\n",a);

	// a = a & 0xe0;
	a &= 0xe0;
	printf("%x\n",a);
}

void main2()
{
	int num;
	cout << "정수 : ";
	cin >> num;

	cout << (((num+3)/4))*4 << endl;

	num += 3;
	num &= ~3;

	cout << num << endl;
}

union con
{
	unsigned i;

	struct bit4
	{
		unsigned a : 8;
		unsigned b : 8;
		unsigned c : 8;
		unsigned d : 8;
	};
};

void main3()
{
	union con p;

	p.i = 0x12345678;

	printf("%x\n",&p);
	printf("%x\n",p.bit4.a);
	printf("%x\n",p.bit4.b);
	printf("%x\n",p.bit4.c);
	printf("%x\n",p.bit4.d);
}

void main4()
{
	short int x = 0x1122;

	printf("%x\n",x);

	x = ((x&0xff) << 8) | ((x<<8) & 0xff);

	printf("%x\n",x);
}

void main()
{
	int num;
	cout << "십진수 입력 : ";
	cin >> num;

	int n, w;
	cout << "n수 입력 : ";
	cin >> n;
	cout << "w수 입력 : ";
	cin >> w;
}*/