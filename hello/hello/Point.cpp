#include "Point.h"

using namespace std;

void Point::Draw()
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << symb;
}

Point::Point(int _x, int _y, char _s)
{
	x = _x;
	y = _y;
	symb = _s;
}