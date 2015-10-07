#include "Point.h"

using namespace std;

int main(void)
{
	Point point1(3, 5, '#'), point2(5, 10, '*');

	point1.Draw();
	point2.Draw();

	system("pause");
}


