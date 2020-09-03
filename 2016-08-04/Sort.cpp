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
 
		value = src[i];		// pv 보다 작은 것

		for (j=0; j<i; j++)  
		{             
			if (src[j] > value)
			{ 
				memmove(&src[j+1],&src[j],sizeof((src[0])*(i-j)));	// memmove(복사할 위치, 데이터의 주소, 크기)
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
    return (*(int*)a - *(int*)b);	// int* 로 캐스팅해서 4byte 씩 본다
}

//라이브러리 제공하는 qsort를 위한 comp_d 함수 완성
int comp_d(const void* a, const void* b) {
	if (*(double*)a > *(double*)b) { return 1; }
	else if (*(double*)a - *(double*)b) { return -1; }
	else { return 0; }	// double* 로 캐스팅해서 8byte 씩 본다    
}

//라이브러리 제공하는 qsort를 위한 comp_s 함수 완성
int comp_s(const void* a, const void* b) {
    return strcmp((char*)a,(char*)b);	// double* 로 캐스팅해서 8byte 씩 본다    
}

int main(void) {
	
	int num;
	const int * p1 = &num;	// 값을 못 바꾼다
	int * const p2 = &num;	// 주소를 못 바꾼다

// * 을 기준으로 const 의 의미가 다르다

    int arri[]= { 3,4,1,5,2,8,9,6,10,7 };
    double arrd[] = { 3.2, 5.6, 4.3, 8.7, 2.3, 4.5, 2.1, 2.3, 4.6, 4.5};
 char arrs[][7]={"정희석","조경빈","김민식","정윤기","김민우",
    "김상원","조성윤","김형섭","나승학","허진석",
    "홍종완","이하연","조유진","박종현","박종후",
    "신지윤","윤승호","윤정문","이현지","이호준",
    "임미경","김소림","김원명","김유미","김정원",
    "조황석","최다운","최진의","허준성"};
    qsort(arri, sizeof(arri)/sizeof(arri[0]), sizeof(int), comp_i);
    printInt(arri, sizeof(arri)/sizeof(arri[0]));

    qsort(arrd, sizeof(arrd)/sizeof(arrd[0]), sizeof(double), comp_d);
    printDbl(arrd, sizeof(arrd)/sizeof(arrd[0]));

 //라이브러리 qsort를 이용하여 2차원배열에 있는 문자열을 정렬합시다.

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