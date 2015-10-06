#include <iostream>
#include <Windows.h>

using namespace std;
void Draw(int x, int y, char symb);

int main(void)
{
	int x1 = 3;
	int y1 = 5;
	char symb1 = '*';

	Draw(x1, y1, symb1);

	int x2 = 10;
	int y2 = 15;
	char symb2 = '#';

	Draw(x2, y2, symb2);

	system("pause>>void");
}

void Draw(int x, int y, char symb)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << symb;
}

