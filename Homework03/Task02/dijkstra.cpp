#include "dijkstra.h"

const Weight max_weight = numeric_limits<double>::infinity();

void dijkstra::computepaths(Vertex source, const Adjacency_list& adjacency_list, vector<Weight>& min_dist, vector<Vertex>& previous)
{
    int i = adjacency_list.size();
    min_dist.clear();
    min_dist.resize(i, max_weight);
    min_dist[source] = 0;
    previous.clear();
    previous.resize(i, -1);
    set <pair<Weight, Vertex>> vertex_queue;
    vertex_queue.insert(make_pair(min_dist[source], source));

    while (!vertex_queue.empty())
    {
        Weight dist = vertex_queue.begin()->first;
        Vertex k = vertex_queue.begin()->second;

        vertex_queue.erase(vertex_queue.begin());

        const vector<neighbor>& neighbors = adjacency_list[k];

        for (vector<neighbor>::const_iterator it = neighbors.begin(); it != neighbors.end(); ++it)
        {
            Vertex v = it->target;
            Weight w = it->weight;
            Weight dist_to_k = dist + w;
            if (dist_to_k < min_dist[v])
            {
                vertex_queue.erase(make_pair(min_dist[v], v));

                min_dist[v] = dist_to_k;
                previous[v] = k;
                vertex_queue.insert(make_pair(min_dist[v], v));
            }
        }
    }
}

list<Vertex> dijkstra::getshortestpath(Vertex vertex, const vector<Vertex>& previous)
{
    list<Vertex> path;

    while (vertex != -1)
    {
        path.push_front(vertex);
        vertex = previous[vertex];
    }
    return path;
}

int row[] = { -1, 0, 0, 1 };
int cols[] = { 0, -1, 1, 0 };

int wall[] = { 20, 60, 100, 140, 180, 220 };

Adjacency_list dijkstra::init(int ROWS, int COLS)
{
    Adjacency_list adj_list(ROWS * COLS);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {

            for (int k = 0; k < 4; k++)
            {
                if ((i + row[k] >= 0 && i + row[k] < ROWS) && (j + cols[k] >= 0 && j + cols[k] < COLS))
                {
                    bool is_wall = false;
                    for (int l = 0; l < 6; l++)
                    {
                        is_wall = ((i + row[k]) * COLS + (j + cols[k]) == wall[l] || is_wall);
                    }
                    if (!is_wall)
                    {
                        adj_list[i * COLS + j].push_back(neighbor((i + row[k]) * COLS + (j + cols[k]), 1));
                    }
                }
            }
        }
    }
    return adj_list;
}
