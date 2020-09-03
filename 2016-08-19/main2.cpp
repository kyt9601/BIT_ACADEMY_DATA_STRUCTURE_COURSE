#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

typedef struct pnt{
	int x;
	int y;
} pointer;

#define col GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute( col,0x000c ) //»¡°£»ö
#define BLUE SetConsoleTextAttribute( col,0x0001 | 0x0008) //ÆÄ¶õ»ö
#define HIGH SetConsoleTextAttribute( col,0x00a) // ¿¬µÎ
#define WHITE SetConsoleTextAttribute( col,0x000f) // Èò»ö
#define SKY SetConsoleTextAttribute( col, 0x000b) //ÇÏ´Ã»ö
#define YELLOW SetConsoleTextAttribute( col, 0x000e) //³ë¶õ»ö
#define HIG SetConsoleTextAttribute( col, 0x000d) //Çü±¤
#define VIO SetConsoleTextAttribute( col,0x0001 | 0x0008 |0x000c) //º¸¶ó

#define ROW_SIZE 10
#define COL_SIZE 19

int sadari[ROW_SIZE][COL_SIZE] =
{
	{1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1},
};

void removeCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
	curInfo.bVisible=0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
}

pointer getCursor(void)
{
	pointer curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
	curPoint.x=curInfo.dwCursorPosition.X;
	curPoint.y=curInfo.dwCursorPosition.Y;

	return curPoint;
}
void setCursor(int x, int y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int main()
{
	bool a[10];
	bool b[19];

	for (int i=0; i<10; i++)
		{ a[i] = false; }

	for (int i=0; i<19; i++)
		{ b[i] = false; }

	RED;

	for (int i=0; i<10; i++)
	{
		for (int j=0; j<19; j++)
		{
			if (sadari[i][j] == 1)
			{
				if (b[j] != true)
				{
					BLUE;
					b[j] = true;
				}
				else
				{
					RED;
				}
				printf("¡á");
			}
			else
			{
				printf("  ");
			}
		}
		puts("");
	}
	puts("");

	WHITE;
	return 0;
}