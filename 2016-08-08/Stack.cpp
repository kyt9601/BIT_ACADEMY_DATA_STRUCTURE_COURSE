#include <iostream>

#include <stdarg.h>

using namespace std;

#define STACK_SIZE 5

int stack[STACK_SIZE];
int top;

void init_stack()
{
	top = -1;
}
void push(int data)
{
	if (top < STACK_SIZE-1) { stack[++top] = data; }
	else { puts("Stack OverFlow"); }
}
void pop()
{
	if (-1 < top) { top--; }
	else { puts("Stack UnderFlow"); }
}

float average(int num, ...)
{
	va_list arg_ptr;
	int cnt, total = 0;

	va_start(arg_ptr,num);

	for (cnt = 0; cnt<num; cnt++)
	{
		total += va_arg(arg_ptr,int);
	}

	va_end(arg_ptr);

	return ((float) total/num);
}

void main()
{
	init_stack();

	push(3);
	push(4);
	push(1);
	push(5);
	push(2);
	push(7);

	pop();
	pop();
	pop();
	pop();
	pop();
	pop();

	float x;

	x = average(10,1,2,3,4,5,6,7,8,9,10);
	cout << x << endl;

	x = average(5,2,2,2,2,2);
	cout << x << endl;
}
