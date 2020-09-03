#include <iostream>

using namespace std;

struct Tree
{
	int key;
	struct Tree *left, *right;
};

Tree *head, *tail;
int cnt_tree;

void init_tree()
{
	head = (Tree*)malloc(sizeof(Tree));
	tail = (Tree*)malloc(sizeof(Tree));

	head->left = tail;
	head->right = tail;
	tail->left = NULL;
	tail->right = NULL;
}
void pre_order(Tree *p)	// 전위 순회 - (루트)->왼쪽->오른쪽
{
	if (p != NULL)
	{
		cout << p->key << " ";
		pre_order(p->left);
		pre_order(p->right);
	}
}
void in_order(Tree *p)	// 중위 순회 - 왼쪽->(루트)->오른쪽
{
	if (p != NULL)
	{
		in_order(p->left);
		cout << p->key << " ";
		in_order(p->right);
	}
}
void post_order(Tree *p)	// 후위 순회 - 왼쪽->오른쪽->(루트)
{
	if (p != NULL)
	{
		post_order(p->left);
		post_order(p->right);
		cout << p->key << " ";
	}
}
void create_data(Tree *p, int key)
{
	p->key = key;
	p->left = NULL;
	p->right = NULL;
}
void set_left_subtree(Tree *p, Tree *c)
{
	p->left = c;
}
void set_right_subtree(Tree *p, Tree *c)
{
	p->right = c;
}
int count_tree(Tree *p)
{
	static int cnt_tree = 0;

	if (p != NULL)
	{
		cnt_tree++;

		count_tree(p->left);
		count_tree(p->right);
	}

	return cnt_tree;
}
int get_depth(Tree *p, int depth)
{
	if (p != NULL)
	{
		if (p->left != NULL)

		if (p->right != NULL)
	}
}

int main()
{
	init_tree();

	Tree a,b,c,d,e;

	create_data(&a,1);
	create_data(&b,2);
	create_data(&c,3);
	create_data(&d,4);
	create_data(&e,5);

	set_left_subtree(&a,&b);
	set_right_subtree(&a,&c);
	set_left_subtree(&b,&d);
	set_left_subtree(&c,&e);

	pre_order(&a);	cout << endl;
	in_order(&a);	cout << endl;
	post_order(&a);	cout << endl;

	cout << count_tree(&a) << endl;
	cout << depth_tree(&a,0) << endl;

	return 0;
}