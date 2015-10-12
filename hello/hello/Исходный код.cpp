#include "Point.h"

using namespace std;

int main(void)
{
	system("mode con lines=25 cols=100"); //- size of console window without scroll

	int key;

	walls rect(24,78);

	Point p(5, 5, '*');
	snake snake(p, 3, direct::right);
	snake.Draw();

	Food tempFood(25, 80, '$');
	Point food = tempFood.createFood();
	food.Draw();

	key = _getch();
	snake.Control(key);

	while (true)
	{
		if (_kbhit()) // for press key event
		{
			key = _getch();
			snake.Control(key);
		}

		if (rect.isHit(snake.head()) || snake.isHitTail())
		{
			system("pause>>void");
			rect.newWalls();
			snake.newSnake(p);
			key = _getch();
			snake.Control(key);
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


