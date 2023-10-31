#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int V = 4; // Number of vertices in the graph

int findMinKey(int key[], bool mstSet[])
{
    int minKey = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
    {
        if (!mstSet[v] && key[v] < minKey)
        {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void primMST(int graph[V][V])
{
    int parent[V];  // Array to store the constructed MST
    int key[V];     // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices not yet included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;     // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1; // First node is always the root of MST

    vector<pair<int, pair<int, int>>> edges; // Vector to store edges and their weights

    for (int count = 0; count < V - 1; count++)
    {
        int u = findMinKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST and store edges in the 'edges' vector
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
        edges.push_back({graph[i][parent[i]], {parent[i], i}});
    }

    // Sort the edges by their weights
    sort(edges.begin(), edges.end());

    // Print the sorted edges and weights
    cout << "\nSorted Edges by Weight:\n";
    for (const auto &edge : edges)
    {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        cout << u << " - " << v << "\t" << weight << "\n";
    }
}

int main()
{
    int graph[V][V] =
        {
            {0, 9, 11, 7},
            {9, 0, 5, 10},
            {11, 5, 0, 12},
            {7, 10, 12, 0},
        };

    primMST(graph);

    return 0;
}
