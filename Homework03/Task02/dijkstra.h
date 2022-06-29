#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits>
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>


using namespace std;

typedef int Vertex;
typedef double Weight;

struct neighbor
{
	Vertex target;
	Weight weight;
	neighbor(Vertex arg_target, Weight arg_weight) : 
		target(arg_target), weight(arg_weight) {}
};

typedef vector<vector<neighbor>> Adjacency_list;

class dijkstra
{

public:
	void computepaths(Vertex source, const Adjacency_list& adjacency_list,
		vector<Weight>& min_dist, vector<Vertex>& previous);
	
	list<Vertex> getshortestpath(Vertex vertex, const vector<Vertex>& previous);

	Adjacency_list init(int ROWS, int COLS);
};

