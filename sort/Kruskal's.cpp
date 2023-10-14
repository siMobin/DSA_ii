#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int src, dest, weight;
};

class Graph
{
public:
    int V, E;
    vector<Edge> edges;

    Graph(int v, int e)
    {
        V = v;
        E = e;
        edges.resize(e);
    }

    void addEdge(int src, int dest, int weight)
    {
        edges.push_back({src, dest, weight});
    }

    // Find the parent of a set using Union-Find
    int findParent(vector<int>& parent, int node)
    {
        if (parent[node] == -1)
            return node;
        return findParent(parent, parent[node]);
    }

    // Union of two sets using Union-Find
    void unionSets(vector<int>& parent, int x, int y)
    {
        int xRoot = findParent(parent, x);
        int yRoot = findParent(parent, y);
        parent[xRoot] = yRoot;
    }

    // Kruskal's algorithm to find the minimum spanning tree
    void kruskalMST()
    {
        vector<Edge> result;
        vector<int> parent(V, -1);

        // Sort the edges in ascending order by weight
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)
        {
            return a.weight < b.weight;
        });

        int edgeCount = 0;
        for (Edge edge : edges)
        {
            int srcRoot = findParent(parent, edge.src);
            int destRoot = findParent(parent, edge.dest);

            if (srcRoot != destRoot)
            {
                result.push_back(edge);
                unionSets(parent, srcRoot, destRoot);
                edgeCount++;

                // If we have added V-1 edges, stop (minimum spanning tree is complete)
                if (edgeCount == V - 1)
                    break;
            }
        }

        // Print the minimum spanning tree
        cout<<"The minimum spanning tree ---> \n";
        for (Edge edge : result)
        {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
        }
    }
};

int main()
{
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    Graph graph(V, E);

    // Add edges to the graph (src, dest, weight)
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    // Find and print the minimum spanning tree
    graph.kruskalMST();

    return 0;
}

