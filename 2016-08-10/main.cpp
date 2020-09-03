/*#include <iostream>
#include <assert.h>

using namespace std;

int main1()
{
	int x;

	cout << "입력 : ";
	cin >> x;

#ifndef NDEBUG
	assert(x);
#endif

	cout << "입력값 : " << x << endl;

	return 0;
}

int main2()
{
	char **a;
	char *b[2];
	char c[2][3];
	char *d[2][3] = {"aa","bb","cc","dd","ee","ff"};
	char (*e)[2][3];
	char (*f[2])[3];

	char ***pa = &a;
	char **pb = b;
	char (*pc)[3] = c;
	char *(*dp)[3] = d;
	char (**pe)[2][3] = &e;
	char (**pf)[3] = f;

	return 0;
}

int main3()
{
	char *d[2][3];
	char **dd[2][3];
	char a[7][3], b[2][3];

	char *(*pd)[3] = d;
	char *(**ppd)[3] = &pd;
	char **(*pdd)[3] = dd;
	char **(**ppdd)[3] = &pdd;
	char (*pab[2])[3];

	pab[0] = a;
	pab[1] = b;

	return 0;
}

int main4()
{
	char ***p1 = (char***)malloc(sizeof(char**) * 1);
	*p1 = (char**)malloc(sizeof(char*)*6);

	**p1 = "aaa";		// *(p[0]+0);
	*(*p1+1) = "bbb";	// *(p[0]+1);
	*(*p1+2) = "ccc";	// *(p[0]+2);

	*(*p1+3) = "ddd";	// *(p[0]+3);

	char ***p2 = (char***)malloc(sizeof(char**) * 2);
	*p2 = (char**)malloc(sizeof(char*)*3);
	*(p2+1) = (char**)malloc(sizeof(char*)*3);

	**p2 = "aaa";		// *(p[0]+0);
	*(*p2+1) = "bbb";	// *(p[0]+1);
	*(*p2+2) = "ccc";	// *(p[0]+2);

	**(p2+1) = "ddd";	// *(p[1]+0);

	return 0;
}

typedef int i;		// i 를 int 로 보겠다
typedef int ai[3];	// ai 를 int array[3] 로 보겠다
typedef int *pi;	// pi 를 int *p 로 보겠다

typedef int (*f_t)(int,int);
typedef int fi(int,int);
typedef fi *pfi;
typedef pfi fpfi();

int add(int a, int b);
f_t return_fp1();
int (*return_fp2())(int,int);

int main5()
{
	i a;	// int a;
	ai b;	// int b[3];
	pi c;	// int *c;

//	int (*fp) (int,int) = add;	// 함수포인터 fp 에 add 의 주소를 전달
	f_t fp = add;

	f_t pt_add1 = return_fp1();
	f_t pt_add2 = return_fp2();

	return 0;
}
int add(int a, int b) { return a+b; }

//	int (*)(int,int) return_fp() { return add; }	// 리턴값이 함수의 주소 int (*)(int,int)
f_t return_fp1() { return add; }

int (*return_fp2())(int,int) { return add; }

fi add;
fpfi return_fp3;

int main()
{


	return 0;
}*/