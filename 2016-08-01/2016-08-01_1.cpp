#include <iostream>

using namespace std;
// #define swap(x,y) do{int t; t=x; x=y; y=t;}while(0)

int Alarusse(int n1, int n2)
{
	int temp = 0;

	do
	{
		// if(n1%2 != 0) { temp += n2; }
		if (n1&0x1 != 0) { temp += n2; }		// 비트 연산, 0x1 은 마지막이 1
		// n1 /= 2;
		n1 >>= 1;	// 비트 연산, 오른쪽으로 한 칸 당긴다
		// n2 *= 2;
		n2 <<= 1;	// 비트 연산, 왼쪽으로 한 칸 민다
	}
	// while (0 < n1);
	while (n1);
 
	return temp;
}
int Uclide(int n1, int n2)
{
	do
	{
		if (n1 < n2) { swap(n1,n2); }
		n1 -= n2;
	}
	// while (n1 != 0);
	while (n1);

	return n2;
}
int UclideImp(int n1, int n2)
{
	// while(n2 != 0)
	while(n2)
	{
		n1 %= n2;
		swap(n1,n2);
	}

	return n1;
}
int ReSum(int num)	// 재귀 함수 : 자신 안에서 자신을 호출하는 함수
{
	if (num == 1) { return num; }	// 꼭 경계 조건이 있어야 한다
	else { return num + ReSum(num-1); }
}
int ReExp(int base, int n)
{
	if (n == 1) { return base; }
	else { ReExp(base*base,--n); }
}
void RePrintc(char c)
{
	cout << c;

	if (c!='Z' && c!='z') { RePrintc(++c); }
}
void ReFibonacci(int num, int sum)
{
	int temp = sum;

	sum += num;

	if (sum < 100)
	{
		cout << sum << endl;
		ReFibonacci(temp,sum);
	}
}
void Bprint()
{
	char c = getchar();

	// 자신을 호출하는 것을 기점으로
	// 위에가 몰아서 한번에 실행되고
	cout << endl << c << " : "<< "before_putchar(c);" << endl;
	if (c != '\n') { Bprint(); }

	// 아래가 몰아서 한번에 실행된다
	cout << endl << c << " : "<< "after_putchar(c);" << endl;
	putchar(c);
}
int Leaf(int num)	// Leaf Function
{
	//...
	return Leaf(num);
	// return 으로 재귀 함수를 호출하면,
	// 여러번 return 되지 않고 한번에 반환된다
}
int ReUclide(int n1, int n2)
{
	return 0;
}

void main()
{
	cout << Alarusse(27,65) << endl;
	cout << Uclide(220,30) << endl;
	cout << UclideImp(220,30) << endl;
	cout << ReSum(10) << endl;
	cout << ReExp(2,10) << endl;
	RePrintc('b');
	cout << endl;
	RePrintc('G');
	cout << endl;
	ReFibonacci(1,0);
	cout << endl;
	Bprint();
	cout << endl;
//	cout << ReUclide(220,30) << endl;
}