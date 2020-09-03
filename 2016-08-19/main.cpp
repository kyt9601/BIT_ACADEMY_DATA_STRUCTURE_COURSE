/*#include<stdio.h>
#include<Windows.h>
#include<conio.h>
typedef struct _point {
 SHORT x;
 SHORT y;
} point;

void removeCursor(void)
{
 CONSOLE_CURSOR_INFO curInfo;
 GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
 curInfo.bVisible=0;
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
}

point getCursor(void)
{
 point curPoint;
 CONSOLE_SCREEN_BUFFER_INFO curInfo;
 GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
 curPoint.x=curInfo.dwCursorPosition.X;
 curPoint.y=curInfo.dwCursorPosition.Y;
 return curPoint;
}

void setCursor(int x, int y)
{
 COORD pos={x, y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

#if 0
int main()
{
 int c=0;
 while(1)
 {
  //c= _getch();
  //printf("-%d-\n", c);
  if(_kbhit() != 0)//(c == 0xE0 || c ==0)
  { 
   c = _getch();
   printf("(%d)\n", c);
  }
  else
  {
   printf("%d\n", c);
  }
 }

}
#endif

#if 1
int main()
{
 point z;
 //RemoveCursor();
 setCursor(0,0);
 printf("бс");

 setCursor(2,0);
 printf("бс");
 setCursor(4,0);
 printf("бс");
 z=getCursor();
 printf("%d %d\n", z.x, z.y);
 setCursor(2,0);
 printf("бр");
 setCursor(2,1);
 
}
#endif
*/