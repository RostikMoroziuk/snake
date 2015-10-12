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

void Point::Move(int i, direct direction)
{
	switch (direction)
	{
	case direct::left:
		x -= i;
		break;
	case direct::up:
		y -= i;
		break;
	case direct::right:
		x += i;
		break;
	case direct::down:
		y += i;
		break;
	}
}

void Point::Clear()
{
	symb = ' ';
	Draw();
}

void Point::X(int xx)
{
	 x = xx;
}

void Point::Y(int yy)
{
	 y = yy;
}

int Point::X()const
{
	return x;
}

int Point::Symb()const
{
	return symb;
}

void Point::Symb(char sym)
{
	symb = sym;
}

bool Point::isHit(Point point)
{
	if (x == point.x && y == point.y)
		return true;
	else
		return false;
}

HorisontalLine::HorisontalLine(int xLeft,int xRight, int y, char s)
{
	for (int x = xLeft; x <= xRight; x++)
	{
		Point p(x, y, s);
		vec.push_back(p);
	}
}

VerticalLine::VerticalLine(int yLeft, int yRight, int x, char s)
{
	for (int y = yLeft; y <= yRight; y++)
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

bool Figure::isHit(Point p)
{
	for (Point i : vec)
	{
		if (i.isHit(p))
			return true;
	}
	return false;
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
		
	case 75:
		rout = direct::left;
		break;
	case 72:
		rout = direct::up;
		break;
	case 77:
		rout = direct::right;
		break;
	case 80:
		rout = direct::down;
		break;
	}
}

bool snake::Eat(Point food)
{
	Point head = this->head();
	if (head.isHit(food))
	{
		food.Symb(head.Symb());
		vec.push_back(food);
		return true;
	}
	else
		return false;
}

Point snake::head()
{
	return vec.back();
}

bool snake::isHitTail()
{
	Point head = vec.back();
	for (int i = 0; i < vec.size() - 2; i++)
	{
		if (head.isHit(vec[i]))
			return true;
	}
	return false;
}

void snake::newSnake(Point point)
{
	for (int i = 0; i < vec.size() - 1; i++)
	{
		vec[i].Symb(' ');
		vec[i].Draw();
	}
	vec.clear();
	for (int i = 0; i < 3; i++)
	{
		Point p = point;
		p.Move(i, direct::right);
		vec.push_back(p);
	}
	Draw();
}

Food::Food(int _height, int _length, char _symb)
{
	heightofMap = (_height - 2);
	lengthofMap = (_length - 2);
	symb = _symb;
}

Point Food::createFood()
{
	srand(time(NULL));
	Point point;
	point.X((rand() % lengthofMap)+1);
	point.Y((rand() % heightofMap)+1);
	return point;
}

walls::walls(int height, int length)
{
	HorisontalLine upLine(0, length, 0, '+');
	HorisontalLine downLine(0, length, height, '+');

	VerticalLine leftLine(0, height, 0, '+');
	VerticalLine rightLine(0, height, length, '+');

	vec.push_back(upLine);
	vec.push_back(downLine);
	vec.push_back(leftLine);
	vec.push_back(rightLine);

	Draw();
}

void walls::Draw()
{
	for (auto i : vec)
	{
		i.Draw();
	}
}

bool walls::isHit(Point p)
{
	for (Figure i : vec)
	{
		if (i.isHit(p))
			return true;
	}
	return false;
}

void walls::newWalls()
{
	HorisontalLine upLine(0, 78, 0, '+');
	HorisontalLine downLine(0, 78, 24, '+');

	VerticalLine leftLine(0, 24, 0, '+');
	VerticalLine rightLine(0, 24, 78, '+');

	vec.push_back(upLine);
	vec.push_back(downLine);
	vec.push_back(leftLine);
	vec.push_back(rightLine);

	Draw();
}
