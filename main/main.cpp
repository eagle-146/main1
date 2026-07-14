#include<stdio.h>

#include<windows.h>
#include <conio.h>
void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void setcolor(int text_color, int bg_color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_color + (bg_color << 4));
}

char block[4][4] = {
	{0,0,0,0},
	{0,1,0,0},
	{0,1,1,1},
	{0,0,0,0}
};

char background[12][12] = {
	{1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1},
};


int x = 0;
int y = 0;
int count = 0;


void make_background()
{
	for (int j = 0; j < 12; j++)
	{
		for (int i = 0; i < 12; i++)
		{
			if (background[j][i] == 1)
			{
				gotoxy(i, j);
				printf("*");
			}
			else
			{
				gotoxy(i, j);
				printf("-");
			}
		}
	}
}

void make_block(int xx, int yy)
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (block[j][i] == 1)
			{
				gotoxy(i + xx, j + yy);
				printf("*");
			}
			//else
			//{
			//	gotoxy(i + xx, j + yy);
			//	printf("-");
			//}
		}
	}
}

void delete_block(int xx, int yy)
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (block[j][i] == 1)
			{
				gotoxy(i + xx, j + yy);
				printf("-");
			}
			//else
			//{
			//	gotoxy(i + xx, j + yy);
			//	printf(" ");
			//}
		}
	}
}


void main()
{
	make_background();
	make_block(x, y);

	while (1)
	{
		//-------------------
		if (count == 100)
		{
			count = 0;

			delete_block(x, y);
			y++;
			make_block(x, y);
		}
		//-------------------
		if (_kbhit())
		{
			char key = _getch();
			if (key == 'w')  // w : up key
			{
				delete_block(x, y);
				y--;
				make_block(x, y);
			}
			else if (key == 's')  // s : down key
			{
				delete_block(x, y);
				y++;
				make_block(x, y);
			}
			else if (key == 'a')  // a : left key
			{
				delete_block(x, y);
				x--;
				make_block(x, y);
			}
			else if (key == 'd')  // d : right key
			{
				delete_block(x, y);
				x++;
				make_block(x, y);
			}
		}
		//-------------------
		count++;
		Sleep(10);
		//-------------------
	}






}



