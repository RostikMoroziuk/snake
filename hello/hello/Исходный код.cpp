#include "Point.h"
#include <conio.h>

using namespace std;

int main(void)
{
	system("mode con lines=25 cols=80"); //- size of console window without scroll

	char key;

	bool flag;

	walls rect(24,78);

	Point p(5, 5, '*');
	snake snake(p, 20, direct::right);
	snake.Draw();

	Food tempFood(25, 80, '$');
	Point food = tempFood.createFood();
	food.Draw();

	while (true)
	{
		if (_kbhit()) // for press key event
		{
			key = _getch();
			snake.Control(key);
		}

		if (rect.isHit(snake.head()) || snake.isHitTail())
		{
			break;
		}

		if (snake.Eat(food))
		{
			food = tempFood.createFood();
			food.Draw();
		}
		
		Sleep(100);
		snake.Move();
	}

	system("pause>>void");

}


