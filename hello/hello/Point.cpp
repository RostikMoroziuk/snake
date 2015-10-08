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

HorisontalLine::HorisontalLine(int xLeft,int xRight, int y, char s)
{
	for (int x = xLeft; x <= xRight; x++)
	{
		Point p(x, y, s);
		vec.push_back(p);
	}
}

void Figure::Draw()
{
	for (auto i : vec)
		i.Draw();
}

VerticalLine::VerticalLine(int yLeft, int yRight, int x, char s)
{
	for (int y = yLeft; y <= yRight; y++)
	{
		Point p(x, y, s);
		vec.push_back(p);
	}
}

snake::snake(Point tail, int length, direct direction)
{
	rout = direction;
	for (int i = 0; i < length; i++)
	{
		Point p = tail;
		p.Move(i, direction);
		vec.push_back(p);
	}
}

void Point::Move(int i, direct direction)
{
	switch (direction)
	{
	case direct::left:
		x -= i;
		break;
	case direct::up:
		y -=  i;
		break;
	case direct::right:
		x += i;
		break;
	case direct::down:
		y += i;
		break;
	}
}

void snake::Move()
{
	Point tail = vec.front() ;
	vec.erase(vec.begin());
	Point head = newHead();
	vec.push_back(head);
	tail.Clear();
	head.Draw();
}

Point snake::newHead()
{
	Point head = vec.back();
	head.Move(1, rout);
	return head;
}

void Point::Clear()
{
	symb = ' ';
	Draw();
}

void snake::Control(char key)
{
	switch (key)
	{
	case 'a':
		rout = direct::left;
		break;
	case 'w':
		rout = direct::up;
		break;
	case 'd':
		rout = direct::right;
		break;
	case 's':
		rout = direct::down;
		break;
	}
}