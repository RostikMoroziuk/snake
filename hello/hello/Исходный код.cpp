#include "Point.h"
#include <conio.h>

using namespace std;

int main(void)
{
	system("mode con lines=25 cols=80"); //- size of console window without scroll

	HorisontalLine upLine(0,78,0,'+');
	HorisontalLine downLine(0, 78, 24, '+');

	VerticalLine leftLine(0, 24, 0, '+');
	VerticalLine rightLine(0,24,78,'+');

	upLine.Draw();
	downLine.Draw();
	leftLine.Draw();
	rightLine.Draw();

	Point p(5, 5, '*');
	snake snake(p, 3, direct::down);
	snake.Draw();
	
	char key;

	while (true)
	{
		key = _getch();
		snake.Control(key);
		Sleep(100);
		snake.Move();
	}




	system("pause>>void");

}


