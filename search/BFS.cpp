#include <iostream>
using namespace std;
const int MAX_VERTICES = 100; // Maximum number of vertices in the graph

class Graph
{
private:
    int V;
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES];

public:
    Graph(int V) : V(V)
    {
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adjMatrix[i][j] = false;
    }

    void addEdge(int v, int w)
    {
        adjMatrix[v][w] = true;
        adjMatrix[w][v] = true;
    }

    void BFS(int source)
    {
        bool visited[MAX_VERTICES] = {false};
        int queue[MAX_VERTICES], front = 0, rear = 0;

        visited[source] = true;
        queue[rear++] = source;

        while (front < rear)
        {
            int currentVertex = queue[front++];
            cout << currentVertex << " ";

            for (int neighbor = 0; neighbor < V; neighbor++)
            {
                if (adjMatrix[currentVertex][neighbor] && !visited[neighbor])
                {
                    visited[neighbor] = true;
                    queue[rear++] = neighbor;
                }
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.BFS(0);

    return 0;
}
