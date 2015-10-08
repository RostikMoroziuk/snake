#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

enum direct{ left, up, right, down };

class Point
{
public:
	Point(){}
	Point(int, int, char);
	~Point(){};
	void Move(int, direct);
	void Draw();
	void Clear();
private:
	int x, y;
	char symb;
};

class Figure
{
protected:
	vector<Point> vec;
public:
	void Draw();
};

class HorisontalLine:public Figure
{
public:
	HorisontalLine(){}
	HorisontalLine(int, int, int, char);
	~HorisontalLine(){}
};

class VerticalLine:public Figure
{
public:
	VerticalLine(){}
	VerticalLine(int, int, int, char);
	~VerticalLine(){}
};

class snake : public Figure
{
public:
	snake(Point, int, direct);
	~snake(){}
	void Move();
	Point newHead();
	void Control(char);
private:
	direct rout;
};
