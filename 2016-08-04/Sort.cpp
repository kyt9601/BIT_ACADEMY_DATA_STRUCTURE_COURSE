/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void sort(int src[], int Length) 
{ 
    int i = 0; 
    int j = 0; 
    int value = 0; 
 
    for (i=1; i<Length; i++) 
    { 
		if (src[i-1] <= src[i]) { continue; }
 
		value = src[i];		// pv ���� ���� ��

		for (j=0; j<i; j++)  
		{             
			if (src[j] > value)
			{ 
				memmove(&src[j+1],&src[j],sizeof((src[0])*(i-j)));	// memmove(������ ��ġ, �������� �ּ�, ũ��)
				src[j] = value; 
				break;     
			} 
		} 
    } 
} 
 
int main() 
{ 
    int src[] = {6, 4, 2, 3, 1, 5}; 
    int Length = sizeof(src) / sizeof(src[0]);
 
    sort(src,Length); 
 
    for (int i=0; i<Length; i++) { printf("%d\n",src[i]); } 
 
    return 0; 
}

void printInt(int *arr, int size);
void printDbl(double *arr, int size);
void printstr(char (*arr)[7], int size);

int comp_i(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);	// int* �� ĳ�����ؼ� 4byte �� ����
}

//���̺귯�� �����ϴ� qsort�� ���� comp_d �Լ� �ϼ�
int comp_d(const void* a, const void* b) {
	if (*(double*)a > *(double*)b) { return 1; }
	else if (*(double*)a - *(double*)b) { return -1; }
	else { return 0; }	// double* �� ĳ�����ؼ� 8byte �� ����    
}

//���̺귯�� �����ϴ� qsort�� ���� comp_s �Լ� �ϼ�
int comp_s(const void* a, const void* b) {
    return strcmp((char*)a,(char*)b);	// double* �� ĳ�����ؼ� 8byte �� ����    
}

int main(void) {
	
	int num;
	const int * p1 = &num;	// ���� �� �ٲ۴�
	int * const p2 = &num;	// �ּҸ� �� �ٲ۴�

// * �� �������� const �� �ǹ̰� �ٸ���

    int arri[]= { 3,4,1,5,2,8,9,6,10,7 };
    double arrd[] = { 3.2, 5.6, 4.3, 8.7, 2.3, 4.5, 2.1, 2.3, 4.6, 4.5};
 char arrs[][7]={"����","�����","��ν�","������","��ο�",
    "����","������","������","������","������",
    "ȫ����","���Ͽ�","������","������","������",
    "������","����ȣ","������","������","��ȣ��",
    "�ӹ̰�","��Ҹ�","�����","������","������",
    "��Ȳ��","�ִٿ�","������","���ؼ�"};
    qsort(arri, sizeof(arri)/sizeof(arri[0]), sizeof(int), comp_i);
    printInt(arri, sizeof(arri)/sizeof(arri[0]));

    qsort(arrd, sizeof(arrd)/sizeof(arrd[0]), sizeof(double), comp_d);
    printDbl(arrd, sizeof(arrd)/sizeof(arrd[0]));

 //���̺귯�� qsort�� �̿��Ͽ� 2�����迭�� �ִ� ���ڿ��� �����սô�.

    qsort(arrs, sizeof(arrs)/sizeof(arrs[0]), sizeof(arrs[0]), comp_s);
    printstr(arrs, sizeof(arrs)/sizeof(arrs[0]));

    return 0;
}
void printInt(int *arr, int size) {
    int dx=0;
    for (dx=0; dx< size; ++dx) {
        printf("%d ", arr[dx]);
    }
    printf("\n");
}

void printDbl(double *arr, int size) {
    int dx=0;
    for (dx=0; dx< size; ++dx) {
        printf("%.1f  ", arr[dx]);
    }
    printf("\n");
}

void printstr(char (*arr)[7], int size) {
    int dx=0;
    for (dx=0; dx< size; ++dx) {
        printf("%s ", arr[dx]);
    }
    printf("\n");
}*/