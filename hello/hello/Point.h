#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>
#include <time.h>
#include <conio.h>

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
	void X(int);
	void Y(int);
	int X()const;
	int Y()const;
	void Symb(char);
	int Symb()const;
	bool isHit(Point);
private:
	int x, y;
	char symb;
};

class Figure
{
protected:
	vector<Point> vec;
public:
	virtual void Draw();
	bool isHit(Point);
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

class Food
{
public:
	Food(int, int, char);
	~Food(){}
	Point createFood();
private:
	int lengthofMap, heightofMap;
	char symb;
};

class snake : public Figure
{
public:
	snake(Point, int, direct);
	~snake(){}
	void Move();
	Point newHead();
	void Control(char);
	bool Eat(Point);
	Point head();
	bool isHitTail();
	void newSnake(Point);
private:
	direct rout;
};

class walls:public Figure
{
	vector<Figure> vec;
public:
	walls(int height, int length);
	~walls(){}
	void Draw();
	bool isHit(Point);
	void newWalls();
};


