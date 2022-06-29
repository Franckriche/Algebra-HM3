#include <iostream>
#include "dijkstra.h"


using namespace std;

int wall_position[] = { 20, 60, 100, 140, 180, 220 };

void draw(Adjacency_list& adj_list, int pos_X, int pos_A, int pos_B)
{
	for (size_t i = 0; i < 20; i++)
	{

		for (size_t j = 0; j < 40; j++)
		{
			bool is_wall = false;
			for (size_t k = 0; k < 6; k++)
			{
				is_wall = (i * 40 + j == wall_position[k] || is_wall);
			}

			if (i * 40 + j == pos_X)
			{
				cout << "x";
			}
			
			else if (i * 40 + j == pos_B)
			{
				cout << "B";
			}
			else if (i * 40 + j == pos_A)
			{
				cout << "A";
			}
			else if (is_wall)
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}
}

int main()
{
	dijkstra board;

	Adjacency_list list = board.init(20, 40);

	int xa, ya, xb, yb;
	int A, B;

	cout << "Point A: ";
	cin >> xa;
	cout << "Point A: ";
	cin >> ya;
	A = xa * 40 + ya;

	cout << "Point B: ";
	cin >> xb;
	cout << "Point B: ";
	cin >> yb;
	B = xb * 40 + yb;

	vector<Weight> min_dist;
	vector<Vertex> previous;
	board.computepaths(A, list, min_dist, previous);
	
	std::list<Vertex> path = board.getshortestpath(B, previous);

	do
	{
		system("CLS");
		draw(list, path.front(), A, B);
		path.pop_front();
	} while (!path.empty());

	return 0;
}