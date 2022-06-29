#include "board.h"



board::board()
{
	
	for (size_t i = 0; i < 50; i++)
	{
	
		for (size_t j = 0; j < 100; j++)
		{
			_board[i][j] = '-';
		}
	}
	
}

void board::set_pointA(int x, int y)
{
	_board[x][y] = 'A';
}

void board::set_pointB(int x, int y)
{
	_board[x][y] = 'B';
}

void board::set_pointX(int x, int y)
{
	this->x = x;
	this->y = y;
}

void board::reset_pointX()
{
	_board[x][y] = '-';
}

int board::getX()
{
	return x;
}

int board::getY()
{
	return y;
}


void board::draw()
{
	for (size_t i = 1; i < ROWS+1; i++)
	{

		for (size_t j = 1; j < COLS+1; j++)
		{
			if (i == x && j == y)
			{
				_board[i][j] = 'x';
			}
				cout << _board[i][j];
			
		}
		cout << endl;
	}
}
