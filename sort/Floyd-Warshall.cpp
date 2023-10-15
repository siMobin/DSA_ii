#include <iostream>
#include <vector>
#include <string>

using namespace std;

void floydWarshall(vector<vector<int>>& dist, vector<string>& vertexNames)
{
    int V = dist.size();

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main()
{
    vector<string> vertexNames = {"A", "B", "C", "D", "E"};// Vertices
    int V = vertexNames.size();
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

    // graph
    dist[0][1] = 5;
    dist[1][3] = 1;
    dist[2][0] = 3;
    dist[2][1] = 2;
    dist[2][4] = -7;
    dist[3][2] = 9;
    dist[4][3] = 8;

    // Set diagonal elements to 0
    for (int i = 0; i < V; i++)
    {
        dist[i][i] = 0;
    }

    floydWarshall(dist, vertexNames);

    cout << "Shortest Distances between Vertices:" << endl<<endl;
    for (int i = 0; i < V; i++)
    {
        cout << "\t(" << vertexNames[i] << ")";
    }
    cout << endl;

    for (int i = 0; i < V; i++)
    {
        cout << "(" << vertexNames[i] << ")\t";
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INT_MAX)
            {
                cout << "inf\t";
            }
            else
            {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }

    return 0;
}
