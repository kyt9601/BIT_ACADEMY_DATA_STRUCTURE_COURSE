#include <stdio.h>
#include <malloc.h>

struct engine
{
	int piston;
	int fan;
	int pipe;
};
struct car
{
	struct engine *sedan, *sports;
	// 초기화 안됨
};

void hyundai(struct car *man)
{
	struct engine *p;

//	p = man->sedan;
//	먼저 하면, 에러 발생
	man->sedan = (engine*)malloc(sizeof(engine));

	p = man->sedan;

	p->piston = 50;
	p->fan = 30;
	p->pipe = 20;
}
void main()
{
	struct car hi;

//	hi.sedan = (engine*)malloc(sizeof(engine));
	hyundai(&hi);

	printf("%d\n",hi.sedan->piston);
	printf("%d\n",hi.sedan->fan);
	printf("%d\n",hi.sedan->pipe);
}