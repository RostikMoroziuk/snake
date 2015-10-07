#include "Point.h"

using namespace std;

int main(void)
{
	Point point1, point2;

	point1.x = 3;
	point1.y = 2;
	point1.symb = '*';
	point1.Draw();

	point2.x = 5;
	point2.y = 0;
	point2.symb = '#';
	point2.Draw();

	system("pause");
}


