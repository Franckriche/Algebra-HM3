#include <iostream>
#include "board.h"

using namespace std;

int main()
{
	board b;
	int xa, ya;
	int xb, yb;
	
	cout << "Point A: ";
	cin >> xa;
	cout << "Point A: ";
	cin >> ya;

	cout << "Point B: ";
	cin >> xb;
	cout << "Point B: ";
	cin >> yb;

	b.set_pointB(xb, yb);

	b.set_pointX(xa, ya);

	do
	{
		int x = b.getX();
		int y = b.getY();
		b.reset_pointX();
		b.set_pointA(xa, ya);
		system("CLS");
		if (yb - y != 0)
		{
			if (yb - y < 0)
			{
				 y -= 1;
			}
			else
			{
				 y += 1;
			}
		}
		else
		{
			if (xb - x < 0)
			{
				 x -= 1;
			}
			else
			{
				 x += 1;
			}
		}
		b.set_pointX(x, y);
		b.draw();
	} while (b.getX() != xb || b.getY() != yb);

	return 0;
}