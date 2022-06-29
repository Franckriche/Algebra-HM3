#pragma once
#include <iostream>

using namespace std;

class board
{
private:
	int x, y;
	static const int ROWS = 20;
	static const int COLS = 40;
	char _board[50][100] = {'-'};
public:
	board();
	void set_pointA(int x, int y);
	void set_pointB(int x, int y);
	void set_pointX(int x, int y);
	void reset_pointX();
	int getX();
	int getY();
	void draw();
};

