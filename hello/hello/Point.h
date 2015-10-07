#include <iostream>
#include <Windows.h>

using namespace std;

class Point
{
public:
	Point(){}
	Point(int, int, char);
	~Point(){};

	void Draw();
	int x, y;
	char symb;
};