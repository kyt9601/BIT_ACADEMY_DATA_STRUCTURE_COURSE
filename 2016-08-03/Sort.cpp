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
	// �ʱ�ȭ �ȵ�
};

void hyundai(struct car *man)
{
	struct engine *p;

//	p = man->sedan;
//	���� �ϸ�, ���� �߻�
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