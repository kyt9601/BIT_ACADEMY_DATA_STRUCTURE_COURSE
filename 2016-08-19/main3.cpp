/*#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX 6

void mix(char (* arr)[7]) 
{ 
 int cnt = 0, r1, r2; 
 char temp[7];
 while(cnt < 5000)
 { 
  r1 = rand() % 5000; 
  r2 = rand() % 5000;
  strcpy(temp, arr[r1]); 
  strcpy(arr[r1], arr[r2]); 
  strcpy(arr[r2], temp);
  cnt++; 
 } 
} 
void create_arr(char (*arr)[7]) 
{ 
 int i, j; 
 int c1, c2;
 srand(time(NULL)); 
 puts("만들기 시작");
 for(i = 0; i < MAX; i++) 
 { 
  for(j = 0; j <= 2; j++){ 
   c1 = rand() % 25 - 80; 
   c2 = rand() % 94 - 95;
   arr[i][2 * j] = c1; 
   arr[i][2 * j + 1] = c2; 
  }
  arr[i][6] = '\0'; 
 } 
 puts("만들기 종료");
 mix(arr); 
 puts("섞기 종료");
}

int main()
{
	return 0;
}*/